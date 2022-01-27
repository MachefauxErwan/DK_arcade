#include "CParserWeapons.h"




/*Cette méthode est un getter()
Elle retourne une std::map<std::string, CStaff*> du membre protegé m_mapStaff de la classe CParserWeapons
*/
std::map<std::string, CStaff*> CParserWeapons::getm_mapStaff()
{
	return m_mapStaff;
}

/*Cette méthode est un getter()
Elle retourne une std::map<std::string, CSword*> du membre protegé m_mapSword de la classe CParserWeapons
*/
std::map<std::string, CSword*> CParserWeapons::getm_mapSword()
{
	return m_mapSword;
}

/*Cette méthode est un getter()
Elle retourne une std::map<std::string, CBow*> du membre protegé m_mapBow de la classe CParserWeapons
*/
std::map<std::string, CBow*> CParserWeapons::getm_mapBow()
{
	return m_mapBow;
}


/*Cette méthode est un setter()
Elle initialise le membre protegé m_mapStaff de la classe CParserWeapons
avec le paramètre de cette méthode
@p_mapStaff std::map<std::string, CStaff*> permetant d'innitialiser le membre m_mapStaff
*/
void CParserWeapons::setm_mapStaff(std::map<std::string, CStaff*> p_mapStaff)
{
	m_mapStaff = p_mapStaff;
}

/*Cette méthode est un setter()
Elle initialise le membre protegé m_mapSword de la classe CParserWeapons
avec le paramètre de cette méthode
@p_mapSword std::map<std::string, CStaff*> permetant d'innitialiser le membre m_mapSword
*/
void CParserWeapons::setm_mapSword(std::map<std::string, CSword*> p_mapSword)
{
	m_mapSword = p_mapSword;
}

/*Cette méthode est un setter()
Elle initialise le membre protegé m_mapBow de la classe CParserWeapons
avec le paramètre de cette méthode
@p_mapBow std::map<std::string, CStaff*> permetant d'innitialiser le membre m_mapBow
*/
void CParserWeapons::setm_mapBow(std::map<std::string, CBow*> p_mapBow)
{
	m_mapBow = p_mapBow;
}


/*Cette méthode est un setter()
Elle initialise les maps de la classe CParserWeapons.
@p_nomFichier std::string est le nom du fichier pour initialiser les maps
*/
void CParserWeapons::setMapWeapons(std::string p_nomFichier)
{
	lireFichier(p_nomFichier);
	std::map<std::string, CStaff*> l_mapStaff;
	std::map<std::string, CSword*> l_mapSword;
	std::map<std::string, CBow*> l_mapBow;
	for (unsigned i = 0; i < getm_ligneFichier().size(); i++)
	{

		if (m_ligneFichier[i] == "Baton")
		{
			l_mapStaff[getm_ligneFichier()[i + 1]] = new CStaff(getm_ligneFichier()[i + 1], std::stoi(getm_ligneFichier()[i + 2]), std::stoi(getm_ligneFichier()[i + 3]), std::stoi(getm_ligneFichier()[i + 4]), std::stoi(getm_ligneFichier()[i + 5]));
		}
		if (m_ligneFichier[i] == "Epee")
		{
			l_mapSword[getm_ligneFichier()[i + 1]] = new CSword(getm_ligneFichier()[i + 1], std::stoi(getm_ligneFichier()[i + 2]), std::stoi(getm_ligneFichier()[i + 3]), std::stoi(getm_ligneFichier()[i + 4]), std::stoi(getm_ligneFichier()[i + 5]), std::stoi(getm_ligneFichier()[i + 5]));
		}
		if (m_ligneFichier[i] == "Arc")
		{

			l_mapBow[getm_ligneFichier()[i + 1]] = new CBow(getm_ligneFichier()[i + 1], std::stoi(getm_ligneFichier()[i + 2]), std::stoi(getm_ligneFichier()[i + 3]), std::stoi(getm_ligneFichier()[i + 4]), std::stoi(getm_ligneFichier()[i + 5]));
		}
	}
	setm_mapBow(l_mapBow);
	setm_mapStaff(l_mapStaff);
	setm_mapSword(l_mapSword);
}


CParserWeapons::CParserWeapons()
{
}

CParserWeapons::~CParserWeapons()
{

}
