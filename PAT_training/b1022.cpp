#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

// ֱ��charǿ��ת����������������ֱ���ַ�����
// �� ��char 97��=> ��a��
//inline string baseConverter(int x, int base) { 
//	string result = "";
//	while (x) {
//		result = (char)(x % base) + result;
//		x /= base;
//	}
//	return result;
//}

/*
inline string baseConverter(int x, int base) {
	string result = "";
	while (x) {
		char tmp[5];
		sprintf(tmp, "%d", x % base);
		result = tmp + result;
		x /= base;
	}
	return result;
}

inline void test() {
	int a, b, d;
	scanf("%d %d %d", &a, &b, &d);
	cout << baseConverter(a+b, d);
}
*/
// ���ϴ����� PAT �в�����ȷ����һ����Ե�𰸴���

inline void test() {
	int a, b, d;
	scanf("%d %d %d", &a, &b, &d);
	a += b;
	int r[32] = { 0 };
	int len = 0;
	while (a) {
		r[len++] = a % d;
		a /= d;
	}
	for (int i = len - 1; i >= 0; i--) { // ����� len - 1����Ϊ��ʹwhile����ִ�У������һ�ֻ����len����һ��
		printf("%d", r[i]);
	}
}

// ummmm ���ǲ��ԡ����� �ұȽϻ����ǲ��� 16���Ƶ���ĸ����
// ���������ϸ��Ĵ��� .,. ummm ���ϵĴ���Ͷ��ˡ���������û�
void test_key() {
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d);
	int sum = a + b;
	int ans[31], num = 0;
	do {
		ans[num++] = sum % d;
		sum /= d;
	} while (sum != 0);
	for (int i = num - 1; i >= 0; i--) {
		printf("%d", ans[i]);
	}
}

