//-----------------------------------------------------------------
// SceneManager class
// C++ Source File SceneManager.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files 
//-----------------------------------------------------------------
#include "SceneManager.h"
#include "Scene.h"

//-----------------------------------------------------------------
// static variable initialization 
//-----------------------------------------------------------------
bool			PrivSceneManager::m_bInstanceFlag;
PrivSceneManager*	PrivSceneManager::m_smSingle;


//-----------------------------------------------------------------
// Constructor(s)/ Destructor 
//-----------------------------------------------------------------
PrivSceneManager::PrivSceneManager()
{
	//m_lSceneList = std::list<Scene>();
}

PrivSceneManager::~PrivSceneManager()
{
	CleanupScenes();
}
//-----------------------------------------------------------------
// General Methods 
//-----------------------------------------------------------------

void PrivSceneManager::DrawCurrentScene()
{
	PrivSceneManager::getSceneManager()->DrawCurrentSceneHelper();
}

void PrivSceneManager::UpdateCurrentScene()
{
	PrivSceneManager::getSceneManager()->UpdateCurrentSceneHelper();
}

void PrivSceneManager::SetCurrentScene(Scene* s)
{
	PrivSceneManager::getSceneManager()->SetCurrentSceneHelper(s);
}

Scene* PrivSceneManager::GetCurrentScene()
{
	return PrivSceneManager::getSceneManager()->GetCurrentSceneHelper();
}

void PrivSceneManager::CleanupScenes()
{
	PrivSceneManager::getSceneManager()->CleanupScenesHelper();
}

//-----------------------------------------------------------------
// Helper Methods 
//-----------------------------------------------------------------

PrivSceneManager* PrivSceneManager::getSceneManager()
{
	if( !m_bInstanceFlag)
	{
		m_smSingle = new PrivSceneManager();
		m_bInstanceFlag = true;
		return m_smSingle;
	}
	else
	{
		return m_smSingle;
	}
}

void PrivSceneManager::DrawCurrentSceneHelper()
{
	GetCurrentSceneHelper()->DrawScene();
}

void PrivSceneManager::SetCurrentSceneHelper(Scene* s)
{
	m_pCurrentScene = s;
	m_pNextScene = s;
}

Scene*	PrivSceneManager::GetCurrentSceneHelper()
{
	return m_pCurrentScene;
}
void PrivSceneManager::UpdateCurrentSceneHelper()
{
	if(m_pCurrentScene != m_pNextScene)
	{
		delete m_pCurrentScene;
		m_pCurrentScene = m_pNextScene;
			printf("Number of objects in  new scene: %d\n", PrivSceneManager::GetCurrentScene()->GetDumpster()->GetSize());
	}
	m_pCurrentScene->UpdateScene();
}

void PrivSceneManager::CleanupScenesHelper()
{
	GetCurrentScene()->CleanScene();
}

void PrivSceneManager::Delete()
{
	if(m_bInstanceFlag)
	{
		delete PrivSceneManager::getSceneManager();
	}

}

void PrivSceneManager::SetNextScene(Scene* s)
{
	PrivSceneManager::getSceneManager()->SetNextSceneHelper(s);
}

void PrivSceneManager::SetNextSceneHelper(Scene* s)
{
	m_pNextScene = s;
}
