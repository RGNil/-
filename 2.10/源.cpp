#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;

// ��С���ǹ淶OJ�����������ϰ
// �ںв��ԣ�������ԡ�������
// codeup��ȡ�����ԣ�PAT��ȡ�������

// ���� A: A+B ���������ϰI
void ex_a() {
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		printf("%d\n", a + b);
	}
}

// ���� B: A+B ���������ϰII
void ex_b() {
	int N,a,b;
	scanf("%d", &N);
	while (N--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
}

// ���� C: A+B ���������ϰIII
void ex_c() {
	int a, b;
	while (1) {
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			break;
		printf("%d\n", a + b);
	}
}

// ���� D: A+B ���������ϰIV
void ex_d() {
	int N;
	while (scanf("%d", &N), N != 0) {
		int* a = (int*)malloc(N * sizeof(int));
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			tmp += a[i];
		}
		printf("%d\n", tmp);
	}
}

// ���� E: A+B ���������ϰV
void ex_e() { // �������0
	int N;
	scanf("%d", &N);
	while (N--){
		int M;
		scanf("%d", &M);
		int* a = (int*)malloc(M * sizeof(int));
		int tmp = 0;
		for (int i = 0; i < M; i++) {
			scanf("%d", &a[i]);
			tmp += a[i];
		}
		printf("%d\n", tmp);
	}
}

// ���� F: A+B ���������ϰVI
void ex_f() {
	int N;
	while (scanf("%d", &N) != EOF) {
		int* a = (int*)malloc(N * sizeof(int));
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			tmp += a[i];
		}
		printf("%d\n", tmp);
	}
}


int main() {

	ex_e();

	return 0;
}