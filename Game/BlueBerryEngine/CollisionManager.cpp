//-----------------------------------------------------------------
// CollisionManager Class 
// C++ Source - CollisionManager.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "CollisionManager.h"


//-----------------------------------------------------------------
// Constructor(s)/Destructor
//-----------------------------------------------------------------
CollisionManager::CollisionManager()
{
	colGroupCollection = std::set<CollidableGroupBase*>();
}

CollisionManager::~CollisionManager(void)
{
	CollisionGroupCollection::iterator it = colGroupCollection.begin(); 
	while(it != colGroupCollection.end())
	{
		delete *it;
		it = colGroupCollection.erase(it);
	}
}

//-----------------------------------------------------------------
// General Methods Files
//-----------------------------------------------------------------
void CollisionManager::ProcessCollisions()
{
	for( CollisionGroupCollection::iterator it = colGroupCollection.begin(); it!= colGroupCollection.end(); it++)
	{
		(*it)->CallAllTestFunctions();
	}
}

void CollisionManager::Cleanup()
{
	CollisionGroupCollection::iterator it = colGroupCollection.begin(); 
	while(it != colGroupCollection.end())
	{
		delete *it;
		it = colGroupCollection.erase(it);
	}
}
