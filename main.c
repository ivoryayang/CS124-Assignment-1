/*
 * Made by Ivory A. Yang 2022
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include "graph.h"
#include "disjoint.h"
#include "kruskal.h"

using namespace std;
int main() {

    srand(time(0));    
    int samples[7] = { 128, 256, 512, 1024, 2048, 4096, 8192 };
        //16384, 32768, 65536, 131072, 262144
    int test_size = 5;
    int i = 0,j=0,x=0;
    float result[7];
    ofstream fs("C:\\Users\\ivyxara\\Desktop\\output.txt");
    for (i = 0; i < 7; i++) {        
        for (x = 1; x <= 4; x++) {
            float mst_total = 0;
            for (int j = 0; j < test_size; j++) {
                int n = samples[i];
                int sample_size = 16;
                int cap = n * sample_size;
                edge** graph = (edge**)malloc(sizeof(edge*) * cap);
                int num_edges = generate_graph(n, x, graph,sample_size);
                graph = sort_graph(num_edges, graph);
                edge** min_span_tree = (edge**)malloc(sizeof(edge*) * (n - 1));
                min_span_tree = kruskal(n, num_edges, graph);
                if (min_span_tree) {
                    int k = 0;
                    for (k = 0; k < n - 1; k++) {
                        mst_total += min_span_tree[k]->length;
                    }
                }
                else
                    j--;
            }
            result[i] = mst_total / (float)test_size;   
    }
    fs.close();
    system("pause");
    return 0;
}
