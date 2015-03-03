//-----------------------------------------------------------------
// Updatable class
// C++ Header File Updatable.h
//-----------------------------------------------------------------

#ifndef UPDATABLE_H
#define UPDATABLE_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------


//-----------------------------------------------------------------
//Updatable class
//-----------------------------------------------------------------
class Updatable
{

public:
	Updatable(void);
	virtual ~Updatable(void);

	virtual void Update() = 0;
	virtual void RegisterUpdatable();
	virtual void DeregisterUpdatable();
};
#endif

