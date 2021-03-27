/*******************************************************
Nom ......... : Exos.cpp
Auteurs ..... : Fabien RONDAN & Maxime WANG
Version ..... : 1.Release
********************************************************/

#pragma warning(disable:4996)

#include "listeDeMots.h"
#include "List.h"
#include "Grille.h"


void exo1() {
	listeDeMots liste;

	initialiser(liste, 1, 5);
	motTrouver(liste);
	afficheScore(liste);
	detruire(liste);
}

void exo2() {
	listeDeMots liste;

	initialiser(liste, 1, 5);
	motTrouver(liste);

	tri(liste);
	supprimeDoublons(liste);
	afficher(liste);
	detruire(liste);
}

void exo3() {
	listeDeMots liste, liste2;

	initialiser(liste, 1, 5);
	initialiser(liste2, 1, 5);
	motTrouver(liste);
	motTrouver(liste2);

	tri(liste);
	supprimeDoublons(liste);
	tri(liste2);
	supprimeDoublons(liste2);

	showCommomWord(liste, liste2, false);

	detruire(liste);
	detruire(liste2);
}

void exo4() {
	listeDeMots liste, liste2;

	initialiser(liste, 1, 5);
	initialiser(liste2, 1, 5);
	motTrouver(liste);
	motTrouver(liste2);

	tri(liste2);
	supprimeDoublons(liste2);

	showCommomWord(liste, liste2);

	detruire(liste);
	detruire(liste2);
}

void exo5() {
	List listOfLists;
	listeDeMots finalWordList;
	initialiser(finalWordList, 1, 5);

	ajouterListe(listOfLists);
	showCommonWordList(listOfLists, finalWordList);
	tri(finalWordList);

	supprimeDoublons(finalWordList);
	afficher(finalWordList);

	detruire(finalWordList);

	for (int i = 0; i < listOfLists.nombreDeListes; i++) {

		detruire(listOfLists.listOfList[i]);

	}
}

void exo6() {
	listeDeMots liste;
	Grille grille;

	ecrireGrille(grille);

	initialiser(liste, 1, 5);
	motDansGrille(liste, grille);

	tri(liste);
	supprimeDoublons(liste);
	afficher(liste);

	detruire(liste);
}


