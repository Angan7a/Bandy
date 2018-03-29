
#ifndef dekompozycjaKrzyzowa_hpp
#define dekompozycjaKrzyzowa_hpp

#include"linia.h"
#include"punkt.h"
#include<set>

Linia* dekompozcyajKrzyzowa(Linia* liniaPozioma, Linia* liniaPionowa, std::set<Linia*>& liniePionowe, std::set<Linia*>& liniePoziome);


#endif




