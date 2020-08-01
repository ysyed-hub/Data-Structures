//
//  main.c
//  MoreBinTree
//
//  Created by Yunus Syed on 7/31/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include <stdio.h>

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
    
    
    return (p -> info);
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
