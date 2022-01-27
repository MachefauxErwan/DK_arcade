#include "CCharacter.h"


/*Cette m�thode permets de d�terminer, de fa�on al�atoire en fonction
du membre m_dodge si le personnage �vite l'attaque.
*/
bool CCharacter::dodge()
{
	srand((unsigned)time(0));
	int nombre_aleatoire = 0;
	nombre_aleatoire = rand() % 100;
	if (nombre_aleatoire <= getm_dodge())
	{
		return true;
	}
	else
	{
		return false;
	}

}

/*Cette m�thode indique si le personnage est en vie.*/
bool CCharacter::isAlive()
{
	if (0 < getm_hp())
	{
		return true;
	}
	else
	{
		return false;
	}

}

/*Cette m�thode est un getter()
Elle retourne un string du membre proteg� m_nom de la classe CCharacter
*/
std::string CCharacter::getm_nom()
{
	return m_nom;
}

/*Cette m�thode est un getter()
Elle retourne un entier du membre proteg� m_hpMax de la classe CCharacter
*/
int CCharacter::getm_hpMax()
{
	return m_hpMax;
}

/*Cette m�thode est un getter()
Elle retourne un entier du membre proteg� m_hp de la classe CCharacter
*/
int CCharacter::getm_hp()
{
	return m_hp;
}

/*Cette m�thode est un getter()
Elle retourne un pointeur sur l'objet CWeapon du membre proteg� m_weapon de la classe CCharacter
*/
CWeapon CCharacter::getm_weapon()
{
	return *m_weapon;
}

/*Cette m�thode est un getter()
Elle retourne un r�el du membre proteg� m_dodge de la classe CCharacter
*/
float CCharacter::getm_dodge()
{
	return m_dodge;
}

/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_nom de la classe CCharacter
avec le param�tre de cette m�thode
@p_nom std::string permetant d'innitialiser le membre m_nom;
*/
void CCharacter::setm_nom(std::string p_nom)
{
	m_nom = p_nom;
}

/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_hpMax de la classe CCharacter
avec le param�tre de cette m�thode
@p_hpMax entier permetant d'innitialiser le membre m_hpMax;
*/
void CCharacter::setm_hpMax(int p_hpMax)
{
	m_hpMax = p_hpMax;
}

/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_hp de la classe CCharacter
avec le param�tre de cette m�thode
@p_hp entier permetant d'innitialiser le membre m_hp;
*/
void CCharacter::setm_hp(int p_hp)
{
	m_hp = p_hp;
}

/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_weapon de la classe CCharacter
avec le param�tre de cette m�thode
@p_weapon pointeur sur l'objet CWeapon permetant d'innitialiser le membre m_weapon;
*/
void CCharacter::setm_weapon(CWeapon *p_weapon)
{
	m_weapon = p_weapon;
}

/*Cette m�thode est un setter()
Elle initialise le membre proteg� m_dodge de la classe CCharacter
avec le param�tre de cette m�thode
@p_dodge r�el permetant d'innitialiser le membre m_dodge;
*/
void CCharacter::setm_dodge(float p_dodge)
{
	m_dodge = p_dodge;
}

