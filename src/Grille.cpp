/*******************************************************
Nom ......... : Grille.cpp
Auteurs ..... : Fabien RONDAN & Maxime WANG
Version ..... : 1.Release
********************************************************/

#pragma warning(disable:4996)
#include <iostream>

#include "listeDeMots.h"
#include "Grille.h"

using namespace std;

void ecrireGrille(Grille& ref_grille) {

	for (int i = 0; i < col; i++) {

		for (int j = 0; j < row; j++) {

			cin >> ref_grille.grille[i][j];
			ref_grille.nombreDeLettres++;
		}

	}

}


void motDansGrille(listeDeMots& ref_liste, Grille& ref_grille) {
	bool isAlreadyInput = true;

	while (isAlreadyInput)
	{
		listeDynamique(ref_liste);

		Mot tmpString;
		cin >> tmpString;

		if (recherche(tmpString, ref_grille)) {
			strcpy(ref_liste.TabDeMots[ref_liste.nombreDeMots], tmpString);
			ref_liste.nombreDeMots++;
		}

		if (strcmp(tmpString, "*") == 0) {
			strcpy(ref_liste.TabDeMots[ref_liste.nombreDeMots], tmpString);
			ref_liste.nombreDeMots++;
			isAlreadyInput = false;
		}

	}
}


bool recherche(Mot& string, Grille& ref_grille) {
	Coord coord;

	resetToFalse(ref_grille);

	for (int x = 0; x < col; x++)
	{
		for (int y = 0; y < row; y++)
		{
			coord.x = x;
			coord.y = y;
			if (SousRecherche(ref_grille, string, 0, coord))
				return true;
		}
	}

	return false;
}


void resetToFalse(Grille& ref_grille) {

	for (int i = 0; i < col; i++)
	{
		for (int y = 0; y < row; y++)
		{
			ref_grille.grilleBool[i][y] = false;
		}
	}

}


bool SousRecherche(Grille& ref_grille, Mot& string, unsigned int pos, Coord& coord) {

	if (pos >= strlen(string))
		return true;
	if (coord.x >= col || coord.y >= row)
		return false;
	if (ref_grille.grille[coord.x][coord.y] != string[pos])
		return false;
	if (ref_grille.grilleBool[coord.x][coord.y] == true)
		return false;

	ref_grille.grilleBool[coord.x][coord.y] = true;


	for (int ligne = max(0, coord.x - 1); ligne <= coord.x + 1; ligne++) {

		for (int colonne = max(0, coord.y - 1); colonne <= coord.y + 1; colonne++) {

			Coord newCoord;
			newCoord.x = ligne;
			newCoord.y = colonne;
			if (SousRecherche(ref_grille, string, pos + 1, newCoord))
				return true;

		}
	}

	ref_grille.grilleBool[coord.x][coord.y] = false;
	return false;
}