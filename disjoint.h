#pragma once

void set_dsu(int* parent, int* rank, int n);
int find(int a, int* parent);
int set_count(int* parent, int n);
void merge_set(int a, int b, int* parent, int* rank);
