#include <stdio.h>

struct _bank {
	int id;
	int arrival_time;
	int service_time;
	int waiting_time;
};

void waitingtime(struct _bank guest[], int N);
double avgtime(struct _bank guest[], int N);

main(void) {
	struct _bank bank[100] = { 0, };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d",&bank[i].id, &bank[i].arrival_time, &bank[i].service_time);
	}

	waitingtime(bank, n);
	printf("%.2lf", avgtime(bank, n));

	return 0;
}

void waitingtime(struct _bank guest[], int N) {
	int sum = 0;
	guest[0].waiting_time = 0;
	for (int i = 1; i < N; i++) {
		sum += guest[i - 1].service_time;
		guest[i].waiting_time = sum - guest[i].arrival_time;
	}
}

double avgtime(struct _bank guest[], int N) {
	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += guest[i].waiting_time;
	}
	return (sum / N);
}