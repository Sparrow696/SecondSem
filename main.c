#include <stdio.h>
#include "bigNumber.h"

int main()
{
	char str1[] = "-12345678911";
	char str2[] = "10000000000000000000000000000000";
	char str3[] = "-10000000000";
	BigNumber* bn1 = CreateBN(str1);
	BigNumber* bn2 = CreateBN(str2);
	BigNumber* bn3 = CreateBN(str3);
	if (bn1 == NULL && bn2 == NULL)
		printf("bn == NULL!\n");

	PrintBN(SumBN(bn1,bn2));
	PrintBN(SubBN(bn1, bn2));
	PrintBN(MultBN(bn1, bn3));

	return 0;
}
