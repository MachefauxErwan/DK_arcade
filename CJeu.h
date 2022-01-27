#ifndef _CJeu_h
#define _CJeu_h
#include <string>
#include <iostream>
#include "CWeapon.h"
#include <ctime>
#include "CCharacter.h"
#include "CStaff.h"
#include "CBow.h"
#include "CSword.h"
#include "CParserWeapons.h"
#include "CParserCharacters.h"

class CJeu
{
protected:
public:
	
	//setter()
	//getter()
	// m�thodes Masqu�e

	CCharacter* MenuChoixPerso();
	CWarrior* MenuChoixWarrior();
	CArcher* MenuChoixArcher();
	CMage* MenuChoixMage();
	CBow* MenuChoixBow();
	CStaff* MenuChoixStaff();
	CSword* MenuChoixSword();
	// autre m�thode
	CJeu();
	~CJeu();
private:

};

#endif // !_CJeu_h
