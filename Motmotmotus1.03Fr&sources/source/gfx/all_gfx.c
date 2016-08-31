//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .c, for easier inclusion in a project

#ifdef __cplusplus
extern "C" {
#endif

#include "all_gfx.h"


// Sprite files : 
#include "rond_16x16_choix_nbr_lettre.c"
#include "joueurs_64x64_choix_joueurs.c"
#include "joueurs_32x32_choix_joueurs_petit.c"
#include "touche_64x32_choix_lettres.c"
#include "case_16x16_valide_rouge_jaune.c"
#include "resul_64x32_solution1_2.c"
#include "resul_32x32_solution2_2.c"
#include "touche_64x32_play_menu.c"
#include "curseur_16x16.c"
#include "factice_32x32.c"

// Background files : 
#include "bg2_bas_menu0.c"
#include "bg2_bas_menu1.c"
#include "bg2_bas_menu2.c"
#include "bg2_bas_menu3.c"
#include "bg2_bas_menu4.c"
#include "bg2_bas_jeu1.c"
#include "bg2_bas_jeu2.c"
#include "bg2_bas_jeu3.c"
#include "bg2_bas_jeu4.c"
#include "bg2_haut_jeu_commun.c"
#include "bg2_bas_commun_jeux.c"
#include "bg1_chiffres_lettres_grilles.c"

// Palette files : 
#include "rond_16x16_choix_nbr_lettre.pal.c"
#include "joueurs_64x64_choix_joueurs.pal.c"
#include "joueurs_32x32_choix_joueurs_petit.pal.c"
#include "touche_64x32_choix_lettres.pal.c"
#include "case_16x16_valide_rouge_jaune.pal.c"
#include "resul_64x32_solution1_2.pal.c"
#include "resul_32x32_solution2_2.pal.c"
#include "touche_64x32_play_menu.pal.c"
#include "curseur_16x16.pal.c"
#include "factice_32x32.pal.c"
#include "bg2_bas_menu0.pal.c"
#include "bg2_bas_menu1.pal.c"
#include "bg2_bas_menu2.pal.c"
#include "bg2_bas_menu3.pal.c"
#include "bg2_bas_menu4.pal.c"
#include "bg2_bas_jeu1.pal.c"
#include "bg2_bas_jeu2.pal.c"
#include "bg2_bas_jeu3.pal.c"
#include "bg2_bas_jeu4.pal.c"
#include "bg2_haut_jeu_commun.pal.c"
#include "bg2_bas_commun_jeux.pal.c"
#include "bg1_chiffres_lettres_grilles.pal.c"

// Background Pointers :
PAGfx_struct bg2_bas_menu0 = {(void*)bg2_bas_menu0_Map, 768, (void*)bg2_bas_menu0_Tiles, 64, (void*)bg2_bas_menu0_Pal, (int*)bg2_bas_menu0_Info };
PAGfx_struct bg2_bas_menu1 = {(void*)bg2_bas_menu1_Map, 768, (void*)bg2_bas_menu1_Tiles, 1664, (void*)bg2_bas_menu1_Pal, (int*)bg2_bas_menu1_Info };
PAGfx_struct bg2_bas_menu2 = {(void*)bg2_bas_menu2_Map, 768, (void*)bg2_bas_menu2_Tiles, 2368, (void*)bg2_bas_menu2_Pal, (int*)bg2_bas_menu2_Info };
PAGfx_struct bg2_bas_menu3 = {(void*)bg2_bas_menu3_Map, 768, (void*)bg2_bas_menu3_Tiles, 1920, (void*)bg2_bas_menu3_Pal, (int*)bg2_bas_menu3_Info };
PAGfx_struct bg2_bas_menu4 = {(void*)bg2_bas_menu4_Map, 768, (void*)bg2_bas_menu4_Tiles, 1792, (void*)bg2_bas_menu4_Pal, (int*)bg2_bas_menu4_Info };
PAGfx_struct bg2_bas_jeu1 = {(void*)bg2_bas_jeu1_Map, 768, (void*)bg2_bas_jeu1_Tiles, 1728, (void*)bg2_bas_jeu1_Pal, (int*)bg2_bas_jeu1_Info };
PAGfx_struct bg2_bas_jeu2 = {(void*)bg2_bas_jeu2_Map, 768, (void*)bg2_bas_jeu2_Tiles, 1792, (void*)bg2_bas_jeu2_Pal, (int*)bg2_bas_jeu2_Info };
PAGfx_struct bg2_bas_jeu3 = {(void*)bg2_bas_jeu3_Map, 768, (void*)bg2_bas_jeu3_Tiles, 2048, (void*)bg2_bas_jeu3_Pal, (int*)bg2_bas_jeu3_Info };
PAGfx_struct bg2_bas_jeu4 = {(void*)bg2_bas_jeu4_Map, 768, (void*)bg2_bas_jeu4_Tiles, 1984, (void*)bg2_bas_jeu4_Pal, (int*)bg2_bas_jeu4_Info };
PAGfx_struct bg2_haut_jeu_commun = {(void*)bg2_haut_jeu_commun_Map, 1024, (void*)bg2_haut_jeu_commun_Tiles, 2880, (void*)bg2_haut_jeu_commun_Pal, (int*)bg2_haut_jeu_commun_Info };
PAGfx_struct bg2_bas_commun_jeux = {(void*)bg2_bas_commun_jeux_Map, 1024, (void*)bg2_bas_commun_jeux_Tiles, 320, (void*)bg2_bas_commun_jeux_Pal, (int*)bg2_bas_commun_jeux_Info };
PAGfx_struct bg1_chiffres_lettres_grilles = {(void*)bg1_chiffres_lettres_grilles_Map, 1024, (void*)bg1_chiffres_lettres_grilles_Tiles, 13440, (void*)bg1_chiffres_lettres_grilles_Pal, (int*)bg1_chiffres_lettres_grilles_Info };


#ifdef __cplusplus
}
#endif

