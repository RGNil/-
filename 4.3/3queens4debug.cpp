#pragma once
#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<cstdlib>
#include<cmath>


// �������ļ�8�ʺ�count����һֱ�Ҳ������⣬���������ݹ���̫��
// ���������� 3�ʺ� ������count�ĸ�������
// ����ʱ��Ҫע�͵� Դ.cpp��������һ��
//int count = 0, p[4], hashTable[4] = { false }; // ����Ҫȡ��3�����Ҵ�1��ʼ�����Գ�����Ϊ4
void queen3(int index, int order, int count) {
	if (index == 4) {
		//count++; // count���������⣬�������ʱ��һֱ��1
		if (1) { // �������Ҫ����Ļʺ����
			printf("the %d queen sequence:\n", count);
			for (int i = 1; i < 4; i++) {
				printf("%d", p[i]);
			}
			printf("\n");
		}
		//count++;
		return;
	}
	for (int x = 1; x <= 3; x++) {
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
				queen3(index + 1, order, count); // �ݹ������һ��
				hashTable[x] = false;// ���еݹ���ϣ����ñ��й�ϣ��
			}
		}
	}
}


void queen4debug()
{
	int order;
	scanf("%d", &order);
	queen3(1, order, count); // �����ǰ��ŵ� �ʺ�

}