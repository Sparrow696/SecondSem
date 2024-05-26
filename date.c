#include "date.h"
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

void add(PEOPLE* dt_) {
	printf("Write name: ");
	scanf("%s", dt_->name);
	printf("Write surname: ");
	scanf("%s", dt_->surname);
	printf("Write patronymic: ");
	scanf("%s", dt_->patronymic);
	dt_->isFilled = 1;
}

int del(PEOPLE* dt_, int size_, int id_)
{
	if (id_ < 0 || id_ >= size_) {
		fprintf(stderr, "Wrong id\n");
		return size_;
	}

	for (int i = id_; i < size_ - 1; i++) {
		dt_[i] = dt_[i + 1];
	}

	dt_[size_ - 1].isFilled = 0;

	return size_ - 1;
}

void print(PEOPLE* dt_)
{
	printf("Name: %s\n", dt_->name);
	printf("Surname: %s\n", dt_->surname);
	printf("Patronymic: %s\n", dt_->patronymic);
}

void printAll(PEOPLE* dt_, int size_)
{
	for (int i = 0; i < size_; i++) {
		if (dt_[i].isFilled)
		{
			printf("Human %d:\n", i + 1);
			print(&dt_[i]);
			printf("\n");
		}
	}
}

int searchBySurname(const PEOPLE* dt_, int size_, const char* surname_)
{
	for (int i = 0; i < size_; i++) {
		if (strcmp(dt_[i].surname, surname_) == 0) {
			printf("Human %d:\n", i + 1);
			print(&dt_[i]);
		}
	}
	return 0;
}

void sortPeopleBySurname(PEOPLE* dt_, int size_) {
	for (int i = 0; i < size_ - 1; i++) {
		for (int j = 0; j < size_ - i - 1; j++) {
			if (strcmp(dt_[j].surname, dt_[j + 1].surname) > 0) {
				PEOPLE temp = dt_[j];
				dt_[j] = dt_[j + 1];
				dt_[j + 1] = temp;
			}
		}
	}
}

void change(PEOPLE* dt_, int size_, int id_) {
	if (id_ < 0 || id_ >= size_ || !dt_[id_].isFilled) {
		printf("Wrong index\n");
		return;
	}

	printf("Write new data for Human %d:\n", id_ + 1);
	add(&dt_[id_]);
}
