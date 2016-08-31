//****************
//*** BRUITAGE ***
//****************
u8 moncanal = 10;

#include "motus.h" //data/motus.raw
#include "bruitage_click.h" //data/bruitage_click.raw
void son_clik() 
{
	moncanal++;
	if (moncanal > 15)
	{
		moncanal = 10;
	}
	PA_PlaySimpleSound(moncanal,bruitage_click);
}

#include "bruitage_quitter.h" //data/bruitage_quitter.raw
void son_quitter()
{
	moncanal++;
	if (moncanal > 15)
	{
		moncanal = 10;
	}
	PA_WaitForVBL();
	PA_PlaySimpleSound(moncanal,bruitage_quitter);
	PA_WaitForVBL();
}

#include "presque.h" //data/presque.raw
#include "bon.h" //data/bon.raw
#include "pasbon.h" //data/pasbon.raw
void son_cases(u8 son_verif)
{
	if (son_verif == 1)
	{
		PA_PlaySimpleSound(0,bon);
	}
	if (son_verif == 2)
	{
		PA_PlaySimpleSound(0,presque);
	}
	if (son_verif == 3)
	{
		PA_PlaySimpleSound(0,pasbon);
	}
	if (son_verif == 0)
	{

	}
}
#include "gagne.h"
void son_gagne() 
{
	moncanal++;
	if (moncanal > 15)
	{
		moncanal = 10;
	}
	PA_PlaySimpleSound(moncanal,gagne);
}


#include "ho.h"
void son_ho() 
{
	moncanal++;
	if (moncanal > 15)
	{
		moncanal = 10;
	}
	PA_PlaySimpleSound(moncanal,ho);
}


#include "superho.h"
void son_superho() 
{
	moncanal++;
	if (moncanal > 15)
	{
		moncanal = 10;
	}
	PA_PlaySimpleSound(moncanal,superho);
}


#include "superapplause.h"
void son_superapplause() 
{
	moncanal++;
	if (moncanal > 15)
	{
		moncanal = 10;
	}
	PA_PlaySimpleSound(moncanal,superapplause);
}


#include "change.h"
void son_change() 
{
	moncanal++;
	if (moncanal > 15)
	{
		moncanal = 10;
	}
	PA_PlaySimpleSound(moncanal,change);
}






