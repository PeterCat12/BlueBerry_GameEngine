//-----------------------------------------------------------------
// UserSceneManager Class 
// C++ Source - UserSceneManager.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "UserSceneManager.h"

//-----------------------------------------------------------------
//General Methods
//-----------------------------------------------------------------

void SceneManager::SetCurrentScene(Scene* pScene)
{
	PrivSceneManager::SetCurrentScene(pScene);
}

void SceneManager::SetNextScene(Scene* pScene)
{
	PrivSceneManager::SetNextScene(pScene);
}

int SceneManager::NumObjectsInScene()
{
	return PrivSceneManager::GetCurrentScene()->GetDumpster()->GetSize();
}
