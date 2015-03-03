//-----------------------------------------------------------------
// Scene class
// C++ Header File Scene.h
//-----------------------------------------------------------------

#ifndef SCENE_H
#define SCENE_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "UpdatableManager.h"
#include "DrawableManager.h"
#include "InputableManager.h"
#include "AlarmManager.h"
#include "CollisionManager.h"
#include "TerminationManager.h"
#include "Dumpster.h"


//-----------------------------------------------------------------
// Scene class
//-----------------------------------------------------------------
class Scene 
{
protected:
	// Member Variables
	DrawableManager		m_DrawMan;
	InputableManager	m_InputMan;
	UpdatableManager	m_UpdateMan;
	AlarmManager		m_AlarmMan;
	CollisionManager	m_CollisionMan;
	TerminationManager  m_TerminationMan;
	Dumpster			m_DumpMan;

public:
	// Constructor(s)/Destructors
	Scene();
	virtual ~Scene();

	// General Methods
	void DrawScene();
	void SetUp();
	void UpdateScene();
	DrawableManager*	GetDrawableManager(); 
	InputableManager*	GetInputableManager();
	UpdatableManager*	GetUpdatableManager(); 	
	AlarmManager*		GetAlarmManager();
	CollisionManager*	GetCollisionManager();
	TerminationManager*	GetTerminationManager();
	Dumpster*			GetDumpster();
	void CleanScene();

private:
	// Helper Methods

};
#endif
