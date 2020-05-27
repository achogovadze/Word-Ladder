/*
* File: WordLadder.cpp
* --------------------------
* Name: [TODO: enter name here]
* Section: [TODO: enter section leader here]
* This file is the starter project for the Word Ladder problem.
* [TODO: rewrite the documentation]
*/

#include <iostream>
//#include "console.h"
#include "simpio.h"
#include "lexicon.h"
#include "set.h"
#include "vector.h"
#include "queue.h"

using namespace std;

bool exists(string start, string dest);
void findPath(string start, string dest);
void displayLadder(Vector<string> &vect);
Lexicon newLex(string word);
Lexicon lex("EnglishWords.dat");

int main() {
	while (1){
		string start = getLine("Enter start word (RETURN to quit): ");
		string dest = getLine("Enter destination word: ");
		if (start == "" || dest == ""){
			cout << "Exit" << endl;
			break;
		}
		if(exists(start, dest)){
			cout << "Searching..." << endl;
			findPath(start, dest);
		}
	}
	return 0;
}

// method checks if such words exist in given dat file.
bool exists(string start, string dest){
	if (lex.contains(start) && lex.contains(dest))
		return true;
	cout << "Such words don't exist" << endl;
	return false;
}

// method searches shortest path from start word to dest word.
void findPath(string start, string dest){
	Set<string> used;
	used += start;
	Queue<Vector<string> > queue;
	Vector<string> vect;
	vect.add(start);
	queue.enqueue(vect);
	Vector<string> cur;
	while (!queue.isEmpty()){
		cur = queue.dequeue();
		if (cur[cur.size()-1] == dest){
			displayLadder(cur);
			break;
		}
		Vector<string> newVect;
		Lexicon checkLex = newLex(cur[cur.size()-1]);
		foreach (string newWord in checkLex){
			if (!used.contains(newWord)){
				used += newWord;
				newVect = cur;
				newVect.add(newWord);
				queue.enqueue(newVect);
			}
		}
		if (queue.isEmpty()){
			cout << "No ladder found " << endl;
		}
	}
}

// this method returns lexicon with words that are one letter different from the given word.
Lexicon newLex(string word){
	Lexicon newLex;
	string temp = word;
	for (int i = 0; i < temp.length(); i++){
		for (int k = 0; k < 26; k++){
			temp[i] = 'a' + k;
			if (word != temp && lex.contains(temp))
				newLex.add(temp);
		}
		temp = word;
	}
	return newLex;
}

// this method prints found ladder to a console.
void displayLadder(Vector<string> &vect){
	string result;
	for (int i = 0; i < vect.size(); i++){
		result += vect[i];
		result += " - - ";
	}
	cout << "Ladder found: " << result << endl;
}