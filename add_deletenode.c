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
int deletenode(nodeptr p, nodeptr *proot);
nodeptr maketree(void); // Example tree
void printtree(nodeptr p);

int main(int argc, const char * argv[]) {
    
    
    nodeptr p = maketree();
    printtree(p);
    printf("\n");
    return 0;
}



/*      10
    6         15
  1   8    12    18
     7 9       16  24
 */

nodeptr maketree(void) {
    nodeptr root = NULL;
    nodeptr p;
    p = root = addnode(root, 10);
    nodeptr *proot = &root;
    addnode(root, 6);
    addnode(root, 15);
    addnode(root, 1);
    addnode(root, 8);
    addnode(root, 7);
    addnode(root, 9);
    addnode(root, 12);
    addnode(root, 18);
    addnode(root, 16);
    addnode(root, 24);
    deletenode(p, proot);
    //deletenode(q);

    return root;
}

void printtree(nodeptr p) {
    if (p == NULL)
        return;
    printf("%d ", p -> info);
    printtree(p -> left);
    printtree(p -> right);
    return;
}

int deletenode(nodeptr p, nodeptr *proot) {
    
    int x = p -> info;
    nodeptr q = p -> up;
    
    // Desired deleted node is a leaf
    if (p -> right == NULL && p -> left == NULL) {
        if (q -> left == p)
            q -> left = NULL;
        if (q -> right == p)
            q -> right = NULL;
        if (p == *proot) // If root node is leaf
            *proot = NULL;
        free(p);
        return x;
    }
    
    // Move right subtree to bottom right of left subtree under various conditions
    nodeptr r;
    if (q == NULL) { // If deleted root node is not a leaf
        if (p -> left == NULL) {
            (p -> right) -> up = NULL;
            *proot = p -> right;
        }
        if (p -> right == NULL) {
            (p -> left) -> up = NULL;
            *proot = p -> left;
        }
        if (p -> left != NULL && p -> right != NULL) {
            *proot = r = p -> left;
            r -> up = q;
            while (r -> right != NULL)
                r = r -> right;
            (p -> right) -> up = r;
            r -> right = p -> right;
        }
        free(p);
        return x;
    }
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
        r -> up = q;
        if (q -> right == p)
            q -> right = r;
        if (q -> left == p)
            q -> left = r;
        while (r -> right != NULL)
            r = r -> right;
        (p -> right) -> up = r;
        r -> right = p -> right;
        free(p);
    }
    
    return (x);
}



nodeptr addnode(nodeptr p, int x) {
    
    if (p == NULL) {
        p = getnode();
        p -> info = x;
        p -> up = p -> left = p -> right = NULL;
        return p;
    }
    
    nodeptr q;
    if (x > (p -> info)) {
        if (p -> right != NULL) {
            return(addnode(p -> right, x));
        }
        else {
            q = getnode();
            p -> right = q;
            q -> up = p;
            q -> info = x;
            q -> left = q -> right = NULL;
            return q;
        }
    }
    
    if (p -> left != NULL) {
        return(addnode(p -> left, x));
    }
    else {
        q = getnode();
        p -> left = q;
        q -> up = p;
        q -> info = x;
        q -> left = q -> right = NULL;
        return q;
    }
}


nodeptr getnode(void) {
    return((nodeptr) malloc(sizeof(struct node)));
}
