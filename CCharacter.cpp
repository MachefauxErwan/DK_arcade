#include "CCharacter.h"


/*Cette méthode permets de déterminer, de façon aléatoire en fonction
du membre m_dodge si le personnage évite l'attaque.
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

/*Cette méthode indique si le personnage est en vie.*/
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

/*Cette méthode est un getter()
Elle retourne un string du membre protegé m_nom de la classe CCharacter
*/
std::string CCharacter::getm_nom()
{
	return m_nom;
}

/*Cette méthode est un getter()
Elle retourne un entier du membre protegé m_hpMax de la classe CCharacter
*/
int CCharacter::getm_hpMax()
{
	return m_hpMax;
}

/*Cette méthode est un getter()
Elle retourne un entier du membre protegé m_hp de la classe CCharacter
*/
int CCharacter::getm_hp()
{
	return m_hp;
}

/*Cette méthode est un getter()
Elle retourne un pointeur sur l'objet CWeapon du membre protegé m_weapon de la classe CCharacter
*/
CWeapon CCharacter::getm_weapon()
{
	return *m_weapon;
}

/*Cette méthode est un getter()
Elle retourne un réel du membre protegé m_dodge de la classe CCharacter
*/
float CCharacter::getm_dodge()
{
	return m_dodge;
}

/*Cette méthode est un setter()
Elle initialise le membre protegé m_nom de la classe CCharacter
avec le paramètre de cette méthode
@p_nom std::string permetant d'innitialiser le membre m_nom;
*/
void CCharacter::setm_nom(std::string p_nom)
{
	m_nom = p_nom;
}

/*Cette méthode est un setter()
Elle initialise le membre protegé m_hpMax de la classe CCharacter
avec le paramètre de cette méthode
@p_hpMax entier permetant d'innitialiser le membre m_hpMax;
*/
void CCharacter::setm_hpMax(int p_hpMax)
{
	m_hpMax = p_hpMax;
}

/*Cette méthode est un setter()
Elle initialise le membre protegé m_hp de la classe CCharacter
avec le paramètre de cette méthode
@p_hp entier permetant d'innitialiser le membre m_hp;
*/
void CCharacter::setm_hp(int p_hp)
{
	m_hp = p_hp;
}

/*Cette méthode est un setter()
Elle initialise le membre protegé m_weapon de la classe CCharacter
avec le paramètre de cette méthode
@p_weapon pointeur sur l'objet CWeapon permetant d'innitialiser le membre m_weapon;
*/
void CCharacter::setm_weapon(CWeapon *p_weapon)
{
	m_weapon = p_weapon;
}

/*Cette méthode est un setter()
Elle initialise le membre protegé m_dodge de la classe CCharacter
avec le paramètre de cette méthode
@p_dodge réel permetant d'innitialiser le membre m_dodge;
*/
void CCharacter::setm_dodge(float p_dodge)
{
	m_dodge = p_dodge;
}

