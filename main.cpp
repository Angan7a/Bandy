#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>
#include <memory>

#include"punkt.h"
#include"linia.h"
#include"dekompozycjaKrzyzowa.h"
#include"dekompozycjaPrawa.h"
#include"dekompozycjaLewa.h"
#include"dekompozycjaDolna.h"
#include"dekompozycjaDolnaPojedyncza.h"

using namespace std;

int main() {
	auto cmpPionowe = [](Linia* a, Linia* b) { return a->getPunktBlizejX()->getX() < b->getPunktBlizejX()->getX() || a->getPunktDalejX()->getY() < b->getPunktDalejX()->getY(); };
	auto cmpPoziome = [](Linia* a, Linia* b) { return a->getPunktL()->getX() < b->getPunktL()->getX() ||  a->getPunktL()->getY() < b->getPunktL()->getY(); };
	auto cmpPunkty = [](shared_ptr<Punkt> a, shared_ptr<Punkt> b) { return a->getX() < b->getX(); };
	auto cmp = [](shared_ptr<Punkt> a, shared_ptr<Punkt> b) { return a->getX() < b->getX(); };
	set<shared_ptr<Punkt>, decltype(cmp)> sPunkt(cmp);

	set<shared_ptr<Punkt>, decltype(cmpPunkty)> pierwszyPunkt(cmpPunkty);
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
		shared_ptr<Punkt> sp1 = make_shared<Punkt>(p1x, p1y);
		sPunkt.insert(sp1);

		shared_ptr<Punkt> p1 = make_shared<Punkt>(p1x, p1y);
		shared_ptr<Punkt> p2 = make_shared<Punkt>(p2x, p2y);
		shared_ptr<Punkt> p3 = make_shared<Punkt>(p3x, p3y);
		shared_ptr<Punkt> p4 = make_shared<Punkt>(p4x, p4y);



		//shared_ptr<Punkt> p1 = new Punkt(p1x, p1y);
		//shared_ptr<Punkt> p2 = new Punkt(p2x, p2y);
		//shared_ptr<Punkt> p3 = new Punkt(p3x, p3y);
		//shared_ptr<Punkt> p4 = new Punkt(p4x, p4y);

		Linia* l1 = new Linia(p1, p2, "prawej");
		Linia* l2 = new Linia(p2, p3, "dol");
		Linia* l3 = new Linia(p3, p4, "lewej");

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


				Linia* l22 = (*itr)->getNastepny();

				if(((*itr)->getPunktR()->getX()) == (l1->getPunktDalejX()->getX() )&&
				  ( (*itr)->getPunktR()->getY()) == (l1->getPunktDalejX()->getY() )&&
  				   (std::strcmp(l22->getSrodekPo(), "lewej") == 0) ) {
					liniePionowe.erase((*itr)->getNastepny());
					liniePionowe.erase(l1);
					dekompozycjaDolna((*itr), l1);

				} else if( (*itr)->getPunktL()->getX() < l1->getPunktBlizejX()->getX() &&
				    l1->getPunktBlizejX()->getX() < (*itr)->getPunktR()->getX() &&

				    l1->getPunktBlizejX()->getY() < (*itr)->getPunktL()->getY() &&
				    (*itr)->getPunktL()->getY() < l1->getPunktDalejX()->getY()	) {
					Linia** o = new Linia*[2];
					o = dekompozycjaKrzyzowa((*itr), l1);
					vPoziome.insert(o[0]);
					liniePionowe.insert(o[1]);
					delete []o;
				}
			}
			for(auto itter = vPoziome.begin(); itter != vPoziome.end(); ++itter) {
				liniePoziome.insert(*itter);
			}
			// znajdz linie pionowe w zbiorze wielokata przeciecinajaca sie z linia pozioma l2
			set<Linia*> vPionowe;
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
				} else if((*itr)->getPunktDalejX()->getY() == l2->getPunktL()->getY() &&
					  l2->getPunktL()->getX() < (*itr)->getPunktDalejX()->getX() &&
					  (*itr)->getPunktDalejX()->getX() < l2->getPunktR()->getX() ){
						if(std::strcmp((*itr)->getSrodekPo(), "prawej") == 0 ) {
							liniePionowe.erase((*itr));
							liniePionowe.erase(l3);
							dekompozycjaDolnaPojedyncza((*itr), l2);
						} else {
							liniePionowe.erase((*itr));
							liniePionowe.erase(l1);
							//znajdz linie pozioma ktora ma prawy punkt rowny punktowi dalej x (*itr)
							Linia* liniaDoPrzekazania;
							for(auto iter = liniePoziome.begin(); iter != liniePoziome.end(); ++iter) {
								if((*iter)->getPunktR()->getX() == (*itr)->getPunktDalejX()->getX() &&
								   (*iter)->getPunktR()->getY() == (*itr)->getPunktDalejX()->getY() ) {
									liniaDoPrzekazania = (*iter);
								}

							}

							dekompozycjaDolnaPojedyncza(l1, liniaDoPrzekazania);
						}
				}
			}
			for(auto itter = vPionowe.begin(); itter != vPionowe.end(); ++itter) {
				liniePionowe.insert(*itter);
			}
			// rozpatruje linie pozioma l3
			set<Linia*> vvPoziome;
			for( auto itr = liniePoziome.begin(); itr != liniePoziome.end(); ++itr) {
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
				shared_ptr<Punkt> pKoncowy =  (*itr);
				while(pKoncowy->getNastepny() != nullptr) {
					pKoncowy = pKoncowy->getNastepny();
				}
				shared_ptr<Punkt> p1Koncowy =  p1;
				while(p1Koncowy->getNastepny() != nullptr) {
					p1Koncowy = p1Koncowy->getNastepny();
				}
				if( (*itr)->getX() <= p1->getX() &&
				    p1->getX() < pKoncowy->getX() ) {
					//skasuj linie zaczynajace sie od punktu p1
					//skasuj niepotrzebne linie
					while(l1 != nullptr) {
						Linia* lnext = l1->getNastepny();
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
						shared_ptr<Punkt> pNext = p1->getNastepny();
						//delete p1;
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
						Linia* lnext = liniaDoSkasowania->getNastepny();
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
					shared_ptr<Punkt> p = (*itr);
					pierwszyPunkt.erase(itr);
					pierwszyPunkt.insert(p1);
					pierwszaLinia.insert(l1);
					while(p != nullptr) {
						shared_ptr<Punkt> pNext = p->getNastepny();
						//delete p;
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
							shared_ptr<Punkt> pNext = dynamic_cast<shared_ptr<Punkt>> (p1->getNastepny());
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
						shared_ptr<Punkt> p = (*itr);
						while(p != nullptr) {
							shared_ptr<Punkt> pNext = dynamic_cast<shared_ptr<Punkt>> (p->getNastepny());
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



		}


		}

	
		//wyswietlanie wynikow

		int x =1;
		for(auto itr = pierwszyPunkt.begin(); itr != pierwszyPunkt.end(); ++itr) {
			shared_ptr<Punkt> p =  *(itr);
		cout << "Seria_punktów_" << x++ << endl;
			int y = 1;
			while(p != nullptr) {
				cout << "Punkt_" << y++ << " - "  << p->getX() << "," << p->getY() << endl;
				p = p->getNastepny();
			}


		}
//wyczysc pamiec
		for(auto itr = pierwszaLinia.begin(); itr != pierwszaLinia.end(); ++itr) {
			Linia* liniaDoSkasowania = (*itr);
			while(liniaDoSkasowania != nullptr) {
				Linia* lnext = liniaDoSkasowania->getNastepny();
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
		}

		for(auto itr = pierwszyPunkt.begin(); itr != pierwszyPunkt.end(); ++itr) {
			//skasuj niepotrzebne punkty
			shared_ptr<Punkt> p = (*itr);
			while(p != nullptr) {
				shared_ptr<Punkt> pNext = p->getNastepny();
				//delete p;
				p = pNext;
		}

	}
return 0;
}

