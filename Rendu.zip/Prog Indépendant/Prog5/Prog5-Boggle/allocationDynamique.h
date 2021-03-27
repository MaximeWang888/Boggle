#pragma once
#include "listeDeMots.h"


/**
 * @brief Initialise une liste de mots
 * Allocation en m�moire dynamique d'une liste de mots
 * de capacit� (capa) extensible par pas d'extension (p)
 * @see detruire, pour sa d�sallocation en fin d'utilisation
 * @param[out] ref_liste : la liste de mots
 * @param [in] capa : capacit� de la liste
 * @param [in] p : pas d'extension de capacit�
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
 * @brief D�salloue la liste de mots en m�moire dynamique
 * @see initialiser, la liste de mots a d�j� �t� allou�
 * @param[out] ref_liste : la liste de mots
 */
void detruire(listeDeMots& ref_liste);


/**
 * @brief Ecrit le mot en param�tre dans la liste de mots
 * @param ref_liste 
 * @param mot 
*/
void ecrire(listeDeMots& ref_liste, const Mot& mot);