#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

struct Student
{
	//int id; int�洢���� 13λ������
	string id;
	int location;
	int grade;
	int local_rank;//���Բ�������������������ͨ��������������õ�
};

inline void selectSort(Student stu[], int amount) {
	for (int i = 0; i < amount; i++) {
		int k = i;
		for (int j = i; j < amount; j++) {
			if (stu[j].grade > stu[k].grade) {
				k = j;
			}
			else if (stu[j].grade == stu[k].grade && stu[j].id < stu[k].id) {
				// ������ͬ����id�Ⱥ��������򣩣�˼��һ������ c++ string����ֱ�ӱȽϴ�С��
				// C++ ����ֱ�ӱȽ�
				k = j;
			}
		}
		// ˼��һ�����⣬�ṹ�����ֱ�Ӹ�ֵ��
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
			cin >> stu[amount].id;
			scanf("%d", &stu[amount].grade);
			stu[amount].location = i;
			amount++;
		}
	}
	selectSort(stu, amount);
	showStu(stu, amount);

	return;
}