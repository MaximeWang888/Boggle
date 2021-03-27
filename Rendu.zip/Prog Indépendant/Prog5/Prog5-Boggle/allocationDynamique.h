#pragma once
#include "listeDeMots.h"


/**
 * @brief Initialise une liste de mots
 * Allocation en mémoire dynamique d'une liste de mots
 * de capacité (capa) extensible par pas d'extension (p)
 * @see detruire, pour sa désallocation en fin d'utilisation
 * @param[out] ref_liste : la liste de mots
 * @param [in] capa : capacité de la liste
 * @param [in] p : pas d'extension de capacité
 * @pre capa>0 et p>0
 */
void initialiser(listeDeMots& ref_liste, unsigned int capa, unsigned int p);


 /**
  * @brief Permet d'afficher la liste de mots.
  * @param [in] ref_liste La liste de mots auquel on va afficher toutes ces valeurs.
  * @pre ref_liste.nombreDeMots < ref_liste.capacite 
 */
void afficher(const listeDeMots& ref_liste);


/**
 * @brief Désalloue la liste de mots en mémoire dynamique
 * @see initialiser, la liste de mots a déjà été alloué
 * @param[out] ref_liste : la liste de mots
 */
void detruire(listeDeMots& ref_liste);


/**
 * @brief Ecrit le mot en paramètre dans la liste de mots
 * @param ref_liste 
 * @param mot 
*/
void ecrire(listeDeMots& ref_liste, const Mot& mot);