#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<cstdlib>

//���� A: ˭�����Ǳ������
int bookTable[210] = { 0 }; // �鱾��Ź�ϣ��
void ex_a() {
	int n, m;
	scanf("%d %d", &n, &m);
	int* buddy = (int*)malloc(n * sizeof(int));//��¼ÿ����ϲ���ı���
	for (int i = 0; i < n; i++) {
		scanf("%d", buddy + i);
		bookTable[buddy[i]]++;
	}
	for (int i = 0; i < n; i++) {
		//if (bookTable[buddy[i]] == 0)//�������ԣ���������㷨��ֻҪ����ϲ��һ���飬������Ϊ1������ֻ��һ����ϲ��
		if (bookTable[buddy[i]] == 1)// ����������ж�Ӧ����ôд
			printf("BeiJu\n");
		else
			//printf("%d\n", bookTable[buddy[i]]);
			printf("%d\n", bookTable[buddy[i]] - 1);// ͬ������Ҫ���Լ���ȥ
	}
}


int main()
{
	ex_a();

	return 0;
}

