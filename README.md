My final project is a command-line program using C that explores Minimum Spanning Trees (MST) using Kruskal’s algorithm. MST refers to a collection of connected vertices in a graph whose cumulative edge weights have the smallest value. Kruskal’s algorithm is one such algorithm to find the MST in a connected graph. By changing the number and dimension of vertices (of the graphs), I was able to explore the behavior of MSTs and also ensure that my program would be able to handle different types of graphs. This is actually very applicable in real life - we can use this program/algorithm to potentially find the shortest driving route to get from one destination to the other, or the shortest set of roads that connects an entire campus together. Depending on what kind of graph we use as input for my program, we can apply it to use in real life scenarios.

For the set-up for my project, I narrowed it down to considering complete, undirected graphs only, as directed graphs would add an additional element of difficulty. Some graphs I considered were:

• Complete graphs on n vertices, where the weight of each edge is a real number chosen uniformly at
random on [0, 1].

• Complete graphs on n vertices, where the vertices are points chosen uniformly at random inside the
unit square. 

• Complete graphs on n vertices, where the vertices are points chosen uniformly at random inside the
unit cube (3 dimensions) and hypercube (4 dimensions). 

My program finds the expected (average) weight of the MST, and how it grows as a function of n (vertices). d in this project refers to dimensions, as shown for the graph examples above. 

For the coding portion, I needed to be able to generate appropriate random graphs, as well as implement an MST algorithm, which in my case I chose Kruskal's algorithm. Firstly, a random graph generator was constructed in graph.c to generate the appropriate random graphs, with the option to change the values of n (vertices) and d (dimensions) Then I used Kruskal’s algorithm in kruskal.c, before implementing a disjoint set data structure (see disjoint.c), which is needed to run Kruskal's algorithm. Finally, I produced the MST of a given graph in main.c .


https://www.youtube.com/watch?v=UOVTDB_0XAk
