#pragma warning(disable:4996)
#include <iostream>
#include "autresFonctions.h"

using namespace std;


void motTrouver(listeDeMots& ref_liste) {
	bool isAlreadyInput = true;

	while (isAlreadyInput)
	{
		if (ref_liste.nombreDeMots >= ref_liste.capacite) {

			int nouvelleTaille = (ref_liste.nombreDeMots + 1) * ref_liste.pasExtension;

			Mot* nouvelleListe = new Mot[nouvelleTaille];

			for (unsigned int j = 0; j < ref_liste.capacite; j++)
			{
				strcpy(nouvelleListe[j], ref_liste.TabDeMots[j]);
			}
			delete[] ref_liste.TabDeMots;
			ref_liste.TabDeMots = nouvelleListe;
			ref_liste.capacite = nouvelleTaille;

			// Changement du Pas d'Extention en fonction de la taille de la liste
			if (ref_liste.capacite <= 5) { ref_liste.pasExtension = 4; }
			if (ref_liste.capacite <= 20) { ref_liste.pasExtension = 3; }
			if (ref_liste.capacite <= 60) { ref_liste.pasExtension = 2; }

		}

		cin >> ref_liste.TabDeMots[ref_liste.nombreDeMots];
		ref_liste.nombreDeMots++;

		if (strcmp(ref_liste.TabDeMots[ref_liste.nombreDeMots - 1], "*") == 0) {
			isAlreadyInput = false;
		}

	}
}


void afficheScore(listeDeMots& ref_liste) {
	unsigned int nbPoints = 0;

	for (unsigned int i = 0; i < ref_liste.nombreDeMots; i++) {
		unsigned int lenghtofString = strlen(ref_liste.TabDeMots[i]);
		if (lenghtofString >= 8) { nbPoints = nbPoints + 11; }
		if (lenghtofString == 7) { nbPoints = nbPoints + 5; }
		if (lenghtofString == 6) { nbPoints = nbPoints + 3; }
		if (lenghtofString == 5) { nbPoints = nbPoints + 2; }
		if (lenghtofString == 3 || lenghtofString == 4) { nbPoints = nbPoints + 1; }
	}
	cout << nbPoints << endl;
}