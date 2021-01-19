#include <stdio.h>
#define LENGTH 4

void print(char str[]) {
	for(int j = LENGTH - 2; j >= 0; j--) {
		printf("%c", str[j]);
	}
}

int main(void) {
	char n1[LENGTH], n2[LENGTH];
	scanf("%s %s", n1, n2);

	for (int i = LENGTH - 1; i >= 0; i--) {
		if (n1[i] > n2[i]) {
			print(n1);
			break;
		}
		else if (n1[i] < n2[i]) {
			print(n2);
			break;
		}
		else
			continue;
	}
	return 0;
}