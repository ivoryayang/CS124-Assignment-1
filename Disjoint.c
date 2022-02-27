#include <assert.h>
#include <stdlib.h>
#include "disjoint.h"

node *makeSet(int x)
{
    node *n = malloc(sizeof(node));
    n->value = x;
    n->parent = n;
    n->rank = 0;
    return n;
}

node *find(node *n)
{
    if (n != n->parent)
    {
        n->parent = find(n->parent);
    }
    return n->parent;
}

void link(node *x, node *y)
{
  if (x->rank > y->rank)
    {
      link(y,x);
      return;
    }
  else if (x->rank == y->rank)
    y->rank++;
  x->parent = y;
}

void join(node *x, node *y)
{
  link(find(x),find(y));
}
