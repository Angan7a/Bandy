#include"wierzcholek.h"
//#include"linia.h"
//#include"punkt.h"

Wierzcholek::Wierzcholek(Punkt p , Linia* l1, Linia* l2, Wierzcholek* nastepny, Wierzcholek* poprzedni) : p(p), l1(l1), l2(l2), nastepny(nastepny), poprzedni(poprzedni) { 
}

