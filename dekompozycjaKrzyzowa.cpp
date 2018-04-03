#include"dekompozycjaKrzyzowa.h"
#include<cstring>
Linia** dekompozycjaKrzyzowa(Linia* liniaPozioma, Linia* liniaPionowa) {

	float x =  liniaPionowa->getPunktBlizejX()->getX();
	float y = liniaPozioma->getPunktL()->getY();
	Linia* * out = new Linia*[2];
	//utwórz dwa punkty - po(punkt obwiedni), ps(do skasowania)
      //  Skasowac* poq = new Punkt(x, y);
      //  Skasowac* psq = new Punkt(x, y);
	Punkt* po = new Punkt(x, y);
	Punkt* ps = new Punkt(x, y);
        // skróc linie pozioma do punktu przecia
        if(std::strcmp(liniaPionowa->getSrodekPo(), "prawej") == 0) {
		Linia* nextLG = liniaPionowa->getNastepny();
		Linia* nextLR = liniaPozioma->getNastepny();
		Punkt* nextPG = liniaPionowa->getPunktDalejX()->getNastepny();
		Punkt* nextPR = liniaPozioma->getPunktR()->getNastepny();

//		Skasowac* nr = new Linia(ps, liniaPozioma->getPunktR(), "dol");
		Linia* nowaLiniaPrawa = new Linia(ps, liniaPozioma->getPunktR(), "dol");
//		Skasowac* ng = new Linia(po, liniaPionowa->getPunktDalejX(), "prawej");
		Linia* nowaLiniaGorna =  new Linia(po, liniaPionowa->getPunktDalejX(), "prawej");

        	liniaPozioma->setPunktR(po);
		liniaPionowa->setPunktDalejX(ps);
		//flow obwiedni
		liniaPozioma->getPunktL()->setNastepny(po); // punkt
		po->setNastepny(nowaLiniaGorna->getPunktDalejX()); //punkt
		nowaLiniaGorna->getPunktDalejX()->setNastepny(nextPG); //punkt
		liniaPozioma->setNastepny(nowaLiniaGorna); //linia
		nowaLiniaGorna->setNastepny(nextLG); //linia
		//dodanie lini poz i pion
//		liniePoziome.insert(liniaPozioma);
		//flow do skasowania
		liniaPionowa->getPunktBlizejX()->setNastepny(ps);//punkt
		ps->setNastepny(nowaLiniaPrawa->getPunktR());//punkt
		nowaLiniaPrawa->getPunktR()->setNastepny(nextPR);//punkt
		liniaPionowa->setNastepny(nowaLiniaPrawa); //linie
		nowaLiniaPrawa->setNastepny(nextLR); //linia
		out[0] = nowaLiniaPrawa;
		out[1] = nowaLiniaGorna;
		return out;
          } else {

		Linia* nextLD = liniaPionowa->getNastepny();
		Linia* nextLR = liniaPozioma->getNastepny();
		Punkt* nextPD = liniaPionowa->getPunktBlizejX()->getNastepny();
		Punkt* nextPR = liniaPozioma->getPunktR()->getNastepny();

//		Skasowac* nr = new Linia(liniaPozioma->getPunktR(), po, "dol");
		Linia* nowaLiniaPrawa = new Linia(liniaPozioma->getPunktR(), po, "dol");
//		Skasowac* nd = new Linia(ps, liniaPionowa->getPunktBlizejX(), "lewej");
		Linia* nowaLiniaDolna = new Linia(ps, liniaPionowa->getPunktBlizejX(), "lewej");


        	liniaPozioma->setPunktR(ps);
		liniaPionowa->setPunktBlizejX(po);

		//flow obwiedni
		liniaPionowa->getPunktDalejX()->setNastepny(po);
		po->setNastepny(nowaLiniaPrawa->getPunktR());
		nowaLiniaPrawa->getPunktR()->setNastepny(nextPR);
		liniaPionowa->setNastepny(nowaLiniaPrawa);
		nowaLiniaPrawa->setNastepny(nextLR);


		//flow do skasowania
		liniaPozioma->getPunktL()->setNastepny(ps);
		ps->setNastepny(nowaLiniaDolna->getPunktBlizejX());
		nowaLiniaDolna->getPunktBlizejX()->setNastepny(nextPD);
		liniaPozioma->setNastepny(nowaLiniaDolna);
		nowaLiniaDolna->setNastepny(nextLD);
		out[0] = nowaLiniaPrawa;
		out[1] = nowaLiniaDolna;
	//	liniePoziome->insert(nowaLiniaPrawa);
		return out;

	}



}

