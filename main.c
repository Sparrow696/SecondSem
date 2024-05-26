#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
	int n = 0;
	printf("Write size of database: ");
	scanf("%d", &n);
	
	PEOPLE* pl = (PEOPLE*)calloc(n, sizeof(PEOPLE));
	if (pl == NULL) {
		fprintf(stderr, "memory error\n");
		return 1;
	}
	for (int i = 0; i < n; i++) {
		pl[i].isFilled = 0;
	}
	int count = 0;
	int choise = 1;
	int cg = 0;
	char search[50];

	while (choise)
	{
		printf(
			"1 : Add\n"
			"2 : Delete\n"
			"3 : Print all\n"
			"4 : Sort\n"
			"5 : Search\n"
			"6 : Change\n"
			"7 : Exit\n"
			">");
		scanf("%d", &choise);
		switch (choise)
		{
		case 1:
			if (count < n)
			{
				add(&pl[count]);
				count++;
			}
			break;
		case 2:
			printf("Will be deleted - ");
			int id = 0;
			scanf("%d", &id);
			n = del(pl, n, id - 1);
			break;
		case 3:
			printAll(pl, n);
			break;
		case 4:
			sortPeopleBySurname(pl, n);
			break;
		case 5:
			printf("Write surname: ");
			scanf("%s", &search);
			searchBySurname(pl, n, search);
			break;
		case 6:
			printf("Write id: ");
			scanf("%d", &cg);
			change(pl, n, cg - 1);
			break;
		case 7:
			choise = 0;
			break;
		default:
			break;
		}
	}

}