/*******************************************************
Nom ......... : List.h
Auteurs ..... : Fabien RONDAN & Maxime WANG
Version ..... : 1.Release
********************************************************/

#pragma once
#include "Structures.h"


/**
 * @brief Ajoute la liste de mots saisie au clavier � la grande liste "listOfLists".
 * @param [in, out] ref_list : La liste des listes de mots auquel on va ins�rer des listes de mots
 * et incr�mente de un (+1) le nombre de listes � chaque fois qu'une liste de mots se termine.
*/
void ajouterListe(List& ref_list);


/**
 * @brief Renvoie "true" si le mot de la premi�re liste apparait dans la seconde,
 * renvoie "false" si le mot de la premi�re liste n'apparait pas dans la seconde.
 * @param [in] ref_list : La grande liste des listes de mots auquel on va s'en servir 
 * pour avoir le mot de la liste souhait�.
 * @param [in] idxList : L'indice de la liste courante.
 * @param [in] nextIdxList : L'indice de la liste suivante.
 * @param [in] i : L'indice du mot auquel on va le comparer avec les mots d'une liste.
 * @return Un Boolean soit "true" soit "false".
*/
bool compare2(List& ref_list, unsigned int& idxList, unsigned int& nextIdxList, const unsigned int i);


/**
 * @brief Permet d'ins�rer dans la liste "finalWordList" tous les mots apparaissant 
 * dans au moins deux listes de mots. 
 * @param [in] ref_list : La liste des listes de mots auquel on va v�rifier les mots en communs
 * qui se retrouve dans au moins deux listes.
 * @param [in] idxList : L'indice de la liste compar�.
 * @param [in] nextIdxList : L'indice de la liste compar�.
 * @param [out] finalWordList : La liste auquel on va ins�rer tous les mots en communs dans au moins deux listes.
*/
void saveCommonWordList(List& ref_list, unsigned int& idxList, unsigned int& nextIdxList, listeDeMots& finalWordList);


/**
 * @brief Affiche la liste de mots "finalWordList" auquel on a ins�r� les mots en communs des diff�rentes listes de mots.
 * @param [in] listOfWord : La liste des listes de mots auquel on va v�rifier les mots en communs
 * qui se retrouve dans au moins deux listes.
 * @param [out] finalWordList : La liste de mots auquel on va ins�rer tous les mots en communs dans au moins deux listes.
*/
void showCommonWordList(List& listOfWord, listeDeMots& finalWordList);




