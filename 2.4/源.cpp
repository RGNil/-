#include<cstdio>
#include<cmath>
#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������

// ���� A: ����5-1-1 ������Ȼ�����
void ex_a() {
	int sum = 0, i =0;
	while (i < 101) {
		sum += i;
		i++;
	}
	printf("%d\n", sum);
}

// ���� B: ����5-1-2 ������Ȼ�����- do-while
void ex_b() {
	int sum = 0, i = 0;
	do {
		sum += i;
		i++;
	} while (i < 101);
	printf("%d\n", sum);
}

// ���� C: ����5-1-3 ������Ȼ����� -for
void ex_c() {
	int sum = 0;
	for (int i = 1; i < 101; i++) {
		sum += i;
	}
	printf("%d\n", sum);
}

// ���� D: ����5-1-4 ������Ȼ����� - break
void ex_d() {
	int sum, i, n;
	sum = i = 0;
	scanf("%d", &n);
	while (1) {
		i++;
		if (i > n) {
			break;
		}
		sum += i;
	}
	printf("%d\n", sum);
}

int main()
{
	//ex_a();
	//ex_b();
	//ex_c();
	ex_d();

	return 0;
}