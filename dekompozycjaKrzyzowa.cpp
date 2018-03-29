#include"linia.h"
#include"punkt.h"
#include<set>
Linia* dekompozcyajKrzyzowa(Linia* liniaPozioma, Linia* liniaPionowa, std::set<Linia*>& liniePionowe, std::set<Linia*>& liniePoziome) {
	float x =0;
	float y =0;

	//utwórz dwa punkty - po(punkt obwiedni), ps(do skasowania)
        Skasowac* poq = new Punkt(x, y);
        Skasowac* psq = new Punkt(x, y);
	Punkt* po = dynamic_cast<Punkt*>(poq);
	Punkt* ps = dynamic_cast<Punkt*>(psq);
        // skróc linie pozioma do punktu przecia
        if(liniaPionowa->getSrodekPo() == "prawej") {
		Linia* nextLG = dynamic_cast<Linia*> (liniaPionowa->getNastepny());
		Linia* nextLR = dynamic_cast<Linia*> (liniaPozioma->getNastepny());
		Punkt* nextPG = dynamic_cast<Punkt*> (liniaPionowa->getPunktDalejX()->getNastepny());
		Punkt* nextPR = dynamic_cast<Punkt*> (liniaPozioma->getPunktR()->getNastepny());

		Skasowac* nr = new Linia(ps, liniaPozioma->getPunktR(), "dol");
		Linia* nowaLiniaPrawa = dynamic_cast<Linia*>(nr);
		Skasowac* ng = new Linia(liniaPionowa->getPunktDalejX(), po, "prawej");
		Linia* nowaLiniaGorna = dynamic_cast<Linia*>(ng);

        	liniaPozioma->setPunktR(po);
		liniaPionowa->setPunktDalejX(ps);
		//flow obwiedni
		liniaPozioma->getPunktL()->setNastepny(po); // punkt
		po->setNastepny(nowaLiniaGorna->getPunktDalejX()); //punkt
		nowaLiniaGorna->getPunktDalejX()->setNastepny(nextPG); //punkt
		liniaPozioma->setNastepny(nowaLiniaGorna); //linia
		nowaLiniaGorna->setNastepny(nextLG); //linia
		//dodanie lini poz i pion
		liniePoziome.insert(nowaLiniaPrawa);
		liniePionowe.insert(nowaLiniaGorna);
		//flow do skasowania
		liniaPionowa->getPunktBlizejX()->setNastepny(ps);//punkt
		ps->setNastepny(nowaLiniaPrawa->getPunktR());//punkt
		nowaLiniaPrawa->getPunktR()->setNastepny(nextPR);//punkt
		liniaPionowa->setNastepny(nowaLiniaPrawa); //linie
		nowaLiniaPrawa->setNastepny(nextLR); //linia
		return nowaLiniaPrawa;
        } else {
        	liniaPozioma->setPunktL(po);
		liniaPozioma->setNastepny(po);
        }




}

