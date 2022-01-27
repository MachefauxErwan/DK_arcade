#include "CJeu.h"



/*Cette méthode affiche sur la console le menu pour le choix du personnage */
CCharacter* CJeu::MenuChoixPerso()
{
	CParserCharacters parser;
	parser.setMapCharacters("characters.txt");
	std::string menu;
	int menuChoixCharactere;
	int nbrperso = 1;
	bool verrou = true;
	std::cout << "taper 1 : Archer " << std::endl;
	std::cout << "taper 2 : Mage " << std::endl;
	std::cout << "taper 3 : Guerrier " << std::endl;
	std::cin >> menuChoixCharactere;

	switch (menuChoixCharactere)
	{
	case 1: {
		return MenuChoixArcher();
		break;
	}
	case 2: {
		return MenuChoixMage();
		break;
	}
	case 3:
	{
		return MenuChoixWarrior();
		break;
	}
	}
}


/*Cette méthode affiche sur la console le menu pour le choix du guerrier */
CWarrior * CJeu::MenuChoixWarrior()
{
	CParserCharacters parser;
	parser.setMapCharacters("characters.txt");
	std::map<std::string, CWarrior*> l_mapWarrior;
	l_mapWarrior= parser.getm_mapWarrior();
	std::vector<std::string> l_NomKey;
	std::string menu;
	int menuChoixCharactere;
	bool verrou = true;
	std::cout << "Guerrier" << std::endl;
	
	for (std::map<std::string, CWarrior*>::iterator it = l_mapWarrior.begin(); it != l_mapWarrior.end(); it++)
	{
		//CWarrior(std::string p_nom, int p_hpMax, CSword *p_weapon, float p_dodge,int p_attack, int p_shield);
		l_NomKey.push_back(it->first);
		std::cout << "taper " << it->first << " : " << " Hp(" << it->second->getm_hpMax() << "), dodge("
			<< it->second->getm_dodge() << "), attack(" << it->second->getm_attack() << ")" << ", shield(" << it->second->getm_shield() << ")" << std::endl;
	}
	do
	{
		std::cout << "veulliez choisir un personnage" << std::endl;
		std::getline(std::cin, menu);
		for (unsigned i = 0; i < l_NomKey.size(); i++)
		{
			if (!menu.compare(l_NomKey[i]))
			{
				verrou = false;
			}

		}

	} while (verrou);
	//CWarrior(std::string p_nom, int p_hpMax, CSword *p_weapon, float p_dodge,int p_attack, int p_shield);

	CWarrior* guerrier = new CWarrior(parser.getm_mapWarrior()[menu]->getm_nom(), parser.getm_mapWarrior()[menu]->getm_hpMax(), MenuChoixSword(), parser.getm_mapWarrior()[menu]->getm_dodge(), parser.getm_mapWarrior()[menu]->getm_attack(), parser.getm_mapWarrior()[menu]->getm_shield());
	return guerrier;
}

/*Cette méthode affiche sur la console le menu pour le choix de l'archer */
CArcher * CJeu::MenuChoixArcher()
{
	CParserCharacters parser;
	parser.setMapCharacters("characters.txt");
	std::map<std::string, CArcher*> l_mapArcher;
	l_mapArcher = parser.getm_mapArcher();
	std::vector<std::string> l_NomKey;
	std::string menu;
	int menuChoixCharactere;
	bool verrou = true;
	std::cout << "Archer" << std::endl;

	for (std::map<std::string, CArcher*>::iterator it = l_mapArcher.begin(); it != l_mapArcher.end(); it++)
	{
		//CArcher(std::string p_nom, int p_hpMax, CBow *arc, float p_dodge, float p_agility);
		l_NomKey.push_back(it->first);
		std::cout << "taper " << it->first << " : " << " Hp(" << it->second->getm_hpMax() << "), dodge("
			<< it->second->getm_dodge() << "), agility(" << it->second->getm_agility() << ")" << std::endl;
		
	}
	do
	{
		std::cout << "veulliez choisir un personnage" << std::endl;
		std::getline(std::cin, menu);
		for (unsigned i = 0; i < l_NomKey.size(); i++)
		{
			if (!menu.compare(l_NomKey[i]))
			{
				verrou = false;
			}

		}

	} while (verrou);
	

	CArcher* archer = new CArcher(parser.getm_mapArcher()[menu]->getm_nom(), parser.getm_mapArcher()[menu]->getm_hpMax(), MenuChoixBow(), parser.getm_mapArcher()[menu]->getm_dodge(), parser.getm_mapArcher()[menu]->getm_agility());
	return archer;
}

/*Cette méthode affiche sur la console le menu pour le choix du mage */
CMage * CJeu::MenuChoixMage()
{

	CParserCharacters parser;
	parser.setMapCharacters("characters.txt");
	std::map<std::string, CMage*> l_mapMage;
	l_mapMage = parser.getm_mapMage();
	std::vector<std::string> l_NomKey;
	std::string menu;
	int menuChoixCharactere;
	bool verrou = true;
	std::cout << "Mage" << std::endl;
	for (std::map<std::string, CMage*>::iterator it = l_mapMage.begin(); it != l_mapMage.end(); it++)
	{
		//CMage(std::string p_nom, int p_hpMax, CStaff * baton, float p_dodge, int p_intellect, int p_manaMax);
		l_NomKey.push_back(it->first);
		std::cout << "taper " << it->first << " : " << " Hp(" << it->second->getm_hpMax() << "), dodge("
			<< it->second->getm_dodge() << "), intellect(" << it->second->getm_intellect() << ")" << ", Mana(" << it->second->getm_mana() << ")" << std::endl;
	}
	do
	{
		std::cout << "veulliez choisir un personnage" << std::endl;
		std::getline(std::cin, menu);
		for (unsigned i = 0; i < l_NomKey.size(); i++)
		{
			if (!menu.compare(l_NomKey[i]))
			{
				verrou = false;
			}

		}
	} while (verrou);

	CMage* mage = new CMage(parser.getm_mapMage()[menu]->getm_nom(), parser.getm_mapMage()[menu]->getm_hpMax(), MenuChoixStaff(), parser.getm_mapMage()[menu]->getm_dodge(), parser.getm_mapMage()[menu]->getm_intellect(), parser.getm_mapMage()[menu]->getm_manaMax());
	return mage;
}

/*Cette méthode affiche sur la console le menu pour le choix de l'arc */
CBow * CJeu::MenuChoixBow()
{
	CParserWeapons parser;
	parser.setMapWeapons("weapons.txt");
	std::map<std::string, CBow*> l_mapBow;
	l_mapBow = parser.getm_mapBow();
	std::vector<std::string> l_NomKey;
	std::string menu;
	int nbrArme = 1;
	bool verrou = true;
	for (std::map<std::string, CBow*>::iterator it = l_mapBow.begin(); it != l_mapBow.end(); it++)
	{
		l_NomKey.push_back(it->first);
		std::cout << "taper " << it->first << " : " << " dommage(" << it->second->getm_dommage() << "), bonus("
			<< it->second->getm_bonus() << "), criticalStrike(" << it->second->getm_criticalStrike() << "), nbArrow("
			<< it->second->getm_nbArrow() << ")" << std::endl;
		nbrArme++;
	}
	do
	{
		std::cout << "veulliez choisir une arme" << std::endl;
		std::getline(std::cin, menu);
		for (unsigned i = 0; i < l_NomKey.size(); i++)
		{
			if (!menu.compare(l_NomKey[i]))
			{
				verrou = false;
			}

		}

	} while (verrou);

	std::cout << menu << std::endl;

	CBow* arc = new CBow(l_mapBow[menu]->getm_nom(), l_mapBow[menu]->getm_dommage(), l_mapBow[menu]->getm_bonus(), l_mapBow[menu]->getm_criticalStrike(), l_mapBow[menu]->getm_nbArrow());
	return arc;


}

/*Cette méthode affiche sur la console le menu pour le choix du baton */
CStaff * CJeu::MenuChoixStaff()
{
	CParserWeapons parser;
	parser.setMapWeapons("weapons.txt");
	std::map<std::string, CStaff*> l_mapStaff;
	l_mapStaff = parser.getm_mapStaff();
	std::vector<std::string> l_NomKey;
	std::string menu;
	int nbrArme = 1;
	bool verrou = true;
	for (std::map<std::string, CStaff*>::iterator it = l_mapStaff.begin(); it != l_mapStaff.end(); it++)
	{
		l_NomKey.push_back(it->first);
		std::cout << "taper " << it->first << " : " << " dommage(" << it->second->getm_dommage() << "), bonus("
			<< it->second->getm_bonus() << "), criticalStrike(" << it->second->getm_criticalStrike() << "), manaCost("
			<< it->second->getm_manaCost() << ")" << std::endl;
		nbrArme++;
	}
	do
	{
		std::cout << "veulliez choisir une arme" << std::endl;
		std::getline(std::cin, menu);
		for (unsigned i = 0; i < l_NomKey.size(); i++)
		{
			if (!menu.compare(l_NomKey[i]))
			{
				verrou = false;
			}

		}

	} while (verrou);

	std::cout << menu << std::endl;
	CStaff* baton = new CStaff(l_mapStaff[menu]->getm_nom(), l_mapStaff[menu]->getm_dommage(), l_mapStaff[menu]->getm_bonus(), l_mapStaff[menu]->getm_criticalStrike(), l_mapStaff[menu]->getm_manaCost());
	return baton;
}

/*Cette méthode affiche sur la console le menu pour le choix de l'épée */
CSword* CJeu::MenuChoixSword()
{
	CParserWeapons parser;
	parser.setMapWeapons("weapons.txt");
	std::map<std::string, CSword*> l_mapSword;
	l_mapSword = parser.getm_mapSword();
	std::vector<std::string> l_NomKey;
	std::string menu;
	int nbrArme = 1;
	bool verrou = true;
	for (std::map<std::string, CSword*>::iterator it = l_mapSword.begin(); it != l_mapSword.end(); it++)
	{
		l_NomKey.push_back(it->first);
		std::cout << "taper " << it->first << " : " << " dommage(" << it->second->getm_dommage() << "), bonus("
			<< it->second->getm_bonus() << "), criticalStrike(" << it->second->getm_criticalStrike() << "), durability("
			<< it->second->getm_durability() << ")" << std::endl;
		nbrArme++;
	}
	do
	{
		std::cout << "veulliez choisir une arme" << std::endl;
		std::getline(std::cin, menu);
		for (unsigned i = 0; i < l_NomKey.size(); i++)
		{
			if (!menu.compare(l_NomKey[i]))
			{
				verrou = false;
			}

		}

	} while (verrou);

	std::cout << menu << std::endl;
	CSword* epee = new CSword(l_mapSword[menu]->getm_nom(), l_mapSword[menu]->getm_dommage(), l_mapSword[menu]->getm_bonus(), l_mapSword[menu]->getm_criticalStrike(), l_mapSword[menu]->getm_durability(), l_mapSword[menu]->getm_durabilityMax());
	return epee;
}




/*Cette méthode est le constructeur de la classe.
Il vient démarrer le jeu de combat tour par tour avec le choix des personnages et des armes.
*/
CJeu::CJeu()
{
	
	CStaff* baton1 = new CStaff("Baguette de Sureau", 7, 20, 15, 6);
	CStaff* baton2 = new CStaff("Atiesh", 10, -15, 12, 7);
	CCharacter* perso1 = MenuChoixPerso();
	CCharacter* perso2 = MenuChoixPerso();

	std::cout << "vie de "<< perso1->getm_nom() <<" : "<< perso1->getm_hp() << std::endl;
	std::cout << "vie de " << perso2->getm_nom() << " : " << perso2->getm_hp() << std::endl;
	int i=0;
	while (perso1->isAlive() == true && perso2->isAlive() == true)
	{
	std::cout << "--------------------Round " << i << "------------------------" << std::endl;
	std::cout << "" << std::endl;
	perso1->action(perso2);
	perso2->action(perso1);
	std::cout << "vie de " << perso1->getm_nom() << " : " << perso1->getm_hp() << std::endl;
	std::cout << "vie de " << perso2->getm_nom() << " : " << perso2->getm_hp() << std::endl;
	i++;
	}
}

CJeu::~CJeu()
{
}
