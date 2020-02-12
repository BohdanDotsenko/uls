#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
	if (s1 == NULL) 
		return (char *)s2;
	else if (s2 == NULL) 
		return (char *)s1;
	else if (s1 == NULL && s2 == NULL)
		return NULL;

	int lens1 = mx_strlen(s1);
	int lens2 = mx_strlen(s2);
	int j = 0;

	char *str = (char *) malloc((lens1 + lens2 + 1) * sizeof(char));

	for (int i = 0; i < lens1; ) 
		str[j++] = s1[i++]; 
	
	for (int i = 0; i < lens2;) 
		str[j++] = s2[i++];
	str[j] = '\0';
	return str;
}

