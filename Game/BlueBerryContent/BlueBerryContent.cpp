#include "Game.h"
#include "SceneManager.h"
//-----------------------------------------------------------------
// BlueBerryContent Class 
// C++ Source - BlueBerryContent.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "GameObject.h"
#include "UserSceneManager.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "SpaceShip.h"
#include "SimpleSphere.h"
#include "Cottage.h"
#include "Floor.h"

Scene* pScene;
Scene*	pScene2;
SpaceShip* pSpaceShip;
SpaceShip* pPlayer;
SimpleSphere* pSimpleSphere;
Cottage*	pCottage;
Floor*		pFloor;


void Game::InitializeGameContent()
{

}

void Game::LoadGameContent()
{
	pScene = new Scene();
	SceneManager::SetCurrentScene(pScene);
	ResourceManager::LoadAllResources();

	pSpaceShip = new SpaceShip(); 
	pSpaceShip->SetPos(50,20,0);

	pFloor = new Floor();

	pPlayer = new SpaceShip();
	pPlayer->setPlayer(true);

	pSimpleSphere = new SimpleSphere(); 

	pCottage = new Cottage();


	SceneManager::SetCollisionPair<Cottage,SpaceShip>();
	SceneManager::SetCollisionPair<SpaceShip,SpaceShip>();
}

void Game::UnloadGameContent()
{

}

void Game::TerminateGameContent()
{

}