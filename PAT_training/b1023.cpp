#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<cstdlib>

inline void test() {
	int numTable[10] = { 0 };
	int count = 0; // ��¼�ܹ��м�����
	for (int i = 0; i < 10; i++) {
		scanf("%d", &numTable[i]);
		count += numTable[i];
	}
	int* output = (int*)malloc(count * sizeof(int));
	// ��ʵ������numTable������õģ���������ĸ��Ϊ0������ֻ��Ҫ�ѵ�һ����0������Ƶ���һλ�ͺ���
	// ʵ�ַ�ʽ���Ȱ�numTable�е�������output���� 001117889
	int index = 0; // �±�ָʾ������¼��ǰ��output�е��±�
	for (int num = 0; num < 10; num++) {
		for (int numAmount = 0; numAmount < numTable[num]; numAmount++) {// ����numAmount <= numTable[num]
			output[index++] = num;
			//output[index] = num;
			//index++;
		}
	}
	// ���ж����ַ��ǲ���0���ǵĻ����ҵ���һ����0����������ַ�����
	if (output[0] == 0) {
		for (int i = 1; i < count; i++) {
			if (output[i] != 0) {
				output[0] = output[i];
				output[i] = 0;
				break;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		printf("%d", output[i]);
	}
}