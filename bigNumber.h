#pragma once
#include <stdbool.h>
typedef unsigned char digit;

bool IsIntString(char* str_);

// Тип большого числа (>10 знаков)
typedef struct BigNumber
{
	unsigned int size;	// Размер числа
	digit* digits;  	// Массив из цифр числа
	bool is_negative;	// Знак числа
}BigNumber;

/*
* @brief Создание большого числа
* @param number_ : Строка с большим числом
* @return Указатель на выделенную память с большим числом
*/
BigNumber* CreateBN(char* number_);

/*
* @brief Удаляет выбранное большое число
* @param bn_ : Указатель на большое число
*/
void DeleteBN(BigNumber** bn_);

/*
* @brief Печать большого числа
* @param bn_ : Указатель на большое число
*/
void PrintBN(BigNumber* bn_);

int CompareBN(BigNumber* bn1_, BigNumber* bn2_);

/*
* @brief Сумма двух больших чисел без учета знака
* @param bn1_, bn2_ : Большие числа
* @return Большое число из суммы без учета знака
*/
BigNumber* SumAbsoluteBN(BigNumber* bn1_, BigNumber* bn2_);

/*
* @brief Разность двух больших чисел без учета знака
* @param bn1_, bn2_ : Большие числа
* @return Большое число из разности без учета знака
*/
BigNumber* SubAbsoluteBN(BigNumber* bn1_, BigNumber* bn2_);

/*
* @brief Сумма двух больших чисел
* @param bn1_, bn2_ : Большие числа
* @return Большое число из суммы двух входных
*/
BigNumber* SumBN(BigNumber* bn1_, BigNumber* bn2_);

/*
* @brief Разность двух больших чисел
* @param bn1_, bn2_ : Большие числа
* @return Большое число из разности двух входных
*/
BigNumber* SubBN(BigNumber* bn1_, BigNumber* bn2_);

BigNumber* MultBN(BigNumber* bn1_, BigNumber* bn2_);