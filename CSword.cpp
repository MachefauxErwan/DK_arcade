#include "CSword.h"

/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_attack de la classe CSword
avec le param�tre de cette m�thode
@p_durability entier permetant d'innitialiser le membre p_durability
*/
void CSword::setm_durability(int p_durability)
{
	m_durability = p_durability;
}

/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_attack de la classe CSword
avec le param�tre de cette m�thode
@p_durabilityMax entier permetant d'innitialiser le membre p_durabilityMax
*/
void CSword::setm_durabilityMax(int p_durabilityMax)
{
	m_durabilityMax = p_durabilityMax;
}

/*Cette m�thode est un getter()
Elle retourne un entier du membre proteg� m_durability de la classe CSword
*/
int CSword::getm_durability()
{
	return m_durability;
}

/*Cette m�thode est un getter()
Elle retourne un entier du membre proteg� m_durabilityMax de la classe CSword
*/
int CSword::getm_durabilityMax()
{
	return m_durabilityMax;
}

/*Cette m�thode indique si l'�p�e est cass�e.*/
bool CSword::isBroken()
{
	if (0 < getm_durability())
	{
		return false;
	}
	else
	{
		return true;
	}

}

/*Cette m�thode r�duit la durabilit� de l'�p�e d'un nombre al�atoire compris entre 1 � 5.*/
void CSword::use()
{
	srand((unsigned)time(0));
	if (!isBroken())
	{
		setm_durability(getm_durability() - (1 + rand() % 5));
		std::cout << getm_nom() << " est a " << getm_durability() << std::endl;
		if (0 >= getm_durability())
		{
			setm_durability(0);
			std::cout << "l'�pee � �t� detruit apr�s le combat " << std::endl;
		}
	}
	else
	{
		setm_durability(0);
	}

}
/*Cette m�thode est le constructeur surcharg� de la classe.
Elle initialise les membres proteg�s de la classe CSword
avec les diff�rents param�tres de cette m�thode
@p_nom string permetant d'innitialiser le membre m_nom
@p_dommage entier permetant d'innitialiser le membre m_dommage
@p_bonus entier permetant d'innitialiser le membre m_bonus
@p_criticalStrike entier permetant d'innitialiser le membre m_criticalStrike
@p_durability entier permetant innitialiser le membre m_durability
@p_durabilityMax entier permetant innitialiser le membre m_durabilityMax
*/
CSword::CSword(std::string p_nom, int p_dommage, int p_bonus, int p_criticalStrike, int p_durability,  int p_durabilityMax) : CWeapon(p_nom, p_dommage, p_bonus, p_criticalStrike)
{
	setm_durability(p_durability);
	setm_durabilityMax(p_durabilityMax);
}

CSword::~CSword()
{
}
