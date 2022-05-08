Documentation for your project in the form of a Markdown file called README.md. This documentation is to be a user’s manual for your project. Though the structure of your documentation is entirely up to you, it should be incredibly clear to the staff how and where, if applicable, to compile, configure, and use your project. Your documentation should be at least several paragraphs in length. It should not be necessary for us to contact you with questions regarding your project after its submission. Hold our hand with this documentation; be sure to answer in your documentation any questions that you think we might have while testing your work.


A short video (that’s no more than 2 minutes in length) in which you present your project to the world, as with slides, screenshots, voiceover, and/or live action, ideally with you yourself appearing in the video. Your video should somehow include your project’s title, your name and year, your dorm/house and concentration, and any other details that you’d like to convey to viewers. See CS171’s tips on how to make a “screencast” though you’re welcome to use a phone or actual camera. Upload your video to YouTube as “public” or “unlisted” and include the URL of the video in your README.md file.




My final project is a command-line program using C that explores Minimum Spanning Trees (MST) using Kruskal’s algorithm. MST refers to a collection of connected vertices in a graph whose cumulative edge weights have the smallest value. Kruskal’s algorithm is one such algorithm to find the MST in a connected graph. By changing the number and dimension of vertices (of the graphs), I was able to explore the behavior of MSTs and also ensure that my program would be able to handle different types of graphs. 

Firstly, a random graph generator was constructed in graph.c to generate the appropriate random graphs. Then I used Kruskal’s algorithm in kruskal.c before implementing a disjoint set data structure (see disjoint.c). Finally, I produced the MST of a given graph in main.c .
