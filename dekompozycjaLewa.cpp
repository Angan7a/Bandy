#include"dekompozycjaLewa.h"
void dekompozycjaLewa(Linia* liniaPozioma, Linia* liniaPionowa, std::set<Linia*>& liniePionowe) {
	float x =0;
	float y =0;

	//utwórz dwa punkty - po(punkt obwiedni), ps(do skasowania)
//        Skasowac* poq = new Punkt(x, y);
        Skasowac* psq = new Punkt(x, y);
//	Punkt* po = dynamic_cast<Punkt*>(poq);
	Punkt* ps = dynamic_cast<Punkt*>(psq);
        // skróc linie pozioma do punktu przecia
        if(liniaPionowa->getSrodekPo() == "prawej") {
		Linia* nextLG = dynamic_cast<Linia*> (liniaPionowa->getNastepny());
		Linia* nextLD = dynamic_cast<Linia*> (liniaPozioma->getNastepny());
		Punkt* nextPG = dynamic_cast<Punkt*> (liniaPionowa->getPunktDalejX()->getNastepny());
//		Punkt* nextPD = dynamic_cast<Punkt*> (liniaPozioma->getPunktR()->getNastepny());

		Skasowac* ng = new Linia(liniaPozioma->getPunktR(),liniaPionowa->getPunktDalejX(), "prawej");
		Linia* nowaLiniaGorna = dynamic_cast<Linia*>(ng);

		liniaPozioma->setPunktDalejX(ps);
		liniaPionowa->setPunktDalejX(ps);
		liniaPionowa->setNastepny(liniaPozioma->getNastepny());
		nextLD->setPunktDalejX(ps);
		//flow obwiedni
//		liniaPozioma->getPunktL()->setNastepny(po); // punkt
		liniaPozioma->getPunktR()->setNastepny(nowaLiniaGorna->getPunktDalejX()); //punkt
		nowaLiniaGorna->getPunktDalejX()->setNastepny(nextPG); //punkt
		liniaPozioma->setNastepny(nowaLiniaGorna); //linia
		nowaLiniaGorna->setNastepny(nextLG); //linia
		//dodanie lini poz i pion
		liniePionowe.insert(nowaLiniaGorna);
		//flow do skasowania
		liniaPionowa->getPunktBlizejX()->setNastepny(ps);//punkt
		ps->setNastepny(nextLD->getPunktBlizejX());//punkt
		liniaPionowa->setNastepny(nextLD); //linie
        } else {

	//
	}



}

