#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "people.h"
#pragma warning(disable : 4996)

struct PEOPLE {
	char name[100];
	char surname[100];
	char patronymic[100];
	int isFilled;
};

ARRAYPEOPLE createArray(int size_) {
	ARRAYPEOPLE peopleArray;
	peopleArray.array = (PEOPLE*)malloc(size_ * sizeof(PEOPLE));
	peopleArray.size = size_;
	if (peopleArray.array != NULL) {
		for (int i = 0; i < size_; i++) {
			peopleArray.array[i].isFilled = 0;
		}
	}
	return peopleArray;
}

void freeArray(ARRAYPEOPLE* dt_) {
	free(dt_->array);
	dt_->array = NULL;
	dt_->size = 0;
}

void add(ARRAYPEOPLE* dt_) {
	for (int i = 0; i < dt_->size; i++) {
		if (!dt_->array[i].isFilled) {
			printf("Write name: ");
			scanf("%s", dt_->array[i].name);
			printf("Write surnam: ");
			scanf("%s", dt_->array[i].surname);
			printf("Write patronymic: ");
			scanf("%s", dt_->array[i].patronymic);
			dt_->array[i].isFilled = 1;
			return;
		}
	}
}

void outputPerson(const PEOPLE* dt_) {
	printf("Name: %s\n", dt_->name);
	printf("Surname: %s\n", dt_->surname);
	printf("Patronymic: %s\n", dt_->patronymic);
}

void printAll(const ARRAYPEOPLE* dt_) {
	for (int i = 0; i < dt_->size; i++) {
		if (dt_->array[i].isFilled) {
			printf("Human %d:\n", i + 1);
			outputPerson(&dt_->array[i]);
			printf("\n");
		}
	}
}

void del(ARRAYPEOPLE* dt_, int id_) {
	if (id_ >= dt_->size) {
		fprintf(stderr, "Wrong id\n");
		return;
	}
	for (int i = id_; i < dt_->size - 1; i++) {
		dt_->array[i] = dt_->array[i + 1];
	}

	dt_->array[dt_->size - 1].isFilled = 0;
}

int searchBySurname(const ARRAYPEOPLE* dt_, const char* surname) {
	for (int i = 0; i < dt_->size; i++) {
		if (dt_->array[i].isFilled && strcmp(dt_->array[i].surname, surname) == 0) {
			printf("\nHuman with surname %s :\n id: %d\n", surname, i + 1);
			outputPerson(&dt_->array[i]);
		}
	}
	return 0;
}

void sortPeopleBySurname(ARRAYPEOPLE* dt_) {
	for (int i = 0; i < dt_->size - 1; i++) {
		for (int j = 0; j < dt_->size - i - 1; j++) {
			if (dt_->array[j].isFilled && dt_->array[j + 1].isFilled &&
				strcmp(dt_->array[j].surname, dt_->array[j + 1].surname) > 0) {

				PEOPLE temp = dt_->array[j];
				dt_->array[j] = dt_->array[j + 1];
				dt_->array[j + 1] = temp;
			}
		}
	}
}

void change(ARRAYPEOPLE* dt_, int id_) {
	if (id_ >= dt_->size || !dt_->array[id_].isFilled) {
		fprintf(stderr, "Wrong id\n");
		return;
	}

	printf("Write new data for human %d:\n", id_ + 1);
	printf("Write name: ");
	scanf("%s", dt_->array[id_].name);
	printf("Write surname: ");
	scanf("%s", dt_->array[id_].surname);
	printf("Write patronymic: ");
	scanf("%s", dt_->array[id_].patronymic);
}