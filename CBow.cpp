#include "CBow.h"

/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_nbArrow de la classe CBow
avec le param�tre de cette m�thode
@p_nbArrow entier permetant d'innitialiser le membre m_nbArrow
*/
void CBow::setm_nbArrow(int p_nbArrow)
{
	m_nbArrow = p_nbArrow;
}

/*Cette m�thode est un getter()
Elle retourne un entier du membre proteg� m_nbArrow de la classe CBow
*/
int CBow::getm_nbArrow()
{
	return m_nbArrow;
}

/*Cette m�thode indique si l'archer � encore des fl�ches .*/
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

/*Cette m�thode permet � l'arc de tirer une fl�che et de r�duire le nombre de fl�che dans son carcois*/
void CBow::shoot()
{
	if (haveArrows() == true)
	{
		setm_nbArrow(getm_nbArrow() - 1);
		if (0 == getm_nbArrow())
		{
			setm_nbArrow(0);
			std::cout << "vous n'avez plus de fl�ches " << std::endl;
		}
	}
	else
	{
		std::cout << "vous n'avez plus de fl�ches " << std::endl;
	}
}

/*Cette m�thode est le constructeur surcharg� de la classe.
Elle initialise les membres proteg�s de la classe CSword
avec les diff�rents param�tres de cette m�thode
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
