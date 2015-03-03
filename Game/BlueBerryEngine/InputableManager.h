//-----------------------------------------------------------------
// Inputable Manager class
// C++ Header File InputableManager.h
//-----------------------------------------------------------------

#ifndef INPUTABLE_MAN_H
#define INPUTABLE_MAN_H

//-----------------------------------------------------------------
// Include Files & forward Declarations
//-----------------------------------------------------------------
#include <unordered_map>
#include "SceneEnums.h"
#include "Trace.h"
#include "KeyObject.h"

class Inputable;


//-----------------------------------------------------------------
// InputableManager class
//-----------------------------------------------------------------
class InputableManager
{
protected:
	// Member variables 
	std::unordered_map<AZUL_KEY, KeyObject*> m_umActiveKeys;

public:
	InputableManager();
	~InputableManager();

	// General Methods
	void UpdateAll();
	void Register(Inputable* p, AZUL_KEY k, KEYPRESS_EVENT e);
	void Deregister(Inputable* p, AZUL_KEY k, KEYPRESS_EVENT e);
	void Cleanup();
	
private:

};
#endif