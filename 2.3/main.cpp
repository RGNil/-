#include<cstdio>
#include<cmath>
#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������

// ���� A: ����4-1 һԪ���η������ ����2.2-E�����в�ͬ��
void ex_a() {
	double a, b, c;
	a = b = c = 0;
	while (1) {
		if (a == 0) {
				scanf("%lf %lf %lf", &a, &b, &c);
			}
		else
		{
			break;
		}
	}
	if ((b * b - 4 * a * c) <= 0) {
		printf("%s\n", "No real roots!");
	}
	else {
		printf("r1=%7.2f\nr2=%7.2f", (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a), (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a));
	}
	
}

//���� B : ����4 - 2 �ȽϽ���ʵ��ֵ
void ex_b() {
	double a, b;
	scanf("%lf %lf", &a, &b);
	if (a > b) {
		printf("%.2f %.2f\n", b, a);
	}
	else {
		printf("%.2f %.2f\n", a, b);
	}
}

//���� C : ����4 - 3 �ȽϽ���3��ʵ��ֵ�����������
void small_swap(double& x, double& y) {
	if (x > y) {
		double tmp = x;
		x = y;
		y = tmp;
	}
}

void ex_c() {
	double a, b, c, tmp;
	scanf("%lf %lf %lf", &a, &b, &c);
	// ˼·��ʼ�ձ���tmp��¼�����н�С��
	// ʹ�� a < b, a < c
	small_swap(a, b);
	small_swap(a, c);
	// ʹ�� b < c
	small_swap(b, c);
	printf("%.2f %.2f %.2f\n", a, b, c);
}

// ���� D: ϰ��4-4 �������������ֵ
// �������ҵ�small_swap�ͺ���, �Ĳ�������
void small_swap_int(int& x, int& y) {
	if (x > y) {
		int tmp = x;
		x = y;
		y = tmp;
	}
}

void ex_d() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	small_swap_int(a, b);
	small_swap_int(a, c);
	small_swap_int(b, c);
	printf("%d\n", c);

}

//���� E: ϰ��4-10-1 �������
void ex_e()
{
	double i;
	scanf("%lf", &i);
	if (i <= 100000) {
		printf("%.2f\n", 0.1 * i);
	}
	else if (i <= 200000) {
		printf("%.2f\n", 0.075 * (i- 100000) + 0.1* 100000);
	}
	else if (i <= 400000) {
		printf("%.2f\n", 0.05*(i- 200000) + 0.075 * 200000 + 0.1 * 100000);
	}
	else if (i <= 600000) {
		printf("%.2f\n", 0.03*(i - 400000) - 0.05 * 400000 + 0.075 * 200000 + 0.1 * 100000);
	}
	else if (i <= 1000000) {
		printf("%.2f\n", 0.015*(i - 600000) - 0.03 * 600000 - 0.05 * 400000 + 0.075 * 200000 + 0.1 * 100000);
	}
	else {
		printf("%.2f\n", 0.01* (i - 1000000) - 0.015 * 1000000 - 0.03 * 600000 - 0.05 * 400000 + 0.075 * 200000 + 0.1 * 100000);
	}
}

int main()
{
	//ex_a();
	//ex_b();
	//ex_c();
	//ex_d();
	ex_e();

	return 0;
}