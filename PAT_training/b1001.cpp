#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>

inline int callatz(int n) {
	int step = 0;
	if (n == 1) {
		return step;
	}
	while (n != 1) {
		if (n % 2 == 0) {// ż��
			n /= 2;
		}
		else {
			n = (3 * n + 1) / 2;
		}
		step += 1;
	}
	return step;
}

inline void test() {
	int n;
	scanf("%d", &n);
	printf("%d", callatz(n));
}