#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<cstdlib>

//���� A: ˭�����Ǳ������
//int bookTable[210] = { 0 }; // �鱾��Ź�ϣ��
//void ex_a_1() {
//	int n, m;
//	scanf("%d %d", &n, &m);
//	int* buddy = (int*)malloc(n * sizeof(int));//��¼ÿ����ϲ���ı���
//	for (int i = 0; i < n; i++) {
//		scanf("%d", buddy + i);
//		bookTable[buddy[i]]++;
//	}
//	for (int i = 0; i < n; i++) {
//		//if (bookTable[buddy[i]] == 0)//�������ԣ���������㷨��ֻҪ����ϲ��һ���飬������Ϊ1������ֻ��һ����ϲ��
//		if (bookTable[buddy[i]] == 1)// ����������ж�Ӧ����ôд
//			printf("BeiJu\n");
//		else
//			//printf("%d\n", bookTable[buddy[i]]);
//			printf("%d\n", bookTable[buddy[i]] - 1);// ͬ������Ҫ���Լ���ȥ
//	}
//}

void ex_a() { // ����codeup�Ƕ��������Խ������� ����ĳ�ѭ��
			  // Ŷ ��֪�������������ˣ��������ԣ��Ұ�bookTable����ȫ�����ˣ�����һ����Թ��ˣ��ڶ����ʱ��bookTable��ʼ����ȫ0��
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		int bookTable[210] = { 0 }; // �鱾��Ź�ϣ��
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
		//free(buddy);
	}
}


int main()
{
	ex_a();

	return 0;
}

