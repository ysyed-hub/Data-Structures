#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>

struct node {
    char *name;
    int number;
    struct node *nextword;
};
typedef struct node *nodeptr;

int getlinef(FILE *fp, char *s);
nodeptr getnames(FILE *fp);
nodeptr getnode(void);
nodeptr startname(nodeptr start);
void getnumbers(nodeptr start);
void josephus(nodeptr start, nodeptr nodestart, int m);

int main(int argc, const char * argv[]) {
    if (argc == 1)
        return 0;
    
    FILE *fp;
    fp = fopen(argv[1], "r");
    nodeptr start = getnames(fp);
    if (start == NULL) {
        printf("File empty");
        return 1;
    }
    
    nodeptr nodestart = startname(start);
    getnumbers(start);
    josephus(start, nodestart, nodestart -> number);
    

    return 0;
}

void josephus(nodeptr start, nodeptr nodestart, int m) {
    int totalnodes = 0;
    nodeptr w = start;
    
    do {
        totalnodes++;
        w = w -> nextword;
    } while (w != start);
    
    if (totalnodes == 1) {
        printf("\"%s\" escapes. \n", nodestart -> name);
        return;
    }
    
    nodeptr v;
    v = w = nodestart;
    
    if (m == 0) {
        while (w -> nextword != nodestart) {
            w = w -> nextword;
        }
        w -> nextword = nodestart -> nextword;
        w = nodestart;
    }
    
    else {
    for (int i = 0; i < m; i++)
        w = w -> nextword;
    for (int i = 0; i < m-1; i++)
        v = v -> nextword;
    v -> nextword = w -> nextword;
    }
    
    printf("\"%s\" is eliminated. \n", w -> name);
    m = w -> number;
    free(w);
    
    josephus(start, v -> nextword, m-1);
}


void getnumbers(nodeptr start) {
    nodeptr w = start;
    do {
        printf("Enter the positive integer for \"%s\": ", w -> name);
        scanf("%d", &(w -> number));
        while(w -> number < 1) {
            printf("Please enter a valid number: ");
            scanf("%d", &(w -> number));
        }
        w = w -> nextword;
    } while(w != start);
}


nodeptr startname(nodeptr start) {
    nodeptr w = start;
    int max = 0;
    do {
        if (max < strlen(w -> name))
            max = strlen(w -> name);
        w = w -> nextword;
    } while(w != start);
    
    char *namestart;
    namestart = (char *) malloc(max * sizeof(char));
    printf("Enter starting name: ");
    scanf("%s", namestart);
    
    w = start;
    nodeptr nodestart;
    do {
        if (strcmp(w -> name, namestart))
            nodestart = w;
        w = w -> nextword;
    } while (w != start);
    
    return nodestart;
}


nodeptr getnames(FILE *fp) {
    char *s = NULL;
    nodeptr start, w, v;
    start = NULL;

    while (getlinef(fp, s)) {
        int state = 0;
        for (w = start; w != NULL; w = w -> nextword) {
            v = w;
            if (strcmp(w -> name, s)) {
                w -> number ++;
                state = 1;
                break;
            }
        }
        if (state == 0) {
            if (start == NULL)
                start = getnode();
            else {
            w = getnode();
            w -> name = s;
            w -> number = 1;
            v -> nextword = w;
            }
        }
    }
    if (start != NULL)
        w -> nextword = start;
    
    return start;
}


int getlinef(FILE *fp, char *s) {
    char c;
    while (isspace(c = getc(fp)))
        ;
    if (c != EOF) {
        s = calloc(1, sizeof(char));
        s[0] = c;
    }
    int i = 1;
    while (!isspace(c = getc(fp)) && c != EOF) {
        s = calloc(i+2, sizeof(char));
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    if (i == 1)
        return 0;
    return 1;
}

nodeptr getnode(void) {
    return (nodeptr) malloc(sizeof(struct node));
}

