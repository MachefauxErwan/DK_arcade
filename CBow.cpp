#include "CBow.h"

/*Cette méthode est un setter()
Elle initialise le membre protegé m_nbArrow de la classe CBow
avec le paramètre de cette méthode
@p_nbArrow entier permetant d'innitialiser le membre m_nbArrow
*/
void CBow::setm_nbArrow(int p_nbArrow)
{
	m_nbArrow = p_nbArrow;
}

/*Cette méthode est un getter()
Elle retourne un entier du membre protegé m_nbArrow de la classe CBow
*/
int CBow::getm_nbArrow()
{
	return m_nbArrow;
}

/*Cette méthode indique si l'archer à encore des fléches .*/
bool CBow::haveArrows()
{
	if (0 <= getm_nbArrow())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*Cette méthode permet à l'arc de tirer une fléche et de réduire le nombre de fléche dans son carcois*/
void CBow::shoot()
{
	if (haveArrows() == true)
	{
		setm_nbArrow(getm_nbArrow() - 1);
		if (0 == getm_nbArrow())
		{
			setm_nbArrow(0);
			std::cout << "vous n'avez plus de flèches " << std::endl;
		}
	}
	else
	{
		std::cout << "vous n'avez plus de flèches " << std::endl;
	}
}

/*Cette méthode est le constructeur surchargé de la classe.
Elle initialise les membres protegés de la classe CSword
avec les différents paramètres de cette méthode
@p_nom string permetant d'innitialiser le membre m_nom
@p_dommage entier permetant d'innitialiser le membre m_dommage
@p_bonus entier permetant d'innitialiser le membre m_bonus
@p_nbArrow entier permetant d'innitialiser le membre m_nbArrow
*/
CBow::CBow(std::string p_nom, int p_dommage, int p_bonus, int p_criticalStrike, int p_nbArrow) : CWeapon(p_nom, p_dommage, p_bonus, p_criticalStrike)
{
	setm_nbArrow(p_nbArrow);
}

CBow::~CBow()
{
}
