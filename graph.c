/*
 * Made by Ivory A. Yang 2022
 * For Harvard CS124 Programming Assignment 1
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "graph.c"

// Generate a complete, undirected graph with n vertices with edge weight between [0,1]


// Generate a random number from [0, 1]
float randFloat() {
return (float) rand() / (float) RAND_MAX;
}
	
// Calculate euclidean distance between two points p1 and p2
float distance(int d, float p1[d], float p2[d]) {
    float sum = 0;
    for (int i = 0; i < d; i++) {
        float diff = p2[i] - p1[i];
        sum += pow(diff, 2.00);
    }
    float distance = sqrt(sum);
    return distance;
}

// Generates a graph with n vertices in adjacency matrix form
int graph(int n, int d, int *cap, edge ***graph){
    // Seed once in microseconds 
    struct timeval t1;
    gettimeofday(&t1, NULL);
    srand(t1.tv_usec * t1.tv_sec);
}
	  
	  

// Obtain threshold for edge throwaway
    float th = threshold(n, d);

    assert (th != -1);

	// Generate graph
	if (d == 0) {
		return generate0d(n, th, cap, graph);
	} else {
		return generate234d(n, d, th, cap, graph);
	}
}
    
    
