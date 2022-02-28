/*
 * Made by Ivory A. Yang 2022
 * For Harvard CS124 Programming Assignment 1
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<ctime>
//#include <sys/time.h>
#include "graph.h"
#include "kruskal.h"

// Generate a random number from [0, 1]
float randFloat();

// Generate graph
int generate_graph0d(int n, edge** graph, int sample_size);
int generate_graph234d(int n, int d, edge** graph,int sample_size);
float distance(int d, float* p1, float* p2);
int generate_graph(int n, int d, edge** graph,int sample_size) {
    if (d == 0) {
        return generate_graph0d(n,  graph,sample_size);
    }
    else {
        return generate_graph234d(n, d, graph, sample_size);
    }
}



float randFloat()
{    
    return (float)rand() / (float)RAND_MAX;
}

void vertex_edges_prioritize(edge*** vmin_edges,const int& from,const int& to,const float& val,const int& m) {
    
    bool check = true;

    if (val < vmin_edges[from][m - 1]->length) {        
        vmin_edges[from][m - 1]->length = val;        
        vmin_edges[from][m - 1]->p1 = from;
        vmin_edges[from][m - 1]->p2 = to;        
        sort_graph(m, vmin_edges[from]);
    }
    if (val < vmin_edges[to][m - 1]->length) {
        vmin_edges[to][m - 1]->length = val;
        vmin_edges[to][m - 1]->p1 = from;
        vmin_edges[to][m - 1]->p2 = to;
        sort_graph(m, vmin_edges[to]);
    }
}
int generate_graph0d(int n, edge** graph, int sample_size) {
   
   /* float** edges;
    edges = (float**)malloc(sizeof(float*) * n);
    
    for (i = 0; i < n; i++)
        edges[i] = (float*)malloc(sizeof(float) * n);
    int th_test = 2;*/
    int numEdges = 0;
    int i = 0, j = 0;    
    int m=n-1<sample_size?n-1: sample_size;
    edge*** vmin_edges = (edge ***) malloc(sizeof(edge**) * n);
    for (i = 0; i < n; i++) {
        vmin_edges[i] = (edge**)malloc(sizeof(edge*) * m);
        for (j = 0; j < m; j++) {
            vmin_edges[i][j] = (edge*)malloc(sizeof(edge));
            vmin_edges[i][j]->length = 1.0;
            vmin_edges[i][j]->p1 = -1;
            vmin_edges[i][j]->p2 = -1;
        }           
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            float val = randFloat();
            vertex_edges_prioritize(vmin_edges, i, j, val, m);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            graph[numEdges++] = vmin_edges[i][j];
        }
    }
    return numEdges;
}

// Generate 234d graph
int generate_graph234d(int n,int d, edge** graph, int sample_size) {
    // Keep track of vertices. Each row is single vertex with dimensionality d
    float** ver_dim;
    ver_dim = (float**)malloc(sizeof(float*) * n);
    int i, j, k;
    for (i = 0; i < n; i++) {
        ver_dim[i] = (float*)malloc(sizeof(float) * d);
    }

    // Initialize vertices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            ver_dim[i][j] = randFloat();
        }
    }

    int numEdges = 0;
    int m = n - 1 < sample_size ? n - 1 : sample_size;
    edge*** vmin_edges = (edge***)malloc(sizeof(edge**) * n);
    for (i = 0; i < n; i++) {
        vmin_edges[i] = (edge**)malloc(sizeof(edge*) * m);
        for (j = 0; j < m; j++) {
            vmin_edges[i][j] = (edge*)malloc(sizeof(edge));
            vmin_edges[i][j]->length = 1.0;
            vmin_edges[i][j]->p1 = -1;
            vmin_edges[i][j]->p2 = -1;
        }
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            float val = distance(d, ver_dim[i], ver_dim[j]);
            vertex_edges_prioritize(vmin_edges, i, j, val,m);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            graph[numEdges++] = vmin_edges[i][j];
        }
    }
    delete vmin_edges;
    for (int i = 0; i < n; i++) {
        delete ver_dim[i];
    }
    delete ver_dim;
    return numEdges;
}



// Calculate euclidean distance between two points p1 and p2
float distance(int d, float* p1, float* p2)
{
    float sum = 0;
    for (int i = 0; i < d; i++)
    {
        float diff = p2[i] - p1[i];
        sum += pow(diff, 2.00);
    }
    float distance = sqrt(sum);
    return distance;
}
