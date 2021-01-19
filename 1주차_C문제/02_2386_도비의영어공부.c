#include <stdio.h>
#include <string.h>

int main(void) {

	char input[255]; //첫문자 + 공백 +250문자 + 개행문자 + \0
	int cnt;
	while (1) {
		fgets(input, 255, stdin);
		cnt = 0;
		if (input[0] != '#') {
			for (int i = 2; i <= strlen(input); i++) {
				if ((input[0] == input[i])||(input[0]==input[i]+'a'-'A')){
					cnt++;
				}
			}
			printf("%c %d\n", input[0], cnt);
			input[0] = '\0';
		}
		else
			break;
	}
	return 0;
}
