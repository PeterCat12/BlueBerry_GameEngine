//-----------------------------------------------------------------
// KeyObject 
// C++ Source - KeyObject.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "KeyObject.h"
#include "Inputable.h"
#include <algorithm>

//-----------------------------------------------------------------
// Constructor(s)/Destructors
//-----------------------------------------------------------------
KeyObject::KeyObject(AZUL_KEY _keyName)
	: m_eKeyName(_keyName), m_bPrevKeyState(false)
{
}

KeyObject::~KeyObject()
{
	ClearLists(); //Is this unnecessary?
}

// Private Constructor. No on should call this constructor. EVER.
KeyObject::KeyObject()
{}

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------
bool KeyObject::KeyPressed()
{
	if( InputMan::GetKeyboard()->GetKeyState(m_eKeyName) && m_bPrevKeyState == false)
	{
		m_bPrevKeyState = true;
		return true;
	}
	return false;
}

bool KeyObject::KeyReleased()
{
	if( !InputMan::GetKeyboard()->GetKeyState(m_eKeyName ) && m_bPrevKeyState == true)
	{
		m_bPrevKeyState = false;
		return true;
	}
	return false;
}

void KeyObject::Register(Inputable* p, KEYPRESS_EVENT e)
{

	if(e == KEYPRESS_EVENT::KEY_PRESSED)
	{
		//Make sure key isn't already registered...
		 std::list<Inputable*>::iterator findIter = std::find(m_lInputableKeyPressed.begin(), m_lInputableKeyPressed.end(), p);
		if(findIter == m_lInputableKeyPressed.end()) 
		{
			m_lInputableKeyPressed.push_front(p);
			//findIter++;
		}
	}
	else
	{
		//Make sure key isn't already registered...
		std::list<Inputable*>::iterator findIter = std::find(m_lInputableKeyReleased.begin(), m_lInputableKeyReleased.end(), p);
		if(findIter == m_lInputableKeyReleased.end()) 
		{
			m_lInputableKeyReleased.push_front(p);
			//findIter++;
		}
	}
}

void KeyObject::Deregister(Inputable* p, KEYPRESS_EVENT e)
{
	if(e == KEYPRESS_EVENT::KEY_PRESSED)
		m_lDeletePressed.push_front(p);
	else
		m_lDeleteReleased.push_front(p);
}

void KeyObject::update()
{
	//Delete those that need deleting
	if(m_lDeletePressed.size() > 0)
	{
		std::list<Inputable*>::iterator delIter = m_lDeletePressed.begin();
		while(delIter != m_lDeletePressed.end())
		{
			m_lInputableKeyPressed.remove( (*delIter) );
			delIter++;
		}
		m_lDeletePressed.clear();
	}

	//Delete those that need deleting
	if(m_lDeleteReleased.size() > 0)
	{
		std::list<Inputable*>::iterator delIter = m_lDeleteReleased.begin();
		while(delIter != m_lDeleteReleased.end())
		{
			m_lInputableKeyReleased.remove( (*delIter) );
			delIter++;
		}
		m_lDeleteReleased.clear();
	}

	if( KeyPressed() )
	{   // iterator through list..
		std::list<Inputable*>::iterator it = m_lInputableKeyPressed.begin();
		while(it != m_lInputableKeyPressed.end() )
		{
			(*it)->KeyPressed(m_eKeyName);
			it++;
		}
	}
	else if(KeyReleased() )
	{ //iterate through list...
		std::list<Inputable*>::iterator it = m_lInputableKeyReleased.begin();
		while(it != m_lInputableKeyReleased.end() )
		{
			(*it)->KeyReleased(m_eKeyName);
			it++;
		}
	}
}

void KeyObject::ClearLists()
{
	m_lInputableKeyPressed.clear();
	m_lInputableKeyReleased.clear();
}