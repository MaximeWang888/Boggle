/*******************************************************
Nom ......... : Grille.h
Auteurs ..... : Fabien RONDAN & Maxime WANG
Version ..... : 1.Release
********************************************************/

#pragma once
#include "Structures.h"


/**
 * @brief Ecrire les lettres dans la grille de Boggle.
 * @param [out] ref_grille : La grille dans laquelle on �crit les lettres.
*/
void ecrireGrille(Grille& ref_grille);


/**
 * @brief Marquer toutes les lettres de la grille comme �tant non visit�es par un booleen "false".
 * @param [out] ref_grille : La grille auquel on marque toutes les cases comme �tant non visit�es.
*/
void resetToFalse(Grille& ref_grille);


/**
 * @brief Renvoie "true" si le mot se trouve dans la grille sinon renvoie "false".
 * @param [in] string : Le mot auquel on v�rifie s'il existe dans la grille.
 * @param [in, out] ref_grille : La grille auquel on va v�rifier si le mot existe dans cette grille.
 * @return Un Boolean soit "true" soit "false".
*/
bool recherche(Mot& string, Grille& ref_grille);


/**
 * @brief Renvoie "true" si la lettre du mot 'String' qui a pour coordonn�e coord se trouve dans
 * la grille et impl�mente +1 � la position pos du mot sinon Renvoie "false" et d�cr�mente -1 � la
 * position pos du mot.
 * @param [in, out] ref_grille : La grille qui permet de v�rifier si le mot se trouve dans celle-ci et
 * si c'est le cas alors on marque la lettre de la grille comme �tant visit�e.
 * @param [in] string : Le mot auquel on v�rifie s'il se trouve dans la grille Boggle.
 * @param [in, out] pos : La position de la lettre dans le mot auquel on incr�mente de 1
 * si il se trouve dans la grille et correspond au mot string.
 * @param [in, out] coord : Elle d�signe une case de la grille auquel on utilise pour retrouver la lettre
 * � cette coordonn�e et on va changer ses coordonn�es si la lettre est pr�sente dans la grille.
 * @return Un Boolean soit "true" soit "false".
*/
bool SousRecherche(Grille& ref_grille, Mot& string, unsigned int pos, Coord& coord);


/**
 * @brief Permet de stocker les mots qui existent dans la grille dans la liste de mots.
 * @param [in, out] ref_liste : La liste de mots auquel on va ins�rer tous les mots qui existe dans la grille
 * dans la liste de mots "ref_liste" et alloue plus de capacit� en m�moire si le nombre de mots >= la capacit�.
 * @param [in] ref_grille : La grille Boggle auquel on va v�rifier si le mot dans la liste de mot
 * existe dans la grille.
*/
void motDansGrille(listeDeMots& ref_liste, Grille& ref_grille);