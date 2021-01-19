#include <stdio.h>

int abs(int a) {
	return a > 0 ? a : -a;
}

int main(void) {
	int num;
	int arr[100000] = { 0, };

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	int left = 0; int right = num - 1;
	int min = abs(arr[left] + arr[right]);
	while (left < right) {
		int sign = 0;
		if ((min >= abs(arr[left] + arr[right - 1])) && (left != right - 1)) {
			min = abs(arr[left] + arr[right - 1]);
			right--;
			sign = 1;
		}
		if ((min >= abs(arr[left + 1] + arr[right])) && (left + 1 != right)) {
			min = abs(arr[left + 1] + arr[right]);
			left++;
			sign = 1;
		}
		if ((sign==0)&&(left + 1 != right-1)){
			min = abs(arr[left + 1] + arr[right - 1]);
			left++;
			right--;
			sign = -1;
		}
		int min = abs(arr[left] + arr[right]);
		if (sign == 0)
			break;
	}
	printf("%d", min);
	return 0;
}