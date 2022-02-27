/*
 * Made by Ivory A. Yang 2022
 * For Harvard CS124 Programming Assignment 1
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "graph.h"

// Prototypes
static graph *generate_graph0d(int n, float th, int *cap, edge ***graph)
static graph *generate_graph234d(int n, int d, float th, int *cap, edge ***graph)
	
// Generate a graph with n vertices in adjacency matrix form
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

// Generate 0d graph
int generate_graph0d(int n, float th, int *cap, edge ***graph)
	int numEdges = 0
	// Find all edges
	for (int i = 1; i < n; i++)
	{
		for (int j = 0, i < i; j++)
		{
			float val = randFloat();
			if (
	


int generate0d(int n, float th, int *cap, edge ***graph) {
    int numEdges = 0;
    // Find all edges
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // If value is greater than threshold, ignore it
            float val = randFloat();
            if (val > th) {
                continue;
            }

            // Creating edge
            edge *e = malloc(sizeof(edge));
            e->p1 = i;
            e->p2 = j;
            e->length = val;
            (*graph)[numEdges] = e;
            numEdges++;

            // Realloc for more space if cap reached
            if (numEdges >= *cap) {
                *graph = (edge**) realloc((void*) *graph, (*cap * 2) * sizeof(edge*));
                *cap *= 2;
            }
        }
    }
    return numEdges;
}
	
// Generate 234d graph
int generate_graph234d(int n, float th, int *cap, edge ***graph) {
	// Keep track of vertices. Each row is single vertex with dimensionality d
	float vertices[n][d];

	// Initialize vertices
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			vertices[i][j] = randFloat();
		}
	}

    int numEdges = 0;

    // Find all edges
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // If individual axes difference greater than threshold, ignore
            for (int dim = 0; dim < d; dim++) {
                if (vertices[i][dim] - vertices[j][dim] > th) {
                    continue;
                }
            }

            // If distance between points greather than threshold, ignore
            float dist = distance(d, vertices[i], vertices[j]);
            if (dist > th) {
                continue;
            }

            // Create edge
            edge *e = malloc(sizeof(edge));
            e->p1 = i;
            e->p2 = j;
            e->length = dist;
            (*graph)[numEdges] = e;
            numEdges++;

            // If cap reached, realloc
            if (numEdges >= *cap) {
                *graph = (edge**) realloc((void*) *graph, (*cap * 2) * sizeof(edge*));
                *cap *= 2;
            }
        }
    }
    return numEdges;
}
								

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
   
    
