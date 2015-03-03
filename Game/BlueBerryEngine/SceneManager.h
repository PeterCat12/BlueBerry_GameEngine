//-----------------------------------------------------------------
// SceneManager class
// C++ Header File SceneManager.h
//-----------------------------------------------------------------

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include <list>
#include "Scene.h"

//-----------------------------------------------------------------
// SceneManager class -- SINGLETONE_--
//-----------------------------------------------------------------
class PrivSceneManager
{
protected:
	// Member variables
	Scene*				m_pCurrentScene;
	Scene*				m_pNextScene;


public:
	// Constructor(s)/Destructors
	~PrivSceneManager();

	// General Methods
	static void		DrawCurrentScene();
	static void		SetCurrentScene(Scene* s);
	static void		SetNextScene(Scene* s);
	static void		UpdateCurrentScene();
	static Scene*	GetCurrentScene();
	static void		CleanupScenes();
	static void		Delete();

private:
	PrivSceneManager();
	//Helper Methods
	static	PrivSceneManager* getSceneManager();
	void	DrawCurrentSceneHelper();
	void	SetCurrentSceneHelper(Scene* s);
	void	SetNextSceneHelper(Scene* s);
	Scene*	GetCurrentSceneHelper();
	void	UpdateCurrentSceneHelper();
	void	CleanupScenesHelper();

	// Private singleton variables
	static bool				m_bInstanceFlag;
	static PrivSceneManager*	m_smSingle;
};
#endif