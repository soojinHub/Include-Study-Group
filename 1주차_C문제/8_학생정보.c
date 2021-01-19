#include <stdio.h>

struct student {
	char name[7];
	int lang, eng, math;
	float avg;
	char score[1];
};

float average(struct student* p);
char score(struct student* p, float avg);

int main(void) {
	int num;
	struct student st[50],*p = st;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%s %d %d %d", st[i].name, &st[i].lang, &st[i].eng, &st[i].math);
	}

	for (int i = 0; i < num; i++) {
		printf("%s", st[i].name);
		printf("бр%.1fбр%c\n", average(&st[i]), score(&st[i], average(&st[i])));
	}

	return 0;
}

float average(struct student*p) {
	float avg = (p->lang + p->eng + p->math) / 3.0;
	return avg;
}

char score(struct student* p, float avg) {
	char score;
	if (avg >= 90)
		score = 'A';
	else if (avg >= 80)
		score = 'B';
	else if (avg >= 70)
		score = 'C';
	else
		score = 'D';
	return score;
}