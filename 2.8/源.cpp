#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;

// ���� A: C����11.1
// C++��string��char *��char[]��ת��
// https://www.cnblogs.com/wuruofeng/p/10412559.html
struct person {
	char name[20];
	int count;
}leader[3] = { "Li",0,"Zhang",0,"Fun",0 };

void ex_a0() { // ��������û���⣬����codeup����һֱ��ʾ�����У����治��string����char* ; ���£���������Ϊnû��ʼ��
	int n;
	scanf("%d", &n); // �������Ӧ�ÿ��ԣ�֮ǰδ�����
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == string(leader[0].name) ){
			leader[0].count += 1;
		}
		else if (tmp == string(leader[1].name) ){
			leader[1].count += 1;
		}
		else if (tmp == string(leader[2].name)){
			leader[2].count += 1;
		}
		tmp.clear(); // ����ַ�������
	}
	for (int i = 0; i < 3; i++) {
		printf("%s:%d\n", leader[i].name, leader[i].count);
	}
}

void ex_a() { // ��Ȼ������string�����ж�Ҫ��ܶ�
	int n;
	char tmp[20];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp);
		if (strcmp(tmp,leader[0].name) == 0) {
			leader[0].count += 1;
		}
		else if (strcmp(tmp, leader[1].name) == 0) {
			leader[1].count += 1;
		}
		else if (strcmp(tmp, leader[2].name) == 0) {
			leader[2].count += 1;
		}
		strcpy(tmp, "");// ����ַ�������
		//tmp.clear(); // ����ַ�������
	}
	for (int i = 0; i < 3; i++) {
		printf("%s:%d\n", leader[i].name, leader[i].count);
	}
}

// ���� B: C����11.2
struct student {
	int num;
	char name[20];
	char sex;
	int age;
};

void ex_b() {
	int n=100;
	while (n > 20)
	{
		scanf("%d", &n);
	}
	student* s = (student*)malloc(n * sizeof(student));
	for (int i = 0; i < n; i++) {
		scanf("%d", &(s+i)->num);
		while (1) {//��֤ÿһ���������������ո��ҳ��Ȳ�����15
			scanf("%s", (s + i)->name);
			if (strlen((s + i)->name) > 15)
				continue;
			for (int i = 0; i < strlen((s + i)->name); i++) {
				if ((s + i)->name[i] == ' ')
					continue;
			}
			break;
		}
		while (true){// ��֤�Ա���M��F�����ַ�����ʾ
			scanf("%c", &(s + i)->sex);
			bool p = (s + i)->sex == 'M' || (s + i)->sex == 'F';
			if (!p)
				continue;
			break;
		}
		scanf("%d", &(s + i)->age);
	}
	for (int i = 0; i < n; i++) {
		printf("%d %s %c %d\n", (s + i)->num, (s + i)->name, (s + i)->sex, (s + i)->age);
	}
}

// ���� C: C����11.4
// C/C++�е�������union���� 
// https://blog.csdn.net/mooneve/article/details/92703036
// �Ҳο��ˡ�C���Գ�������ִ������ڶ��桷��union��֪ʶ
// ����֮��union��struct��Ψһ������
// struct�ĳ�Ա���Լ��������ڴ�ռ䣬��union�ĳ�Ա��������Ա���ڴ�ռ䣨union������һ��Ա��ֵ����Ӱ���ĳ�Ա��
struct member{
	int num;
	char name[10];
	char sex;
	char job;
	union {
		int classID;
		char position[10];
	}category;
};

void ex_c() {
	int n=110;
	while (n > 100) {//��֤n������100
		scanf("%d", &n);
	}
	member* m = (member*)malloc(n * sizeof(member));
	for (int i = 0; i < n; i++) {
		scanf("%d", &(m + i)->num);
		while (1) {//��֤ÿһ���������������ո��ҳ��Ȳ�����9
			scanf("%s", (m + i)->name);
			if (strlen((m + i)->name) > 9)
				continue;
			for (int i = 0; i < strlen((m + i)->name); i++) {
				if ((m + i)->name[i] == ' ')
					continue;
			}
			break;
		}
		while (true) {// ��֤�Ա���m��f�����ַ�����ʾ
			scanf("%c", &(m + i)->sex);
			bool p = (m + i)->sex == 'm' || (m + i)->sex == 'f';
			if (!p)
				continue;
			break;
		}
		while (true) {// ��֤job��s��t�����ַ�����ʾ
			scanf("%c", &(m + i)->job);
			bool p = (m + i)->job == 's' || (m + i)->job == 't';
			if (!p)
				continue;
			break;
		}
		if ((m + i)->job == 's') {
			scanf("%d", &(m + i)->category.classID);
		}
		else {
			while (1) {//��ְ֤�񳤶Ȳ�����9���޿ո��ַ���
				scanf("%s", (m + i)->category.position);
				if (strlen((m + i)->category.position) > 9)
					continue;
				for (int i = 0; i < strlen((m + i)->category.position); i++) {
					if ((m + i)->category.position[i] == ' ')
						continue;
				}
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d %s %c %c ", (m + i)->num, (m + i)->name, (m+ i)->sex, (m + i)->job);
		if ((m + i)->job == 's') {
			printf("%d\n", (m + i)->category.classID);
		}
		else {
			printf("%s\n", (m + i)->category.position);
		}
	}

}

// ���� D: C����11.7
struct Student_D {
	int id;
	char name[20];
	int grades[3];
};

void input(Student_D s[]) {
	for (int i = 0; i < 5; i++) {
		scanf("%d", &(s+i)->id);
		while (1) {// ���֣����Ȳ�����19���޿ո��ַ�����
			scanf("%s", (s + i)->name);
			if (strlen((s + i)->name) > 19)
				continue;
			for (int i = 0; i < strlen((s + i)->name); i++) {
				if ((s + i)->name[i] == ' ')
					continue;
			}
			break;
		}
		for (int j = 0; j < 3; j++) { //3�ſγ̵ĳɼ���0��100֮���������
			while (scanf("%d", &(s + i)->grades[j]), (s + i)->grades[j] <0 || (s + i)->grades[j] > 100) {
				// do nothing
			}
		}
		
	}
}

void print(Student_D s[]) {
	for (int i = 0; i < 5; i++) {
		printf("%d %s %d %d %d\n", (s + i)->id, (s + i)->name,
			(s + i)->grades[0], (s + i)->grades[1], (s + i)->grades[2]);
	}
}

void ex_d() {
	Student_D s[5];
	input(s);
	print(s);

}

// ���� E: C����11.8
struct Student_E {
	int id;
	char name[20];
	int grades[3];
	double avg_grade;
};

void input_e(Student_E s[], int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d", &(s + i)->id);
		while (1) {// ���֣����Ȳ�����19���޿ո��ַ�����
			scanf("%s", (s + i)->name);
			if (strlen((s + i)->name) > 19)
				continue;
			for (int i = 0; i < strlen((s + i)->name); i++) {
				if ((s + i)->name[i] == ' ')
					continue;
			}
			break;
		}
		(s+i)->avg_grade = 0;
		for (int j = 0; j < 3; j++) { //3�ſγ̵ĳɼ���0��100֮���������
			while (scanf("%d", &(s + i)->grades[j]), (s + i)->grades[j] < 0 || (s + i)->grades[j] > 100) {
				// do nothing
			}
			(s + i)->avg_grade += (s + i)->grades[j];
		}
		(s + i)->avg_grade /= 3;
	}
}



void ex_e() {
	Student_E s[3];
	int n = 10;
	input_e(s, n);
	int max = 0;
	double grade_avg[3] = { 0,0,0 };
	for (int i = 0; i < n; i++) {
		if (s[max].avg_grade < s[i].avg_grade)
			max = i;
		grade_avg[0] += (double)s[i].grades[0];
		grade_avg[1] += (double)s[i].grades[1];
		grade_avg[2] += (double)s[i].grades[2];
	}
	for (int i = 0; i < 3; i++) {
		printf("%.2f ", grade_avg[i] /= n);
	}
	printf("\n%d %s %d %d %d\n", (s + max)->id, (s + max)->name,
		(s + max)->grades[0], (s + max)->grades[1], (s + max)->grades[2]);

}

int main()
{
	//ex_a();
	//ex_b();
	//ex_c();
	//ex_d();
	ex_e();

	return 0;
}