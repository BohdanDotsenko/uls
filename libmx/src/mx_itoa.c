#include "libmx.h"

char * mx_itoa(int number) {
	if (number == 0) 
		return 0;
	long int x = number;
	int i = 0;
	int negative = 0;
	int size = mx_intlen(x);	
	char *str = (char *) malloc((size) * sizeof(char));

	if (x < 0) {
		negative = 1;
		x = -x;
	}
	while (x) {
		int sum = x % 10;
		str[i++] = sum + 48;
		x = x / 10;
	}
	if (negative)
		str[i++] = '-';

	str[i] = '\0';
	mx_str_reverse(str);
	return str;
}


