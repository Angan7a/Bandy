#include"wielokat.h"
#include<algorithm>
//#include<cstring>


void Wielokat::skasujNiepotrzebneLIP(Linia* l1, Punkt* p1) {
	bool byl = 0;
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

        } else {
                                        byl =1;
                                }
                        }
                        if(byl) {
                                pierwszyPunkt.insert(p1);
                                pierwszaLinia.insert(l1);
                        }
}
