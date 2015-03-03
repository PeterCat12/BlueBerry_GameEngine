//-----------------------------------------------------------------
// Updatable class
// C++ Source - Updatable.cpp
//-----------------------------------------------------------------


//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Updatable.h"
#include "SceneManager.h"

//-----------------------------------------------------------------
// Constructor(s) / Destructors 
//-----------------------------------------------------------------

Updatable::Updatable(void)
{

}


Updatable::~Updatable(void)
{
}

//-----------------------------------------------------------------
// General methods
//-----------------------------------------------------------------

void Updatable::RegisterUpdatable()
{
	PrivSceneManager::GetCurrentScene()->GetUpdatableManager()->Register(this);
}

void Updatable::DeregisterUpdatable()
{
	PrivSceneManager::GetCurrentScene()->GetUpdatableManager()->Deregister(this);
}
