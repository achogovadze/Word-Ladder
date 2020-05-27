A word ladder is a connection from one word to another formed by changing one letter at a time with
the constraint that at each step the sequence of letters still forms a valid word. For example, here is a
word ladder connecting "code" to "data".
code ® core ® care ® dare ® date ® data
That word ladder, however, is not the shortest possible one. Although the words may be a little less
familiar, the following ladder is one step shorter:
code ® cade ® cate ® date ® data

This is a program that finds a minimal word ladder between two words.
Code will make use of several of the ADTs from Chapter 5, along with a powerful algorithm
called breadth-first search to find the shortest such sequence.