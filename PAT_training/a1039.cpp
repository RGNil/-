#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>


inline int getID(char name[]) {
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}

inline void test() {
	// "const char *" ���͵�ֵ�������ڳ�ʼ�� "char *" ���͵�ʵ������ֽ������
	// https://www.cnblogs.com/xiximayou/p/12121287.html
	//char* name = "ZOE1";
	char name[] = "ZOE1";
	printf("%d\n", getID(name));

}