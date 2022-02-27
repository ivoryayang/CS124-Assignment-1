#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include "graph.h"
#include "disjoint.h"

// Generate a minimum spanning tree 
int generateMST(int v, int d, int edges, edge *graph[n * (n - 1) / 2], edge *mst[n - 1]) {
    // Sorts edges by weight
    mergeSort(graph, 0, edges - 1);
