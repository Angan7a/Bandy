#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>

#include"punkt.h"
#include"wierzcholek.h"
#include"linia.h"


using namespace std;

int main() {
	vector<Wierzcholek*> wielokat;
	set<Linia*> liniePionowe;
	set<Linia*> liniePoziome;
	char a[12];
/*	float center, width, alarm;
	while((scanf("%12s - %f, %f, %f", a, &center, &width, &alarm)) != EOF) {
		Punkt *p1 = new Punkt(center - width/2, 0);
		Punkt *p2 = new Punkt(center - width/2, alarm);
		Punkt *p3 = new Punkt(center + width/2, alarm);
		Punkt *p4 = new Punkt(center + width/2, 0);
*/

        float p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
        while((scanf("%12s - (%f, %f)(%f, %f)(%f, %f)(%f, %f)", a, &p1x, &p1y, &p2x, &p2y, &p3x, &p3y, &p4x, &p4y)) != EOF) {
                Punkt *p1 = new Punkt(p1x, p1y);
                Punkt *p2 = new Punkt(p2x, p2y);
                Punkt *p3 = new Punkt(p3x, p3y);
                Punkt *p4 = new Punkt(p4x, p4y);

		Linia *l1 = new Linia(p1, p2, "pionowa");
		Linia *l2 = new Linia(p2, p3, "pozioma");
		Linia *l3 = new Linia(p3, p4, "pionowa");

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

		if(wielokat.empty()) {
			wielokat.push_back(w1);
			liniePoziome.insert( l2 );
			liniePionowe.insert( l1 );
			liniePionowe.insert( l3 );
		} else {
			// znajdz linie pionowe w zbiorze wielokata przeciecinajaca sie z linia pozioma l2
			cout << "Linia pozima l2: " << l2->getP1()->getX() << "," << l2->getP1()->getY() << "        " << l2->getP2()->getX() << "," << l2->getP2()->getY()  << endl;
			for(auto itr = liniePionowe.begin(); itr != liniePionowe.end(); ++itr) {
				cout << "Rozpatruje teraz linie pionowa: " << (*itr)->getP1()->getX() << "," << (*itr)->getP1()->getY() << "        " << (*itr)->getP2()->getX() << "," << (*itr)->getP2()->getY()  << endl;
				if( ((*itr)->getP1()->getY() <= l2->getP1()->getY() &&
				   l2->getP1()->getY() <= (*itr)->getP2()->getY() &&
				   l2->getP1()->getX() <= (*itr)->getP1()->getX() &&
				   (*itr)->getP1()->getX() <= l2->getP2()->getX() ) ||

				  ((*itr)->getP1()->getY() >= l2->getP1()->getY() &&
				   l2->getP1()->getY() >= (*itr)->getP2()->getY() &&
				   l2->getP1()->getX() <= (*itr)->getP1()->getX() &&
				   (*itr)->getP1()->getX() <= l2->getP2()->getX() )  ){
					cout << "dodaj ta linie" << endl;
				} else { cout << "nie dodaje taj linii" << endl; }
			}
		// znajdz linie pioziome w zbiorze wielokata przeciecinajaca sie z linia pozioma l1
		// znajdz linie pioziome w zbiorze wielokata przeciecinajaca sie z linia pozioma l3

		}
		cout << endl;
	}

return 0;
}

