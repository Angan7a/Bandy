#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>

#include"punkt.h"
#include"wierzcholek.h"
#include"linia.h"
#include"dekompozycjaKrzyzowa.h"

using namespace std;

int main() {
	vector<Punkt*> pierwszyPunkt;
	vector<Linia*> pierwszaLinia;
	vector<Linia*> liniePionowe;
	vector<Linia*> liniePoziome;
	vector<Linia*> linieDoSkasowania;
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
                Skasowac *p11 = new Punkt(p1x, p1y);
                Skasowac *p22 = new Punkt(p2x, p2y);
                Skasowac *p33 = new Punkt(p3x, p3y);
                Skasowac *p44 = new Punkt(p4x, p4y);
		Punkt* p1 = dynamic_cast<Punkt*>(p11);
		Punkt* p2 = dynamic_cast<Punkt*>(p22);
		Punkt* p3 = dynamic_cast<Punkt*>(p33);
		Punkt* p4 = dynamic_cast<Punkt*>(p44);


		Skasowac *l11 = new Linia(p1, p2, "prawej");
		Skasowac *l22 = new Linia(p2, p3, "dol");
		Skasowac *l33 = new Linia(p3, p4, "lewej");
		Linia* l1 = dynamic_cast<Linia*>(l11);
		Linia* l2 = dynamic_cast<Linia*>(l22);
		Linia* l3 = dynamic_cast<Linia*>(l33);

		p1->setNastepny(p2);
		p2->setNastepny(p3);
		p3->setNastepny(p4);

		l1->setNastepny(l2);
		l2->setNastepny(l3);

		if(pierwszyPunkt.empty()) {
			pierwszyPunkt.push_back(p1);
			pierwszaLinia.push_back(l1);
			liniePoziome.push_back( l2 );
			liniePionowe.push_back( l1 );
			liniePionowe.push_back( l3 );
		} else {
			//rozpatruje linie pionowa l1
			for( auto itr = liniePoziome.begin(); itr != liniePoziome.end(); ++itr) {
				if( (*itr)->getPunktL()->getX() < l1->getPunktBlizejX()->getX() &&
				    l1->getPunktBlizejX()->getX() < (*itr)->getPunktR()->getX() &&

				    l1->getPunktBlizejX()->getY() < (*itr)->getPunktL()->getY() &&
				    (*itr)->getPunktL()->getY() < l1->getPunktDalejX()->getY()	) {
					dekompozycjaKrzyzowa((*itr), l1);
					cout << "teraz l1 to: " << l1->getPunktDalejX()->getY() <<endl;
				}
			}

			// znajdz linie pionowe w zbiorze wielokata przeciecinajaca sie z linia pozioma l2
		//	cout << "Linia pozima l2: " << l2->getP1()->getX() << "," << l2->getP1()->getY() << "        " << l2->getP2()->getX() << "," << l2->getP2()->getY()  << endl;
			for(auto itr = liniePionowe.begin(); itr != liniePionowe.end(); ++itr) {
				  if( l2->getPunktL()->getX() < (*itr)->getPunktBlizejX()->getX() &&
				      (*itr)->getPunktBlizejX()->getX() < l2->getPunktR()->getX() &&

				      (*itr)->getPunktBlizejX()->getY() < l2->getPunktL()->getY() &&
				      l2->getPunktL()->getY() < (*itr)->getPunktDalejX()->getY() ){
					// punkt przeciecia
					l2 = dekompozycjaKrzyzowa(l2, (*itr));
					if(strcmp( (*itr)->getSrodekPo(), "lewej") == 0) {
						liniePoziome.push_back(l2);
					}

				}
			}
		// rozpatruje linie pozioma l3
			for( auto itr = liniePoziome.begin(); itr != liniePoziome.end(); ++itr) {
				if( (*itr)->getPunktL()->getX() < l3->getPunktBlizejX()->getX() &&
				    l3->getPunktBlizejX()->getX() < (*itr)->getPunktR()->getX() &&

				    l3->getPunktBlizejX()->getY() < (*itr)->getPunktL()->getY() &&
				    (*itr)->getPunktL()->getY() < l3->getPunktDalejX()->getY()	) {
					dekompozycjaKrzyzowa((*itr), l3);
				}
				liniePionowe.push_back(l3);
			}
		//czyszczenie pamieci z niepotrzebnych punktow i linii
			for(auto itr = pierwszyPunkt.begin(); itr != pierwszyPunkt.end(); ++itr) {
				Punkt* pKoncowy =  (*itr);
				while(pKoncowy->getNastepny() != nullptr) {
					pKoncowy = dynamic_cast<Punkt*> (pKoncowy->getNastepny());
				}
				Punkt* p1Koncowy =  p1;
				while(p1Koncowy->getNastepny() != nullptr) {
					p1Koncowy = dynamic_cast<Punkt*> (p1Koncowy->getNastepny());
				}

				if( (*itr)->getX() < p1->getX() &&
				    p1->getX() < pKoncowy->getX() ) {
					//skasuj linie zaczynajace sie od punktu p1

					//skasuj niepotrzebne linie
					while(l1->getNastepny() != nullptr) {

						Linia* lpom1 = dynamic_cast<Linia*> (l1->getNastepny());
			cout << "%%%%%%%%%%%%%%%%Kasuje: " << 
l1->getP1()->getX() << "    "    <<
l1->getP1()->getY() << "    "    << "                   "<<
l1->getP2()->getX() << "    "    <<
l1->getP2()->getY() << "    "    << endl;

						if(lpom1) {
							delete l1;
						l1 = lpom1;
						}
					}
					//skasuj niepotrzebne punkty
					while(p1->getNastepny() == nullptr) {
						p1 = dynamic_cast<Punkt*> (p1->getNastepny());
						if(p1) {
							delete p1;
						}
					}
				//(*itr) w srodku dodawanego bantu
				} else if( p1->getX() < (*itr)->getX() &&
					   (*itr)->getX() < p1Koncowy->getX() ){
					//skasuj linie zaczynajace sie od punktu (*itr)
					int lDoSkasowania;
					for(auto it = pierwszaLinia.begin(); it != pierwszaLinia.end(); it++) {
						if((*it)->getPunktBlizejX()->getX() == (*itr)->getX() ) {
							cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%saaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << (*it)->getPunktBlizejX()->getX() << endl;
							//lDoSkasowania = (*it)->getPunktBlizejX()->getX();

						}
					}
				/*	//skasuj niepotrzebne linie
					while(liniaDoSkasowania->getNastepny() == nullptr) {
						liniaDoSkasowania = dynamic_cast<Linia*> (liniaDoSkasowania->getNastepny());
						if(liniaDoSkasowania) {
							delete liniaDoSkasowania;
						}
					}
					//skasuj niepotrzebne punkty
					Punkt* p = (*itr);
					while(p->getNastepny() == nullptr) {
						p = dynamic_cast<Punkt*> (p->getNastepny());
						if(p) {
							delete p;
						}
					}*/
				}
			}
		//wyswietlanie wynikow
		for(auto itr = pierwszyPunkt.begin(); itr != pierwszyPunkt.end(); ++itr) {
			Punkt* p =  *(itr);
			while(p != nullptr) {
				cout << p->getX() << "    " << p->getY() << endl;
				p = dynamic_cast<Punkt*> (p->getNastepny());
			}
		cout << "sdasdasdsa" << endl;

		}}

	}

return 0;
}

