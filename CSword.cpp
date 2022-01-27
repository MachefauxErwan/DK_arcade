#include "CSword.h"

/*Cette méthode est un setter()
Elle initialise le membre protegé m_attack de la classe CSword
avec le paramètre de cette méthode
@p_durability entier permetant d'innitialiser le membre p_durability
*/
void CSword::setm_durability(int p_durability)
{
	m_durability = p_durability;
}

/*Cette méthode est un setter()
Elle initialise le membre protegé m_attack de la classe CSword
avec le paramètre de cette méthode
@p_durabilityMax entier permetant d'innitialiser le membre p_durabilityMax
*/
void CSword::setm_durabilityMax(int p_durabilityMax)
{
	m_durabilityMax = p_durabilityMax;
}

/*Cette méthode est un getter()
Elle retourne un entier du membre protegé m_durability de la classe CSword
*/
int CSword::getm_durability()
{
	return m_durability;
}

/*Cette méthode est un getter()
Elle retourne un entier du membre protegé m_durabilityMax de la classe CSword
*/
int CSword::getm_durabilityMax()
{
	return m_durabilityMax;
}

/*Cette méthode indique si l'épée est cassée.*/
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

/*Cette méthode réduit la durabilité de l'épée d'un nombre aléatoire compris entre 1 à 5.*/
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
			std::cout << "l'épee à été detruit aprés le combat " << std::endl;
		}
	}
	else
	{
		setm_durability(0);
	}

}
/*Cette méthode est le constructeur surchargé de la classe.
Elle initialise les membres protegés de la classe CSword
avec les différents paramètres de cette méthode
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
