//
//  main.c
//  bintreestuff
//
//  Created by Yunus Syed on 7/25/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include <stdio.h>


struct node {
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node *nodeptr;

int treelevels(nodeptr p);
nodeptr cpytree(nodeptr p);
nodeptr getnode(void);
nodeptr revcpytree(nodeptr p);

int main(int argc, const char * argv[]) {
    
    nodeptr p, q, r;
    p = getnode();
    q = getnode();
    r = getnode();
    p -> left = q;
    p -> right = r;
    r -> right = getnode();
    r = r -> right;
    r -> left = getnode();
    
    int x = treelevels(p);
    printf("%d\n", x);
    
    return 0;
}

nodeptr cpytree(nodeptr p) {
    
    if (p == NULL)
        return NULL;
    
    nodeptr q = getnode();
    q -> info = p -> info;
    if (p -> left != NULL) {
        q -> left = cpytree(p -> left);
    }
    if (p -> right != NULL) {
        q -> right = cpytree(p -> right);
    }
    
    return q;
}

nodeptr revcpytree(nodeptr p) {

    if (p == NULL)
        return NULL;

    nodeptr q = getnode();
    q -> info = p -> info;
    if (p -> left != NULL) {
        q -> right = cpytree(p -> left);
    }
    if (p -> right != NULL) {
        q -> left = cpytree(p -> right);
    }

    return q;
}


int treelevels(nodeptr p) {
    if (p == NULL)
        return 0;
    int x, y;
    x = y = 1;
    x += treelevels(p -> left);
    y += treelevels(p -> right);
    return (x > y ? x : y);
}

nodeptr getnode() {
    return ((nodeptr) malloc(sizeof(struct node)));
}
