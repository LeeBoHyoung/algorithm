#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


typedef struct {
	char name[12];
	short id;
	char sex;
	double kor;
	double math;
	double eng;
}student;

int main() {
	student s;
	FILE* fp;
	int maleCnt = 0;
	double korSum = 0;
	double mathSum = 0;
	double engSum = 0;
	fp = fopen("C:\\db.dat", "rb");
	while(feof(fp) == 0) {
		fread(&s, sizeof(s), 1, fp);
		if (s.sex == 0) {
			maleCnt++;
			korSum += s.kor;
			mathSum += s.math;
			engSum += s.eng;
		}
	}
	printf("남학생 수 = %d\n", maleCnt);
	printf("국어 = %.2f\n", korSum / maleCnt);
	printf("수학 = %.2f\n", mathSum / maleCnt);
	printf("영어 = %.2f\n", engSum / maleCnt);
	

	return 0;
}