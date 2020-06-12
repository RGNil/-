#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

// ���� A: C����10.1
// ummm ����Ŀ��������û����˼
void big_swap(int* a, int* b) { // ע�⣬C++�Դ�swap����������Ҫ�����ˣ���
	if (*a < *b) {
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}
void ex_a() {
	int a, b;
	cin >> a >> b;
	big_swap(&a, &b);
	cout << a << " " << b;
}

// ���� B: C����10.2
void ex_b() {
	int a, b, c;
	cin >> a >> b >> c;
	big_swap(&a, &b); // ��֤a>b
	big_swap(&a, &c); // ��֤a>c
	big_swap(&b, &c); // ��֤b>c
	cout << a << " " << b << " " << c << endl;

}

// ���� C: C����10.10
void ex_c() {
	const char* a = "I love China!"; // VS2019,cpp�ļ��в��� char* a = "abc";һ��Ҫ��const
	int n = 100;
	while (!(n >= 0 && n < 13)) {
		cin >> n;
	}
	char* b = (char*)malloc(strlen(a) * sizeof(char));
	strcpy(b, a + n);
	cout << b << endl;

}
// �и�����, �� bool p = n >= 0 && n < 13; ���жϣ���ô��һֱ��ѭ����
// ummmɵ�ˣ�while����û�и��� p����
void ex_c_err() {
	const char* a = "I love China!"; // VS2019,cpp�ļ��в��� char* a = "abc";һ��Ҫ��const
	int n = 100;
	bool p = n >= 0 && n < 13;
	while (!p) {
		cin >> n;
		// p = n >= 0 && n < 13; // �������ͺ���
	}
	char* b = (char*)malloc(strlen(a) * sizeof(char));
	strcpy(b, a + n);
	cout << b << endl;

}

// ���� D: C����10.15
void str_swap_err(char* a, char* b) { 
	// ����ַ��� ָ���ַ�����Ĵ��󣬸�������һ������
	// ����� a b����ʱ�������洢�˴���ָ��ĵ�ַ
	// �ں����ｻ�� a b����Ȼ�����˵�ַ
	// ���ǳ��˺����󣬲�δ��������ָ��ĵ�ַ
	// ��ϸԭ������㷨�ʼǡ�p68
	if (strcmp(a, b) > 0) {
		char* tmp = a;
		a = b;
		b = tmp;
	}
}

void str_swap_err0(char*& a, char*& b) {
	// ����������ã������ʱ�����ֱ�Ӳ���ԭ����ָ�����
	// ��ϸԭ������㷨�ʼǡ�p69 - ָ�������
	// ���ǻ��ǲ���
	if (strcmp(a, b) > 0) {
		char* tmp = a;
		a = b;
		b = tmp;
	}
}

//void ex_d_err0() {
//	char* a[512], b[512], c[512];
//	scanf("%s\n%s\n%s", a, b, c);
//	str_swap_err0(a, b);
//	//�޷��� "char *[512]" ���͵�ֵ��ʼ�� "char *&" ���͵�����(�ǳ����޶�)
//}

// ���߲�����ָ���ַ�����Խ���strcpy����ָ��ָ����ַ�������
void str_swap(char* a, char* b) {
	if (strcmp(a, b) > 0) {
		char* tmp = (char*)malloc(strlen(a) * sizeof(char));
		strcpy(tmp, a);
		strcpy(a, b);
		strcpy(b, tmp);
	}
}

// ������string
void str_swap1(string& a, string& b) {
	if (a > b) {
		string tmp = a;
		a = b;
		b = tmp;
	}
}

void ex_d_err() { // �о����ܲ�����string
	string a, b, c;
	// ��ĿҪ�󣺱�֤ÿ���ַ����ĳ��Ȳ�����20
	while (1) {
		cin >> a >> b >> c;
		bool p = a.length() <= 20 && b.length() <= 20 && c.length() <= 20;
		if (p) {
			break;
		}
	}
	// ����һ
	str_swap((char*)a.c_str(), (char*)b.c_str()); // ��֤a<b
	str_swap((char*)a.c_str(), (char*)c.c_str()); // ��֤a<c
	str_swap((char*)b.c_str(), (char*)c.c_str()); // ��֤b<c
	// ������, ����û����ָ�룬��Ŀ˵Ҫ��ָ��
	//str_swap1(a, b);
	//str_swap1(a, c);
	//str_swap1(b, c);
	cout << a << endl << b << endl << c << endl;

}

void ex_d() { // ��Ȼ������string�˾���ȷ��
	char a[20], b[20], c[20];
	while (1) {
		scanf("%s\n%s\n%s", a, b, c);
		bool p = strlen(a) <= 20 && strlen(b) <= 20 && strlen(c) <= 20;
		if (p) {
			break;
		}
	}
	str_swap(a, b);
	str_swap(a, c);
	str_swap(b, c);
	printf("%s\n%s\n%s", a, b, c);
}

// ���� E: C����10.16
void input(int a[]) {
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
}

void deal(int a[]) {
	int max = 0, min = 0;
	for (int i = 1; i < 10; i++) {
		if (a[i] > a[max]) {
			max = i;
		}
		if (a[i] < a[min]) {
			min = i;
		}
	}
	int tmp = a[0];
	a[0] = a[min];
	a[min] = tmp;
	
	tmp = a[9];
	a[9] = a[max];
	a[max] = tmp;
}

void output(int a[]) {
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
}

void ex_e() {
	int a[10];
	input(a);
	deal(a);
	output(a);
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