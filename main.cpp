#include<iostream>
#include<stdio.h>
#include<vector>

#include"punkt.h"
#include"wierzcholek.h"
#include"linia.h"


using namespace std;

int main() {
	vector<Wierzcholek*> wielokat;
	char a[12];
	float center, width, alarm;
	while((scanf("%12s - %f, %f, %f", a, &center, &width, &alarm)) != EOF) {
		Punkt *p1 = new Punkt(center - width/2, 0);
		Punkt *p2 = new Punkt(center - width/2, alarm);
		Punkt *p3 = new Punkt(center + width/2, alarm);
		Punkt *p4 = new Punkt(center + width/2, 0);

		Linia *l1 = new Linia(p1, p2);
		Linia *l2 = new Linia(p2, p3);
		Linia *l3 = new Linia(p3, p4);

		Wierzcholek *w1 = new Wierzcholek(p1, l1);
		Wierzcholek *w2 = new Wierzcholek(p2, l1, l2);
		Wierzcholek *w3 = new Wierzcholek(p3, l2, l3);
		Wierzcholek *w4 = new Wierzcholek(p4, nullptr, l3);

		w1->setNastepny(w2);
		w2->setNastepny(w3);
		w3->setNastepny(w4);

		w4->setPoprzedni(w3);
		w3->setPoprzedni(w2);
		w2->setPoprzedni(w1);

		cout << endl;
	}

return 0;
}
