#include"linia.h"
#include"punkt.h"
void dekompozcyajKrzyzowa(Linia* liniaPozioma, Linia* liniaPionowa) {
	float x =0;
	float y =0;

	//utwórz dwa punkty - po(punkt obwiedni), ps(do skasowania)
        Skasowac* poq = new Punkt(x, y);
        Skasowac* psq = new Punkt(x, y);
	Punkt* po = dynamic_cast<Punkt*>(poq);
	Punkt* ps = dynamic_cast<Punkt*>(psq);
        // skróc linie pozioma do punktu przecia
        if(liniaPionowa->getSrodekPo() == "prawej") {
		Linia* lgTmp = liniaPionowa->getNastepny();
		Linia* lrTmp = liniaPozioma->getNastepny();
		Punkt* pgTmp = liniaPionowa->getPunktDalejX()->getNastepny();
		Punkt* prTmp = liniaPozioma->getPunktR()->getNastepny();
		Skasowac* nr = new Linia(ps, liniaPozioma->getPunktR(), "dol");
		Linia* nowaLiniaPrawa = dynamic_cast<Linia*>(nr);
		Skasowac* ng = new Linia(liniaPionowa->getPunktDalejX(), po, "prawej");
		Linia* nowaLiniaGorna = dynamic_cast<Linia*>(ng);
        	liniaPozioma->setPunktR(po);
		liniaPionowa->setPunktDalejX(ps);
		//flow obwiedni
////		Linia* lTmp = 
		liniaPozioma->getPunktL()->setNastepny(po); // punkt
		po->setNastepny(nowaLiniaGorna->getPunktDalejX()); //punkt
		nowaLiniaLewa->setNastepny(nowaLiniaGorna); //linie
		//flow do skasowania
		liniaPionowa->getPunktBlizejX()->setNastepny(ps);//punkt
		ps->setNastepny(liniaPozioma->getPunktR());//punkt
		liniaPionowa->setNastepny(liniaPozioma); //linie
		//dodaj linie do skasowania 	
		//dodaj linie pionowe i poziome do obwiedni	
        } else {
        	liniaPozioma->setPunktL(po);
		liniaPozioma->setNastepny(po);
        }




}

