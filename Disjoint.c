#include <assert.h>
#include <stdlib.h>
#include "Disjoint.h"


void set_dsu(int* parent,int* rank, int n) {

    int i;
    for ( i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 1;
    }
}

int find(int a, int* parent) {
    if (parent[a] == a) return a;
    else return find(parent[a],parent);
}

void merge_set(int a, int b,int *parent,int* rank) {
    int u = find(a,parent), v = find(b,parent);
    if (u != v) {
        if (rank[u] > rank[v]) {
            parent[v] = u;
            rank[u] = (rank[u] > 1 + rank[v]) ? rank[u] : 1 + rank[v];
        }
        else {
            parent[u] = v;
            rank[v] = (rank[v] > 1 + rank[u]) ? rank[v] : 1 + rank[u];
        }
    }
    return;
}
int set_count(int* parent,int n) {
    int cnt{};
    for (int i = 0; i < n; i++)
    {
        if (i == parent[i])
            cnt++;
    }
    return cnt;
}
