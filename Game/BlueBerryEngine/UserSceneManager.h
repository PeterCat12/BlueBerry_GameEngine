//-----------------------------------------------------------------
// UserSceneManager Class 
// C++ Header - UserSceneManager.h
//-----------------------------------------------------------------

#ifndef B_SCENEMANAGER_H
#define B_SCENEMANAGER_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "SceneManager.h"


//-----------------------------------------------------------------
// SceneManager Class
//-----------------------------------------------------------------
class SceneManager
{
public:
	//General Methods
	static void SetCurrentScene(Scene* pScene);
	static void SetNextScene(Scene* pScene);
	template <class C1, class C2>
	static void SetCollisionPair();

	//Accessors
	static int NumObjectsInScene();

private:
	SceneManager(void);
	~SceneManager(void);
};

// Template Defined Function
template <class C1, class C2>
void SceneManager::SetCollisionPair()
{
	PrivSceneManager::GetCurrentScene()->GetCollisionManager()->SetCollisionPair<C1,C2>();
}

#endif