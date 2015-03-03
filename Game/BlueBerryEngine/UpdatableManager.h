//-----------------------------------------------------------------
// UpdatableManager class
// C++ Header File UpdatableManager.h
//-----------------------------------------------------------------

#ifndef UPDATABLEMANAGER_H
#define UPDATABLEMANAGER_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include <list>

class Updatable;

//-----------------------------------------------------------------
// DrawableManager class
//-----------------------------------------------------------------
class UpdatableManager
{
protected:
	// Member variables 
	std::list<Updatable*> m_lActiveUpdatables;
	std::list<Updatable*> m_lObjectsToDelete;

public:
	//Constructor(s)/ Destructor
	UpdatableManager();
	~UpdatableManager();

	// General Methods
	void UpdateAll();
	void Register(Updatable* u);
	void Deregister(Updatable* u);
	void Cleanup();

private:
	//non-copyable
	UpdatableManager(const UpdatableManager& cpy);
};
#endif