#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>

#include"punkt.h"
#include"wierzcholek.h"
#include"linia.h"


using namespace std;

int main() {
	vector<Punkt*> pierwszyPunkt;
	vector<Linia*> pierwszaLinia;
	set<Linia*> liniePionowe;
	set<Linia*> liniePoziome;
	set<Linia*> linieDoSkasowania;
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
					// punkt przeciecia
					float x = (*itr)->getP1()->getX();
					float y = l2->getP1()->getY();
					cout << "Punkt przeciecia: " << x << "  " << y << endl;
					if(y == (*itr)->getP1()->getY()) {
						if(x == (*itr)->getP1()->getX() ||
						   x == (*itr)->getP2()->getX()	  ) {
							cout << "Punkt przeciecia znajduje sie w punktcie P1 lub P2" << endl;
							// zaznacz ktore linie i punkty maja zostac a ktora maja byc skasowane (wybor nie ma znaczenia)
							if(l2->getPunktL()->getX() < x) {
								if(l2->getPunktL()->getSkasowac() == 'T') {
									l2->getPunktL()->setSkasowac('T');
									l2->getPunktL()->getNastepny()->setSkasowac('T');
									l2->getPunktL()->getNastepny()->getNastepny()->setSkasowac('T');
									l2->setSkasowac('T');
									l2->getNastepny()->setSkasowac('T');
//									linieDoSkasowania.insert(nowaLiniaLewa);
									(*itr)->getPunktDalejX()->setSkasowac('N');
									(*itr)->getPunktBlizejX()->setSkasowac('N');
									(*itr)->setSkasowac('N');
								} else {
									l2->getPunktL()->setSkasowac('N');
									l2->getPunktL()->getNastepny()->setSkasowac('N');
									l2->getPunktL()->getNastepny()->getNastepny()->setSkasowac('N');
									l2->setSkasowac('N');
									l2->getNastepny()->setSkasowac('N');
//									linieDoSkasowania.insert(nowaLiniaLewa);
									(*itr)->getPunktDalejX()->setSkasowac('T');
									(*itr)->getPunktBlizejX()->setSkasowac('T');
									(*itr)->setSkasowac('T');
								}
							} else {
								Punkt* po = new Punkt(x, y);
//								Punkt* ps = new Punkt(x, y);
								if((*itr)->getSrodekPo() == "prawej") {
									Skasowac* n1 = new Linia(po, (*itr)->getPunktDalejX(), "prawej");
									Linia* nowaLiniaGorna = dynamic_cast<Linia*>(n1);
									//flow obwiedni
									l2->getPunktL()->setNastepny(po);
									l2->getPunktL()->getNastepny()->setNastepny(nowaLiniaGorna->getPunktDalejX());
									l2->setNastepny(nowaLiniaGorna);
									//czy skasowac
									l2->setSkasowac('N'); // linia
									l2->getNastepny()->setSkasowac('N'); // linia
									l2->getPunktL()->setSkasowac('N'); //reszta to punkty
									l2->getPunktL()->getNastepny()->setSkasowac('N');
									l2->getPunktL()->getNastepny()->getNastepny()->setSkasowac('N');
									//flow do skasowania
									(*itr)->getPunktBlizejX()->setNastepny( l3->getPunktDalejX() );
//									(*itr)->getPunktBlizejX()->getNastepny()->setNastepny(l3->getPunktDalejX());
									(*itr)->setNastepny(l3);
									//czy skasowac
									(*itr)->setSkasowac('T'); //linia
									(*itr)->getNastepny()->setSkasowac('T'); //linia
									(*itr)->getPunktBlizejX()->setSkasowac('T'); //reszta to punkty
									(*itr)->getPunktBlizejX()->getNastepny()->setSkasowac('T');
									(*itr)->getPunktBlizejX()->getNastepny()->getNastepny()->setSkasowac('T');
								} else {
										
										
										

								}
							}
						} else {
						cout << "Punkt przeciecia znajduje sie na linii pionowej" << endl;
						}
					} else {
						//utwórz dwa punkty - po(punkt obwiedni), ps(do skasowania)
						Punkt* po = new Punkt(x, y);
						Punkt* ps = new Punkt(x, y);
						// skróc linie l2 do punktu przecia
						if((*itr)->getPunktBlizejX() == (*itr)->getP1()) {
							(*itr)->setP2(ps);
						} else {
							(*itr)->setP1(ps);
						}

						if((*itr)->getSrodekPo() == "prawej") {
							Linia* nowaLiniaGorna = new Linia(po, (*itr)->getPunktDalejX(), "prawej");
							Linia* nowaLiniaLewa = new Linia(l2->getP1(), po, "dol");
							l2->setP1(po);
							//flow
							nowaLiniaLewa->getPunktL()->setNastepny(po);
							po->setNastepny(nowaLiniaGorna->getPunktDalejX());
							(*itr)->getPunktBlizejX()->setNastepny(ps);
							ps->setNastepny(l2->getPunktR());
							//dodaj punkty i linie
							liniePionowe.insert(nowaLiniaGorna);
							liniePoziome.insert(nowaLiniaLewa);

						} else 	if((*itr)->getSrodekPo() == "lewej") {
							Linia* nowaLiniaGorna = new Linia(po, (*itr)->getPunktDalejX(), "lewej");
							Linia* nowaLiniaLewa = new Linia(l2->getP1(), ps, "dol");
							l2->setP1(ps);
							//flow
							nowaLiniaLewa->getPunktL()->setNastepny(ps);
							ps->setNastepny((*itr)->getPunktBlizejX());
							nowaLiniaGorna->getPunktDalejX()->setNastepny(po);
							po->setNastepny(l2->getPunktR());
							//dodaj punkty i linie
							liniePionowe.insert(nowaLiniaGorna);
							linieDoSkasowania.insert(nowaLiniaLewa);
						}
					}


				} else { cout << "nie dodaje taj linii" << endl; } 
			}
		// znajdz linie pioziome w zbiorze wielokata przeciecinajaca sie z linia pozioma l1
		// znajdz linie pioziome w zbiorze wielokata przeciecinajaca sie z linia pozioma l3

		}
		cout << endl;
	}

return 0;
}

