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

//���� E: ʵ����1+2+3+...�͵ĳ���Ҫ��õ�ʹʹ��������1000����С������
void ex_e() {
	int sum = 0, i =0;
	for (i = 1; sum < 1001; i++) {
		sum += i;
	}
	i -= 1; // ��Ϊ��sum<1001�ж����i++�����жϽ����ζ�Ҫִ��
	printf("%d\n", i);

}

// ���� F: ����5-6 �������
void ex_f() {
	for (int i = 1; i < 5; i++) {
		printf("%3d%3d%3d%3d%3d\n", i, 2 * i, 3 * i, 4 * i, 5 * i);
	}
}

// ���� G: ����5-7 ��Բ����pi�Ľ���ֵ
void ex_g_err() {
	double pi = 0;
	for (int i = 1; 1 / (double)(2 * i - 1) >= pow(10, -6); i++) {
		if (i % 2 == 0) { // ����ᵼ��i���ֵ������һ��i++ ��ʱ��Ͳ�����ż���
			i = -i;
		}
		pi += 1 / (double)(2 * i - 1);
	}
	printf("%10.8f", 4 * pi);
}
void ex_g() {
	double pi = 0;
	for (int i = 1; 1 / (double)(2 * i - 1) >= pow(10, -6); i++) {
		if (i % 2 == 0) {
			pi -= 1 / (double)(2 * i - 1);
			continue;
		}
		pi += 1 / (double)(2 * i - 1);
	}
	printf("PI=%10.8f\n", 4 * pi);
}

int main()
{
	//ex_a();
	//ex_b();
	//ex_c();
	//ex_d();
	//ex_e();
	//ex_f();
	ex_g();

	return 0;
}