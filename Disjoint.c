#include <assert.h>
#include <stdlib.h>
#include <string.h>


int ds_find(ds_forest *, int);

ds_forest *ds_make_forest(int size) {
    ds_forest *f = (ds_forest *) malloc(sizeof(ds_forest));
    f->p = (int *) malloc(sizeof(int) * size);
    f->rank = (int *) malloc(sizeof(int) * size);
    memset(f->p, -1, sizeof(int) * size);
    memset(f->rank, -1, sizeof(int) * size);
    f->size = size;
    return f;
}
