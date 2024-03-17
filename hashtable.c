#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int create(int);
void linear_prob(int[], int, int);
void display(int[]);

int main() {
    int a[MAX], num, key, i;
    bool ans = true;

    printf("Collision handling by linear probing:\n");
    for (i = 0; i < MAX; i++) {
        a[i] = -1;
    }

    do {
        printf("\nEnter the data: ");
        scanf("%d", &num);
        key = create(num);
        linear_prob(a, key, num);
        printf("\nDo you wish to continue? (1/0) ");
        scanf("%d", &ans);
    } while (ans);

    display(a);
    return 0;
}

int create(int num) {
    return num % MAX;
}

void linear_prob(int a[MAX], int key, int num) {
    int i, next;

    if (a[key] == -1) {
        a[key] = num;
    } else {
        printf("\nCollision Detected...!!!\n");
        i = 1;
        next = (key + i) % MAX;
        while (a[next] != -1 && next != key) {
            i++;
            next = (key + i) % MAX;
        }

        if (a[next] == -1) {
            a[next] = num;
            printf("Collision avoided successfully using LINEAR PROBING\n");
        } else {
            printf("\nHash table is full\n");
            display(a);
            exit(1);
        }
    }
}
void display(int a[MAX]) {
    int i, choice;
    printf("\n1. Display ALL\n2. Filtered Display\n");
    scanf("%d", &choice);

    printf("\nThe hash table is:\n");
    for (i = 0; i < MAX; i++) {
        if (choice == 2 && a[i] == -1) {
            continue;
        }
        printf("%d %d\n", i, a[i]);
    }
}
