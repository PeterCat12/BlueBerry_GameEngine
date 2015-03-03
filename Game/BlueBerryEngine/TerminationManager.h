//-----------------------------------------------------------------
// TerminationManager class
// C++ Header File TerminationManager.h
//-----------------------------------------------------------------

#ifndef TERMINATIONMAN_H
#define	TERMINATIONMAN_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include <list>

class Terminatable;

//-----------------------------------------------------------------
// TerminationManager Class
//-----------------------------------------------------------------
class TerminationManager
{
protected:
	std::list<Terminatable*> m_lActiveTermiables;

public:
	TerminationManager(void);
	~TerminationManager(void);

	// General Methods
	void Register(Terminatable* d);
	void ProcessTerminationEvents();
	void Cleanup();

private:
	TerminationManager(const TerminationManager& cpy);
};

#endif // !TERMINATIONMAN_H