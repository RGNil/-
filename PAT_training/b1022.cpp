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

inline string baseConverter(int x, int base) {
	string result = "";
	while (x) {
		char tmp[2];
		sprintf(tmp, "%d", x % base);
		result = tmp + result;
		x /= base;
	}
	return result;
}

inline void test() {
	cout << baseConverter(123+456, 8);
}

