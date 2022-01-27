#include "CWeapon.h"


/*Cette méthode est un getter()
Elle retourne un std::string du membre protegé m_nom de la classe CWeapon
*/
std::string CWeapon::getm_nom()
{
	return m_nom;
}

/*Cette méthode est un getter()
Elle retourne un entier du membre protegé m_dommage de la classe CWeapon
*/
int CWeapon::getm_dommage()
{
	return m_dommage;
}

/*Cette méthode est un getter()
Elle retourne un int du membre protegé m_bonus de la classe CWeapon
*/
int CWeapon::getm_bonus()
{
	return m_bonus;
}

/*Cette méthode est un getter()
Elle retourne un int du membre protegé m_criticalStrike de la classe CWeapon
*/
int CWeapon::getm_criticalStrike()
{
	return m_criticalStrike;
}

/*Cette méthode est un setter()
Elle initialise le membre protegé m_nom de la classe CWeapon
avec le paramètre de cette méthode
@p_nom string permetant d'innitialiser le membre m_nom
*/
void CWeapon::setm_nom(std::string p_nom)
{
	m_nom = p_nom;
}

/*Cette méthode est un setter()
Elle initialise le membre protegé m_dommage de la classe CWeapon
avec le paramètre de cette méthode
@p_dommage entier permetant d'innitialiser le membre m_dommage
*/
void CWeapon::setm_dommage(int p_dommage)
{
	m_dommage = p_dommage;
}

/*Cette méthode est un setter()
Elle initialise le membre protegé m_bonus de la classe CWeapon
avec le paramètre de cette méthode
@p_bonus entier permetant d'innitialiser le membre m_bonus
*/
void CWeapon::setm_bonus(int p_bonus)
{
	m_bonus = p_bonus;
}

/*Cette méthode est un setter()
Elle initialise le membre protegé m_criticalStrike de la classe CWeapon
avec le paramètre de cette méthode
@p_criticalStrike string entier permetant innitialiser le membre m_criticalStrike
*/
void CWeapon::setm_criticalStrike(int p_criticalStrike)
{
	m_criticalStrike = p_criticalStrike;
}

CWeapon::CWeapon()
{

}

/*Cette méthode est le constructeur surchargé de la classe.
Elle initialise les membres protegés de la classe CWeapon
avec les différents paramètres de cette méthode
@p_nom string permetant d'innitialiser le membre m_nom
@p_dommage entier permetant d'innitialiser le membre m_dommage
@p_bonus entier permetant d'innitialiser le membre m_bonus
@p_criticalStrike entier permetant innitialiser le membre m_criticalStrike
*/
CWeapon::CWeapon(std::string p_nom, int p_dommage, int p_bonus, int p_criticalStrike)
{
	setm_nom(p_nom);
	setm_dommage(p_dommage);
	setm_bonus(p_bonus);
	setm_criticalStrike(p_criticalStrike);
}

/*Cette méthode permets de déterminer, de façon aléatoire en fonction 
du membre m_criticalStrike s'il y a un coup critique !
*/
bool CWeapon::criticalStrike()
{
	srand((unsigned)time(0));
	int nombre_aleatoire = 0;
	nombre_aleatoire = rand() % 100;
	if (getm_criticalStrike() > nombre_aleatoire)
	{
		std::cout << "coup critique !" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

CWeapon::~CWeapon()
{

}
