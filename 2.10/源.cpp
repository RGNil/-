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

int main() {

	return 0;
}