#include "bigNumber.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool IsIntString(char* str_)
{
	if (str_[0] == '-')
		str_++;

	while (*str_)
	{
		if (*str_ < '0' || *str_ > '9')
			return false;

		str_++;
	}

	return true;
}

BigNumber* CreateBN(char* number_)
{
	if (number_ == NULL || strlen(number_) == 0 ||
		!IsIntString(number_))
		return NULL;

	BigNumber* bn = (BigNumber*)malloc(sizeof(BigNumber));
	if (bn == NULL)
		return NULL;

	size_t size = strlen(number_);
	if (*number_ == '-')
	{
		bn->size = size - 1;
		bn->is_negative = true;
		number_++;
	}
	else
	{
		bn->size = size;
		bn->is_negative = false;
	}

	bn->digits = (digit*)calloc(bn->size, sizeof(digit));
	if (bn->digits == NULL)
	{
		free(bn);
		return NULL;
	}

	for (size_t i = 0; i < bn->size; ++i)
		bn->digits[i] = number_[i] - '0';

	return bn;
}

void DeleteBN(BigNumber** bn_)
{
	free((*bn_)->digits);
	free(*bn_);

	*bn_ = NULL;
}

void PrintBN(BigNumber* bn_)
{
	if (bn_ == NULL)
	{
		printf("BigNumber is empty!\n");
		return;
	}

	if (bn_->is_negative)
		printf("-");

	for (size_t i = 0; i < bn_->size; ++i)
		printf("%u", bn_->digits[i]);

	printf("\n");
}

BigNumber* SumBN(BigNumber* bn1_, BigNumber* bn2_)
{
	if (bn1_ == NULL || bn2_ == NULL) {
		return NULL;
	}

	size_t max_size = bn1_->size > bn2_->size ? bn1_->size : bn2_->size;

	BigNumber* result = (BigNumber*)malloc(sizeof(BigNumber));
	if (result == NULL) {
		return NULL;
	}

	result->size = max_size + 1; // +1 для возможного переноса
	result->is_negative = false; 
	result->digits = (digit*)calloc(result->size, sizeof(digit));
	if (result->digits == NULL) {
		free(result);
		return NULL;
	}

	int carry = 0;
	size_t i = bn1_->size, j = bn2_->size, k = result->size;

	while (i > 0 || j > 0 || carry > 0) {
		int sum = carry;
		if (i > 0) {
			sum += bn1_->digits[--i];
		}
		if (j > 0) {
			sum += bn2_->digits[--j];
		}
		result->digits[--k] = sum % 10;
		carry = sum / 10;
	}

	if (result->digits[0] == 0) {
		memmove(result->digits, result->digits + 1, max_size * sizeof(digit));
		result->size--;
	}

	return result;
}