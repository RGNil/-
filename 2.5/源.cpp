#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;

void ss_inOut_test() {
	int n;
	char str[100] = "123";
	sscanf(str, "%d", &n);
	printf("%d\n", n);
	n = 99;
	sprintf(str, "%d", n);
	printf("%s\n", str);
}

void bubble_sort(int a[], int len, int reverse=0) {
	for (int i = 1; i <= len - 1; i++) {
		for (int j = 0; j < len - i; j++) {
			if (reverse) {
				if (a[j] < a[j + 1]) {
					int tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
				}
			}
			else {
				if (a[j] > a[j + 1]) {
					int tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
				}
			}
		}
	}
}

// ���� A: ϰ��6-4 �������
void ex_a() {
	int a[10];
	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &a[9]);
	bubble_sort(a, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
}


// ���� B: ϰ��6-5 ����Ԫ������
void reverse_array(int a[], int len) {
	// ˼��ֱ�ӽ���������β�������м�ĺ��Լ�����Ҳ���ǲ��������պý���������[len/2] ȡ��
	for (int i = 0; i < len / 2; i++) {
		int tmp = a[i];
		a[i] = a[len - 1 - i];
		a[len - 1 - i] = tmp;
	}
}

void ex_b() {
	int a[10];
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	reverse_array(a, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}

}

// ���� C: ϰ��6-6 �������
// �������� ���������
// ��Ϊ������ǵ�ÿһ������������չ��
int factoria(int n) {
	int f = 1;
	for (int i = 1; i <= n; i++) { // n=0ʱ�򣬲�ִ��for��ֱ��return f=1
		f *= i;
	}
	return f;
}
int combination(int m, int n) {
	return factoria(n) / (factoria(m) * factoria(n - m));
}

void ex_c() {
	int n;
	scanf("%d", &n);
	for (int k = 0; k < n; k++) {
		for (int i = 0; i <= k; i++) {
			printf("%d ", combination(i, k));
		}
		printf("\n");
	}
}

// ���� D: ϰ��6-12 ����
// �����Ƿǳ��򵥵� �������滻�������ʵ��
// ע��������� �� �û����� ����
// ��������һ���ַ����Ͻ���ӳ���滻�����û��������Ļ����Ͻ��л�λ
// ����һ���Ƚ�ֱ�ӵ�˼·�� ���ַ���ֱ�Ӷ�������飬ͨ�������±��������д�������
// ���ǣ�����ֱ������asccii���

char decode(char encode_chr) {
	bool p = encode_chr >= 'A' && encode_chr <= 'Z';
	bool q = encode_chr >= 'a' && encode_chr <= 'z';
	if (!(p || q)) { // ������ĸ�ķ��ر���
		return encode_chr;
	}
	if (encode_chr < 'a')
		return 'Z' - (encode_chr - 'A');
	return 'z' - (encode_chr - 'a');
}

void ex_d() {
	string cipher;
	cin >> cipher;
	for (int i = 0; i < cipher.length(); i++) {
		cipher[i] = decode(cipher[i]);
	}
	cout << cipher;
}

//���� E: ϰ��6-13 �ַ����Ƚ�
int RG_strcmp(char str1[], char str2[]) {
	char* p1 = str1;
	char* p2 = str2;
	int cmp = 0;
	while (*p1 != '\0' && *p2 != '\0'){
		cmp = *p1 - *p2;
		if (cmp == 0) {
			p1 += 1;
			p2 += 1;
		}
		else {
			return cmp;
		}
	}
}
// ���� c++ stringתchar
// https://www.cnblogs.com/mdumpling/p/8179167.html
// https://www.cnblogs.com/wuruofeng/p/10412559.html
void ex_e() { // Ŷ����������������Ŀ�涨������gets()�����ַ�
	string a, b;
	cin >> a;
	cin >> b;
	// const char* c_a = a.c_str();
	//char* pa = (char*)malloc(a.length() * sizeof(char));
	//char* pb = (char*)malloc(b.length() * sizeof(char));
	//pa = (char*)a.c_str();
	//pb = (char*)b.c_str();
	//printf("%d", RG_strcmp(pa, pb));
	printf("%d", RG_strcmp((char*)a.c_str(), (char*)b.c_str()));
}
// ���ߴֱ��㣬ֱ�ӿ�������������
void ex_e_vio() {
	char a[512], b[512];
	gets_s(a, 512);
	gets_s(b, 512);
	printf("%d", RG_strcmp(a, b));
}

// ���� F: ����6-1 �����������Ԫ��
// ���⡣�������� c��Ŀ

// ���� G: ����6-2 �������Fibonacci��������
int fibo(int n) { 
	if (n < 3) {
		return 1;
	}
	else {
		int a = 1, f = 2;
		for (int i = 0; i < n - 3; i++) {
			int tmp;
			tmp = a;
			a = f;
			f += tmp;
		}
		return f;
	}
}

void ex_g() {
	for (int i = 1; i < 21; i++) {
		printf("%d\n", fibo(i));
	}
}

// ���� H: ����6-3 ð������
// A��ʵ�ֹ���ֱ���þ�������
void ex_h() {
	int a[10];
	for (int i=0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	bubble_sort(a, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
}

// ���� I: ����6-4 ����ת��
// void f(int a[][]) // �Ƿ�����ά����ڶ�ά����ָ��
// void f(int** a)  // �������
// �Ҿ��ÿ�����һά����ģ���ά���飬�����Ͳ�����Ƕ��for�����Ӷ�Ҳ����
// �����������д����ֱ�ӵ�˼·
void transposition_err(int** a, int m, int n) { // �����⣬a�ĵ�ַ���ᱻ�ĵ�
	int** tmp = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		tmp[i] = (int*)malloc(m * sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = a[j][i];
		}
	}
	a = tmp; // ����ʹ��aָ��tmp�ˣ����Ե�ʱ��Ҳ�Ե�
	// ����һ�����������ˣ�a�ֲ���ָ��tmp�ˣ�����Ϊɶ
	// �Ҳ²⣺tmp����������ڴ˺����ڣ����˸ú����ڴ�ͱ�������
	// ����a�ں������غ��ָ���ģ�����Ĳ������ֱ��ԭ���ĵ�ַ��
	// https://blog.csdn.net/u010954806/article/details/23127371
}
void ex_i_err() {
	//int a[2][3]; //  "int (*)[3]" ���͵�ʵ���� "int **" ���͵��ββ�����
	// transposition(int** a, int m, int n)
	// ���� ��ά����Ͷ�άָ�뻹�����������
	int m = 2, n = 3;
	int** a = (int**)malloc(m * sizeof(int*));
	// ����һ�����󣬶�άָ�룬a��a+1�ĵ�ַ����������
	// a[0][0]-[2]������a[1][0]-[2]����������a[0][2]����һ����ַ����a[1][0]
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	transposition_err(a, 2, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
// ---------------------------------------------------------
// ���䱿�ȴ��룬�һ�������Ķ���ָ����ֵĴ��󣬺�����Ӧ������
void to1(int* x) {
	int a = 1;
	int* tmp = &a;
	x = tmp;
}

void test() {
	int a = 10;
	int* p = &a;
	to1(p);
	printf("%d", *p);
}
// ---------------------------------------------------------


// һ���ܼ򵥵Ľ������, ֱ�Ӵ���һ��ָ�����ڽ��վͺ�
void transposition(int** a, int m, int n, int **a_t) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a_t[i][j] = a[j][i];
		}
	}
}

void ex_i() {
	//int a[2][3]; //  "int (*)[3]" ���͵�ʵ���� "int **" ���͵��ββ�����
	// transposition(int** a, int m, int n)
	// ���� ��ά����Ͷ�άָ�뻹�����������
	int m = 2, n = 3;
	int** a = (int**)malloc(m * sizeof(int*));
	// ����һ�����󣬶�άָ�룬a��a+1�ĵ�ַ����������
	// a[0][0]-[2]������a[1][0]-[2]����������a[0][2]����һ����ַ����a[1][0]
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int** a_t = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		a_t[i] = (int*)malloc(m * sizeof(int));
	}
	transposition(a, 2, 3, a_t);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", a_t[i][j]);
		}
		printf("\n");
	}
}

// ��΢�ÿ�Щ
int** transposition_1(int** a, int m, int n) {
	int** tmp = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		tmp[i] = (int*)malloc(m * sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = a[j][i];
		}
	}

	return tmp;
}
void ex_i_1() {
	//int a[2][3]; //  "int (*)[3]" ���͵�ʵ���� "int **" ���͵��ββ�����
	// transposition(int** a, int m, int n)
	// ���� ��ά����Ͷ�άָ�뻹�����������
	int m = 2, n = 3;
	int** a = (int**)malloc(m * sizeof(int*));
	// ����һ�����󣬶�άָ�룬a��a+1�ĵ�ַ����������
	// a[0][0]-[2]������a[1][0]-[2]����������a[0][2]����һ����ַ����a[1][0]
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	a = transposition_1(a, 2, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	//ss_inOut_test();
	//ex_a();
	//ex_b();
	//ex_c();
	//ex_d();
	//ex_e();
	//ex_g();
	//ex_h();
	//ex_i();
	ex_i_1();



	return 0;
}