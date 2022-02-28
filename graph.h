#pragma once
typedef struct {
	int p1;
	int p2;
	float length;
} edge;

int generate_graph(int n, int d, edge** graph,int sample_size);
