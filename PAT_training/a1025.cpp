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
				k = j;
			}
		}
		// ˼��һ�����⣬�ṹ�����ֱ�Ӹ�ֵ��
		Student tmp = stu[i];
		stu[i] = stu[k];
		stu[k] = tmp;
	}
}

inline void test() {
	return;
}