#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "RGG.c"



// Generate a random number from [0, 1]
float randFloat() {
return (float) rand() / (float) RAND_MAX;
  
int generateGraph(int n, int d, int *cap, edge ***graph) {
    // Seed RNG
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand((unsigned) tv.tv_usec);

	// Obtain threshold
    float th = threshold(n, d);

    assert (th != -1);

	// Generate graph
	if (d == 0) {
		return generate0d(n, th, cap, graph);
	} else {
		return generate234d(n, d, th, cap, graph);
	}
}
    
    
