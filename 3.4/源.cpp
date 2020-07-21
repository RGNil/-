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

	// ���� date1 �� date2 ����˼������꣬����������
	int yearsBetween = date2 / 10000 - date1 / 10000;// -1; ����ŵ�whileͷ����
	if (yearsBetween == 0) {
		month = (date1 / 100) % 100;
		days = days - date1 % 100 + 1;
		while (--month) {
			days -= daysOfMonth(date1 / 10000, month);
		}
	}
	else if(yearsBetween == 1){// ���� date1 ������һ�껹ʣ����
		month = (date1 / 100) % 100;
		days += daysOfMonth(date1 / 10000, month) - date1 % 100 + 1;
		for (int m = month + 1; m < 13; m++) {
			days += daysOfMonth(date1 / 10000, m);
		}
	}
	else {
		month = (date1 / 100) % 100;
		days += daysOfMonth(date1 / 10000, month) - date1 % 100 + 1;
		for (int m = month + 1; m < 13; m++) {
			days += daysOfMonth(date1 / 10000, m);
		}
		for (int y = 1; y < yearsBetween; y++) {
			for (int m = 1; m < 13; m++) {
				days += daysOfMonth(date1 / 10000 + y, m);
			}
		}
	}
	return days;
}

int main()
{
	printf("%d", interval_days(20130101,20130105));
	return 0;
}