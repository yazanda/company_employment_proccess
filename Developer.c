#include "Developer.h"
int numOfEmployees = 0, numOfCandidates = 0;
//Method that prints the candidates list of the company.
void printCandidates(Developer *cand[]) {
    //if the candidates number is 0 tell the user that it's empty.
    if(numOfCandidates == 0)
        printf("there's no candidates in the company list!\n");
    else {
        printf("Candidates List:\n");
        int candNum = 1;
        //loop that pass on all the candidates to print their details.
        for (int i = 0; i < N; i++) {
            if (cand[i] != NULL) {
                printf("%d)%s %s\n learning details : %s\n", (candNum), cand[i]->name, cand[i]->familyName,
                       cand[i]->learning);
                candNum++;
                if (cand[i]->dev1 != NULL)
                    printf("Recommender from the company:\n%s %s\n", cand[i]->dev1->name, cand[i]->dev1->familyName);
                if (cand[i]->dev2 != NULL)
                    printf("Recommender from the company:\n%s %s\n", cand[i]->dev2->name, cand[i]->dev2->familyName);
                if (cand[i]->rec1 != NULL)
                    printf("recommender: %s %s\n email: %s\n", cand[i]->rec1->name, cand[i]->rec1->familyName,
                           cand[i]->rec1->email);
                if (cand[i]->rec2 != NULL)
                    printf("recommender: %s %s\n email: %s\n", cand[i]->rec2->name, cand[i]->rec2->familyName,
                           cand[i]->rec2->email);
            }
        }
    }
}
//Method that print the list of the employees in the company.
void printWorkers(Developer *emplo[]) {
    //if the number of the employees is 0 tell the user that it's empty.
    if (numOfEmployees == 0)
        printf("there's no employees in the company!\n");
    else {
        //loop to print all the workers.
        printf("Workers List:\n");
        int emploNum = 1;
        for (int i = 0; i < N; i++) {
            if (emplo[i] != NULL) {
                printf("%d) %s %s\n", emploNum, emplo[i]->name, emplo[i]->familyName);
                printf("---------------------\n");
                emploNum++;
            }
        }
    }
}
//Method that insert a new candidate to the list.
void insert(Developer *candidate[], Developer *emplo[]) {
    //if the number of the candidates is already 20 tell the user that it's full.
    if(numOfCandidates == N-1)
        printf("our candidates list is full! try at another time.");
    else {
        printf("Please enter the candidate details (first and last name and learning degree):\n");
        int candidatesIndex = 0;
        //find an empty place in the list to add the candidate.
        for (int i = 0; i < N; i++) {
            if (candidate[i] == NULL) {
                candidate[i] = (Developer *) malloc(sizeof(Developer));
                candidatesIndex = i;
                break;
            }
        }
        //receive the candidate details.
        for (int i = 0; i < 3; i++) {
            if (i == 0)
                scanf("%s", candidate[candidatesIndex]->name);
            else if (i == 1)
                scanf("%s", candidate[candidatesIndex]->familyName);
            else
                scanf("%s", candidate[candidatesIndex]->learning);
        }
        char haveRec[4];
        printf("does he have any recommenders from the company? yes/no\n");
        scanf("%s", haveRec);
        int numOfRec = 0;
        char Name[20], Family[20], Email[20];
        //loop that ask for the recommenders and receive details.
        while (strcmp(haveRec, "yes") == 0 && numOfRec != 2) {
            printf("Please enter the recommender details :\n");
            for (int i = 0; i < 2; i++) {
                if (i == 0) {
                    printf("First Name:\n");
                    scanf("%s", Name);
                } else if (i == 1) {
                    printf("Last Name:\n");
                    scanf("%s", Family);
                }
            }
            //check if the recommender is from the company.
            int found = 0;
            for (int i = 0; i < N; i++) {
                if (emplo[i] != NULL) {
                    if (strcmp(emplo[i]->name, Name) == 0 && strcmp(emplo[i]->familyName, Family) == 0) {
                        if (candidate[candidatesIndex]->dev1 == NULL) {
                            candidate[candidatesIndex]->dev1 = emplo[i];
                        } else if (candidate[candidatesIndex]->dev2 == NULL) {
                            candidate[candidatesIndex]->dev2 = emplo[i];
                        }
                        found = 1;
                        numOfRec++;
                        break;
                    }
                } else
                    continue;
            }
            if (found == 0) {
                printf("this name doesn't exist in the employees list of the company!\n");
            }
            if (numOfRec < 2) {
                printf("did he has any other recommenders from the company?\n");
                scanf("%s", haveRec);
            }


        }
        printf("does he have any recommenders from out of the company? yes/no\n");
        scanf("%s", haveRec);
        numOfRec = 0;
        //ask and receive details of recommenders from out of the company.
        while (strcmp(haveRec, "yes") == 0 && numOfRec != 2) {
            printf("Please enter the recommender details :\n");
            for (int i = 0; i < 3; i++) {
                if (i == 0) {
                    printf("First Name:\n");
                    scanf("%s", Name);
                } else if (i == 1) {
                    printf("Last Name:\n");
                    scanf("%s", Family);
                } else {
                    printf("E-mail:\n");
                    scanf("%s", Email);
                }
            }
            if (candidate[candidatesIndex]->rec1 == NULL) {
                candidate[candidatesIndex]->rec1 = (Recommender *) malloc(sizeof(Recommender));
                strcpy(candidate[candidatesIndex]->rec1->name, Name);
                strcpy(candidate[candidatesIndex]->rec1->familyName, Family);
                strcpy(candidate[candidatesIndex]->rec1->email, Email);
            } else if (candidate[candidatesIndex]->rec2 == NULL) {
                candidate[candidatesIndex]->rec2 = (Recommender *) malloc(sizeof(Recommender));
                strcpy(candidate[candidatesIndex]->rec2->name, Name);
                strcpy(candidate[candidatesIndex]->rec2->familyName, Family);
                strcpy(candidate[candidatesIndex]->rec2->email, Email);
            }
            numOfRec++;
            if (numOfRec < 2) {
                printf("did he has any other recommenders?\n");
                scanf("%s", haveRec);
            }
        }
        printf("New candidate added!\n");
        numOfCandidates++;
    }
}
//Method that accept a candidate to start working at the company.
void acceptCandidate(Developer *cand[], Developer *Emplo[]) {
    //if the number of the workers is already 20 tell the user that it's full.
    if (numOfEmployees == N - 1)
        printf("the company is full, we cant add any employee!");
    else {
        printf("Please enter the new employee details :\n");
        char Name[20], Family[20];
        for (int i = 0; i < 2; i++) {
            if (i == 0)
                scanf("%s", Name);
            else if (i == 1)
                scanf("%s", Family);
        }
        int added = 0;
        //check if the received name is existed in the candidates list and add him/her to the workers.
        for (int i = 0; i < N; i++) {
            if (cand[i] != NULL) {
                if (strcmp(cand[i]->name, Name) == 0 && strcmp(cand[i]->familyName, Family) == 0) {
                    Emplo[numOfEmployees] = (Developer *) malloc(sizeof(Developer));
                    strcpy(Emplo[numOfEmployees]->name, Name);
                    strcpy(Emplo[numOfEmployees]->familyName, Family);
                    cand[i]->dev1 = NULL;
                    cand[i]->dev2 = NULL;
                    cand[i]->rec2 = NULL;
                    cand[i]->rec1 = NULL;
                    cand[i] = NULL;
                    free(cand[i]);
                    added = 1;
                    break;
                } else
                    continue;
            }
        }
        if (added == 1) {
            printf("new employee was added!\n");
            numOfEmployees++;
            numOfCandidates--;
        } else printf("the name isn't exacts in the candidates list!\n");
    }
}