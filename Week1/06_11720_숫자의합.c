#include <stdio.h>

int main(void) {
	int num;
	int arr[100] = { 0, };
	int total = 0;

	scanf_s("%d", &num);
	
	for (int i = 0; i < num; i++) {
		scanf_s("%1d", &arr[i]); //�ѱ��ھ� �Է¹ޱ�
	}

	for (int i = 0; i < num; i++) {
		total += arr[i];
		}
	printf("%d",total);


	return 0;
}