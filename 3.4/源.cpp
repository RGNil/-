#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>

// ���� A: ���ڲ�ֵ

bool isLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100))
		return true;
	return false;
}

int daysOfMonth(int year, int month) {
	if (month == 0)
		return 0;
	else if (month == 2) {
		if (isLeapYear(year))
			return 29;
		else
			return 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	return 31;

}

int interval_days(int date1, int date2) {
	if (date1 > date2) {
		int tmp = date1;
		date1 = date2;
		date2 = tmp;
	}
	int days = date2 % 100; // ��¼����
	// ����date2 ��ȥ�˼���
	int month = (date2 / 100) % 100;
	while (--month) { // ֱ��mod�������·ݲ�����
		days += daysOfMonth(date2 / 10000, month);
	}
	printf("%d", days);
	return 0;
	// ���� date1 ������һ�껹ʣ����

	// ���� date1 �� date2 ����˼������꣬����������
	




}

void ex_a() {

}

int main()
{
	interval_days(20200101, 20200301);
	return 0;
}