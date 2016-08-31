// Includes

#include <PA9.h>
 
#include <stdio.h>  // nécessaire pour la gestion fichier
#include <stdlib.h>
#include <fcntl.h>
#include "fat.h"

#include "gfx/all_gfx.c"
#include "gfx/all_gfx.h"



//****************
//*** Les GIFS ***
//****************
#include "bg3_haut_intro.h"
#include "bg3_bas_intro.h"

#include "bg3_haut_menu.h"
#include "bg3_bas_menu.h"

#include "bg3_haut_instruction.h"
#include "bg3_bas_instruction.h"

#include "bg3_bas_credits.h"

#include "bg3_bas_scores.h"

#include "bg3_bas_jeu_mode.h"

#include "bg3_haut_jeu_1joueur.h"
#include "bg3_bas_jeu_1joueur.h"
#include "bg3_bas_jeu_2_joueurs_3manches.h"
#include "bg3_bas_jeu_2_joueurs_motus.h"
#include "bg3_bas_congratulation.h"
#include "bg3_bas_egalite.h"
#include "bg3_haut_congratulation_j1.h"
#include "bg3_haut_congratulation_j2.h"

//*********************
//*** Mes Variables ***
//*********************
u8 startmenu = 0;
u8 nbre_lettres = 6;
u8 mode_de_jeu = 1;
u8 colonnes = 0;
u8 lignes = 0;
u8 nbreCase=0;
u8 t=0;
u16 z=0;
u8 point_j1=1;
u8 point_j2=0;
int manche = 1;
u8 joueur = 1;
int centieme=0; int second=0; u8 dizsecond =0; u8 minute=0; u8 dizminute = 0;
char mot_du_joueur_dico [10] = "";
long mot_du_joueur [10];
long aide_mot_du_joueur [10];
char solution      [10] = "";
long position      [10];
long aide_position [10];
u8 suppr=1;
int valid=0;
u8 invers=0;
long nbre_lettre_mot_du_joueur[10];
long nbre_lettre_solution[10];
long lettre_valide_rouge[10];
long lettre_valide_jaune[10];
int pioche_tirage6=0;
int pioche_tirage7=0;
int pioche_tirage8=0;
int pioche_tirage9=0;

long pioche_last [10];
long pioche_valeur_tirer [10];

int taille_pioche6=126;
int taille_pioche7=125;
int taille_pioche8=125;
int taille_pioche9=100;


void decoupeTemps(int* pointeurDizMinut, int* pointeurUniMinut, int* pointeurDizSecond, int* pointeurUniSecond, int* pointeurScoreSecond);
int dizMinut  = 0;	int uniMinut  = 0;	int dizSecond = 0;	int uniSecond = 0; 	int ScoreSecond[9] = {0}; int temps_[8] = {0};

int LastScoreSecond[8] = {0};

u16 angle = 0;

//****************
//*** Les Mots ANIMAL ABANDON ACCEPTE ANIMER***
//****************

//126 mots
char pioche6 [126][7] = 
{"ABDUCT","ABSENT","ABSORB","ABSURD","ACCEPT","ACCESS","ACCORD","ACROSS","ACTION","ACTIVE","ACTUAL","ADDICT","AIRBAG","AMAZON","AMOUNT","ARIGHT","ARMORY","AROUND",
 "ATTACK","ATTENT","ARCADE","ATTAIN","ATYPIC","AUTMUN","BACKUP","BALLET","BANZAI","BASKET","BATTLE","BOTTLE","BOTTOM","CASTEL","CAREER","CARBON","CHORAL","COLOUR",
 "CLOSER","COMMON","CREDIT","DRIVEN","EGOISM","EARNER","EASIER","EDITOR","EMPIRE","EMPLOY","ENERGY","ENABLE","ENGAGE","EXCESS","EXPAND","EXPECT","EXTEND","EXPORT",
 "EXTEND","EXTERN","EXTRAS","FACILE","FACTOR","FAILED","FALCON","FAMILY","FAMOUS","FARMER","FATHER","FLIGHT","FEMALE","FLINCH","FOREST","FORGET","FORMAT","FINISH",
 "FRIEND","FUSION","FUTURE","GARAGE","GENUIS","GUITAR","HACKER","HAFTER","HAMMER","HEROES","HEROIC","HEROIN","HIGHER","HITMAN","HOCKEY","HOLLOW","HOTDOG","HOUSES",
 "HUDDLE","HUMANS","HUNTER","IMPACT","IMPORT","IMPOSE","INDUCE","INDUCT","INSTAL","JOGGER","JOYOUS","KARATE","KIDNAP","KILLER","LADIES","LAGOON","LAUNCH","LEAGUE",
 "LEGACY","RACING","ROTATE","SCHOOL","SCREEN","SEASON","SECOND","SERVER","SHRIMP","STRAIN","SPONGE","SUBMIT","TIMBER","TRAUMA","TRAVEL","WRITER","WRITER","WORKUP"};

//125 mots
char pioche7 [125][8] = 
{"ACRONYM","ACCOUNT","ACCLAIM","ABDOMEN","ACRYLIC","ADVANCE","AEROSOL","AGILITY","AIRPORT","AMBIENT","ANSWERS","ANXIETY","ANXIOUS","APOLOGY","APPOINT","AQUATIC","APRICOT",
 "ARCHAIC","ATHEISM","AUDITOR","BACKOUT","BASKETS","BATTLES","BEDROOM","BEETLES","BENEFIT","BINOCLE","BIOLOGY","BIOMASS","BLACKER","BOBBLES","BOATMAN","BOOSTER","BOTTLES",
 "BOTTOMS","BREAKER","BROTHER","BUFFALO","BUILDER","CABINET","CAOLRIC","CALORIE","CAMPING","CAPITAL","CAPTAIN","CAPSULE","CAREFUL","CARNAGE","CARTOON","CARWASH","CASTELS",
 "CATCHER","CATALOG","CAUTION","CELLULE","CENTURY","CHARIOT","CHECKUP","CHEEPER","CHECKEN","CHOREAL","CINEMAS","CINEAST","CIRCUIT","CITIZEN","CLARITY","CLASHER","CLASSIC",
 "CLEANUP","COACHER","COASTAL","COEXIST","CRAFTER","CRACKER","CRUISER","DAIMONS","DAMAGES","DANCING","DAYLONG","DAYWORK","DECLINE","DECRYPT","DEFENCE","DEFAULT","DEFAMER",
 "DELIGHT","DESKTOP","DISABLE","DISTURB","DOLPHIN","DRIVERS","DRIFTER","EARLESS","EARLIER","ECOLOGY","ECONOMY","EDITION","EGOISMS","ELASTIC","ELISION","EMBRYON","EMPEROR",
 "ENCRYPT","ERRATUM","EXAMENS","EXEMPTS","EXPLODE","EXTRACT","FALLOUT","FANTOMS","FANTASY","FARMERS","FEELING","FINNALY","FISSION","FITNESS","FLIGHTS","GENERIC","HAIRCUT",
 "HEALTHS","HARDIER","HAMMERS","IMPLANT","LEARNER","LICENSE"};


//125 mots
char pioche8 [125][9] = 
{"ABSOLUTE","ABSTRACT","ACADEMIA","ACCIDENT","ACCURATE","ACTIVITY","ADDITION","ADHERENT","ADOPTION","ADVISORY","AFFINITY","AIRCRAFT","AIRSPACE","ALLERGIC",
 "ALLIANCE","ALLOCATE","ANNULATE","ANNALIST","ANTOLOGY","ANYWHERE","APPLAUSE","AQUALUNG","AQUARIUM","ARMCHAIR","BACHELOR","BAGGAGES","BATHROOM","BEDROOMS",
 "BICOLOUR","BILLIONS","BIRTHDAY","BLACKOUT","BOXBOARD","BUILDING","BUSINESS","CAFFEINE","CALENDAR","CAMPAIGN","CANNULAR","CAPACITY","CEREBRAL","CEREMONY",
 "CHAMPION","CHECKING","CHEMICAL","CHILDREN","CITATION","COMMANDO","COLONIAL","CONQUEST","CORRIDOR","CREATURE","CREATIVE","CRITICAL","CRIMINAL","DARKNESS",
 "DATABASE","DAUGHTER","DAYLIGHT","DESERTIC","DETECTOR","DIAMETER","DIPLOMAT","DIRECTOR","DISCOUNT","DISCOVER","EARPHONE","EARTHMAN","EARTHING","ELECTRON",
 "ELECTION","ELECTRIC","EMOTICON","EMPLOYER","EQUALITY","ERUPTION","ETERNITY","EVERYONE","FABULOUS","FACILITY","FAIRNESS","FATALITY","FIGHTING","HARDCORE",
 "HANDBALL","HALFLIFE","HANDYMAN","HERMETIC","IDEALISM","IDEOLOGY","IMMORTAL","IMPOSTOR","INTERNET","INNOCENT","LEGALITY","LISTENER","LOCATION","LOGISTIC",
 "MARATHON","MEMORIAL","MIDNIGHT","MODELING","MONARCHY","OCCASION","ORGANIZE","OUTSIDER","PACIFIST","PASSPORT","PEDAGOGY","PENALITY","PERIODIC","PHYSIQUE",
 "PIZZERIA","PLAYLIST","POSSIBLE","PRACTICE","PREVIOUS","PROGRESS","PROFILER","RELOCATE","REPUBLIC","RHYTHMIC","ROMANTIC","SANDWICH","SPECIFIC"};


//100 mots
char pioche9 [100][10] = 
{"ABSURDITY","AEROPLANE","AGGRAVATE","ALGORITHM","ALTIMETER","ANIMATION","ANONIMOUS","ANTARCTIC","ANTHOLOGY","APOLOGIZE","BEFFSTEAK","BEHAVIOUR","BIOGRAPHY",
 "BIOMETRIC","BIORHYTHM","BIRTHDAYS","BOOMERANG","BOYFRIEND","BREAKDOWN","BREAKFAST","CALIBRATE","CALENDARS","CALORIFIC","CALCULATE","CAMERAMAN","CAPTIVATE",
 "CARPENTER","CATACLYSM","CELEBRITY","CELESTIAL","CELEBRATE","CHECKBOOK","CHECKROOM","CHOCOLATE","CHRONICLE","CICATRIZE","CIVILIANS","CLEANNESS","COALITION",
 "CLUBHOUSE","COGNITIVE","COLLECTOR","COMMANDER","COMMUNIST","CONDUCTOR","CONNEXION","CONSTRUCT","CONTAGION","CORROSION","COSMONAUT","COUNTDOWN","COUNTABLE",
 "CYBERPUNK","DANGEROUS","DESPERATE","DETECTION","DEVELOPER","DIFFICULT","DIMENSION","DIPLOMACY","DIRECTORY","DISPARATE","DIVERSITY","DUPLICATE","ECOLOGIST",
 "EFFECTUAL","EDUCATION","ELECTORAL","EMERGENCY","EMOTIVITY","EMULATION","ENDURANCE","ENERGETIC","ENUMERATE","ENVIOUSLY","EPIDERMIC","EQUALIZER","ERADICATE",
 "EPICUREAN","ESCALATOR","ESSENTIAL","ETERNALLY","ETYMOLOGY","EXAMINATE","EVOLUTION","EXACTNESS","FABRICATE","FANTASTIC","GANGSTERS","GENERATOR","INCEPTION",
 "INSTITUTE","MALICIOUS","MODERNITY","MYTHOLOGY","NOSTALGIC","OBSCURITY","PANORAMIC","PAPARAZZI","PARTITION"};


//*********************
//*** Les dicos ***
//*********************
#include "dico6.h"
#include "dico7.h"
#include "dico8.h"
#include "dico9.h"

//*********************
//*** Les fonctions ***
//*********************
#include "sons.h"
#include "fonctions.h"
#include "jeux.h"



//*****************************************************************************
//*** MAIN ***
//************
int main(int argc, char ** argv)
{
	PA_Init();
	PA_InitVBL();
	fatInitDefault(); 
	PA_InitSound();
	PA_InitRand();

	#include "sauvegarde.h"

	PA_InitAllSpriteDraw();  // Inits the sprite draw mode, necessary for the pixel-perfect touch detection



	//*******************
	//*** ECRANS HAUT ***
	//*******************
	//* Background 3 :
	PA_Init8bitBg(1, 3); //A mettre en priorité avant tout autre fond et à ne plus toucher 3/8 VRAM

	//* Background 2 :





	//* Background 1 :

	//* Background 0 :



	//******************
	//*** ECRANS BAS ***
	//******************
	//* Background 3 :
	PA_Init8bitBg(0, 3); //A mettre en priorité avant tout autre fond et à ne plus toucher 3/8 VRAM

	//* Background 2 :
	PA_EasyBgLoad(0,2,bg2_bas_menu0);//vide < 512 tiles donc 1/8 VRAM

	//* Background 1 :

	//* Background 0 :



	//***************
	//*** SPRITES ***
	//***************
	PA_LoadSpritePal(0,0, (void*)rond_16x16_choix_nbr_lettre_Pal);
	PA_CreateSprite(0,0, (void*)rond_16x16_choix_nbr_lettre_Sprite, OBJ_SIZE_16X16,1,0, -16, -16);

	PA_LoadSpritePal(1,1, (void*)joueurs_64x64_choix_joueurs_Pal);
	PA_CreateSprite(1,67, (void*)joueurs_64x64_choix_joueurs_Sprite, OBJ_SIZE_64X64,1,1, -64, -64);
	PA_SetSpriteRotEnable(1, 67, 0);

	PA_LoadSpritePal(1,2, (void*)joueurs_32x32_choix_joueurs_petit_Pal);
	PA_CreateSprite(1,1, (void*)joueurs_32x32_choix_joueurs_petit_Sprite, OBJ_SIZE_32X32,1,2, -32, -32);
	PA_SetSpriteRotEnable(1, 1, 1);

	PA_LoadSpritePal(1,4, (void*)factice_32x32_Pal);
	PA_CreateSprite(1,68, (void*)factice_32x32_Sprite, OBJ_SIZE_32X32,1,4, -32, -32);

	PA_LoadSpritePal(0,2, (void*)touche_64x32_choix_lettres_Pal);
	PA_CreateSprite(0,2, (void*)touche_64x32_choix_lettres_Sprite, OBJ_SIZE_64X32,1,2, -32, -64);

	PA_LoadSpritePal(0,3, (void*)resul_64x32_solution1_2_Pal);
	PA_CreateSprite(0,4, (void*)resul_64x32_solution1_2_Sprite, OBJ_SIZE_64X32,1,3, -64, -32);

	PA_LoadSpritePal(0,4, (void*)resul_64x32_solution2_2_Pal);
	PA_CreateSprite(0,5, (void*)resul_64x32_solution2_2_Sprite, OBJ_SIZE_64X32,1,4, -64, -32);

	PA_LoadSpritePal(0,5, (void*)touche_64x32_play_menu_Pal);
	PA_CreateSprite(0,6, (void*)touche_64x32_play_menu_Sprite, OBJ_SIZE_64X32,1,5, -64, -32);

	PA_LoadSpritePal(0,6, (void*)curseur_16x16_Pal);
	PA_CreateSprite(0,7, (void*)curseur_16x16_Sprite, OBJ_SIZE_16X16,1,6, -16, -16);


	for (t=3; t<67; t++)
	{
		PA_LoadSpritePal(1,3, (void*)case_16x16_valide_rouge_jaune_Pal);
		PA_CreateSprite(1,t, (void*)case_16x16_valide_rouge_jaune_Sprite, OBJ_SIZE_16X16,1,3, -16, -16);
	}	


	//*************
	//*** INTRO ***
	//*************
	effet_lumiere_masquer(1,1);//ecran haut, ecran bas (0 = non, 1 = oui), ici effet sur les 2 écrans
		PA_LoadGif(1, (void*)bg3_haut_intro);
		PA_LoadGif(0, (void*)bg3_bas_intro);
	effet_lumiere_voir(1,1);//ecran haut, ecran bas (0 = non, 1 = oui), ici effet sur les 2 écrans

	attente_ou_touche(300);//5s




	

	while (1)
	{
		//MENU GENERAL


		effet_lumiere_masquer(1,1);//ecran haut, ecran bas (0 = non, 1 = oui), ici effet sur les 2 écrans
			PA_SetSpriteXY(0, 0, -16, -16);PA_SetSpriteXY(1, 67, -64, -64);PA_SetSpriteXY(1, 1, -32, -32);
			PA_SetSpriteXY(0, 2, -32, -32);PA_SetSpriteXY(0, 6, -64, -32);	PA_SetSpriteXY(0, 7, -16, -16);
			PA_LoadGif(1, (void*)bg3_haut_menu);PA_EasyBgLoad(1,2,bg2_bas_menu0);PA_EasyBgLoad(1,1,bg2_bas_menu0);
			PA_LoadGif(0, (void*)bg3_bas_menu);PA_EasyBgLoad(0,2,bg2_bas_menu0);PA_EasyBgLoad(0,1,bg2_bas_menu0);
		effet_lumiere_voir(1,1);//ecran haut, ecran bas (0 = non, 1 = oui), ici effet sur les 2 écrans


		PA_PlaySoundRepeat(0, motus);


		startmenu = 2;valid =0;centieme=0;invers=0;
		
		while (startmenu == 2)
		{
			PA_SetSpriteXY(1, 68, 0, (centieme/60)*32);
			if (invers==0) centieme++;if (invers==1) centieme--;if ( centieme==30 ){ invers=0; }if ( centieme==330 ){ invers=1; }

			if (Stylus.Newpress)
			{
				PA_SetSpriteXY(1, 68, -32, -32);
				//*********************************************
				//*** PLAY ***
				//************
				if ( PA_StylusInZone(113,28,228,55) )
				{

					son_clik();
					PA_EasyBgLoad(0,2,bg2_bas_menu1);
					temporisation(30);point_j1=0;

					effet_lumiere_masquer(0,1);//ecran haut, ecran bas (0 = non, 1 = oui), ici effet sur l'écran du bas uniquement
					PA_EasyBgLoad(0,2,bg2_bas_menu0);//masquer l'écran du bouton enfoncée sur le menu

					PA_LoadGif(0, (void*)bg3_bas_jeu_mode);

					PA_EasyBgLoad(0,2,bg2_bas_jeu1);
                            		PA_SetSpriteXY(0, 0, 176, 64);//bouton radio sur le choix 1
                            		nbre_lettres = 6;mode_de_jeu = 1;
					colonnes = 0; lignes = 0;
					
					effet_lumiere_voir(0,1);//ecran haut, ecran bas (0 = non, 1 = oui), ici effet sur l'écran du bas uniquement

					//*** ICI LA PROGRAMMATION DU CHOIX DE JEU ***
					choix_mode_nbre_lettres();
					PA_StopSound(0);
					if (startmenu == 3)
					{
						jouer();
					}

					son_quitter();

					startmenu = 1;
				}
				//*********************************************
				//*** INSTRUCTION ***
				//*******************
				else if ( PA_StylusInZone(113,64,228,91) )
				{
					son_clik();
					PA_EasyBgLoad(0,2,bg2_bas_menu2);
					temporisation(30);

					effet_lumiere_masquer(1,1);//ecran haut, ecran bas (0 = non, 1 = oui), ici effet sur les 2 écrans
						PA_EasyBgLoad(0,2,bg2_bas_menu0);//masquer l'écran du bouton enfoncée sur le menu

						PA_LoadGif(1, (void*)bg3_haut_instruction);
						PA_LoadGif(0, (void*)bg3_bas_instruction);
					effet_lumiere_voir(1,1);//ecran haut, ecran bas (0 = non, 1 = oui), ici effet sur les 2 écrans

					pause();PA_SetSpriteAnim(0, 6, 3);PA_SetSpriteXY(0, 6, 15, 156);

					son_quitter();

					startmenu = 1;
				}
				//*********************************************
				//*** CREDITS ***
				//***************
				else if ( PA_StylusInZone(113,100,228,127) )
				{
					son_clik();
					PA_EasyBgLoad(0,2,bg2_bas_menu3);
					temporisation(30);

					effet_lumiere_masquer(0,1);//ecran haut, ecran bas (0 = non, 1 = oui), ici effet sur l'écran du bas uniquement
						PA_EasyBgLoad(0,2,bg2_bas_menu0);//masquer l'écran du bouton enfoncée sur le menu

						PA_LoadGif(0, (void*)bg3_bas_credits);
					effet_lumiere_voir(0,1);//ecran haut, ecran bas (0 = non, 1 = oui), ici effet sur l'écran du bas uniquement

					pause();PA_SetSpriteAnim(0, 6, 2);PA_SetSpriteXY(0, 6, 8, 165);

					son_quitter();

					startmenu = 1;
				}
				//*********************************************
				//*** SCORES ***
				//**************
				else if ( PA_StylusInZone(113,136,228,163) )
				{
					son_clik();
					PA_EasyBgLoad(0,2,bg2_bas_menu4);
					temporisation(30);

					effet_lumiere_masquer(0,1);//ecran haut, ecran bas (0 = non, 1 = oui), ici effet sur l'écran du bas uniquement
						PA_EasyBgLoad(0,2,bg2_bas_menu0); //masquer l'écran du bouton enfoncée sur le menu

						PA_LoadGif(0, (void*)bg3_bas_scores);
					effet_lumiere_voir(0,1);//ecran haut, ecran bas (0 = non, 1 = oui), ici effet sur l'écran du bas uniquement

					//*** ICI LA ROUTINE POUR AFFICHER LES SCORES ***

					afficher_scores();
					pause();

					son_quitter();PA_SetSpriteAnim(0, 6, 2);PA_SetSpriteXY(0, 6, 8, 165);
					startmenu = 1;
				}
				Stylus.Newpress = false;
			}
			PA_WaitForVBL();
		}
	}
	return 0;
}

