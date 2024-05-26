#pragma once

typedef struct PEOPLE
{
	char name[100];
	char surname[100];
	char patronymic[100];
	int isFilled;
} PEOPLE;


void add(PEOPLE* dt_);

int del(PEOPLE* dt_, int size_,int id_);

void print(PEOPLE* dt_);

void printAll(PEOPLE* dt_, int size_);

int searchBySurname(const PEOPLE* dt_, int size_, const char* surname_);

void sortPeopleBySurname(PEOPLE* dt_, int size_);

void change(PEOPLE* dt_, int size_, int id_);