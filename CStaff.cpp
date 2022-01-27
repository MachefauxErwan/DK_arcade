#include "CStaff.h"

/*Cette méthode est un setter()
Elle initialise le membre protegé m_manaCost de la classe CStaff
avec le paramètre de cette méthode
@p_manaCost entier permetant d'innitialiser le membre m_manaCost
*/
void CStaff::setm_manaCost(int p_manaCost)
{
	m_manaCost = p_manaCost;
}

/*Cette méthode est un getter()
Elle retourne un entier du membre protegé m_manaCost de la classe CStaff
*/
int CStaff::getm_manaCost()
{
	return m_manaCost;
}

/*Cette méthode est le constructeur surchargé de la classe.
Elle initialise les membres protegés de la classe CStaff
avec les différents paramètres de cette méthode
@p_nom string permetant d'innitialiser le membre m_nom
@p_dommage entier permetant d'innitialiser le membre m_dommage
@p_bonus entier permetant d'innitialiser le membre m_bonus
@p_criticalStrike entier permetant d'innitialiser le membre m_criticalStrike
@p_manaCost entier permetant innitialiser le membre m_manaCost
*/
CStaff::CStaff(std::string p_nom, int p_dommage, int p_bonus, int p_criticalStrike, int p_manaCost) : CWeapon(p_nom, p_dommage, p_bonus, p_criticalStrike)
{
	setm_manaCost(p_manaCost);
}

CStaff::~CStaff()
{

}
