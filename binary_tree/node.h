#include<cstddef>
#ifndef NODE
#define NODE
typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;

    Node(int val) {
       this -> val = val; 
       this -> left = NULL;
       this -> right = NULL;
    }
} Node;
#endif
