/*******************************************************
Nom ......... : Structures.h
Auteurs ..... : Fabien RONDAN & Maxime WANG
Version ..... : 1.Release
********************************************************/

#pragma once

#define col 4
#define row 4

typedef char Mot[25 + 1]; 

/** @brief Liste de mots allou�s en m�moire dynamique
 *  de capacit� extensible suivant un pas d'extension
 */
struct listeDeMots {
	Mot* TabDeMots;		       // tableau de mots allou� en m�moire dynamique
	unsigned int nombreDeMots; // nombre de mots (>0)
	unsigned int capacite; 	   // capacit� du conteneur (>0)
	unsigned int pasExtension; // pas d'extension du conteneur (>0)
};


/**
 * @brief Liste de listes de mots allou�s en m�moire dynamique
 *  de capacit� extensible 
*/
struct List {
	listeDeMots* listOfList;	
	unsigned int nombreDeListes = 0;
	unsigned int capacite = 0; 	   // capacit� du conteneur (>0)
};


/**
 * @brief La grille ou autrement dit le plateau de jeu Boggle
*/
struct Grille{
	char grille[col][row];
	bool grilleBool[col][row];
	unsigned int nombreDeLettres;
};


/**
 * @brief Les coordonn�es utilis�es pour retrouver la lettre dans la grille
*/
struct Coord {
	int x, y;
};

