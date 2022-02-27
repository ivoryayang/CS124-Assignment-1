int generateMST(int n, int d, int edges, edge *graph[n * (n - 1) / 2], edge *mst[n - 1]) {
    // Sorts edges by weight
    mergeSort(graph, 0, edges - 1);
