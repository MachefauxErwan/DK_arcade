#include "CParserCharacters.h"



/*Cette m�thode est un setter()
Elle initialise les maps de la classe CParserCharacters.
@p_nomFichier std::string est le nom du fichier pour initialiser les maps.
*/
void CParserCharacters::setMapCharacters(std::string p_nomFichier)
{
	lireFichier(p_nomFichier);
	std::map<std::string, CMage*> l_mapMage;
	std::map<std::string, CWarrior*> l_mapWarrior;
	std::map<std::string, CArcher*> l_mapArcher;
	std::vector<std::string> l_ligneFichier;
	for (unsigned i = 0; i < getm_ligneFichier().size(); i++)
	{

		if (getm_ligneFichier()[i] == "Mage")
		{
			//CMage(std::string p_nom, int p_hpMax, CStaff * baton, float p_dodge, int p_intellect, int p_manaMax);
			CStaff* baton1 = new CStaff("baton par default", 7, 20, 15, 6);
			l_mapMage[getm_ligneFichier()[i + 1]] = new CMage(getm_ligneFichier()[i + 1], std::stoi(getm_ligneFichier()[i + 2]), baton1, std::stoi(m_ligneFichier[i + 3]), std::stoi(getm_ligneFichier()[i + 4]), std::stoi(getm_ligneFichier()[i + 5]));
			
		}
		if (getm_ligneFichier()[i] == "Guerrier")
		{
			//CWarrior(std::string p_nom, int p_hpMax, CSword *p_weapon, float p_dodge, int p_attack, int p_shield);
			CSword* epee1 = new CSword("epee par default", 15, 10, 20, 20, 20);
			l_mapWarrior[getm_ligneFichier()[i + 1]] = new CWarrior(getm_ligneFichier()[i + 1], std::stoi(getm_ligneFichier()[i + 2]), epee1, std::stoi(getm_ligneFichier()[i + 3]), std::stoi(getm_ligneFichier()[i + 4]), std::stoi(getm_ligneFichier()[i + 5]));
		}
		if (getm_ligneFichier()[i] == "Archer")
		{
			//CArcher(std::string p_nom, int p_hpMax, CBow *arc, float p_dodge, float p_agility);
			CBow* bow = new CBow("arc par default", 10, 10, 12, 10);
			l_mapArcher[getm_ligneFichier()[i + 1]] = new CArcher(getm_ligneFichier()[i + 1], std::stoi(getm_ligneFichier()[i + 2]), bow, std::stoi(getm_ligneFichier()[i + 3]), std::stoi(getm_ligneFichier()[i + 4]));
		}
	}
	setm_mapMage(l_mapMage);
	setm_mapWarrior(l_mapWarrior);
	setm_mapArcher(l_mapArcher);
}


/*Cette m�thode est un getter()
Elle retourne une std::map<std::string, CMage*> du membre proteg� m_mapMage de la classe CParserWeapons
*/
std::map<std::string, CMage*> CParserCharacters::getm_mapMage()
{
	return m_mapMage;
}

/*Cette m�thode est un getter()
Elle retourne une std::map<std::string, CWarrior*> du membre proteg� m_mapWarrior de la classe CParserWeapons
*/
std::map<std::string, CWarrior*> CParserCharacters::getm_mapWarrior()
{
	return m_mapWarrior;
}

/*Cette m�thode est un getter()
Elle retourne une std::map<std::string, CArcher*> du membre proteg� m_mapArcher de la classe CParserWeapons
*/
std::map<std::string, CArcher*> CParserCharacters::getm_mapArcher()
{
	return m_mapArcher;
}




/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_mapMage de la classe CParserCharacters
avec le param�tre de cette m�thode
@p_mapMage std::map<std::string, CStaff*> permetant d'innitialiser le membre m_mapMage
*/
void CParserCharacters::setm_mapMage(std::map<std::string, CMage*> p_mapMage )
{
	m_mapMage = p_mapMage;
}

/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_mapWarrior de la classe CParserCharacters
avec le param�tre de cette m�thode
@p_mapWarrior std::map<std::string, CStaff*> permetant d'innitialiser le membre m_mapWarrior
*/
void CParserCharacters::setm_mapWarrior(std::map<std::string, CWarrior*> p_mapWarrior)
{
	m_mapWarrior = p_mapWarrior;
}

/*Cette m�thode est un setter()
Elle initialise le membre proteg� p_mapMage de la classe CParserCharacters
avec le param�tre de cette m�thode
@p_mapArcher std::map<std::string, CStaff*> permetant d'innitialiser le membre m_mapArcher
*/
void CParserCharacters::setm_mapArcher(std::map<std::string, CArcher*> p_mapArcher)
{
	m_mapArcher = p_mapArcher;
}

CParserCharacters::CParserCharacters()
{

}

CParserCharacters::~CParserCharacters()
{

}
