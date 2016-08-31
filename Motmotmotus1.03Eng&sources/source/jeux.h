

void jouer()
{			
	u8 z=0;

	if ( nbre_lettres == 6 ) 
	{
		pioche_tirage6 = PA_RandMinMax(0, taille_pioche6 - 1);

		u8 i=0;
		for (i=0;i<6;i++) 
		{
			pioche_last [i]  = pioche6 [taille_pioche6 - 1][i]; 
			solution [i]  = pioche6 [pioche_tirage6][i];
			pioche6[taille_pioche6 - 1][i]  = solution [i];
			pioche6[pioche_tirage6][i]  = pioche_last [i]; 
		}
		taille_pioche6--;

		afficher_1er_lettre(  0, solution [0]);
	}
	else if ( nbre_lettres == 7 ) 
	{
		pioche_tirage7 = PA_RandMinMax(0, taille_pioche7 - 1);
		u8 i=0;
		for (i=0;i<7;i++) 
		{
			pioche_last [i]  = pioche7 [taille_pioche7 - 1][i]; 
			solution [i]  = pioche7 [pioche_tirage7][i];
			pioche7[taille_pioche7 - 1][i]  = solution [i];
			pioche7[pioche_tirage7][i]  = pioche_last [i]; 
		}
		taille_pioche7--;
		
		afficher_1er_lettre(  0, solution [0]);
	}
	else if ( nbre_lettres == 8 ) 
	{
		pioche_tirage8 = PA_RandMinMax(0, taille_pioche8 - 1);
		u8 i=0;
		for (i=0;i<8;i++) 
		{
			pioche_last [i]  = pioche8 [taille_pioche8 - 1][i]; 
			solution [i]  = pioche8 [pioche_tirage8][i];
			pioche8[taille_pioche8 - 1][i]  = solution [i];
			pioche8[pioche_tirage8][i]  = pioche_last [i]; 
		}
		taille_pioche8--;
		
		afficher_1er_lettre(  0, solution [0]);
	}
	else if ( nbre_lettres == 9 ) 
	{
		pioche_tirage9 = PA_RandMinMax(0, taille_pioche9 - 1);
		u8 i=0;
		for (i=0;i<9;i++) 
		{
			pioche_last [i]  = pioche9 [taille_pioche9 - 1][i]; 
			solution [i]  = pioche9 [pioche_tirage9][i];
			pioche9[taille_pioche9 - 1][i]  = solution [i];
			pioche9[pioche_tirage9][i]  = pioche_last [i]; 
		}
		taille_pioche9--;
		
		afficher_1er_lettre(  0, solution [0]);
	}

	while(z==0)
	{
		PA_WaitForVBL();
		
		if ( (mode_de_jeu == 1)||(mode_de_jeu == 2) ) { chrono (); compte_point1 (point_j1); }
		if ( (mode_de_jeu == 3)||(mode_de_jeu == 4) ) { compte_point1 (point_j1); compte_point2 (point_j2);  compte_A_rebours (); }
		
		if ( (( mode_de_jeu == 3 )&&( manche == 4 )) || (( mode_de_jeu == 4 )&&( manche == 6 )) )
		{

			effet_lumiere_masquer(1,1);
			PA_SetSpriteXY(0, 2, -32, -32);
			PA_SetSpriteXY(1, 67, -64, -64);
			PA_SetSpriteXY(1, 1, -32, -32);
			PA_SetSpriteXY(0, 7, -16, -16);
			PA_EasyBgLoad(0,1,bg2_bas_menu0);
			PA_EasyBgLoad(0,2,bg2_bas_menu0);
			PA_EasyBgLoad(1,1,bg2_bas_menu0);
			PA_EasyBgLoad(1,2,bg2_bas_menu0);


			u8 boucleEFF=0;
			u8 i = 0;
						
			centieme=0; second=0; dizsecond =0; minute=0; dizminute = 0;ScoreSecond[0]=0;

			for (boucleEFF=0;boucleEFF<(18+nbreCase);boucleEFF+=2)
			{
				for (i=0;i<16;i+=2)
				{
					afficher_case_vide ( boucleEFF, i);
					afficher_case_bas_vide ( boucleEFF, 0);
				}
			}	
			for (t=3; t<67; t++){PA_SetSpriteAnim(1, t, 0); PA_SetSpriteXY(1, t,  -16, -16);}
			colonnes=0;lignes=0;

			// remettre les mots vierges
			for (i = 0 ; i < 9 ; i++)
			{
				aide_mot_du_joueur[i] = 0;
				aide_position [i] = 0;
				mot_du_joueur_dico[i] = 0 ;
			}

			
			son_superapplause();
			if ( point_j1==point_j2 )
			{
				PA_LoadGif(0, (void*)bg3_bas_egalite);PA_LoadGif(1, (void*)bg3_bas_egalite);effet_lumiere_voir(1,1);
			}
			if ( point_j1>point_j2 )
			{
				PA_LoadGif(1, (void*)bg3_haut_congratulation_j1);PA_LoadGif(0, (void*)bg3_bas_congratulation);effet_lumiere_voir(1,1);
			}
			if ( point_j1<point_j2 )
			{
				PA_LoadGif(1, (void*)bg3_haut_congratulation_j2);PA_LoadGif(0, (void*)bg3_bas_congratulation);effet_lumiere_voir(1,1);
			}

			
			temporisation(180);
			startmenu =4; z=1;

		}


		if ( Pad.Newpress.Start )
		{
			u8 boucleEFF=0;
			u8 i = 0;
			startmenu =4; z=1; valid =0;
			centieme=0; second=0; dizsecond =0; minute=0; dizminute = 0;
			for (boucleEFF=0;boucleEFF<(18+nbreCase);boucleEFF+=2)
			{
				for (i=0;i<16;i+=2)
				{
					afficher_case_vide ( boucleEFF, i);
					afficher_case_bas_vide ( boucleEFF, 0);
				}
			}
			for (t=3; t<67; t++){PA_SetSpriteAnim(1, t, 0); PA_SetSpriteXY(1, t,  -16, -16);}
			colonnes=0;lignes=0;

			
			for (i = 0 ; i < 9 ; i++)
    			{
       				aide_mot_du_joueur[i] = 0;
				aide_position [i] = 0;
				mot_du_joueur_dico[i] = 0 ;
    			}
		}
		
		if ( Stylus.Newpress ) 
		{
			detection_touche ();
	
			u8 i=0;u8 j=0;u8 k=0;	
			for (i = 0 ; i < nbre_lettres ; i++)
    			{
       				position[i] = 0;
 				nbre_lettre_mot_du_joueur[i] = 0;
				nbre_lettre_solution[i] = 0;
				lettre_valide_rouge[i]= 0;
				lettre_valide_jaune[i] = 0;
   			}



	
			if ( colonnes == (nbre_lettres*2) )
			{
				//compte le nombre de lettre égale des 2 premières lettre égale à la deuxieme lettre etc...
				for (i=0;i<nbre_lettres;i++)
				{
					for (j=0;j<(k+1) ;j++)
					{
						if  ( mot_du_joueur[j] == mot_du_joueur[i] )
						{
							nbre_lettre_mot_du_joueur[i]++;
						}
					}
				k++;
				}



				//compte du nombre de lettre identique dans la solution par rapport à une lettre du mot tape
				for (i=0;i<nbre_lettres;i++)
				{
					for (j=0;j<nbre_lettres;j++)
					{
						if  ( mot_du_joueur[i] == solution[j] )
						{
							nbre_lettre_solution[i]++;
	
						}
					}
				}
	
				//compte le nombre de lettre valide en rouge
				/*for (i=0;i<nbre_lettres;i++)
				{
					for (j= 0 ;j<nbre_lettres;j++)
					{
						if ( ( i < j )&&( mot_du_joueur[i] == solution[i] )&& ( mot_du_joueur[j] == solution[j] ) )
						{
							lettre_valide_rouge[i]++;
						}
						if ( ( i > j )&&( mot_du_joueur[i] == solution[i] )&& ( mot_du_joueur[j] == solution[j] ) )
						{
							lettre_valide_rouge[i]--;
						}
					}
				}*/

				for (i=0;i<nbre_lettres;i++)
				{
					for (j= 0 ;j<nbre_lettres;j++)
					{
						if  ( ( mot_du_joueur[i] == solution[j] )&&( mot_du_joueur[j] == solution[j] ) )
						{
							lettre_valide_rouge[i]++; 
						}
					}
					
				}



				u8 test=0;
				for (i=0;i<nbre_lettres;i++)
				{
					mot_du_joueur_dico[i] = mot_du_joueur[i];
				}


				if   ( ( nbre_lettres == 6 )&&( strstr(DICO6, mot_du_joueur_dico) == 0 ) )
				{
					PA_SetSpriteAnim(0, 6, 4);PA_SetSpriteXY(0, 6, 84, 8); son_ho(); temporisation(90);
				}				
				else if   ( ( nbre_lettres == 7 )&&( strstr(DICO7, mot_du_joueur_dico) == 0 ) )
				{
					PA_SetSpriteAnim(0, 6, 4);PA_SetSpriteXY(0, 6, 84, 8); son_ho(); temporisation(90);
				}
				else if   ( ( nbre_lettres == 8 )&&( strstr(DICO8, mot_du_joueur_dico) == 0 ) )
				{
					PA_SetSpriteAnim(0, 6, 4);PA_SetSpriteXY(0, 6, 84, 8); son_ho(); temporisation(90);
				}
				else if   ( ( nbre_lettres == 9 )&&( strstr(DICO9, mot_du_joueur_dico) == 0 ) )
				{
					PA_SetSpriteAnim(0, 6, 4);PA_SetSpriteXY(0, 6, 84, 8); son_ho(); temporisation(90);
				}
				else if   ( mot_du_joueur[0] != solution[0] )
				{
					PA_SetSpriteAnim(0, 6, 5);PA_SetSpriteXY(0, 6, 84, 8); son_ho(); temporisation(90);
				}
				else 
				{

					for (i=0;i<nbre_lettres;i++)
					{
	
						//lettre jaune
						for (j=0;j<nbre_lettres;j++)
						{
							if ( ( i >= j )&&( mot_du_joueur[i] == solution[j] )&&( mot_du_joueur[i] != solution[i] ) 
							     &&( ( nbre_lettre_mot_du_joueur[i] /*+ lettre_valide_rouge[i]*/ ) <= nbre_lettre_solution[i] ) )
							{
								position[i] = 2;//mal placée
							}
							if ( ( i < j )&&( mot_du_joueur[i] == solution[j] )&&( mot_du_joueur[i] != solution[i] ) 
							     &&( ( nbre_lettre_mot_du_joueur[i] - lettre_valide_rouge[i] ) <= nbre_lettre_solution[i] ) )
							{
								position[i] = 2;//mal placée
							}
						}
					
		
						if ( mot_du_joueur[i] == solution[i] )
						{
							position[i] = 1;//bon
							aide_position [i] = 1;
							aide_mot_du_joueur[i]= mot_du_joueur[i];
							test++;
						}
	
						else
						{
							//Pas bon
						}
					}

				
					for (i=0;i<nbre_lettres;i++)
					{
						valid++;
						u8 decale_sprite = 0;
	
						if (( nbre_lettres == 6 ) && ( nbre_lettres == 7 )) { decale_sprite=0; }
						if ( nbre_lettres == 8 ) { decale_sprite=16; }
						if ( nbre_lettres == 9 ) { decale_sprite=16*2; }					


						if ( position[i] == 2)
						{
							PA_SetSpriteAnim(1, 3+valid, 1); PA_SetSpriteXY(1, 3+valid,  40+(i*16)-decale_sprite, 72+lignes*8);
							son_cases(2);
						}
						else if ( position[i] == 1 )
	 					{
						
							PA_SetSpriteAnim(1, 3+valid, 0); PA_SetSpriteXY(1, 3+valid,  40+(i*16)-decale_sprite, 72+lignes*8);
							son_cases(1);
						}
						else
						{
							son_cases(3);
						}
	
						/*if ( ( aide_position [i] == 1 )&&( i>>0 )&&(test!=nbre_lettres)&&(lignes != 12) )
						{ 
							afficher_lettre(2+i*2, lignes+2, 1, aide_mot_du_joueur[i]); 
						}*/
						temporisation(20);

					}

				}



				for (i=0;i<nbre_lettres;i++)
				{
					if ( ( aide_position [i] == 1 )&&( i>>0 )&&(test!=nbre_lettres)&&(lignes != 12) )
					{ 
						afficher_lettre(2+i*2, lignes+2, 1, aide_mot_du_joueur[i]); 
					}
				}
				

				PA_SetSpriteXY(0, 6, -64, -32);
				efface_lettres_bas() ;

				if ( colonnes == (nbre_lettres*2) ) { colonnes=0; lignes+=2;}

				u8 gagne = 0;

				if ( ( mode_de_jeu == 1 )||( mode_de_jeu == 2 ) )
				{
					for (i=0;i<nbre_lettres;i++)
					{
						if ( position[i] == 1 ) gagne++;
						if ( gagne == nbre_lettres ) 
						{ 
							point_j1+=1;
							son_gagne(); 
							compte_point1 (point_j1);
						}
					}
				}
				
				if ( mode_de_jeu == 3 )
				{
					for (i=0;i<nbre_lettres;i++)
					{
						if ( position[i] == 1 ) gagne++;
						if ( gagne == nbre_lettres ) 
						{ 
							if ( joueur == 1 )
							{
								point_j1+=1;
								son_gagne(); 
								compte_point1 (point_j1);valid=0;
							}
							if ( joueur == 2 )
							{
								point_j2+=1;
								son_gagne(); 
								compte_point2 (point_j2);valid=0;
							}

						}
					}
				}


				u8 boucleEFF=0;
				if ( 	( ( mode_de_jeu == 1 )&&( point_j1 == 5 ) )||( ( mode_de_jeu == 2 )&&( point_j1 == 10 ) ) )
				{
					PA_SetSpriteXY(0, 2, -32, -32);
					PA_EasyBgLoad(0,2,bg2_bas_menu0);
					effet_lumiere_masquer(0,1);son_superapplause(); PA_SetSpriteXY(0, 7, -16, -16);

					FILE* fichier = NULL;

					fichier = fopen("/motscore.sav", "r+");
					if (fichier != NULL)
					{
						rewind(fichier); 
						fscanf(fichier, "%d %d %d %d %d %d %d %d", &LastScoreSecond[0], &LastScoreSecond[1], &LastScoreSecond[2], &LastScoreSecond[3], 
						&LastScoreSecond[4], &LastScoreSecond[5], &LastScoreSecond[6], &LastScoreSecond[7]);
						
						if ( mode_de_jeu == 1 )
						{
							ScoreSecond[nbre_lettres - 5] = ScoreSecond[0];
							if ( ScoreSecond[nbre_lettres - 5] >= LastScoreSecond[nbre_lettres - 6] )
							{
								ScoreSecond[nbre_lettres - 5] = LastScoreSecond[nbre_lettres - 6];
							}
							for(i=1; i<9; i++) 
							{
								if ( i != nbre_lettres - 5 )  ScoreSecond[i] = LastScoreSecond[i-1];
							}
						}
						else if ( mode_de_jeu == 2 )
						{
							ScoreSecond[nbre_lettres - 1] = ScoreSecond[0];
							if ( ScoreSecond[nbre_lettres - 1] >= LastScoreSecond[nbre_lettres - 2] )
							{
								ScoreSecond[nbre_lettres - 1] = LastScoreSecond[nbre_lettres - 2];
							}
							for(i=1; i<9; i++) 
							{
								if ( i != nbre_lettres - 1 )  ScoreSecond[i] = LastScoreSecond[i-1];
							}
						}




						rewind(fichier);
						fputs("                                                                        ", fichier);
						rewind(fichier);
						fprintf(fichier, "%d %d %d %d %d %d %d %d", ScoreSecond[1], ScoreSecond[2], ScoreSecond[3], ScoreSecond[4],
						ScoreSecond[5], ScoreSecond[6], ScoreSecond[7], ScoreSecond[8]);
						fclose(fichier); 
					}
					
					PA_LoadGif(0, (void*)bg3_bas_congratulation);

					effet_lumiere_voir(0,1);
					temporisation(180);

					u8 boucleEFF=0;
					u8 i = 0;
					startmenu =4; z=1; 
						
					centieme=0; second=0; dizsecond =0; minute=0; dizminute = 0; ScoreSecond[0]=0;

					for (boucleEFF=0;boucleEFF<(18+nbreCase);boucleEFF+=2)
					{
						for (i=0;i<16;i+=2)
						{
							afficher_case_vide ( boucleEFF, i);
							afficher_case_bas_vide ( boucleEFF, 0);
						}
					}	
					for (t=3; t<67; t++){PA_SetSpriteAnim(1, t, 0); PA_SetSpriteXY(1, t,  -16, -16);}
					colonnes=0;lignes=0;
					for (i = 0 ; i < 9 ; i++)
    					{
       						aide_mot_du_joueur[i] = 0;
						aide_position [i] = 0;
						mot_du_joueur_dico[i] = 0 ;
    					}
	
				}


				for (i=0;i<nbre_lettres;i++)
				{
					if  ( 	(( gagne == nbre_lettres )&&( mode_de_jeu == 1 )&&( point_j1 != 5 )) || 
						(( gagne == nbre_lettres )&&( mode_de_jeu == 2 )&&( point_j1 != 10 )) || 
						(( lignes == 14 )&&( mode_de_jeu == 1 )&&( point_j1 != 5 )) ||
						(( lignes == 14 )&&( mode_de_jeu == 2 )&&( point_j1 != 10)) || 
						(( gagne != nbre_lettres )&&( lignes == 14 )) ||
						(( gagne == nbre_lettres )&&( mode_de_jeu == 3 ))   )
					{


						if ( ( gagne != nbre_lettres )&&( lignes == 14 ) )
						{ 
							//le mot à trouver est :
							temporisation(60);son_superho();
							PA_SetSpriteXY(0, 4, 16*4+4, 102-16*5 );
							PA_SetSpriteXY(0, 5, 16*8+4, 102-16*5 );
							for (i=0;i<nbre_lettres;i++)
							{
								afficher_lettre_bas(2+2*i, 0, 0, solution [i]);
							}
						}


						temporisation(120);
						//effacer tout vu gagner
						PA_SetSpriteXY(0, 4, -64, -32 );
						PA_SetSpriteXY(0, 5, -64, -32 );
						for (boucleEFF=0;boucleEFF<(18+nbreCase);boucleEFF+=2)
						{
							for (i=0;i<(18+nbreCase);i+=2)
							{
								afficher_case_vide ( boucleEFF, i);
								afficher_case_bas_vide ( boucleEFF, 0);
							}
						}
						for (t=3; t<67; t++){PA_SetSpriteAnim(1, t, 0); PA_SetSpriteXY(1, t,  -16, -16);}
						colonnes=0;lignes=0;
						test=0;
						for (i = 0 ; i < nbre_lettres ; i++)
    						{
       							aide_mot_du_joueur[i] = 0;
							aide_position [i] = 0;
							mot_du_joueur_dico[i] = 0 ;
    						}


						if  ( nbre_lettres == 6 ) 
						{
							pioche_tirage6 = PA_RandMinMax(0, taille_pioche6 - 1);
							for (i=0;i<6;i++) 
							{
								pioche_last [i]  = pioche6 [taille_pioche6 - 1][i]; 
								solution [i]  = pioche6 [pioche_tirage6][i];
								pioche6[taille_pioche6 - 1][i]  = solution [i];
								pioche6[pioche_tirage6][i]  = pioche_last [i]; 
							}
							taille_pioche6--;
							valid=0;
							afficher_1er_lettre(  0, solution [0]);

						}
						else if  ( nbre_lettres == 7 ) 
						{
							pioche_tirage7 = PA_RandMinMax(0, taille_pioche7 - 1);
							for (i=0;i<7;i++) 
							{
								pioche_last [i]  = pioche7 [taille_pioche7 - 1][i]; 
								solution [i]  = pioche7 [pioche_tirage7][i];
								pioche7[taille_pioche7 - 1][i]  = solution [i];
								pioche7[pioche_tirage7][i]  = pioche_last [i]; 
							}
							taille_pioche7--;
							valid=0;
							afficher_1er_lettre(  0, solution [0]);

						}
						else if  ( nbre_lettres == 8 )
						{
							pioche_tirage8 = PA_RandMinMax(0, taille_pioche8 - 1);
							for (i=0;i<8;i++) 
							{
								pioche_last [i]  = pioche8 [taille_pioche8 - 1][i]; 
								solution [i]  = pioche8 [pioche_tirage8][i];
								pioche8[taille_pioche8 - 1][i]  = solution [i];
								pioche8[pioche_tirage8][i]  = pioche_last [i]; 
							}
							taille_pioche8--;
							valid=0;
							afficher_1er_lettre(  0, solution [0]);

						}
						else if  ( nbre_lettres == 9 )
						{
							pioche_tirage9 = PA_RandMinMax(0, taille_pioche9 - 1);
							for (i=0;i<9;i++) 
							{
								pioche_last [i]  = pioche9 [taille_pioche9 - 1][i]; 
								solution [i]  = pioche9 [pioche_tirage9][i];
								pioche9[taille_pioche9 - 1][i]  = solution [i];
								pioche9[pioche_tirage9][i]  = pioche_last [i]; 
							}
							taille_pioche9--;
							valid=0;
							afficher_1er_lettre(  0, solution [0]);

						}



						
					}
				}

			}
		}

	}
}

