//-----------------------------------------------------------------
// Inputable class
// C++ Header File Inputable.h
//-----------------------------------------------------------------

#ifndef INPUTABLE_H
#define INPUTABLE_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

class Keyboard;
class mouse;

#include "SceneEnums.h"
#include "Keyboard.h"


//-----------------------------------------------------------------
// Inputable Class 
//-----------------------------------------------------------------

class Inputable
{
protected:
	// Member Variables

public:
	// Constructor(s)/Destructors
	Inputable();
	virtual ~Inputable();

	// General Methods
	virtual void KeyPressed(AZUL_KEY k) = 0;
	virtual void KeyReleased(AZUL_KEY k) = 0;
	virtual void RegisterInputable(AZUL_KEY K, KEYPRESS_EVENT E);
	virtual void DerigisterInputable(AZUL_KEY K, KEYPRESS_EVENT E);

private:
	// Helper Methods

};
#endif