#pragma warning(disable : 4996) // ����VS�İ�ȫ��ʩ��ʹscanf��ԭ��C��������
#include<cstdio>
#include<cstdlib>
#include<algorithm> // ��sort����
using namespace std;


struct MoonCake
{
	double totalAmount;
	double totalPrice;
	double price;
};

bool cmp(MoonCake a, MoonCake b) {// sort�õıȽϺ��������յ��۴Ӹߵ�������
	return a.price > b.price;
}

inline void test() {
	int n, d; // �±����������г����������
	scanf("%d %d", &n, &d);
	MoonCake* moonCake = (MoonCake*)malloc(n * sizeof(MoonCake));
	for (int i = 0; i < n; i++) {
		scanf("%lf", &moonCake[i].totalAmount);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf", &moonCake[i].totalPrice);
		moonCake[i].price = moonCake[i].totalPrice / moonCake[i].totalAmount;
	}
	sort(moonCake, moonCake + n, cmp);
	d = (double)d; // ��������ǿ�Ʊ��double��
	double supplyAmount = 0; // ��¼�Ѿ������˶�������
	int cakeId = 0;
	while (d) {
		if (moonCake[cakeId].totalAmount > 0) {

		}
	}
}