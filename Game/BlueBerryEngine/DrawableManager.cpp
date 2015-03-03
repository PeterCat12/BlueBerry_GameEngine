//-----------------------------------------------------------------
// DrawableManager class
// C++ Source File DrawableManager.cpp
//-----------------------------------------------------------------


//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "DrawableManager.h"
#include "Drawable.h"
//#include "Drawable.h"

//-----------------------------------------------------------------
// Constructor(s)/Destructor
//-----------------------------------------------------------------

DrawableManager::DrawableManager()
{
	m_lActiveDrawables = std::list<Drawable*>();
	m_lObjectsToDelete = std::list<Drawable*>();
}

DrawableManager::~DrawableManager()
{
	Cleanup();
}
//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------

void DrawableManager::Register(Drawable* d)
{

	//Make sure d is not already registered...
	 std::list<Drawable*>::iterator findIter = std::find(m_lActiveDrawables.begin(), m_lActiveDrawables.end(), d);
		if(findIter == m_lActiveDrawables.end()) 
		{
			m_lActiveDrawables.push_front(d);
		}
}

void DrawableManager::Deregister(Drawable* d)
{
	m_lObjectsToDelete.push_front(d);
	//m_lActiveDrawables.remove(d);
}

void DrawableManager::DrawAll()
{

	//Delete those that need deleting
	if(m_lObjectsToDelete.size() > 0)
	{
		std::list<Drawable*>::iterator delIter = m_lObjectsToDelete.begin();
		while(delIter != m_lObjectsToDelete.end())
		{
			m_lActiveDrawables.remove( (*delIter) );
			delIter++;
		}
		m_lObjectsToDelete.clear();
	}

	std::list<Drawable*>::iterator it = m_lActiveDrawables.begin();
	while(it != m_lActiveDrawables.end() )
	{
		if( !(*it)->IsHidden())
			(*it)->Draw();
		it++;
	}
}

void DrawableManager::Cleanup()
{
	m_lActiveDrawables.clear();
	m_lObjectsToDelete.clear();
}