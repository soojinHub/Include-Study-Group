#include <stdio.h>
#include <conio.h>

char decrypt(char ch, int M);
char encrypt(char ch, int M);

int main(void) {
	char str[100];//max_length 가 100 이므로
	char restr[100];
	int idx = 0;
	int n1, n2;
	while (1) {
		char temp = _getche();
		if (temp == '*') 
			break;
		str[idx] = temp;
		idx++;
	}
	str[idx] = '\0';
	printf("%c", '\n');
	scanf("%d %d", &n1, &n2);
	for (int i = 0; i < idx; i++) {
		restr[i] = decrypt(str[i],n1);
		printf("%c", restr[i]);
	}

	printf("%c", '\n');
	for (int i = 0; i < idx; i++) {
		printf("%c", encrypt(restr[i], n2));
	}

}

char decrypt(char ch, int M) {
	if (((ch >= 'a') && (ch <= 'z'))|| ((ch >= 'A') && (ch <= 'Z')))
	{
		for (int i = 0; i < M; i++) {
			if (ch == 'a') 
				ch = 'z';
			else if (ch == 'A') 
				ch = 'Z';
			else 
				ch = ch - 1;
		}
	}
	if (ch == 'z')
		ch = 'a';
	if (ch == 'Z')
		ch = 'A';

	return ch;
}

char encrypt(char ch, int M) {
	if (((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')))
	{
		for (int i = 0; i < M; i++) {
			if (ch == 'z')
				ch = 'a';
			else if (ch == 'Z')
				ch = 'A';
			else
				ch = ch + 1;
		}
	}
	if (ch == 'a')
		ch = 'z';
	if (ch == 'A')
		ch = 'Z';

	return ch;
}