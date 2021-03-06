#pragma once

#include "NNMacroSet.h"
#include "NNObject.h"
#include "NNLabel.h"
#include "GameConfig.h"
#include "headers.h"
#include "PlayScene.h"
#include "CharacterConfig.h"

class NNSound;
class NNAnimation;
class NNSprite;
class NNSpriteAtlas;
class CPlayer;


class CCharacter : public NNObject
{
public:
	CCharacter(void);
	virtual ~CCharacter(void);
	
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CCharacter);	
	void InitSprite(std::wstring imagePath);	
	virtual void initStatus( CharacterInfo *characterInfo, int characterType );
	void InitZombieAnimation();
	void InitHPBar(void );
	void SetRandomPositionAroundBase();


	std::wstring string2wstring(std::string str);

	// gets & sets
	float GetHP() {return m_HealthPoint;}
	float GetMovingSpeed() {return m_MovingSpeed;}
	int GetAttackPower() {return m_AttackPower;}
	int GetDefensivePower() {return m_DefensivePower;}
	float GetAttackRange() {return m_AttackRange;}
	int GetNumberOfTarget() {return m_NumberOfTarget;}
	int GetAttackSpeed() {return m_AttackSpeed;}
	CharacterIdentity GetIdentity() {return m_Identity;}
	NNSprite *GetSprite(){return m_Sprite;}
	std::wstring GetSpritepath(){return m_spritePath;}
	NNSprite* GetHitEffect() const { return m_HitEffect; }
	bool GetIsBleeding() const { return m_IsBleeding; }
		
	void SetHP(float hp) {m_HealthPoint = hp;}
	void SetSpeed(float speed) {m_MovingSpeed = speed;}
	void SetAttackPower(int AP) {m_AttackPower = AP;}
	void SetDefensivePower(int DP) {m_DefensivePower = DP;}
	void SetAttackRange(float AR) {m_AttackRange = AR;}
	void SetNumberOfTarget(int NT) {m_NumberOfTarget = NT;}
	void SetAttackSpeed(int AS) {m_AttackSpeed = AS;}
	void SetIdentity(CharacterIdentity set_id) {m_Identity = set_id;}
	void SetCreateTime(clock_t time) {m_LastAttackTime = time;}
	void SetBeginFreezingTime(clock_t time) {m_BeginFreezingTIme = time;}
	void SetFreeze(bool ice_state) {m_Freeze = ice_state;}
	void SetTotalFreezingTime(clock_t tft) { m_TotalFreezingTime = tft;}
	void SetHitEffect(NNSprite* val) { m_HitEffect = val; }
	void SetIsBleeding(bool val) { m_IsBleeding = val; }

	void PlayDeadSound();
	

protected: 
	virtual void initStatus( void ) {};	
	void InitHitEffect(std::wstring imagePath);

	void UpdateHPBar(void);	
	void UpdateAttackTarget();
	void UpdateZindex();
	void ShowHitEffect(float dTime);

	bool CheckAttackTiming(clock_t currentTime) { return currentTime - m_LastAttackTime > m_AttackSpeed; }
	void CheckMeltingTime(clock_t currentTime);

	void AttackEnemy(clock_t currentTime);
	void NormalAttack(CCharacter* target, clock_t currentTime);
	void SplashAttack(NNPoint splashPoint, clock_t currentTime);

	void GoToAttackTarget(float dTime);
	void GoForward(float dTime);

	bool TargetInRange() { return m_Position.GetDistance(m_AttackTarget->GetPosition()) <= m_AttackRange; }
	bool TargetInSight() { return m_Position.GetDistance(m_AttackTarget->GetPosition()) <= m_Sight; }

	// variations for Character status
	CharacterIdentity	m_Identity;
	std::string			m_typeName; // xml parser를 위한 변수인가?
	float	m_HealthPoint;
	float	m_FullHP; //HP를 100에 대한 비율로 알기 위한 변수 
	float	m_MovingSpeed;
	int		m_AttackPower;
	int		m_DefensivePower;
	float	m_AttackRange;
	int		m_NumberOfTarget;
	int		m_AttackSpeed;
	bool	m_SuicideBomber;
	bool	m_SplashAttack;
	bool	m_FreezingAttack;
	float	m_SplashAttackRange;
	clock_t	m_FreezingAttackDuration;


	//사운드 관련 변수
	NNSound *m_creation_sound;
	NNSound *m_attack_sound;
	NNSound *m_dead_sound;


	// 공격 및 이동 관련 내부 변수	
	LIST_CHARACTER	*enemyList;
	CCharacter*		m_AttackTarget;	
	clock_t			m_LastAttackTime;
	bool			m_Freeze;
	clock_t			m_BeginFreezingTIme;
	clock_t			m_TotalFreezingTime;
	float			m_Sight;
	

	// 기본 내부 변수
	NNSprite		*m_Sprite;	//캐릭터는 기본적으로 sprite하나를 갖게함. 추후에 애니메이션으로 업그레이드되겠지?
	NNAnimation		*m_Animation[NUMBER_OF_CHARACTER_STATUS];
	
	NNAnimation		*m_AttackEffect;
	NNSprite		*m_HitEffect;

	bool			m_IsBleeding;
	float			m_bleedingTime;
	std::wstring	m_spritePath;
	NNSpriteAtlas	*m_pShowHP;
	
// 	std::list<std::wstring>	WalkAnimationImagePath;
// 	std::list<std::wstring> DeadAnimationImagePath;
// 	std::list<std::wstring> CreateAnimationImagePath;
// 	std::list<std::wstring> AttackAnimationImagePath;
// 	
// 	int				m_WalkAniImageNum;
// 	int				m_DeadAniImageNum;
// 	int				m_CreateAniImageNum;
// 	int				m_AttackAniImageNum;
};

