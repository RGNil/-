#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

inline string strReverse(string str) {
	string reStr = "";
	int subStrStart = 0; // ��¼ÿ�����ʵ�����ĸ�±�
	//string���length()����size()�������ص���unsigned integer(�޷�����)���͡�
	//������forѭ��ʱ�����������������Ϊ�ж�����ʱ����s.length()����0ʱ��s.length()-1 ������ -1
	// https://blog.csdn.net/lonyw/article/details/75268172
	//for (int i = 0; i < str.length(); i++) {// ���ﱨ���з���/�޷��Ų�ƥ�䣬ԭ�����
	for (int i = 0; i < (int)str.length(); i++) {
		if (str[i] == ' ') {
			//reStr = str.substr(subStrStart, i - 1) + reStr; // �����ᵼ��ÿ������û�пո�
			reStr = str.substr(subStrStart, i) + reStr; // iλ���Ǹ��ո񣬵���Ҫ�ǵ�ȥ�����һ���ո�
			subStrStart = i + 1;
		}
	}// erase ��Ա��������ɾ�� string �����е��Ӵ�, ��ֻ��һ��index��ɾ����index�������������������ַ�
	return reStr.erase(reStr.length() - 1); // ȥ�����һ���ո�
}

inline void test()
{
	string str = "abcde";
	cout << str.substr(2, str.length() - 1);
}