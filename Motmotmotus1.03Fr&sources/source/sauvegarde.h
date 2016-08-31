


void decoupeTemps(int* pointeurDizMinut, int* pointeurUniMinut, int* pointeurDizSecond, int* pointeurUniSecond, int* pointeurScoreSecond)
{
	*pointeurDizMinut = ( *pointeurScoreSecond / 60 ) / 10;
	*pointeurUniMinut = ( *pointeurScoreSecond / 60 ) - *pointeurDizMinut * 10;

	*pointeurDizSecond = ( *pointeurScoreSecond - ( *pointeurDizMinut * 10 + *pointeurUniMinut )*60 ) / 10;
	*pointeurUniSecond = ( *pointeurScoreSecond - ( *pointeurDizMinut * 10 + *pointeurUniMinut )*60 ) - *pointeurDizSecond * 10;

}

/*void enregistrer_scores(int ScoreSecond)
{
 
	FILE* fichier = NULL;

	fichier = fopen("/motscore.sav", "w");
	if (fichier != NULL)
	{
		rewind(fichier); 
		fprintf(fichier, "%d", ScoreSecond);
		fputs("1254",fichier);	
		fclose(fichier); 
	}
}*/


void afficher_scores(void)
{
	PA_LoadSimpleBg(0,1,bg1_chiffres_lettres_grilles_Tiles,Blank,BG_256X256,0,1);
	PA_LoadBgPal(0, 1, (void*)bg1_chiffres_lettres_grilles_Pal);

	int temps_[8] = {0}; u8 x = 0; u8 y = 0; u8 i = 0;

 
	FILE* fichier = NULL;

	fichier = fopen("/motscore.sav", "r");

	if (fichier != NULL)
	{
		fscanf(fichier, "%d %d %d %d %d %d %d %d", &temps_[0], &temps_[1], &temps_[2], &temps_[3], &temps_[4], &temps_[5], &temps_[6], &temps_[7]);

		for ( i=0 ; i<8; i++ )
		{
			if (i==1) { x =  0; y =  2; }
			else if (i==2) { x = 14; y =  0; }
			else if (i==3) { x = 14; y =  2; }

			else if (i==4) { x =  0; y =  8; }
			else if (i==5) { x =  0; y = 10; }
			else if (i==6) { x = 14; y =  8; }
			else if (i==7) { x = 14; y = 10; }
			else { }

			decoupeTemps(&dizMinut, &uniMinut, &dizSecond, &uniSecond, &temps_[i]);

			PA_SetMapTileEx(0,1,	10+x,	7+y,	bg1_chiffres_lettres_grilles_Map[ 2 +  (352) + dizMinut  ],0,0,0);
			PA_SetMapTileEx(0,1,	11+x,	7+y,	bg1_chiffres_lettres_grilles_Map[ 2 +  (352) + uniMinut  ],0,0,0);

			PA_SetMapTileEx(0,1,	12+x,	7+y,	bg1_chiffres_lettres_grilles_Map[ 352+1  ],0,0,0);

			PA_SetMapTileEx(0,1,	13+x,	7+y,	bg1_chiffres_lettres_grilles_Map[ 2 +  (352) + dizSecond  ],0,0,0);
			PA_SetMapTileEx(0,1,	14+x,	7+y,	bg1_chiffres_lettres_grilles_Map[ 2 +  (352) + uniSecond  ],0,0,0);
		}
 
		fclose(fichier);
	}


}


FILE* fichier = NULL;

fichier = fopen("/motscore.sav", "r");

if (fichier != NULL)
{
	fscanf(fichier, "%d %d %d %d %d %d %d %d", &temps_[0], &temps_[1], &temps_[2], &temps_[3], &temps_[4], &temps_[5], &temps_[6], &temps_[7]);

	fclose(fichier);
}
else 
{
	fichier = fopen("/motscore.sav", "w");

	if (fichier != NULL)
	{
		fputs("5400 5300 5200 5100 5000 4900 4800 4700", fichier);

		fclose(fichier);
	}		
}



