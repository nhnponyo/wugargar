#include "HeroZombie.h"
#include "NNAnimation.h"

CHeroZombie::CHeroZombie(void)
{
	initStatus();
}


CHeroZombie::~CHeroZombie(void)
{
}

void CHeroZombie::initStatus( void )
{
	m_zombieType = HERO_ZOMBIE_SM9;

	m_HealthPoint = 300;
	m_FullHP = m_HealthPoint;
	m_MovingSpeed = 20.0f;
	m_AttackPower = 30;
	m_DefensivePower = 5;
	m_AttackRange = 120.0f;
	m_NumberOfTarget = 5;
	m_AttackSpeed = 3000;
	m_CreateCost = 500;
	m_Identity = Zombie;
	m_SplashAttack = false;
}


void CHeroZombie::Render()
{
	NNObject::Render();
}

void CHeroZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
