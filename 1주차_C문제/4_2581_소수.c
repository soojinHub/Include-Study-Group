#include <stdio.h>

int main(void) {
	int n1, n2;
	scanf("%d", &n1);
	scanf("%d", &n2);

	// �Ҽ��� 2 ���� �ڱ��ڽ�-1 ������ ���ڷ� ���������� �ʴ� �� 
	int idx = 0;
	int arr[10000];
	for (int i = n1; i <= n2; i++) {
		int cnt = 0;
		for (int j = 2; j < i; j++) {
			if (i % j != 0) {
				cnt++;
			}
		}
		if (cnt == i - 2) {
			arr[idx] = i;
			idx++;
			
		}
	}

	if (idx == 0) {
		printf("%d", -1);
	}
	else {
		int total = 0;
		for (int k = 0; k < idx; k++) {
			total += arr[k];
		}

		int min = arr[0];
		for (int k = 0; k < idx; k++) {
			if (min > arr[k])
				min = arr[k];
		}

		printf("%d\n%d", total, min);
	}
	return 0;
}