#include"wielokat.h"
#include<cstring>
#include"dekompozycjaDolnaPojedyncza.h"
#include"dekompozycjaKrzyzowa.h"
#include"dekompozycjaPrawa.h"
#include"dekompozycjaLewa.h"


void Wielokat::zbadajL2(Linia* l1, Linia* l2,Linia* l3) {
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
/////                                              dekompozycjaPrawa(l1, (*itr));
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
	        for(auto itter = vPionowe.begin(); itter != vPionowe.end(); ++itter) {
                	liniePionowe.insert(*itter);
			VPionowe.push_back((*itter));
			sortPionowe();
                }
	}
}
