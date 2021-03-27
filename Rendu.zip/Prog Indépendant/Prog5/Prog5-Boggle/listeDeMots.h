#pragma once

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

