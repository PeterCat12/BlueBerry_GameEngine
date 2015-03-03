//-----------------------------------------------------------------
// UpdatableManager class
// C++ Source File UpdatableManager.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "UpdatableManager.h"
#include "Updatable.h"

//-----------------------------------------------------------------
// Construcotor(s)/Destructor 
//-----------------------------------------------------------------

UpdatableManager::UpdatableManager()
{
	m_lActiveUpdatables = std::list<Updatable*>();
	m_lObjectsToDelete = std::list<Updatable*>();
}

UpdatableManager::~UpdatableManager()
{
	Cleanup();
}

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------

void UpdatableManager::Register(Updatable* u)
{
	// Make sure item is not already registered...
	 std::list<Updatable*>::iterator findIter = std::find(m_lActiveUpdatables.begin(), m_lActiveUpdatables.end(), u);
	if(findIter == m_lActiveUpdatables.end()) 
	{
		m_lActiveUpdatables.push_front(u);
	}
}

void UpdatableManager::Deregister(Updatable* u)
{
	m_lObjectsToDelete.push_front(u);
	//m_lActiveUpdatables.remove(u);
}

void UpdatableManager::UpdateAll()
{
	//Delete those that need deleting
	if(m_lObjectsToDelete.size() > 0)
	{
		std::list<Updatable*>::iterator delIter = m_lObjectsToDelete.begin();
		while(delIter != m_lObjectsToDelete.end())
		{
			m_lActiveUpdatables.remove( (*delIter) );
			delIter++;
		}
		m_lObjectsToDelete.clear();
	}


	std::list<Updatable*>::iterator it = m_lActiveUpdatables.begin();
	while(it != m_lActiveUpdatables.end() )
	{
		(*it)->Update();
		it++;
	}
}

void UpdatableManager::Cleanup()
{
	m_lActiveUpdatables.clear();
}