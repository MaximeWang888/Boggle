#pragma once
#include "listeDeMots.h"

/**
 * @brief Permet de saisir une liste de mots au clavier.
 * @param [in,out] ref_liste On incr�mente de un le compteur � chaque fois
 * qu'on saisit un mot et on ins�re le mot dans la liste de mots.
*/
void motTrouver(listeDeMots& ref_liste);

/**
 * @brief Affiche � l��cran le nombre de points que la liste de mots repr�sente.
 * @param [in] ref_liste Le conteneur auquel on veut lire les mots pr�sent dans la liste de mots.
*/
void afficheScore(listeDeMots& ref_liste);