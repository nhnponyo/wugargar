#include "NormalPolice.h"



CNormalPolice::CNormalPolice(void)
{
	initStatus();
}


CNormalPolice::~CNormalPolice(void)
{

}

void CNormalPolice::Render()
{
	NNObject::Render();
}

void CNormalPolice::Update( float dTime )
{

}

void CNormalPolice::initStatus( void )
{
	m_HealthPoint = 100;
	m_MovingSpeed = 2.0f;
	m_AttackPower = 10;
	m_DefensivePower = 2;
	m_AttackRange = 50.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 1;
	m_Identity = Police;
}
