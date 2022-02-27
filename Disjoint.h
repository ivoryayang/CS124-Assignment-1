typedef struct node node;

// Create new node with value x
node *makeset(int x);

// Find root of tree that n is in
node *find(node *n);

// Join trees containing node x and node y
void join(node *x, node *y);
