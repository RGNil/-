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

// ���� B: ϰ��7-7 �����ַ����е�Ԫ����ĸ
string vowel_extract(string str) {
	string vowels = "";
	for (int i = 0; i < str.length(); i++) {
		bool p = str[i] == 'a' || str[i] == 'e' 
			|| str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
			|| str[i] == 'A' || str[i] == 'E' || str[i] == 'I' 
			|| str[i] == 'O' || str[i] == 'U';
		if (p) {
			vowels += str[i];
		}
	}
	return vowels;
}

void ex_b() {
	string s;
	cin >> s;
	cout << vowel_extract(s);
}

int main()
{
	//ex_a();
	ex_b();

	return 0;
}