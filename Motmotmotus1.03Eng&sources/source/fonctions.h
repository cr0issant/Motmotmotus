

void temporisation(u16 temps)
{
	u16 z = 0;
	while (z < temps)
	{
		z++;
		PA_WaitForVBL();
	}
}



void afficher_case_bas(u8 colonnes, s8 position_cadreX)
{
	PA_SetMapTileEx(0,2,	8+colonnes + position_cadreX,	6,	bg2_haut_jeu_commun_Map[1],0,0,0);
	PA_SetMapTileEx(0,2,	8+colonnes+1 + position_cadreX,	6,	bg2_haut_jeu_commun_Map[2],0,0,0);
	PA_SetMapTileEx(0,2,	8+colonnes + position_cadreX,	6+1,	bg2_haut_jeu_commun_Map[3],0,0,0);
	PA_SetMapTileEx(0,2,	8+colonnes+1 + position_cadreX,	6+1,	bg2_haut_jeu_commun_Map[4],0,0,0);
}



void afficher_case_bas_vide( u8  boucleEFF, u8 lignes)
{
	PA_SetMapTileEx(0,1,	4+boucleEFF,		6+lignes,	bg2_haut_jeu_commun_Map[0],0,0,0);
	PA_SetMapTileEx(0,1,	4+boucleEFF+1,		6+lignes,	bg2_haut_jeu_commun_Map[0],0,0,0);
	PA_SetMapTileEx(0,1,	4+boucleEFF,		6+lignes+1,	bg2_haut_jeu_commun_Map[0],0,0,0);
	PA_SetMapTileEx(0,1,	4+boucleEFF+1,		6+lignes+1,	bg2_haut_jeu_commun_Map[0],0,0,0);
}


void afficher_case(u8 colonnes, u8 lignes, s8 position_cadreX)
{
	PA_SetMapTileEx(1,2,	5+colonnes + position_cadreX,		9+lignes,	bg2_haut_jeu_commun_Map[5],0,0,0);
	PA_SetMapTileEx(1,2,	5+colonnes+1 + position_cadreX,		9+lignes,	bg2_haut_jeu_commun_Map[6],0,0,0);
	PA_SetMapTileEx(1,2,	5+colonnes + position_cadreX,		9+lignes+1,	bg2_haut_jeu_commun_Map[7],0,0,0);
	PA_SetMapTileEx(1,2,	5+colonnes+1 + position_cadreX,		9+lignes+1,	bg2_haut_jeu_commun_Map[8],0,0,0);
}

void afficher_case_vide( u8  boucleEFF, u8 lignes)
{
	PA_SetMapTileEx(1,1,	1+boucleEFF,		9+lignes,	bg2_haut_jeu_commun_Map[0],0,0,0);
	PA_SetMapTileEx(1,1,	1+boucleEFF+1,		9+lignes,	bg2_haut_jeu_commun_Map[0],0,0,0);
	PA_SetMapTileEx(1,1,	1+boucleEFF,		9+lignes+1,	bg2_haut_jeu_commun_Map[0],0,0,0);
	PA_SetMapTileEx(1,1,	1+boucleEFF+1,		9+lignes+1,	bg2_haut_jeu_commun_Map[0],0,0,0);
}




void effet_lumiere_masquer(u8 ecranhaut, u8 ecranbas)
{
	s8 a;
	for (a = 0; a >= -16; a--)
	{
		if (ecranhaut == 1) {PA_SetBrightness(1, a);}
		if (ecranbas == 1) {PA_SetBrightness(0, a);}
		PA_WaitForVBL();
		PA_WaitForVBL();
	}
}


void effet_lumiere_voir(u8 ecranhaut, u8 ecranbas)
{
	s8 a;
	for (a = -16; a <= 0; a++)
	{
		if (ecranhaut == 1) {PA_SetBrightness(1, a);}
		if (ecranbas == 1) {PA_SetBrightness(0, a);}
		PA_WaitForVBL();
		PA_WaitForVBL();
	}
}



void chrono (void)
{

	u8 decalage = 0;
	if (( nbre_lettres == 6 ) && ( nbre_lettres == 7 )) { decalage=0; }
	if ( nbre_lettres == 8 ) { decalage=2; }
	if ( nbre_lettres == 9 ) { decalage=4; }

	
	centieme+=1;

	PA_SetSpriteAnim(0, 7, centieme/15);
	PA_SetSpriteXY(0, 7, 64 + colonnes*8 - decalage*8, 60);


	if ( centieme >= 60 ) {ScoreSecond[0]+=1; second+=1; centieme = 0; }
	if ( second >= 60 )  { minute+=1; second=0;}


	PA_SetMapTileEx(1,1,	23,	12,	bg1_chiffres_lettres_grilles_Map[ 2 +  (256) + minute/10  ],0,0,0);
	PA_SetMapTileEx(1,1,	24,	12,	bg1_chiffres_lettres_grilles_Map[ 2 +  (256) + minute - minute/10*10  ],0,0,0);


	PA_SetMapTileEx(1,1,	26,	12,	bg1_chiffres_lettres_grilles_Map[ 2 +  (256) + second/10  ],0,0,0);
	PA_SetMapTileEx(1,1,	27,	12,	bg1_chiffres_lettres_grilles_Map[ 2 +  (256) + second - second/10*10  ],0,0,0);


	PA_SetMapTileEx(1,1,	25,	12,	bg1_chiffres_lettres_grilles_Map[ 256+1  ],0,0,0);
	if ( centieme >= 30 )
	{
	PA_SetMapTileEx(1,1,	25,	12,	bg1_chiffres_lettres_grilles_Map[ 0  ],0,0,0);
	}			

}


void compte_A_rebours (void)
{

	u8 decalage = 0;
	if (( nbre_lettres == 6 ) && ( nbre_lettres == 7 )) { decalage=0; }
	if ( nbre_lettres == 8 ) { decalage=2; }
	if ( nbre_lettres == 9 ) { decalage=4; }

	
	angle &= 511;
	centieme++;

	PA_SetSpriteAnim(0, 7, centieme/15);
	PA_SetSpriteXY(0, 7, 64 + colonnes*8 - decalage*8, 60);

	if ( centieme >= 60 ) {second-=1; centieme = 0; }
	if ( second <= -1 )  { minute-=1; second=59;}
	if ( ( centieme == 0 )&&( second == 0 )&&( minute == 0 )&&(joueur == 1 ) ) 
	{ 
		son_change();
		PA_SetSpriteAnim(1, 67, 1); PA_SetSpriteXY(1, 67, 176, 8 );minute=1; second=59; joueur=2;
		for ( angle=0; angle < 511; angle+=50 ) { PA_SetRotsetNoZoom(1, 0, angle); PA_SetRotsetNoZoom(1, 1, angle);PA_WaitForVBL(); }
		PA_SetRotsetNoZoom(1, 0, 0);PA_SetRotsetNoZoom(1, 1, 0);
 		PA_SetSpriteAnim(1, 1, 0); PA_SetSpriteXY(1, 1, 176+48, 8+48 );
		PA_SetMapTileEx(1,2,22+1,9+0,bg2_haut_jeu_commun_Map[9+2*32],0,0,0);
		PA_SetMapTileEx(1,2,22+2,9+0,bg2_haut_jeu_commun_Map[10+2*32],0,0,0);

		PA_SetMapTileEx(1,2,22+6,9+5,bg2_haut_jeu_commun_Map[24+manche],0,0,0);
	}
	if ( ( centieme == 0 )&&( second == 0 )&&( minute == 0 )&&(joueur == 2 ) ) 
	{ 
		son_change();
		PA_SetSpriteAnim(1, 67, 0); PA_SetSpriteXY(1, 67, 176, 8 );minute=1; second=59; joueur=1; manche+=1;
		for ( angle=0; angle < 511; angle+=50 ) { PA_SetRotsetNoZoom(1, 0, angle); PA_SetRotsetNoZoom(1, 1, angle);PA_WaitForVBL(); }
		PA_SetRotsetNoZoom(1, 0, 0);PA_SetRotsetNoZoom(1, 1, 0);
 		PA_SetSpriteAnim(1, 1, 1); PA_SetSpriteXY(1, 1, 176+48, 8+48 );
		PA_SetMapTileEx(1,2,22+1,9+0,bg2_haut_jeu_commun_Map[12],0,0,0);
		PA_SetMapTileEx(1,2,22+2,9+0,bg2_haut_jeu_commun_Map[13],0,0,0);

		PA_SetMapTileEx(1,2,22+6,9+5,bg2_haut_jeu_commun_Map[24+manche],0,0,0);
	}



	PA_SetMapTileEx(1,1,	23,	12,	bg1_chiffres_lettres_grilles_Map[ 2 +  (256) + minute/10  ],0,0,0);
	PA_SetMapTileEx(1,1,	24,	12,	bg1_chiffres_lettres_grilles_Map[ 2 +  (256) + minute - minute/10*10  ],0,0,0);


	PA_SetMapTileEx(1,1,	26,	12,	bg1_chiffres_lettres_grilles_Map[ 2 +  (256) + second/10  ],0,0,0);
	PA_SetMapTileEx(1,1,	27,	12,	bg1_chiffres_lettres_grilles_Map[ 2 +  (256) + second - second/10*10  ],0,0,0);


	PA_SetMapTileEx(1,1,	25,	12,	bg1_chiffres_lettres_grilles_Map[ 256+1  ],0,0,0);
	if ( centieme >= 30 )
	{
	PA_SetMapTileEx(1,1,	25,	12,	bg1_chiffres_lettres_grilles_Map[ 0  ],0,0,0);
	}			

}


void compte_point1 (u8 point_j1)
{
	u8 diz_point_j1;
	diz_point_j1 = point_j1/10;


	PA_SetMapTileEx(1,1,	27,	18,	bg1_chiffres_lettres_grilles_Map[ 2 + 256 + 32 + diz_point_j1  ],0,0,0);
	PA_SetMapTileEx(1,1,	28,	18,	bg1_chiffres_lettres_grilles_Map[ 2 + 256 + 32 + point_j1 - diz_point_j1*10  ],0,0,0);


}

void compte_point2 (u8 point_j2)
{
	u8 diz_point_j2;
	diz_point_j2 = point_j2/10;


	PA_SetMapTileEx(1,1,	27,	18+3,	bg1_chiffres_lettres_grilles_Map[ 2 + 256 + 2*32 + diz_point_j2  ],0,0,0);
	PA_SetMapTileEx(1,1,	28,	18+3,	bg1_chiffres_lettres_grilles_Map[ 2 + 256 + 2*32 + point_j2 - diz_point_j2*10  ],0,0,0);


}



void attente_ou_touche(u16 temps)
{
	u16 z = 0;
	while (z < temps)
	{
		z++;
		//test stylus ou pad
		if(Stylus.Newpress || Pad.Newpress.A) {z = temps;}
		PA_WaitForVBL();
	}
	Stylus.Newpress = false;
	Pad.Newpress.A = false;
}

void pause()
{
	Stylus.Newpress = false;
	Pad.Newpress.Select = false;
	u8 z=0;
	while(z==0)
	{
		PA_WaitForVBL();
		if (Stylus.Newpress || Pad.Newpress.Anykey) {z=1;}
	}
	Stylus.Newpress = false;
	Pad.Newpress.Anykey = false;
}






u8 AFFmode_1joueur [8*10] =

{
	0, 12, 13,  0, 0, 0, 0, 0,
	0,  0,  0,  0, 0, 0, 0, 0,
	0,  0,  0,  0, 0, 0, 0, 0,
	0,  0,  0,  0, 0, 0, 0, 0,
	0,  0,  0,  0, 0, 0, 0, 0,
	0,  0,  0,  0, 0, 0, 0, 0,
	0,  0,  0,  0, 0, 0, 0, 0,
	0,  0,  0,  0, 0, 0, 0, 0,
	0,  0,  0,  0, 0, 0, 0, 0,
	0, 12, 13, 14, 0, 0, 0, 0
};

u8 AFFmode_2joueurs_manche [8*14] =

{
	 0, 12, 13,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0, 15, 16, 17,
	19, 20, 21, 22, 23, 24, 25, 28+32,
	 0,  0,  0,  0,  0, 29+32, 30, 31,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0, 12, 13, 14,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,

	  0+2*32,  1+2*32,  2+2*32,  3+2*32,  4+2*32,  5+2*32,  6+2*32,  7+2*32,
	  8+2*32,  9+2*32, 10+2*32, 11+2*32, 12+2*32, 13+2*32, 14+2*32, 15+2*32,
	 16+2*32, 17+2*32, 18+2*32, 19+2*32, 20+2*32, 21+2*32, 22+2*32, 23+2*32
};


u8 AFFmode_2joueurs_motus [8*14] =

{
	 0, 12, 13,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,
	 0, 12, 13, 14,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,

	  0+2*32,  1+2*32,  2+2*32,  3+2*32,  4+2*32,  5+2*32,  6+2*32,  7+2*32,
	  8+2*32,  9+2*32, 10+2*32, 11+2*32, 12+2*32, 13+2*32, 14+2*32, 15+2*32,
	 16+2*32, 17+2*32, 18+2*32, 19+2*32, 20+2*32, 21+2*32, 22+2*32, 23+2*32
};




void afficher_mode_jeu(void)
{
	u16 LeNumeroDuTile = 0;

	u8 colonnes = 0;
	u8 lignes = 0;

	//Afficher les differents mode de jeux avec les tableaux de tiles ainsi qu une double boucle

	if ( ( mode_de_jeu == 1 ) || ( mode_de_jeu == 2 ) )
	{
		PA_LoadGif(0, (void*)bg3_bas_jeu_1joueur);
		PA_SetSpriteAnim(1, 67, 0); PA_SetSpriteXY(1, 67, 176, 8 );
		for (lignes=0;lignes<10;lignes++)
		{
			for (colonnes=0;colonnes<8;colonnes++)
			{
				LeNumeroDuTile = AFFmode_1joueur [colonnes + (lignes*8)];
				PA_SetMapTileEx(1,2,22+colonnes,9+lignes,bg2_haut_jeu_commun_Map[LeNumeroDuTile],0,0,0);//ecran, bg, x, y, elements
			}
		}	
	}

	if ( ( mode_de_jeu == 3 ) || ( mode_de_jeu == 4 ) )
	{
		PA_LoadGif(0, (void*)bg3_bas_jeu_2_joueurs_3manches);
		PA_SetSpriteAnim(1, 67, 0); PA_SetSpriteXY(1, 67, 176, 8 );
		PA_SetSpriteAnim(1, 1, 1); PA_SetSpriteXY(1, 1, 176+48, 8+48 );
		for (lignes=0;lignes<14;lignes++)
		{
			for (colonnes=0;colonnes<8;colonnes++)
			{
				LeNumeroDuTile = AFFmode_2joueurs_manche [colonnes + (lignes*8)];
				PA_SetMapTileEx(1,2,22+colonnes,9+lignes,bg2_haut_jeu_commun_Map[LeNumeroDuTile],0,0,0);//ecran, bg, x, y, elements
			}
		}	
	}


}






void afficher_cadre_case(u8 nbreCase, s8 position_cadreX)
{
	u8 caseX = 0;
	u8 caseY = 0;

	PA_SetMapTileEx(1,2, 4+position_cadreX, 8, bg2_haut_jeu_commun_Map[2],0,0,0);
	PA_SetMapTileEx(1,2, 5+position_cadreX, 8, bg2_haut_jeu_commun_Map[3],0,0,0);

	PA_SetMapTileEx(1,2, 16+nbreCase+position_cadreX, 8, bg2_haut_jeu_commun_Map[9],0,0,0);
	PA_SetMapTileEx(1,2, 17+nbreCase+position_cadreX, 8, bg2_haut_jeu_commun_Map[10],0,0,0);

	for (caseX=0;caseX<(10+nbreCase);caseX++)
	{
		PA_SetMapTileEx(1,2, 6+caseX+position_cadreX, 8, bg2_haut_jeu_commun_Map[4],0,0,0);
	}

	for (caseY=0;caseY<14;caseY++)
	{
		PA_SetMapTileEx(1,2,           4+position_cadreX, 9+caseY, bg2_haut_jeu_commun_Map[1],0,0,0);
		PA_SetMapTileEx(1,2, 17+nbreCase+position_cadreX, 9+caseY, bg2_haut_jeu_commun_Map[11],0,0,0);
	}


}


void afficher_grilles(void)
{
	PA_LoadSimpleBg(1,2,bg2_haut_jeu_commun_Tiles,Blank,BG_256X256,0,1);
	PA_LoadBgPal(1, 2, (void*)bg2_haut_jeu_commun_Pal);

	PA_LoadSimpleBg(0,2,bg2_bas_commun_jeux_Tiles,Blank,BG_256X256,0,1);
	PA_LoadBgPal(0, 2, (void*)bg2_bas_commun_jeux_Pal);

	PA_LoadSimpleBg(1,1,bg1_chiffres_lettres_grilles_Tiles,Blank,BG_256X256,0,1);
	PA_LoadBgPal(1, 1, (void*)bg1_chiffres_lettres_grilles_Pal);

	PA_LoadSimpleBg(0,1,bg1_chiffres_lettres_grilles_Tiles,Blank,BG_256X256,0,1);
	PA_LoadBgPal(0, 1, (void*)bg1_chiffres_lettres_grilles_Pal);

	u8 caseX = 0;
	u8 caseY = 0;

	u8 nbreCase = (nbre_lettres - 6) * 2;
	s8 position_cadreX = 0;

	if ( nbre_lettres >= 8) {position_cadreX = -(nbre_lettres - 7) * 2;}

	afficher_mode_jeu();

	for (caseX=0;caseX<(12+nbreCase);caseX+=2)
	{
		for (caseY=0;caseY<14;caseY+=2)
		{
			afficher_case( caseX, caseY, position_cadreX);
		}
	}
	afficher_cadre_case(nbreCase, position_cadreX);

	for (caseX=0;caseX<(12+nbreCase);caseX+=2)
	{
		afficher_case_bas( caseX, position_cadreX);
	}
}




void afficher_lettre(u8 colonnes, u8 lignes, u8 couleur, u8 valeurchar)
{
	u8 posdebut =0;
	u8 decalage =0;

	if (valeurchar >= 65 && valeurchar <=77)
	{
		//A a M
		valeurchar = valeurchar - 65;//Le "A" devient zero
		posdebut = 1 + (valeurchar * 2) + (couleur * 128);//Position du 1er Tile du A
	}
	else
	{
		//N a Z
		valeurchar = valeurchar - 78;//Le "N" devient zero
		posdebut = 1 + (valeurchar * 2) + 64 + (couleur * 128);//Position du 1er Tile du N
	}

	if (( nbre_lettres == 6 ) && ( nbre_lettres == 7 )) { decalage=0; }
	if ( nbre_lettres == 8 ) { decalage=2;  }
	if ( nbre_lettres == 9 ) { decalage=4;  }


	PA_SetMapTileEx(1,1,	3+colonnes-decalage,	9+lignes,	bg1_chiffres_lettres_grilles_Map[ posdebut      ],0,0,0);
	PA_SetMapTileEx(1,1,	3+colonnes+1-decalage,	9+lignes,	bg1_chiffres_lettres_grilles_Map[ posdebut+1    ],0,0,0);
	PA_SetMapTileEx(1,1,	3+colonnes-decalage,	9+1+lignes,	bg1_chiffres_lettres_grilles_Map[ posdebut+32   ],0,0,0);
	PA_SetMapTileEx(1,1,	3+colonnes+1-decalage,	9+1+lignes,	bg1_chiffres_lettres_grilles_Map[ posdebut+32+1 ],0,0,0);

}


void afficher_1er_lettre( u8 couleur, u8 valeurchar)
{
	u8 posdebut =0;
	u8 lignes = 0;
	u8 decalage=0;

	if (valeurchar >= 65 && valeurchar <=77)
	{
		//A a M
		valeurchar = valeurchar - 65;//Le "A" devient zero
		posdebut = 1 + (valeurchar * 2) + (couleur * 128);//Position du 1er Tile du A
	}
	else
	{
		//N a Z
		valeurchar = valeurchar - 78;//Le "N" devient zero
		posdebut = 1 + (valeurchar * 2) + 64 + (couleur * 128);//Position du 1er Tile du N
	}

	if (( nbre_lettres == 6 ) && ( nbre_lettres == 7 )) { decalage=0; }
	if ( nbre_lettres == 8 ) { decalage=2; }
	if ( nbre_lettres == 9 ) { decalage=4; }

	for(lignes=0 ; lignes<14 ; lignes+=2)
	{
		PA_SetMapTileEx(1,1,	5-decalage,	9+lignes,	bg1_chiffres_lettres_grilles_Map[ posdebut      ],0,0,0);
		PA_SetMapTileEx(1,1,	5+1-decalage,	9+lignes,	bg1_chiffres_lettres_grilles_Map[ posdebut+1    ],0,0,0);
		PA_SetMapTileEx(1,1,	5-decalage,	9+1+lignes,	bg1_chiffres_lettres_grilles_Map[ posdebut+32   ],0,0,0);
		PA_SetMapTileEx(1,1,	5+1-decalage,	9+1+lignes,	bg1_chiffres_lettres_grilles_Map[ posdebut+32+1 ],0,0,0);
	}
}




void afficher_lettre_bas(u8 colonnes, u8 lignes, u8 couleur, u8 valeurchar)
{
	u8 posdebut =0;
	u8 decalage=0;

	if (valeurchar >= 65 && valeurchar <=77)
	{
		//A a M
		valeurchar = valeurchar - 65;//Le "A" devient zero
		posdebut = 1 + (valeurchar * 2) + (couleur * 128);//Position du 1er Tile du A
	}
	else
	{
		//N a Z
		valeurchar = valeurchar - 78;//Le "N" devient zero
		posdebut = 1 + (valeurchar * 2) + 64 + (couleur * 128);//Position du 1er Tile du N
	}


	if (( nbre_lettres == 6 ) && ( nbre_lettres == 7 )) { decalage=0; }
	if ( nbre_lettres == 8 ) { decalage=2; }
	if ( nbre_lettres == 9 ) { decalage=4; }


	PA_SetMapTileEx(0,1,	6+colonnes-decalage ,	6+lignes,	bg1_chiffres_lettres_grilles_Map[ posdebut      ],0,0,0);
	PA_SetMapTileEx(0,1,	6+colonnes+1-decalage,	6+lignes,	bg1_chiffres_lettres_grilles_Map[ posdebut+1    ],0,0,0);
	PA_SetMapTileEx(0,1,	6+colonnes-decalage,	6+1+lignes,	bg1_chiffres_lettres_grilles_Map[ posdebut+32   ],0,0,0);
	PA_SetMapTileEx(0,1,	6+colonnes+1-decalage,	6+1+lignes,	bg1_chiffres_lettres_grilles_Map[ posdebut+32+1 ],0,0,0);

}


void efface_lettres_bas (void)
{
	u8 boucleEFF =0;
	for (boucleEFF=0;boucleEFF<(18+nbreCase);boucleEFF+=2)
	{
		afficher_case_bas_vide ( boucleEFF, 0);
	}
}



char clavierlettre[30] = {"QWERTYUIOPASDFGHJKL--ZXCVBNM--"};
void detection_touche (void)
{
	if ( PA_StylusInZone(8,104,247,175) )
	{
		u8 posX = (Stylus.X - 8) / 24;
		u8 posY = (Stylus.Y - 104) / 24;
		u8 case_lettre = posX + (posY * 10);
		u8 boucleEFF =0;
		u8 decalage =0;
		u8 i=0;
		//if ( colonnes == (nbre_lettres*2) ) { colonnes=0; lignes+=2; for (boucleEFF=0;boucleEFF<(16+nbreCase);boucleEFF+=2) afficher_case_bas_vide ( boucleEFF, 0);}

		if (( nbre_lettres == 6 ) && ( nbre_lettres == 7 )) { decalage=0; }
		if ( nbre_lettres == 8 ) { decalage=2; }
		if ( nbre_lettres == 9 ) { decalage=4; }

		if ( (case_lettre == 20) || ( Stylus.X <= 7 ) || ( Stylus.Y <= 103 ) )
		{
			//vide

		}
		else if ( (case_lettre == 19) && (colonnes >= 1) )
		{
 			PA_SetSpriteAnim(0, 2, 0);
			PA_SetSpriteXY(0, 2, 8+(posX*24), 104+(posY*24) );
			afficher_case_bas_vide ( (colonnes+nbreCase-decalage+2), 0 );
			colonnes-=2;

			//effacer une lettre
		}
		else if ( (case_lettre == 28 || case_lettre == 29) && (colonnes >= 2) )
		{
			PA_SetSpriteAnim(0, 2, 1);
			PA_SetSpriteXY(0, 2, 8+(8*24), 104+(2*24) );
			//effacer tout
			for (boucleEFF=0;boucleEFF<(16+nbreCase);boucleEFF+=2)
			{
				afficher_case_bas_vide ( boucleEFF, 0);
			}
			colonnes=0;


		}
		else if  ( (case_lettre <= 27) &&  (case_lettre != 19) )
		{
			//la lettre
			colonnes+=2;
			PA_SetSpriteAnim(0, 2, 0);
			PA_SetSpriteXY(0, 2, 8+(posX*24), 104+(posY*24) );
			s16 valeurchar = 0;
			valeurchar = clavierlettre[case_lettre];
			mot_du_joueur[(colonnes/2)-1] = clavierlettre[case_lettre];
			afficher_lettre_bas(colonnes, 0, 0, valeurchar);

			if ( colonnes == (nbre_lettres*2) )
			{ 
				for ( i=0 ; i<nbre_lettres ; i++)
				{
					afficher_lettre(i*2+2, lignes, 0, mot_du_joueur[i]);//x, y, couleur, lettre
				}
			}
		}
	}
}



void choix_mode_nbre_lettres(void)
{
	u8 positionY = 0;

	
	while(startmenu ==2)
	{
		PA_WaitForVBL();
		//4 boutons radios
		if ( PA_StylusInZone(176,64,240,127) )
		{
			//qu'elle bouton ?
			positionY = (Stylus.Y - 64) / 16;

			//bouton radio active
			PA_SetSpriteXY(0, 0, 176, 64 + (positionY * 16) );

			//calcul du nb de lettre
			nbre_lettres = positionY + 6;

		}

		// quel jeu
		if ( PA_StylusInZone(17,56,76,77) )
		{
			//1 joueur - 5 mots
			PA_EasyBgLoad(0,2,bg2_bas_jeu1);
			mode_de_jeu = 1;
			second=0; minute=0;centieme=0;
		}
		else if ( PA_StylusInZone(97,56,157,77) )
		{
			//1 joueur - 10 mots
			PA_EasyBgLoad(0,2,bg2_bas_jeu2);
			mode_de_jeu = 2;
			second=0; minute=0;centieme=0;
		}
		else if ( PA_StylusInZone(16,111,85,135) )
		{
			//2 joueurs - 3 manches
			PA_EasyBgLoad(0,2,bg2_bas_jeu3);
			mode_de_jeu = 3;
			second=59; minute=1;centieme=0;
		}
		else if ( PA_StylusInZone(89,111,158,134) )
		{
			//2 joueurs - 5 manches
			PA_EasyBgLoad(0,2,bg2_bas_jeu4);
			mode_de_jeu = 4;
			second=59; minute=1;centieme=0;
		}

		/**********************************************/
		if ( PA_StylusInZone(136,168,184,184) )	
		{ 
			//retour au menu
			PA_SetSpriteAnim(0, 6, 1);
			PA_SetSpriteXY(0, 6, 118, 161);
			startmenu = 4; 
		}

		if ( PA_StylusInZone(185,160,240,184) )	 
		{
			PA_SetSpriteAnim(0, 6, 0);
			PA_SetSpriteXY(0, 6, 186, 161);

			effet_lumiere_masquer(1,1);//ecran haut, ecran bas (0 = non, 1 = oui), ici effet sur les 2 ecrans

				PA_SetSpriteXY(0, 6, -64, -32);
				PA_LoadGif(1, (void*)bg3_haut_jeu_1joueur);
				PA_EasyBgLoad(0,2,bg2_bas_menu0);PA_SetSpriteXY(0, 0, -16, -16 );
				afficher_grilles();

			effet_lumiere_voir(1,1);//ecran haut, ecran bas (0 = non, 1 = oui), ici effet sur les 2 ecrans

			startmenu = 3;
		}

	}
}











