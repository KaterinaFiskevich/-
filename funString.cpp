#include "funString.h"

int _strlen(const char *str) {
	int i = 0;
	if (str)
		while (str[i] != '\0') ++i;
	return i;
}
void _strcpy(char *str1, const char *str2, int N) {
	for (int i = 0; i < N; ++i)
		str1[i] = str2[i];
}

void _strcpy(char *str1, const char *str2, int L, int R) {
	int i, j;
	for (i = L, j = 0; i < R; ++i, ++j)
		str1[j] = str2[i];
}