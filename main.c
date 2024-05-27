#include <stdio.h>
#include "bigNumber.h"

int main()
{
	char str1[] = "12345312312341245123412312312312";
	char str2[] = "100000000000000000000000000000000";
	BigNumber* bn1 = CreateBN(str1);
	BigNumber* bn2 = CreateBN(str2);
	if (bn1 == NULL && bn2 == NULL)
		printf("bn == NULL!\n");

	PrintBN(SumBN(bn1,bn2));

	return 0;
}
