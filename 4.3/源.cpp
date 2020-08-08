#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<cstdlib>
#include<cmath>

// ���� D: �˻ʺ�
int count=0, p[9], hashTable[9] = { false }; // ����Ҫȡ��8�����Ҵ�1��ʼ�����Գ�����Ϊ9
void queen8(int index, int order) {
	if (index == 9) {
		count++; // count���������⣬�������ʱ��һֱ��1,�ҵ������ˣ���count�ظ������ԭ�򣬼�������Ŀ
		if (count == order) { // �������Ҫ����Ļʺ����
			//printf("the %d queen sequence:\n", count);
			for (int i = 1; i < 9; i++) {
				printf("%d", p[i]);
			}
			printf("\n");
		}
		return;
	}
	for (int x = 1; x <= 8; x++) {
		if (hashTable[x] == false) {// x�л�û�лʺ�
			bool notCollision = true; // true��ʾ��ǰ�ʺ���֮ǰ�ʺ󲻳�ײ
			for (int pre = 1; pre < index; pre++) {
				// ��ǰ�ʺ��к�Ϊindex���к�Ϊx������������ǰ�Ļʺ�
				// ��ǰ�ʺ��к�Ϊpre���к�Ϊp[x]
				if (abs(index - pre) == abs(x - p[pre])) {// ��ͻ
					notCollision = false;
					break; // ��ǰx���ֳ�ײ������ѭ����������һ��x
				}
			}
			if (notCollision) {// ����ײ����ǰx���Դ�������
				p[index] = x;
				hashTable[x] = true;
				queen8(index + 1, order); // �ݹ������һ��
				hashTable[x] = false;// ���еݹ���ϣ����ñ��й�ϣ��
			}
		}
	}
}

void ex_d() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			int order;
			scanf("%d", &order);
			queen8(1, order); // �����ǰ��ŵ� �ʺ�
			for (i = 0; i < 9; i++) { // ��ϣ����������
				hashTable[i] = false;
			}
			count = 0;
		}
	}
}

void test() {
	int order;
	scanf("%d", &order);
	queen8(1, order); // �����ǰ��ŵ� �ʺ�
}

int main()
{
	test();
	return 0;
}