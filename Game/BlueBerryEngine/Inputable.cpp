//-----------------------------------------------------------------
// Inputable class
// C++ Source - Inputable.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Inputable.h"
#include "SceneManager.h"

//-----------------------------------------------------------------
// Constructor(s)/ Destructors
//-----------------------------------------------------------------
Inputable::Inputable(void)
{
}

Inputable::~Inputable(void)
{
}

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------

void Inputable::RegisterInputable(AZUL_KEY K, KEYPRESS_EVENT E)
{
	PrivSceneManager::GetCurrentScene()->GetInputableManager()->Register(this,K,E);
}

void Inputable::DerigisterInputable(AZUL_KEY K, KEYPRESS_EVENT E)
{
	PrivSceneManager::GetCurrentScene()->GetInputableManager()->Deregister(this,K,E);
}