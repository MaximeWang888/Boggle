#pragma warning(disable:4996)
#include <iostream>
#include <cassert>
#include "allocationDynamique.h"

using namespace std;


void initialiser(listeDeMots& ref_liste, unsigned int capa, unsigned int p) {
	assert(capa > 0 || p > 0);

	ref_liste.capacite = capa;
	ref_liste.pasExtension = p;
	ref_liste.TabDeMots = new Mot[capa];
	ref_liste.nombreDeMots = 0;
}


void afficher(const listeDeMots& ref_liste) {
	assert(ref_liste.nombreDeMots < ref_liste.capacite);

	for (unsigned int i = 0; i < ref_liste.nombreDeMots; i++)
	{
		cout << ref_liste.TabDeMots[i] << endl;
	}
}


void detruire(listeDeMots& ref_liste) {
	delete[] ref_liste.TabDeMots;
}