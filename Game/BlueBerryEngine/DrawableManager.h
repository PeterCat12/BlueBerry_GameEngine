//-----------------------------------------------------------------
// DrawableManager class
// C++ Header File DrawableManager.h
//-----------------------------------------------------------------

#ifndef DRAWABLEMANAGER_H
#define DRAWABLEMANAGER_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include <list>
class Drawable;

//-----------------------------------------------------------------
// DrawableManager class
//-----------------------------------------------------------------
class DrawableManager
{
protected:
	// Member variables 
	std::list<Drawable*> m_lActiveDrawables;
	std::list<Drawable*> m_lObjectsToDelete;

public:
	// Constructor(s)/Destructors
	DrawableManager();
	~DrawableManager();

	// General Methods
	void Register(Drawable* d);
	void Deregister(Drawable* d);
	void DrawAll();
	void Cleanup();

private:
	//non copyable
	DrawableManager(const DrawableManager& cpy);
};
#endif