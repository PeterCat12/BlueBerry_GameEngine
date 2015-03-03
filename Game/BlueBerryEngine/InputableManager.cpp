//-----------------------------------------------------------------
// Inputable Manager class
// C++ Source File InputableManager.cpp
//-----------------------------------------------------------------


//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "InputableManager.h"

//-----------------------------------------------------------------
// Constructor(s)\Destructors
//-----------------------------------------------------------------

InputableManager::InputableManager()
{
	m_umActiveKeys = std::unordered_map<AZUL_KEY, KeyObject*>();
}

InputableManager::~InputableManager()
{
	Cleanup();
}

void InputableManager::Register(Inputable* p, AZUL_KEY k, KEYPRESS_EVENT e)
{
	if(m_umActiveKeys.count(k) == 0)
	{
		KeyObject* keyObject = new KeyObject(k);
		keyObject->Register(p,e);
		m_umActiveKeys.insert (std::pair<AZUL_KEY,KeyObject*>(k,keyObject) );
	}
	else
	{ //keyobject already exists
		m_umActiveKeys.find(k)->second->Register(p,e);
	}
}

void InputableManager::Deregister(Inputable* p, AZUL_KEY k, KEYPRESS_EVENT e)
{
	if(m_umActiveKeys.count(k) != 0)
	{
		m_umActiveKeys.find(k)->second->Deregister(p,e);
	}
	else
	{
		_trace("Error: Attempting to deregister key currently not registered");
	}
}


void InputableManager::UpdateAll()
{
	std::unordered_map<AZUL_KEY,KeyObject*>::iterator it = m_umActiveKeys.begin();
	while(it != m_umActiveKeys.end())
	{
		it->second->update();
		it++;
	}
}

void InputableManager::Cleanup()
{
	std::unordered_map<AZUL_KEY,KeyObject*>::iterator it = m_umActiveKeys.begin();
	while(it != m_umActiveKeys.end())
	{
		delete it->second;
		it = m_umActiveKeys.erase(it);
	}
}

