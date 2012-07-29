#include <stdio.h>

int main(void)
{
	unsigned width, precision;
	int number=256;
	double weight=242.5;

	printf("What field width?");
	scanf("%d", &width);
	printf("The number=[%*d]\n", width, number);
	printf("Now enter a width and a precision:\n");
	scanf("%d %d", &width, &precision);
	printf("Weight=[%*.*f]\n", width, precision, weight);
	return 0;
}
