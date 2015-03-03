//-----------------------------------------------------------------
// Dumpster class
// C++ Header File Dumpster.h
//-----------------------------------------------------------------
#ifndef DUMPSTER_H
#define DUMPSTER_H

//-----------------------------------------------------------------
// Include Files & Forward Declaration
//-----------------------------------------------------------------
#include <list>
class Terminatable;

//-----------------------------------------------------------------
// DumpsterClass
//-----------------------------------------------------------------
class Dumpster
{
protected:
	// Member Variables
	std::list<Terminatable*> m_lActiveTm;
	int	m_iSize;

public:
	// Constructor(s)/Destructor
	Dumpster();
	~Dumpster();

	// General Methods
	static void SetUnused(Terminatable*  t);
	void Register(Terminatable* t);
	void Deregister(Terminatable* t);
	void Clean();

	//Accessors
	int GetSize();

private:
};
#endif