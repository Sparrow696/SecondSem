#include "people.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main() {
    int n = 0;
    printf("Write size: ");
    scanf("%d", &n);

    ARRAYPEOPLE pl = createArray(n);

    int choice = 1;
    int cg = 0;
    char search[50];

    while (choice) {
        printf(
            "1 : Add\n"
            "2 : Delete\n"
            "3 : Print all\n"
            "4 : Sort\n"
            "5 : Search\n"
            "6 : Change\n"
            "7 : Exit\n"
            ">");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add(&pl);
            break;
        case 2:
            printf("Will deleted - ");
            int id = 0;
            scanf("%d", &id);
            del(&pl, id - 1);
            break;
        case 3:
            printAll(&pl);
            break;
        case 4:
            sortPeopleBySurname(&pl);
            break;
        case 5:
            printf("Write surname: ");
            scanf("%s", search);
            searchBySurname(&pl, search);
            break;
        case 6:
            printf("Write id: ");
            scanf("%d", &cg);
            change(&pl, cg - 1);
            break;
        case 7:
            choice = 0;
            break;
        default:
            break;
        }
    }

    freeArray(&pl);
    return 0;
}