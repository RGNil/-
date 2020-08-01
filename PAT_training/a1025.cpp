#pragma warning(disable : 4996) // 弃用VS的安全措施，使scanf等原生C函数可用
#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

struct Student
{
	//int id; int存储不了 13位的数字
	string id;
	int location;
	int grade;
	int local_rank;//可以不设置总排名，总排名通过整体数组排序得到
};

inline void selectSort(Student stu[], int amount) {
	for (int i = 0; i < amount; i++) {
		int k = i;
		for (int j = i; j < amount; j++) {
			if (stu[j].grade > stu[k].grade) {
				k = j;
			}
			else if (stu[j].grade == stu[k].grade && stu[j].id < stu[k].id) {
				// 分数相同按照id先后排序（升序），思考一个问题 c++ string可以直接比较大小吗
				// C++ 可以直接比较
				k = j;
			}
		}
		// 思考一个问题，结构体可以直接赋值吗？
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
	int n; // 考场数量
	scanf("%d", &n);
	Student stu[10 * 10 * 10 * 10];
	memset(stu, 0, sizeof(stu));// 整体置为0
	int amount = 0;// 记录总人数
	for (int i = 1; i <= n; i++) {
		int k; // 考场中考生数量
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