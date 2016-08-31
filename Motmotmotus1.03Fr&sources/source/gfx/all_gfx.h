//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .h, for easier inclusion in a project

#ifndef ALL_GFX_H
#define ALL_GFX_H

#ifndef PAGfx_struct
    typedef struct{
    void *Map;
    int MapSize;
    void *Tiles;
    int TileSize;
    void *Palette;
    int *Info;
} PAGfx_struct;
#endif


// Sprite files : 
extern const unsigned char rond_16x16_choix_nbr_lettre_Sprite[256] __attribute__ ((aligned (4))) ;  // Pal : rond_16x16_choix_nbr_lettre_Pal
extern const unsigned char joueurs_64x64_choix_joueurs_Sprite[8192] __attribute__ ((aligned (4))) ;  // Pal : joueurs_64x64_choix_joueurs_Pal
extern const unsigned char joueurs_32x32_choix_joueurs_petit_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : joueurs_32x32_choix_joueurs_petit_Pal
extern const unsigned char touche_64x32_choix_lettres_Sprite[4096] __attribute__ ((aligned (4))) ;  // Pal : touche_64x32_choix_lettres_Pal
extern const unsigned char case_16x16_valide_rouge_jaune_Sprite[512] __attribute__ ((aligned (4))) ;  // Pal : case_16x16_valide_rouge_jaune_Pal
extern const unsigned char resul_64x32_solution1_2_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : resul_64x32_solution1_2_Pal
extern const unsigned char resul_32x32_solution2_2_Sprite[1024] __attribute__ ((aligned (4))) ;  // Pal : resul_32x32_solution2_2_Pal
extern const unsigned char touche_64x32_play_menu_Sprite[12288] __attribute__ ((aligned (4))) ;  // Pal : touche_64x32_play_menu_Pal
extern const unsigned char curseur_16x16_Sprite[1280] __attribute__ ((aligned (4))) ;  // Pal : curseur_16x16_Pal
extern const unsigned char factice_32x32_Sprite[1024] __attribute__ ((aligned (4))) ;  // Pal : factice_32x32_Pal

// Background files : 
extern const int bg2_bas_menu0_Info[3]; // BgMode, Width, Height
extern const unsigned short bg2_bas_menu0_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_menu0_Pal
extern const unsigned char bg2_bas_menu0_Tiles[64] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_menu0_Pal
extern PAGfx_struct bg2_bas_menu0; // background pointer

extern const int bg2_bas_menu1_Info[3]; // BgMode, Width, Height
extern const unsigned short bg2_bas_menu1_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_menu1_Pal
extern const unsigned char bg2_bas_menu1_Tiles[1664] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_menu1_Pal
extern PAGfx_struct bg2_bas_menu1; // background pointer

extern const int bg2_bas_menu2_Info[3]; // BgMode, Width, Height
extern const unsigned short bg2_bas_menu2_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_menu2_Pal
extern const unsigned char bg2_bas_menu2_Tiles[2368] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_menu2_Pal
extern PAGfx_struct bg2_bas_menu2; // background pointer

extern const int bg2_bas_menu3_Info[3]; // BgMode, Width, Height
extern const unsigned short bg2_bas_menu3_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_menu3_Pal
extern const unsigned char bg2_bas_menu3_Tiles[1920] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_menu3_Pal
extern PAGfx_struct bg2_bas_menu3; // background pointer

extern const int bg2_bas_menu4_Info[3]; // BgMode, Width, Height
extern const unsigned short bg2_bas_menu4_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_menu4_Pal
extern const unsigned char bg2_bas_menu4_Tiles[1792] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_menu4_Pal
extern PAGfx_struct bg2_bas_menu4; // background pointer

extern const int bg2_bas_jeu1_Info[3]; // BgMode, Width, Height
extern const unsigned short bg2_bas_jeu1_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_jeu1_Pal
extern const unsigned char bg2_bas_jeu1_Tiles[1728] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_jeu1_Pal
extern PAGfx_struct bg2_bas_jeu1; // background pointer

extern const int bg2_bas_jeu2_Info[3]; // BgMode, Width, Height
extern const unsigned short bg2_bas_jeu2_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_jeu2_Pal
extern const unsigned char bg2_bas_jeu2_Tiles[1792] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_jeu2_Pal
extern PAGfx_struct bg2_bas_jeu2; // background pointer

extern const int bg2_bas_jeu3_Info[3]; // BgMode, Width, Height
extern const unsigned short bg2_bas_jeu3_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_jeu3_Pal
extern const unsigned char bg2_bas_jeu3_Tiles[2048] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_jeu3_Pal
extern PAGfx_struct bg2_bas_jeu3; // background pointer

extern const int bg2_bas_jeu4_Info[3]; // BgMode, Width, Height
extern const unsigned short bg2_bas_jeu4_Map[768] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_jeu4_Pal
extern const unsigned char bg2_bas_jeu4_Tiles[1984] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_jeu4_Pal
extern PAGfx_struct bg2_bas_jeu4; // background pointer

extern const int bg2_haut_jeu_commun_Info[3]; // BgMode, Width, Height
extern const unsigned short bg2_haut_jeu_commun_Map[1024] __attribute__ ((aligned (4))) ;  // Pal : bg2_haut_jeu_commun_Pal
extern const unsigned char bg2_haut_jeu_commun_Tiles[2880] __attribute__ ((aligned (4))) ;  // Pal : bg2_haut_jeu_commun_Pal
extern PAGfx_struct bg2_haut_jeu_commun; // background pointer

extern const int bg2_bas_commun_jeux_Info[3]; // BgMode, Width, Height
extern const unsigned short bg2_bas_commun_jeux_Map[1024] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_commun_jeux_Pal
extern const unsigned char bg2_bas_commun_jeux_Tiles[320] __attribute__ ((aligned (4))) ;  // Pal : bg2_bas_commun_jeux_Pal
extern PAGfx_struct bg2_bas_commun_jeux; // background pointer

extern const int bg1_chiffres_lettres_grilles_Info[3]; // BgMode, Width, Height
extern const unsigned short bg1_chiffres_lettres_grilles_Map[1024] __attribute__ ((aligned (4))) ;  // Pal : bg1_chiffres_lettres_grilles_Pal
extern const unsigned char bg1_chiffres_lettres_grilles_Tiles[13440] __attribute__ ((aligned (4))) ;  // Pal : bg1_chiffres_lettres_grilles_Pal
extern PAGfx_struct bg1_chiffres_lettres_grilles; // background pointer


// Palette files : 
extern const unsigned short rond_16x16_choix_nbr_lettre_Pal[11] __attribute__ ((aligned (4))) ;
extern const unsigned short joueurs_64x64_choix_joueurs_Pal[212] __attribute__ ((aligned (4))) ;
extern const unsigned short joueurs_32x32_choix_joueurs_petit_Pal[166] __attribute__ ((aligned (4))) ;
extern const unsigned short touche_64x32_choix_lettres_Pal[11] __attribute__ ((aligned (4))) ;
extern const unsigned short case_16x16_valide_rouge_jaune_Pal[3] __attribute__ ((aligned (4))) ;
extern const unsigned short resul_64x32_solution1_2_Pal[18] __attribute__ ((aligned (4))) ;
extern const unsigned short resul_32x32_solution2_2_Pal[18] __attribute__ ((aligned (4))) ;
extern const unsigned short touche_64x32_play_menu_Pal[63] __attribute__ ((aligned (4))) ;
extern const unsigned short curseur_16x16_Pal[2] __attribute__ ((aligned (4))) ;
extern const unsigned short factice_32x32_Pal[2] __attribute__ ((aligned (4))) ;
extern const unsigned short bg2_bas_menu0_Pal[1] __attribute__ ((aligned (4))) ;
extern const unsigned short bg2_bas_menu1_Pal[23] __attribute__ ((aligned (4))) ;
extern const unsigned short bg2_bas_menu2_Pal[23] __attribute__ ((aligned (4))) ;
extern const unsigned short bg2_bas_menu3_Pal[23] __attribute__ ((aligned (4))) ;
extern const unsigned short bg2_bas_menu4_Pal[23] __attribute__ ((aligned (4))) ;
extern const unsigned short bg2_bas_jeu1_Pal[15] __attribute__ ((aligned (4))) ;
extern const unsigned short bg2_bas_jeu2_Pal[16] __attribute__ ((aligned (4))) ;
extern const unsigned short bg2_bas_jeu3_Pal[15] __attribute__ ((aligned (4))) ;
extern const unsigned short bg2_bas_jeu4_Pal[15] __attribute__ ((aligned (4))) ;
extern const unsigned short bg2_haut_jeu_commun_Pal[76] __attribute__ ((aligned (4))) ;
extern const unsigned short bg2_bas_commun_jeux_Pal[14] __attribute__ ((aligned (4))) ;
extern const unsigned short bg1_chiffres_lettres_grilles_Pal[12] __attribute__ ((aligned (4))) ;


#endif

