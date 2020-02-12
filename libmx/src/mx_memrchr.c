#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
	unsigned char *str = (unsigned char *) s;
	unsigned char del = (unsigned char) c;
	size_t i = 0;

	while (i < n) {
		if (str[n] == del) 
			return &str[n];
		n--;
	}
	return NULL;
}

