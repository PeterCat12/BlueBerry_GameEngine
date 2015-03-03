//-----------------------------------------------------------------
// Scene class
// C++ Scource File Scene.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
//Include Files
//-----------------------------------------------------------------
#include "Scene.h"

//-----------------------------------------------------------------
//Constructor(s)/Destructor
//-----------------------------------------------------------------
Scene::Scene()
{

}

Scene::~Scene()
{
	m_DrawMan.Cleanup();
	m_InputMan.Cleanup();
	m_UpdateMan.Cleanup();
	m_AlarmMan.CleanUpAlarms();
	m_CollisionMan.Cleanup();
	m_TerminationMan.Cleanup();
}

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------

void Scene::DrawScene()
{
	m_DrawMan.DrawAll();
}

void Scene::UpdateScene()
{
	m_TerminationMan.ProcessTerminationEvents();
	m_InputMan.UpdateAll();
	m_UpdateMan.UpdateAll();
	m_AlarmMan.UpdateAlarms();
	m_CollisionMan.ProcessCollisions();
}

void Scene::SetUp()
{
	return;
}

void Scene::CleanScene()
{
	m_DrawMan.Cleanup();
	m_InputMan.Cleanup();
	m_UpdateMan.Cleanup();
	m_AlarmMan.CleanUpAlarms();
	m_TerminationMan.Cleanup();
	m_DumpMan.Clean();
}

InputableManager* Scene::GetInputableManager()
{
	return &m_InputMan;
}

DrawableManager* Scene::GetDrawableManager()
{
	return &m_DrawMan;
}

UpdatableManager* Scene::GetUpdatableManager()
{
	return &m_UpdateMan;
}

AlarmManager* Scene::GetAlarmManager()
{
	return &m_AlarmMan;
}

CollisionManager* Scene::GetCollisionManager()
{
	return &m_CollisionMan;
}

TerminationManager* Scene::GetTerminationManager()
{
	return &m_TerminationMan;
}

Dumpster* Scene::GetDumpster()
{
	return &m_DumpMan;
}
