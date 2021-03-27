#pragma once

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

