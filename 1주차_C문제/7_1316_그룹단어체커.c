#include <stdio.h>
#include <string.h>

int check(char str[], int n);

int main(void) {
	int n, sum=0;
	scanf("%d", &n);
	char str[100];
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		sum += check(str, strlen(str));
	}
	printf("%d", sum);
	return 0;
}

int check(char str[], int n) {

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if ((str[i] == str[j]) && (j - i > 1) && (str[j-1]!=str[j])){
				return 0;
			}
		}	
	}
	return 1;
}