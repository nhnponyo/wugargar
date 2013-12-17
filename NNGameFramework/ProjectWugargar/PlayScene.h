#pragma once

#include "NNScene.h"
#include "NNLabel.h"
#include "NNPoint.h"
#include "Background.h"
#include "UIButton.h"
#include "MapCreator.h"
#include "PoliceCreator.h"
#include "Police.h"
#include "Zombie.h"
#include "GameConfig.h"
#include "HumanFarm.h"
#include "Lightning.h"
#include "DeadPolice.h"
#include "MapObstaclManager.h"
#include "NNSound.h"

class CPlayScene : public NNScene
{
private :
	static CPlayScene* m_pInstance;
	CPlayScene(void);
	virtual ~CPlayScene(void);

public:
	void Render();
	void Update( float dTime );
	std::list<CCharacter*> GetZombieList() { return *m_llistZombie; }
	std::list<CCharacter*> GetPoliceList() { return *m_llistPolice; }
	std::list<CDeadPolice*> GetDeadPoliceList() { return *m_llistDeadPolice;}
	CMapCreator* GetMapCreator(void) { return m_pMapCreator;}

	static CPlayScene* GetInstance();
	static void ReleaseInstance();
	void MakeZombie(ZombieType type);
	void MakeZombie(ZombieType type, NNPoint* position);
	void MakeZombieButtonOperate(float dTime);
	void DeadCharacterCollector();
	void MakePoliceFromScript();
	void MakePoliceFromScriptWithTimeInterval(float stageElapsedTime);
	void CollectDeadPoliceByClick();
	bool CheckGameOver();
	void ShowResult(std::wstring result);

	CHumanFarm* GetHumanFarm() {return m_pHumanFarm;}
	std::wstring string2wstring(std::string str);

	int GetCurrentStageNum() {return m_currentStageNum;}
	void SetCurrentStageNum(int set) {m_currentStageNum = set;}

	void loadPoliceInfo();
	void loadZombieInfo();


private :
	void _initBackground( void );
	void _initUI( void );
	void _initMap( void );

private :
	CPlayer		*m_pPlayer;
	CBackground *m_pBackground;
	CMapCreator *m_pMapCreator;
	NNSprite	*m_pUIBackground;

	NNSprite	*m_pResultImage;
	NNLabel		*m_pResultLabel;
	wchar_t		m_aResultBuffer[255];

	CUIButton	*m_pUIButtons[NUM_OF_UIBUTTON];
	NNLabel		*m_pShowMouseStatus;
	NNLabel		*m_pShowMeatPoint;
	NNPoint		m_CursorPos;
	CPoliceCreator *m_pPoliceCreator;
	CHumanFarm *m_pHumanFarm;
	CLightning	*m_pLightning;
	MapObstaclManager *m_pMapObstacleManager;
	NNSound		*m_backgraound_sound;

	NNXML*		m_PoliceXML;
	NNXML*		m_ZombieXML;

	std::list<CCharacter*>		*m_llistZombie;
	std::list<CCharacter*>		*m_llistPolice;
	std::list<CDeadPolice*>		*m_llistDeadPolice;

	wchar_t		temp[256]; // 화면 마우스 커서 표시를 위한 임시변수
	wchar_t		localmoney[256]; //meat Point 표시를 위한 임시변수
	float		m_LocalMoneyTimeChecker; // local money증가를 위한 1초단위 카운터
	float		m_StageElapsedTime;// 게임이 시작된 후부터 진행된 시간 정보를 저장

	int m_currentStageNum;

public: // update함수가 지저분해서 테스트 함수 밖으로 다 뺐습니다 // Good job~
	void Test_ShowMousePosition();
	void Test_ShowFPS();
	void Test_ShowLocalMoney();
};
