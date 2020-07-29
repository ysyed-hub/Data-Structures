//
//  main.c
//  5.2
//
//  Created by Yunus Syed on 7/23/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include <stdio.h>

struct node {
    int sign;
    struct node *left;
    struct node *right;
};

typedef struct node *nodeptr;

struct nodelist {
    nodeptr info;
    struct nodelist *r;
};

typedef struct nodelist *nodelistptr;

int traversetree(nodeptr p, nodeptr a);
void leafcount(nodeptr p, int *x);
nodeptr maketree(void);
int makenodelist(nodelistptr start, nodelistptr q, nodeptr p);
nodelistptr getnodelist(void);

void isroot(nodeptr p);

int main(int argc, const char * argv[]) {
    
    nodeptr p = maketree();
    
    printf("Hello, World!\n");
    return 0;
}

void isroot(nodeptr p) {
    int n;
    if (p == NULL)
        n = -1;
    nodelistptr start = getnodelist();
    nodelistptr q = start;
    n = makenodelist(start, q, p);
    
    if (n == -1)
        printf("Not a root of a valid binary tree");
    else {
        printf("Is a root of a valid binary tree");
    }
}

nodelistptr getnodelist(void) {
    return ((nodelistptr) malloc(sizeof(struct nodelist)));
}

int makenodelist(nodelistptr start, nodelistptr q, nodeptr p) {
    if (p == NULL)
        return 0;
    
    q -> info = p;
    q = q -> r;
    nodelistptr a;
    int count = 0;
    for (a = start; a != NULL && a -> r != NULL; a = a -> r) {
        if (p == a -> info)
            count++;
    }
    if (count > 1)
        return -1;
    if (makenodelist(start, q, p -> left) == -1)
        return -1;
    if (makenodelist(start, q, p -> right) == -1)
        return -1;
    return 0;
}
