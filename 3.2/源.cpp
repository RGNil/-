#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<cstdlib>

//���� B: ��x

int findX(int n) {
	int* a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int x;
	scanf("%d", &x);
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}

void ex_b_err() { // ���ֻ�ܲ�һ������
	int n;
	scanf("%d", &n);
	printf("%d", findX(n));
}

void ex_b_() { 
	int n;
	while (scanf("%d", &n) != EOF) { // ��������ʱ��һ��Ҫ�������ѭ��
		printf("%d\n", findX(n)); // ���Ҫ�� \n ����ȷͨ��
	}
}

int main()
{
	ex_b();
	return 0;
}