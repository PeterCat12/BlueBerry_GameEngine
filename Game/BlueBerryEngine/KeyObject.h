//-----------------------------------------------------------------
// Key Object class
// C++ Header File ResourceManager.h
//-----------------------------------------------------------------

#ifndef KEY_OBJECT_H
#define KEY_OBJECT_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include <list>
#include "SceneEnums.h"
#include "InputMan.h"

class Inputable;

//-----------------------------------------------------------------
// Key Object class
//-----------------------------------------------------------------
class KeyObject
{
protected:
	// Member Variables
	std::list<Inputable*>	m_lInputableKeyPressed;
	std::list<Inputable*>	m_lInputableKeyReleased;
	std::list<Inputable*>	m_lDeletePressed;
	std::list<Inputable*>	m_lDeleteReleased;
	AZUL_KEY				m_eKeyName;
	bool					m_bPrevKeyState;

public:
	
	// Constructor(s)/Destructors
	KeyObject(AZUL_KEY _KeyName);
	virtual ~KeyObject();

	// General Methods
	void update();
	void Register(Inputable* p, KEYPRESS_EVENT e);
	void Deregister(Inputable* p, KEYPRESS_EVENT e);

private:
	// Constructor(s)
	KeyObject();

	// Helper Methods
	bool KeyPressed();
	bool KeyReleased();
	void ClearLists();
};
#endif