#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<iostream>	
#include<string>
using namespace std;

// ���� I: ���ַ��������Ĵ�
bool isPalindrome(string str) {
	for (int i = 0; i < str.length() / 2; i++) {
		if (str[i] != str[str.length() - 1 - i])
			return false;
	}
	return true;
}

void ex_i() {
	string str;
	cin >> str;
	if (isPalindrome(str))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main() {
	ex_i();
	return 0;
}