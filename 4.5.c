//
//  main.c
//  4.5
//
//  Created by Yunus Syed on 7/19/20.
//  Copyright © 2020 Yunus Syed. All rights reserved.
//

#include <stdio.h>
#include <strings.h>


void swap(char *names, int a, int b);
void josephus(char *names, int n, int m, int j);

int main() {
    int n;
    
    printf("Enter number of names: ");
    scanf("%d", &n);
    char names[n];
    char c;
    
    for (int i = 0; i < n; i++) {
        printf("Enter name %d: ", i+1);
        scanf("%s", &c);
        names[i] = c;
    }
    
    printf("Choose starting name: ");
    scanf("%s", &c);
    if (c == '\n')
        scanf("%c", &c);
    
    int x, j;
    x = 0;
    for (j = 0; j < n; j++)
        if (names[j] == c) {
            x = 1;
            break;
        }
    if (x == 0) {
        printf("Not valid starting name\n");
        return 0;
    }
    
    int m;
    printf("Enter a number: ");
    scanf("%d", &m);
    
    josephus(names, n, m, j);
    printf("\n");
    
    return 0;
}

void josephus(char *names, int n, int m, int j) {
    
    if (n == 1) {
        printf("The person who gets away is %c", names[0]);
        return;
    }
    
    int i = (j + m) % n;
    j = i;
    if (i != n)
        while (i < n) {
            swap(names, i, i+1);
            i++;
        }
    
    n--;
    char *s;
    s = (char *) malloc(n * sizeof(char));
    strncpy(s, names, n);
    josephus(names, n, m, j);
    
    return;
}

void swap(char *names, int a, int b) {
    char temp;
    temp = names[a];
    names[a] = names[b];
    names[b] = temp;
}
