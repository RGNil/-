#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

struct Student
{
	//int id; int�洢���� 13λ������
	//string id; // ֮ǰ����һЩ�������⣬�ĳ�char
	char id[15];
	int location;
	int grade;
	int local_rank;//���Բ�������������������ͨ��������������õ�(���ǲ��������ͻ�Ҫ����)
	int total_rank;//���Ի�������һ���������ɡ�����
};

inline void selectSort(Student stu[], int amount) {
	for (int i = 0; i < amount; i++) {
		int k = i;
		for (int j = i; j < amount; j++) {
			if (stu[j].grade > stu[k].grade) {
				k = j;
			}
			//else if (stu[j].grade == stu[k].grade && stu[j].id < stu[k].id) {
				// ������ͬ����id�Ⱥ��������򣩣�˼��һ������ c++ string����ֱ�ӱȽϴ�С��
				// C++ ����ֱ�ӱȽ�
			else if (stu[j].grade == stu[k].grade && strcmp(stu[j].id, stu[k].id) < 0) {
				k = j;
			}
		}
		// ˼��һ�����⣬�ṹ�����ֱ�Ӹ�ֵ�𣿿���
		Student tmp = stu[i];
		stu[i] = stu[k];
		stu[k] = tmp;
	}
}

inline void showStu(Student stu[], int amount) {
	for (int i = 0; i < amount; i++) {
		cout << stu[i].id << ' ' << stu[i].grade << ' ' << stu[i].location << ' ' << stu[i].local_rank << endl;
	}
}

inline void calcRank(Student stu[], int amount, bool localOrTotal) {
	if (localOrTotal) {
		stu[0].local_rank = 1;
		for (int i = 1; i < amount; i++) {
			// ������������
			if (stu[i].grade == stu[i - 1].grade) {// ��������һ��һ��������ȡ��һλ
				stu[i].local_rank = stu[i - 1].local_rank;
			}
			else {// ��һ�����������ǵ�ǰ���
				stu[i].local_rank = i;
			}
		}
	}
	else {
		stu[0].total_rank = 1;
		for (int i = 1; i < amount; i++) {
			// ����������
			if (stu[i].grade == stu[i - 1].grade) {// ��������һ��һ��������ȡ��һλ
				stu[i].total_rank = stu[i - 1].total_rank;
			}
			else {// ��һ�����������ǵ�ǰ���
				stu[i].total_rank = i;
			}
		}
	}
}

inline void test() {
	int n; // ��������
	scanf("%d", &n);
	Student stu[10 * 10 * 10 * 10];
	memset(stu, 0, sizeof(stu));// ������Ϊ0
	int amount = 0;// ��¼������
	for (int i = 1; i <= n; i++) {
		int k; // �����п�������
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			/*cin >> stu[amount].id;*/
			scanf("%s %d", stu[amount].id, &stu[amount].grade);
			stu[amount].location = i;
			amount++;
		}
		// ���������һ������������¼�룬�ڴ����϶����������������
		selectSort(stu + amount - k, k); // ������ ָ��ͷ�ļ��㣬ÿ�������ĵ�һ��������ַ
		calcRank(stu + amount - k, k, true);// ���㿼������

	}
	selectSort(stu, amount);// ��������
	calcRank(stu, amount, false);// ����������
	showStu(stu, amount);

	return;
}