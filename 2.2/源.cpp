#include<cstdio>
#include<cmath>
#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������

// ���� A: ����1-1-1 ��Ҫ�������Ϣ(1)
// http://codeup.cn/problem.php?cid=100000566&pid=0
void ex_A() {
	printf("%s", "This is my first c program!");
}

// ���� B: ����1-1-2 ��Ҫ�������Ϣ(2)
// http://codeup.cn/problem.php?cid=100000566&pid=1
void ex_B(){
	printf("%s", "********************\nVery Good!\n********************");
}

void ex_C() {
	int a = 123, b = 456;
	int sum = a + b;
	printf("sum=%d", sum);
}

//���� D : ����1 - 2 - 2 ����������֮��(2)
void ex_D() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", a + b);
}

//���� E : ����3 - 5 ��һԪ���η��̵ĸ�
void ex_E() {
	double a, b, c;
	a = b = c = 0;
	while (1) {
		if (a == 0 && (b * b - 4 * a * c) <= 0) {
			scanf("%lf %lf %lf", &a, &b, &c);
		}
		else {
			break;
		}
	}
	printf("r1=%7.2f\nr2=%7.2f", (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a), (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a));

}

//���� F : ����3 - 9 �ַ��������
void ex_F_1() {
	char a = getchar();
	char b = getchar();
	char c = getchar();
	getchar();
	putchar(a);
	putchar(b);
	putchar(c);

}
void ex_F_2() { // ���ò����bug����û�е��Թ�
	char a[3];
	for (int i = 0; i < 3; i++) {
		a[i] = getchar();
	}
	a[3] = '\0'; // ע�����ǿ�����Ͻ�����
	printf("%s", a);
}

int main()
{
	//ex_A();
	//ex_B();
	//ex_C();
	//ex_D();
	//ex_E();
	//ex_F_1();
	ex_F_2();

	return 0;
}