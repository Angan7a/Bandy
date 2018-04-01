#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>

#include"punkt.h"
#include"wierzcholek.h"
#include"linia.h"
#include"dekompozycjaKrzyzowa.h"
#include"dekompozycjaPrawa.h"
#include"dekompozycjaLewa.h"

using namespace std;

int main() {
	auto cmpPionowe = [](Linia* a, Linia* b) { return a->getPunktBlizejX()->getX() < b->getPunktBlizejX()->getX() || a->getPunktDalejX()->getY() < b->getPunktDalejX()->getY(); };
	auto cmpPoziome = [](Linia* a, Linia* b) { return a->getPunktL()->getX() < b->getPunktL()->getX() ||  a->getPunktL()->getY() < b->getPunktL()->getY(); };
	auto cmpPunkty = [](Punkt* a, Punkt* b) { return a->getX() < b->getX(); };
	set<Punkt*, decltype(cmpPunkty)> pierwszyPunkt(cmpPunkty);
	set<Linia*, decltype(cmpPionowe)> pierwszaLinia(cmpPionowe);
	set<Linia*, decltype(cmpPionowe)> liniePionowe(cmpPionowe);
	set<Linia*, decltype(cmpPoziome)> liniePoziome(cmpPoziome);
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
                int byl = 0;
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

		liniePoziome.insert( l2 );
		liniePionowe.insert( l1 );
		liniePionowe.insert( l3 );

		if(pierwszyPunkt.empty()) {
			pierwszyPunkt.insert(p1);
			pierwszaLinia.insert(l1);
		} else {
			//rozpatruje linie pionowa l1
			set<Linia*> vPoziome;
			for( auto itr = liniePoziome.begin(); itr != liniePoziome.end(); ++itr) {
				if( (*itr)->getPunktL()->getX() < l1->getPunktBlizejX()->getX() &&
				    l1->getPunktBlizejX()->getX() < (*itr)->getPunktR()->getX() &&

				    l1->getPunktBlizejX()->getY() < (*itr)->getPunktL()->getY() &&
				    (*itr)->getPunktL()->getY() < l1->getPunktDalejX()->getY()	) {
					Linia** o = new Linia*[2];
					o = dekompozycjaKrzyzowa((*itr), l1);
			cout << "Linia na prawo od l1 to: " << o[0]->getPunktL()->getX() << "   " <<   o[0]->getPunktL()->getY()  << "            " <<  o[0]->getPunktR()->getX()  << "    " <<  o[0]->getPunktR()->getY() << endl;
					vPoziome.insert(o[0]);
					liniePionowe.insert(o[1]);
					delete []o;
				}
			}
			for(auto itter = vPoziome.begin(); itter != vPoziome.end(); ++itter) {
				liniePoziome.insert(*itter);
			}
			for(auto itter = liniePoziome.begin(); itter != liniePoziome.end(); ++itter) {
				cout << "Linia poziome to: " << (*itter)->getPunktL()->getX() << "   " <<   (*itter)->getPunktL()->getY()  << "            " <<  (*itter)->getPunktR()->getX()  << "    " <<  (*itter)->getPunktR()->getY() << endl;
			}
			// znajdz linie pionowe w zbiorze wielokata przeciecinajaca sie z linia pozioma l2
			set<Linia*> vPionowe;
		cout << "Teraz l2 to: " << l2->getPunktL()->getX() << "   " <<   l2->getPunktL()->getY()  << "            " <<  l2->getPunktR()->getX()  << "    " <<  l2->getPunktR()->getY() << endl;
			for(auto itr = liniePionowe.begin(); itr != liniePionowe.end(); ++itr) {
				  if( l2->getPunktL()->getX() < (*itr)->getPunktBlizejX()->getX() &&
				      (*itr)->getPunktBlizejX()->getX() < l2->getPunktR()->getX() &&

				      (*itr)->getPunktBlizejX()->getY() < l2->getPunktL()->getY() &&
				      l2->getPunktL()->getY() < (*itr)->getPunktDalejX()->getY() ){
					Linia** o = new Linia*[2];
					o = dekompozycjaKrzyzowa(l2, (*itr));
					l2 = o[0];
					liniePoziome.insert(o[0]);
					vPionowe.insert(o[1]);
					delete []o;
				} else if((*itr)->getPunktBlizejX()->getX() == l2->getPunktL()->getX() &&
					  (*itr)->getPunktDalejX()->getY() < l2->getPunktL()->getY() &&
					  std::strcmp((*itr)->getSrodekPo(), "prawej") == 0 ) {
						 dekompozycjaPrawa(l1, (*itr));
				} else if((*itr)->getPunktBlizejX()->getX() == l2->getPunktL()->getX() &&
					  (*itr)->getPunktBlizejX()->getY() < l2->getPunktL()->getY() &&
					  l2->getPunktL()->getY() < (*itr)->getPunktDalejX()->getY() &&
					  std::strcmp((*itr)->getSrodekPo(), "lewej") == 0 ) {
						dekompozycjaPrawa(l1, (*itr));
				} else if((*itr)->getPunktBlizejX()->getX() == l2->getPunktL()->getX() &&
					  (*itr)->getPunktDalejX()->getY() < l2->getPunktL()->getY() &&
					  std::strcmp((*itr)->getSrodekPo(), "lewej") == 0 ) {
						//znajdz linie pozioma ktora ma prawy punkt rowny punktowi dalej x (*itr)
						Linia* liniaDoPrzekazania;
						for(auto iter = liniePoziome.begin(); iter != liniePoziome.end(); ++iter) {
							if((*iter)->getPunktR()->getX() == (*itr)->getPunktDalejX()->getX() &&
							   (*iter)->getPunktR()->getY() == (*itr)->getPunktDalejX()->getY() ) {
								liniaDoPrzekazania = (*iter);
							}
						}
						liniePionowe.insert(dekompozycjaLewa(l1, liniaDoPrzekazania));
				} else if((*itr)->getPunktBlizejX()->getX() == l2->getPunktL()->getX() &&
					  (*itr)->getPunktBlizejX()->getY() < l2->getPunktL()->getY() &&
					  l2->getPunktL()->getY() < (*itr)->getPunktDalejX()->getY() &&
					  std::strcmp((*itr)->getSrodekPo(), "lewej") == 0 ) {
//						dekompozycjaPrawa(l1, (*itr));
				cout << "KKKKKKKKKKKKKKKKKKKKKKKKKK" << endl;

				}
			}
			for(auto itter = vPionowe.begin(); itter != vPionowe.end(); ++itter) {
				liniePionowe.insert(*itter);
			}
			// rozpatruje linie pozioma l3
			set<Linia*> vvPoziome;
			for( auto itr = liniePoziome.begin(); itr != liniePoziome.end(); ++itr) {
					cout << "Rozpatruje linie krzyzujaca sie z l3 -" << (*itr)->getPunktL()->getX() << "   " <<   (*itr)->getPunktL()->getY()  << "            " <<  (*itr)->getPunktR()->getX()  << "    " <<  (*itr)->getPunktR()->getY() << endl;

				if( (*itr)->getPunktL()->getX() < l3->getPunktBlizejX()->getX() &&
				    l3->getPunktBlizejX()->getX() < (*itr)->getPunktR()->getX() &&

				    l3->getPunktBlizejX()->getY() < (*itr)->getPunktL()->getY() &&
				    (*itr)->getPunktL()->getY() < l3->getPunktDalejX()->getY()	) {
					Linia** o = new Linia*[2];
					o = dekompozycjaKrzyzowa((*itr), l3);
					vvPoziome.insert(o[0]);
					liniePionowe.insert(o[1]);
					delete []o;
				}

			}
			for(auto itter = vvPoziome.begin(); itter != vvPoziome.end(); ++itter) {
				liniePoziome.insert(*itter);
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

				if( (*itr)->getX() <= p1->getX() &&
				    p1->getX() < pKoncowy->getX() ) {
					//skasuj linie zaczynajace sie od punktu p1
					//skasuj niepotrzebne linie
					while(l1 != nullptr) {
						Linia* lnext = dynamic_cast<Linia*> (l1->getNastepny());
						if( l1->czyPionowa() ) {
							auto e = find(liniePionowe.begin(), liniePionowe.end(), l1);
							if(e != liniePionowe.end()) {
								liniePionowe.erase(e);
							}
						} else {
							auto e = find(liniePoziome.begin(), liniePoziome.end(), l1);
							if(e != liniePoziome.end()) {
								liniePoziome.erase(e);
							}

						}
						delete l1;
						l1 = lnext;
					}
					//skasuj niepotrzebne punkty
					while(p1 != nullptr) {
						Punkt* pNext = dynamic_cast<Punkt*> (p1->getNastepny());
						delete p1;
						p1 = pNext;
					}
				//(*itr) w srodku dodawanego bantu
				} else if( p1->getX() < (*itr)->getX() &&
					   (*itr)->getX() < p1Koncowy->getX() ){
					//znajdz liniepierwsze ktora zawiera (*itr)
					Linia* liniaDoSkasowania;
					for(auto it = pierwszaLinia.begin(); it != pierwszaLinia.end(); it++) {
						if((*it)->getPunktBlizejX()->getX() == (*itr)->getX() ) {
							liniaDoSkasowania = (*it);
							pierwszaLinia.erase(it);
							//pierwszaLinia.push_back(l1);
						}
					}
					//skasuj niepotrzebne linie
					while(liniaDoSkasowania != nullptr) {
						Linia* lnext = dynamic_cast<Linia*> (liniaDoSkasowania->getNastepny());
						if( liniaDoSkasowania->czyPionowa() ) {
							auto e = find(liniePionowe.begin(), liniePionowe.end(), liniaDoSkasowania);
							if(e != liniePionowe.end()) {
								liniePionowe.erase(e);
							}
						} else {
							auto e = find(liniePoziome.begin(), liniePoziome.end(), liniaDoSkasowania);
							if(e != liniePoziome.end()) {
								liniePoziome.erase(e);
							}
						}

						delete liniaDoSkasowania;
						liniaDoSkasowania = lnext;
					}
					//skasuj niepotrzebne punkty
					Punkt* p = (*itr);
					pierwszyPunkt.erase(itr);
					pierwszyPunkt.insert(p1);
					pierwszaLinia.insert(l1);
					while(p != nullptr) {
						Punkt* pNext = dynamic_cast<Punkt*> (p->getNastepny());
						delete p;
						p = pNext;
					}
			/*	} else if ((*itr)->getX() == p1->getX()) {
					//znajdz liniepierwsze ktora zawiera (*itr)
					Linia* liniaDoSkasowania;
					for(auto it = pierwszaLinia.begin(); it != pierwszaLinia.end(); it++) {
						if((*it)->getPunktBlizejX()->getX() == (*itr)->getX() ) {
							liniaDoSkasowania = (*it);
						}
					}
					if(p2->getY() <= liniaDoSkasowania->getPunktDalejX()->getY()) {
						//skasuj linie zaczynajace sie od punktu p1
						//skasuj niepotrzebne linie
						while(l1 != nullptr) {
							Linia* lnext = dynamic_cast<Linia*> (l1->getNastepny());
							if( l1->czyPionowa() ) {
								auto e = find(liniePionowe.begin(), liniePionowe.end(), l1);
								if(e != liniePionowe.end()) {
									liniePionowe.erase(e);
								}
							} else {
								auto e = find(liniePoziome.begin(), liniePoziome.end(), l1);
								if(e != liniePoziome.end()) {
									liniePoziome.erase(e);
								}
							}
							delete l1;
							l1 = lnext;
						}
						//skasuj niepotrzebne punkty
						while(p1 != nullptr) {
							Punkt* pNext = dynamic_cast<Punkt*> (p1->getNastepny());
							delete p1;
							p1 = pNext;
						}

							cout << "linie sie pokrywaja" << endl;
					} else {
						pierwszaLinia.insert(l1);
						pierwszyPunkt.erase((*itr));
						pierwszaLinia.erase(liniaDoSkasowania);
						pierwszyPunkt.insert(p1);
						//skasuj niepotrzebne linie
						while(liniaDoSkasowania != nullptr) {
							Linia* lnext = dynamic_cast<Linia*> (liniaDoSkasowania->getNastepny());
							if( liniaDoSkasowania->czyPionowa() ) {
								auto e = find(liniePionowe.begin(), liniePionowe.end(), liniaDoSkasowania);
								if(e != liniePionowe.end()) {
									liniePionowe.erase(e);
								}
							} else {
								auto e = find(liniePoziome.begin(), liniePoziome.end(), liniaDoSkasowania);
								if(e != liniePoziome.end()) {
									liniePoziome.erase(e);
								}
							}
							delete liniaDoSkasowania;
							liniaDoSkasowania = lnext;
						}
						//skasuj niepotrzebne punkty
						Punkt* p = (*itr);
						while(p != nullptr) {
							Punkt* pNext = dynamic_cast<Punkt*> (p->getNastepny());
							delete p;
							p = pNext;
						}

					}


				} else if(p1->getX() == pKoncowy->getX()) {
					cout << "p1 i pKoncowy pokrywaja sie" << endl;
		*/		} else {
					byl =1;
				}
			}
			if(byl) {
				pierwszyPunkt.insert(p1);
				pierwszaLinia.insert(l1);
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

