#ifndef _CCharacter_h
#define _CCharacter_h
#include "CBow.h"
#include "CStaff.h"
#include "CSword.h"


class CCharacter
{
protected:
	std::string m_nom;
	int m_hpMax;
	int m_hp;
	CWeapon* m_weapon;
	float m_dodge;
public:
	//getter()
	std::string getm_nom();
	int getm_hpMax();
	int getm_hp();
	CWeapon getm_weapon();
	float getm_dodge();
	//setter()
	void setm_nom(std::string p_nom);
	void setm_hpMax(int p_hpMax);
	void setm_hp(int p_hp);
	void setm_weapon(CWeapon* p_weapon);
	void setm_dodge(float p_dodge);
	// autre méthode 
	virtual void action(CCharacter * p_enemy)= 0;
	virtual void unarmedAttack(CCharacter *p_enemy) = 0;
	virtual void armedAttack(CCharacter *p_enemy) = 0;
	virtual void applyDamage(int p_damage) = 0;
	bool dodge();
	bool isAlive();
private:
	
};

#endif // !_CWeapon_h
