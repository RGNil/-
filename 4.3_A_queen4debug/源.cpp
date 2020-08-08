#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<cstdlib>
#include<cmath>


// �������ļ�8�ʺ�count����һֱ�Ҳ������⣬���������ݹ���̫��
// ���������� 3�ʺ� ������count�ĸ�������
// ummm ͻȻ����3�ʺ� �޽�
//�ĳ�4�ʺ�
int count = 0, p[5], hashTable[5] = { false }; // ����Ҫȡ��4�����Ҵ�1��ʼ�����Գ�����Ϊ5

void queen3(int index, int order/*, int count*/) { 
	// ���Ե�ʱ�����ڷ����ˣ�������ɵ���ֶ�����һ��count��������queen3�������count�Ǿֲ�������ÿ��return֮�������Ϊ0
	// ����ֱ��ɾ�� queen3��count����ͺ��ˣ��ⲿ�Ѿ�������ȫ�ֱ�����
	if (index == 5) {
		count++; // count���������⣬�������ʱ��һֱ��1
		if (count == order) { // �������Ҫ����Ļʺ����
			//printf("the %d queen sequence:\n", count);
			for (int i = 1; i < 5; i++) {
				printf("%d", p[i]);
			}
			printf("\n");
		}
		return;
	}
	for (int x = 1; x <= 4; x++) {
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
				queen3(index + 1, order); // �ݹ������һ��
				hashTable[x] = false;// ���еݹ���ϣ����ñ��й�ϣ��
			}
		}
	}
}


int main()
{
	int order;
	scanf("%d", &order);
	queen3(1, order); // �����ǰ��ŵ� �ʺ�

	return 0;
}