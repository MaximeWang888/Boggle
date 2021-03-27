/*******************************************************
Nom ......... : Structures.h
Auteurs ..... : Fabien RONDAN & Maxime WANG
Version ..... : 1.Release
********************************************************/

#pragma once

#define col 4
#define row 4

typedef char Mot[25 + 1]; 

/** @brief Liste de mots alloués en mémoire dynamique
 *  de capacité extensible suivant un pas d'extension
 */
struct listeDeMots {
	Mot* TabDeMots;		       // tableau de mots alloué en mémoire dynamique
	unsigned int nombreDeMots; // nombre de mots (>0)
	unsigned int capacite; 	   // capacité du conteneur (>0)
	unsigned int pasExtension; // pas d'extension du conteneur (>0)
};


/**
 * @brief Liste de listes de mots alloués en mémoire dynamique
 *  de capacité extensible 
*/
struct List {
	listeDeMots* listOfList;	
	unsigned int nombreDeListes = 0;
	unsigned int capacite = 0; 	   // capacité du conteneur (>0)
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
 * @brief Les coordonnées utilisées pour retrouver la lettre dans la grille
*/
struct Coord {
	int x, y;
};

