//-----------------------------------------------------------------
// Dumpster class
// C++ Source File Dumpster.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Dumpster.h"
#include "SceneManager.h"
#include "Terminatable.h"
#include <algorithm>

//-----------------------------------------------------------------
// Constructor(s)/Destructors
//-----------------------------------------------------------------

Dumpster::Dumpster()
{
	m_lActiveTm = std::list<Terminatable*>();
	m_iSize = 0;
}

Dumpster::~Dumpster()
{
	m_lActiveTm.clear();
}

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------
void Dumpster::SetUnused(Terminatable* t)
{
	PrivSceneManager::GetCurrentScene()->GetDumpster()->Deregister(t);
	delete t;
}

void Dumpster::Register(Terminatable* t)
{
	m_lActiveTm.push_front(t);
	m_iSize++;
}

void Dumpster::Deregister(Terminatable* t)
{
	std::list<Terminatable*>::iterator it = std::find (m_lActiveTm.begin(), m_lActiveTm.end(), t);
	m_lActiveTm.erase(it);
	m_iSize--;
	printf("Number of objects left in scene: %d\n",m_iSize);
}

void Dumpster::Clean()
{
	std::list<Terminatable*>::iterator it = m_lActiveTm.begin(); 
	while(it != m_lActiveTm.end())
	{
		delete(*it);
		it = m_lActiveTm .erase(it);
		m_iSize--;
	}
	printf("Number of objects left in scene: %d\n",m_iSize);
}

//Accessors
int Dumpster::GetSize()
{
	return m_iSize;
}


