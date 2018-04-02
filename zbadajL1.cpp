#include"wielokat.h"
#include<cstring>
#include"dekompozycjaDolna.h"
#include"dekompozycjaKrzyzowa.h"


void Wielokat::zbadajL1(Linia* l1) {
	//rozpatruje linie pionowa l1
	set<Linia*> vPoziome;
	for( auto itr = liniePoziome.begin(); itr != liniePoziome.end(); ++itr) {
		Linia* l22 = dynamic_cast<Linia*>((*itr)->getNastepny());
		if(((*itr)->getPunktR()->getX()) == (l1->getPunktDalejX()->getX() )&&
		   ( (*itr)->getPunktR()->getY()) == (l1->getPunktDalejX()->getY() )&&
		   (std::strcmp(l22->getSrodekPo(), "lewej") == 0) ) {
			liniePionowe.erase(dynamic_cast<Linia*> ((*itr)->getNastepny()));
			liniePionowe.erase(l1);
			dekompozycjaDolna((*itr), l1);
		} else if( (*itr)->getPunktL()->getX() < l1->getPunktBlizejX()->getX() &&
			   l1->getPunktBlizejX()->getX() < (*itr)->getPunktR()->getX() &&
			   l1->getPunktBlizejX()->getY() < (*itr)->getPunktL()->getY() &&
			   (*itr)->getPunktL()->getY() < l1->getPunktDalejX()->getY()  ) {
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
}
