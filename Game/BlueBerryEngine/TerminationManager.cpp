#include "TerminationManager.h"
#include "Terminatable.h"


TerminationManager::TerminationManager(void)
{
	m_lActiveTermiables = std::list<Terminatable*>();
}


TerminationManager::~TerminationManager(void)
{
	Cleanup();
}

void TerminationManager::Register(Terminatable* d)
{
	m_lActiveTermiables.push_back(d);
}

void TerminationManager::ProcessTerminationEvents()
{
	std::list<Terminatable*>::iterator it = m_lActiveTermiables.begin();
	while(it != m_lActiveTermiables.end() )
	{
		(*it)->Terminate();

		it = m_lActiveTermiables.erase(it);
	}
}

void TerminationManager::Cleanup()
{
	m_lActiveTermiables.clear();
}

