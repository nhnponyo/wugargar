#pragma once
#include "Character.h"

class CZombie : public CCharacter
{
public:
	CZombie(void);
	virtual ~CZombie(void);

public:
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CZombie);

public:
	float	GetInfectingAccuracyRate() {return m_infectingAccuracyRate;};
	int		GetCreateCost() {return m_CreateCost;};
	void	SetInfectingAccuracyRate(float IAR) {m_infectingAccuracyRate = IAR;};	
	void	SetCreateCost(int cost) {m_CreateCost = cost;};

	void	ApplyZombieLevel();

protected:
	float		m_infectingAccuracyRate;
	int			m_CreateCost;
	ZombieType	m_Type;
};

