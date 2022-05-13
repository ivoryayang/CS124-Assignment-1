#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "graph.h"
#include "disjoint.h"

edge** merge(edge** left, edge** right, int lsize, int rsize,int n) {
	edge** temp = (edge**)malloc(sizeof(edge*)* (lsize + rsize));
	int lp = 0, rp = 0,tp=0;
	while (lp < lsize && rp < rsize) {
		if (left[lp]->length < right[rp]->length) {
			temp[tp++] = left[lp++];
		}
		else {
			temp[tp++] = right[rp++];
		}
	}
	if (lp < lsize) {
		while (lp < lsize)
			temp[tp++] = left[lp++];
	}
	else if (rp < rsize) {
		while (rp < rsize)
			temp[tp++] = right[rp++];
	}
	int i = 0;
	for (i = 0; i < lsize + rsize; i++) {
		left[i] = temp[i];
	}
	delete temp;
	return left;

}
edge** merge_sort(int l, int h, edge** edges,int n) {
	if (l == h) {
		return edges + l;
	}
	int m = (h + l) / 2;
	edge** left = merge_sort(l, m, edges,n);
	edge** right = merge_sort(m + 1, h, edges,n);
	return merge(left, right,m-l+1,h-m,n);
}

edge** sort_graph(int n,edge** edges) {
	return merge_sort(0, n - 1, edges,n);
}

edge** kruskal(int n,int gsize, edge** graph) {
	edge** min_spanning_tree = (edge**)malloc(sizeof(edge*) * (n-1));
	int mst_ind = 0;
	sort_graph(gsize, graph);
	int*parent = (int*)malloc(sizeof(int) * n);
	int* rank = (int*)malloc(sizeof(int) * n);
	set_dsu(parent, rank, n);
	for (int i = 0; i < gsize; i++) {
		int p1 = find(graph[i]->p1,parent);
		int p2 = find(graph[i]->p2, parent);
		if (p1 != p2) {
			merge_set(p1, p2, parent, rank);
			min_spanning_tree[mst_ind++] = graph[i];
		}
		if (mst_ind == n)
			break;
	}
	if (mst_ind != n - 1)
		return nullptr;
	int snum=set_count(parent, n);
	return min_spanning_tree;
}
