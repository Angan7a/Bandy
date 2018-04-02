#include"wielokat.h"
#include<cstring>
#include"dekompozycjaKrzyzowa.h"


void Wielokat::zbadajL3(Linia* l3) {
	// rozpatruje linie pozioma l3
	set<Linia*> vvPoziome;
	for( auto itr = liniePoziome.begin(); itr != liniePoziome.end(); ++itr) {
		if( (*itr)->getPunktL()->getX() < l3->getPunktBlizejX()->getX() &&
		    l3->getPunktBlizejX()->getX() < (*itr)->getPunktR()->getX() &&

		    l3->getPunktBlizejX()->getY() < (*itr)->getPunktL()->getY() &&
		    (*itr)->getPunktL()->getY() < l3->getPunktDalejX()->getY()  ) {
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


}
