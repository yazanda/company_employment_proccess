#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Developer.h"

int main() {
    Developer *employees[N], *candidates[N];
    for (int i = 0; i < N; i++) {
        employees[i] = NULL;
        candidates[i] = NULL;
    }
    int chose = 0;
    //loop to receive the chosen number of service and get the methods.
    while (chose != 5) {
        printf("Welcome, what do you want to do?\n");
        printf("1. Print candidates.\n2. Print workers.\n3. Insert new Candidate.\n4. Hire candidate.\n5. Exit.\n");
        scanf("%d", &chose);
        if (chose == 1) {
            printCandidates(candidates);
        } else if (chose == 3) {
            insert(candidates, employees);
        } else if (chose == 4) {
            acceptCandidate(candidates, employees);
        } else if (chose == 2) {
            printWorkers(employees);
        }else if (chose != 5){
            printf("Wrong Number! try another time\n");
        }
    }
    //free all the memory.
    for (int i = 0; i < N; i++) {
        free(candidates[i]);
        free(employees[i]);
    }
    return 0;
}