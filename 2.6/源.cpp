#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

// ���� A: ϰ��7-5 �ַ���������
void str_reverse(string &a) {// Ҫ���ã���Ȼ����ı䴫���string
	for (int i=0; i < a.length() / 2; i++) {
		char tmp = a[i];
		a[i] = a[a.length() - 1 - i];
		a[a.length() - 1 - i] = tmp;
	}
}
void ex_a() {
	string a;
	cin >> a;
	str_reverse(a);
	cout << a;
}


int main()
{
	ex_a();

	return 0;
}