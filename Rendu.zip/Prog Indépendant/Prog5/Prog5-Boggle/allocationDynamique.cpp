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
	assert(ref_liste.nombreDeMots <= ref_liste.capacite);

	for (unsigned int i = 0; i < ref_liste.nombreDeMots; i++)
	{
		cout << ref_liste.TabDeMots[i] << endl;
	}
}


void detruire(listeDeMots& ref_liste) {
	delete[] ref_liste.TabDeMots;
}



void ecrire(listeDeMots& ref_liste, const Mot& mot) {
	
		if (ref_liste.nombreDeMots >= ref_liste.capacite) {

			int nouvelleTaille = (ref_liste.nombreDeMots + 1) * ref_liste.pasExtension;

			Mot* nouvelleListe = new Mot[nouvelleTaille];

			for (unsigned int j = 0; j < ref_liste.capacite; j++)
			{
				strcpy(nouvelleListe[j], ref_liste.TabDeMots[j]);
			}
			delete[] ref_liste.TabDeMots;
			ref_liste.TabDeMots = nouvelleListe;
			ref_liste.capacite = nouvelleTaille ;

			// Changement du Pas d'Extention en fonction de la taille de la liste
			if (ref_liste.capacite <= 5) { ref_liste.pasExtension = 4; }
			if (ref_liste.capacite <= 20) { ref_liste.pasExtension = 3; }
			if (ref_liste.capacite <= 60) { ref_liste.pasExtension = 2; }

		}

		strcpy(ref_liste.TabDeMots[ref_liste.nombreDeMots], mot);
		ref_liste.nombreDeMots++;

}
