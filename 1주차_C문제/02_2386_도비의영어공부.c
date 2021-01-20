#include <stdio.h>
#include <string.h>

int main(void) {

	char input[254]; //첫문자 + 공백 + 250 문자 + 개행문자 + null
	int cnt;
	while (1) {
		fgets(input, 254, stdin); //fgets 는 개행문자까지 받아들인다
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
