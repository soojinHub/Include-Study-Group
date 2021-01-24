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

	int l = 0; int r = num - 1;
	int sum = arr[l] + arr[r];
	while (1) {
		if(arr[l]+arr[r]>0) r--;
		else l++;
		if(l>=r) break;
		if (abs(sum)> abs(arr[l]+arr[r])) sum = arr[l]+arr[r];
	}
	printf("%d", sum);
	return 0;
}