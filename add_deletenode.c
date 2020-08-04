//
//  main.c
//  MoreBinTree
//
//  Created by Yunus Syed on 7/31/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *left;
    struct node *up;
    struct node *right;
};

typedef struct node *nodeptr;
nodeptr getnode(void);
nodeptr addnode(nodeptr p, int x);
int deletenode(nodeptr p);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}


int deletenode(nodeptr p) {
    
    int x = p -> info;
    
    // Desired deleted node is a leaf
    nodeptr q = p -> up;
    if (p -> right == NULL && p -> left == NULL) {
        if (q -> left == p)
            q -> left = NULL;
        if (q -> right == p)
            q -> right = NULL;
        free(p);
    }
    
    // Move right subtree to bottom right of left subtree under various conditions
    nodeptr r;
    if (p -> left == NULL && p -> right != NULL) {
        r = p -> right;
        r -> up = q;
        if (q -> left == p)
            q -> left = r;
        if (q -> right == p)
            q -> right = r;
        free(p);
    }
    
    if (p -> left != NULL && p -> right == NULL) {
        r = p -> left;
        r -> up = q;
        if (q -> left == p)
            q -> left = r;
        if (q -> right == p)
            q -> right = r;
        free(p);
    }
    
    if (p -> left != NULL && p -> right != NULL) {
        r = p -> left;
        while (r -> right != NULL)
            r = r -> right;
        (p -> right) -> up = r;
        r -> right = p -> right;
        free(p);
    }
    
    return (x);
}



nodeptr addnode(nodeptr p, int x) {
    
    nodeptr q;
    if (x > (p -> info)) {
        if (p -> right != NULL) {
            addnode(p -> right, x);
        }
        else {
            q = getnode();
            p -> right = q;
            q -> up = p;
            q -> info = x;
            q -> left = q -> right = NULL;
        }
        return q;
    }
    
    if (p -> left != NULL) {
        addnode(p -> left, x);
    }
    else {
        q = getnode();
        p -> left = q;
        q -> up = p;
        q -> info = x;
        q -> left = q -> right = NULL;
    }
        return q;
}


nodeptr getnode(void) {
    return((nodeptr) malloc(sizeof(struct node)));
}
