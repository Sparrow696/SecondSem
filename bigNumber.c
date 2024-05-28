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

int CompareBN(BigNumber* bn1_, BigNumber* bn2_) {
	if (bn1_->size > bn2_->size) return 1;
	if (bn1_->size < bn2_->size) return -1;
	for (int i = 0; i < bn1_->size; ++i) {
		if (bn1_->digits[i] > bn2_->digits[i]) return 1;
		if (bn1_->digits[i] < bn2_->digits[i]) return -1;
	}
	return 0;
}

BigNumber* SumAbsoluteBN(BigNumber* bn1_, BigNumber* bn2_) {
	int max_size = bn1_->size > bn2_->size ? bn1_->size : bn2_->size;

	BigNumber* result = (BigNumber*)malloc(sizeof(BigNumber));
	if (result == NULL) {
		return NULL;
	}

	result->size = max_size + 1;
	result->is_negative = false;
	result->digits = (digit*)calloc(result->size, sizeof(digit));
	if (result->digits == NULL) {
		free(result);
		return NULL;
	}

	int per = 0;
	int i = bn1_->size, j = bn2_->size, k = result->size;

	while (i > 0 || j > 0 || per > 0) {
		int sum = per;
		if (i > 0) {
			sum += bn1_->digits[--i];
		}
		if (j > 0) {
			sum += bn2_->digits[--j];
		}
		result->digits[--k] = sum % 10;
		per = sum / 10;
	}

	if (result->digits[0] == 0) {
		memmove(result->digits, result->digits + 1, max_size * sizeof(digit));
		result->size--;
	}

	return result;
}

BigNumber* SubAbsoluteBN(BigNumber* bn1_, BigNumber* bn2_) {
	BigNumber* result = (BigNumber*)malloc(sizeof(BigNumber));
	if (result == NULL) {
		return NULL;
	}

	result->size = bn1_->size;
	result->is_negative = false;
	result->digits = (digit*)calloc(result->size, sizeof(digit));
	if (result->digits == NULL) {
		free(result);
		return NULL;
	}

	int borrow = 0;
	int i = bn1_->size, j = bn2_->size, k = result->size;

	while (i > 0 || j > 0) {
		int diff = bn1_->digits[--i] - borrow;
		if (j > 0) {
			diff -= bn2_->digits[--j];
		}

		if (diff < 0) {
			diff += 10;
			borrow = 1;
		}
		else {
			borrow = 0;
		}

		result->digits[--k] = diff;
	}

	int leadZeros = 0;
	while (leadZeros < result->size && result->digits[leadZeros] == 0) {
		leadZeros++;
	}

	if (leadZeros == result->size) {
		leadZeros = result->size - 1;
	}

	result->size -= leadZeros;
	memmove(result->digits, result->digits + leadZeros, result->size * sizeof(digit));

	return result;
}

BigNumber* SumBN(BigNumber* bn1_, BigNumber* bn2_)
{
	if (bn1_ == NULL || bn2_ == NULL) {
		return NULL;
	}

	if (bn1_->is_negative == bn2_->is_negative) {
		BigNumber* result = SumAbsoluteBN(bn1_, bn2_);
		if (result != NULL) {
			result->is_negative = bn1_->is_negative;
		}
		return result;
	}
	else {
		int cmp = CompareBN(bn1_, bn2_);
		if (cmp == 0) {
			BigNumber* result = (BigNumber*)malloc(sizeof(BigNumber));
			result->size = 1;
			result->is_negative = false;
			result->digits = (digit*)calloc(1, sizeof(digit));
			result->digits[0] = 0;
			return result;
		}
		else if (cmp > 0) {
			BigNumber* result = SubAbsoluteBN(bn1_, bn2_);
			if (result != NULL) {
				result->is_negative = bn1_->is_negative;
			}
			return result;
		}
		else {
			BigNumber* result = SubAbsoluteBN(bn2_, bn1_);
			if (result != NULL) {
				result->is_negative = bn2_->is_negative;
			}
			return result;
		}
	}
}

BigNumber* SubBN(BigNumber* bn1_, BigNumber* bn2_) {
	if (bn1_ == NULL || bn2_ == NULL) {
		return NULL;
	}

	if (bn1_->is_negative != bn2_->is_negative) {
		BigNumber* result = SumAbsoluteBN(bn1_, bn2_);
		if (result != NULL) {
			result->is_negative = bn1_->is_negative;
		}
		return result;
	}
	else {
		int cmp = CompareBN(bn1_, bn2_);
		if (cmp == 0) {
			BigNumber* result = (BigNumber*)malloc(sizeof(BigNumber));
			result->size = 1;
			result->is_negative = false;
			result->digits = (digit*)calloc(1, sizeof(digit));
			result->digits[0] = 0;
			return result;
		}
		else if (cmp > 0) {
			BigNumber* result = SubAbsoluteBN(bn1_, bn2_);
			if (result != NULL) {
				result->is_negative = bn1_->is_negative;
			}
			return result;
		}
		else {
			BigNumber* result = SubAbsoluteBN(bn2_, bn1_);
			if (result != NULL) {
				result->is_negative = !bn1_->is_negative;
			}
			return result;
		}
	}
}

BigNumber* MultBN(BigNumber* bn1_, BigNumber* bn2_) {
	if (bn1_ == NULL || bn2_ == NULL) {
		return NULL;
	}

	BigNumber* result = (BigNumber*)malloc(sizeof(BigNumber));
	if (result == NULL) {
		return NULL;
	}

	result->size = bn1_->size + bn2_->size;
	result->is_negative = bn1_->is_negative != bn2_->is_negative;
	result->digits = (digit*)calloc(result->size, sizeof(digit));
	if (result->digits == NULL) {
		free(result);
		return NULL;
	}

	for (int i = 0; i < bn1_->size; ++i) {
		int carry = 0;
		for (int j = 0; j < bn2_->size; ++j) {
			int result_index = result->size - 1 - (i + j);
			int product = result->digits[result_index] + bn1_->digits[bn1_->size - 1 - i] * bn2_->digits[bn2_->size - 1 - j] + carry;
			result->digits[result_index] = product % 10;
			carry = product / 10;
		}
		result->digits[result->size - 1 - (i + bn2_->size)] += carry;
	}

	int leadZeros = 0;
	while (leadZeros < result->size - 1 && result->digits[leadZeros] == 0) {
		leadZeros++;
	}

	if (leadZeros > 0) {
		result->size -= leadZeros;
		memmove(result->digits, result->digits + leadZeros, result->size * sizeof(digit));
	}

	return result;
}



