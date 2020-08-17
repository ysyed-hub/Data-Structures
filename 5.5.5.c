//
//  main.c
//  5.5.5
//
//  Created by Yunus Syed on 8/8/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>


struct treenode {
    int info;
    struct treenode *next;
    struct treenode *son;
};

typedef struct treenode *treenodeptr;

struct forestnode {
    treenodeptr root;
    struct forestnode *left;
    struct forestnode *right;
};

typedef struct forestnode *forestnodeptr;

// Making a list to hold treenodes
struct node {
    treenodeptr tree;
    struct node *nextnode;
};

typedef struct node *nodeptr;

void printforest(forestnodeptr start); // Stores all nodes into a list before printing them out

treenodeptr gettreenode(void);
forestnodeptr getforestnode(void);
nodeptr getnode(void);

treenodeptr maketree(treenodeptr root);
forestnodeptr makeforest(void);
treenodeptr addtreenode(int a, treenodeptr *proot); // Adding node containing "a" to the tree with root p

int forestleafcount(forestnodeptr root);
int treeleafcount(treenodeptr root);
nodeptr forestlist(forestnodeptr root, nodeptr start, nodeptr *end);
int foresttreecount(forestnodeptr root);


int main() {
    forestnodeptr p = makeforest();
    printforest(p);
    return 0;
}

void printforest(forestnodeptr root) { // Stores
    
    if (root == NULL)
        return;
    
    nodeptr start, current, end;
    nodeptr *pend = &end;
    start = NULL;
    start = forestlist(root, start, pend);
    current = start;
    nodeptr q = end;
        
    
    int i = 0;
    while (i < forestleafcount(root)) {
        i++;
        treenodeptr p = (current -> tree);
        p = p -> son;
        while (p != NULL) {

            q -> nextnode = getnode();
            q = q -> nextnode;
            q -> tree = p;
            p = p -> next;
        }
        current = current -> nextnode;
    }
    
    i = 0;
    while (i < forestleafcount(root)) {
        printf("%d ", (start -> tree) -> info);
        start = start -> nextnode;
        i++;
    }
    printf("\n");
    
}

int foresttreecount(forestnodeptr root) {
    int x = 0;
    if (root == NULL)
        return x;
    x++;
    x+= foresttreecount(root -> left);
    x+= foresttreecount(root -> right);
    return x;
}

nodeptr forestlist(forestnodeptr root, nodeptr start, nodeptr *end) {
    if (root == NULL)
        return NULL;
    if (start == NULL) {
        start = getnode();
        *end = start;
        start -> nextnode = NULL;
        start -> tree = root -> root;
    }
    else {
        (*end) -> nextnode = getnode();
        *end = (*end) -> nextnode;
        (*end) -> nextnode = NULL;
        (*end) -> tree = root -> root;
    }
    forestlist(root -> left, start, end);
    forestlist(root -> right, start, end);
    return start;
}

int forestleafcount(forestnodeptr froot) {
    int x = 0;
    if (froot == NULL)
        return x;
    x += treeleafcount(froot -> root);
    x += forestleafcount(froot -> left);
    x += forestleafcount(froot -> right);
    return x;
}

int treeleafcount(treenodeptr root) {
    int x = 0;
    if (root == NULL)
        return x;
    x++;
    x += treeleafcount(root -> next);
    x += treeleafcount(root -> son);
    return x;
}

forestnodeptr makeforest(void) {
    forestnodeptr first = getforestnode();
    treenodeptr root = NULL;
    treenodeptr *proot = &root;
    first -> root = root = addtreenode(20, proot);
    addtreenode(25, proot);
    addtreenode(10, proot);
    addtreenode(7, proot);
    addtreenode(13, proot);
    addtreenode(21, proot);
    addtreenode(29, proot);
    addtreenode(27, proot);
    addtreenode(30, proot);
    
    
    forestnodeptr second = getforestnode();
    first -> left = second;
    treenodeptr root2 = NULL;
    treenodeptr *proot2 = &root2;
    second -> root = root2 = addtreenode(15, proot2);
    addtreenode(7, proot2);
    addtreenode(21, proot2);
    addtreenode(19, proot2);
    addtreenode(25, proot2);
    second -> left = second -> right = NULL;
    
    forestnodeptr third = getforestnode();
    first -> right = third;
    treenodeptr root3 = NULL;
    treenodeptr *proot3 = &root3;
    third -> root = root3 = addtreenode(2, proot3);
    addtreenode(1, proot3);
    addtreenode(4, proot3);
    addtreenode(3, proot3);
    third -> left = third -> right = NULL;
    
    return first;
}

/* treenodeptr maketree(treenodeptr root) {
    treenodeptr p;
    treenodeptr *proot = &root;
    root = addtreenode(20, proot);
    p = addtreenode(25, proot);
    addtreenode(10, proot);
    addtreenode(7, proot);
    addtreenode(13, proot);
    addtreenode(21, proot);
    addtreenode(29, proot);
    addtreenode(27, proot);
    addtreenode(30, proot);
    //printf("%d %d ", (p -> next) -> info, ((p -> next) -> son) -> info);

    return root;
} */

treenodeptr addtreenode(int a, treenodeptr *proot) {
    treenodeptr p, q = *proot;
    if (*proot == NULL) {
        *proot = gettreenode();
        (*proot) -> info = a;
        (*proot) -> next = (*proot) -> son = NULL;
        return *proot;
    }
    
    p = (*proot) -> son;
    int state = 1;
    while (p != NULL) {
        q = p;
        if (a > (p -> info)) {
            p = p -> next;
            state = 0;
            continue;
        }
        if (a < (p -> info)) {
            p = p -> son;
            state = 1;
            continue;
        }
        if (a == (p -> info))
            return p;
        
    }
    
    p = gettreenode();
    p -> info = a;

    if (state == 0) // p is to the right of q
        q -> next = p;
    if (state == 1) // p is the son of q
        q -> son = p;
    
    p -> next = p -> son = NULL;
    return p;
}

nodeptr getnode(void) {
    return((nodeptr) malloc(sizeof(struct node)));
}

treenodeptr gettreenode(void) {
    return((treenodeptr) malloc(sizeof(struct treenode)));
}
forestnodeptr getforestnode(void) {
    return((forestnodeptr) malloc(sizeof(struct forestnode)));

}
