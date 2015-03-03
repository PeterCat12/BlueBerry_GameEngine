//-----------------------------------------------------------------
// CollisionManager class
// C++ Header File CollisionManager.h
//-----------------------------------------------------------------
#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "CollidableGroup.h"
#include <set>

// TypeDefiniton
typedef std::set<CollidableGroupBase*> CollisionGroupCollection;

//-----------------------------------------------------------------
// Collision Manager class
//-----------------------------------------------------------------

class CollisionManager
{
protected:
	// Member variables
	CollisionGroupCollection colGroupCollection;

public:
	// Constructor(s)/Destructors
	CollisionManager();
	~CollisionManager(void);

	// General Methods
	template <class C1, class C2>
	void SetCollisionPair()
	{
		CollidableGroupBase* ptrColGrp1 = CollidableGroup< C1 >::Instance();
		CollidableGroupBase* ptrColGrp2 = CollidableGroup< C2 >::Instance();

		// Test to see if the pointers are the same...
		if(ptrColGrp1 == ptrColGrp2)
		{
			colGroupCollection.insert( ptrColGrp1 );
			CollidableGroup<C1>::AddPrivTestCollisionWithOther();
		}
		else
		{
			colGroupCollection.insert( ptrColGrp1 );
			colGroupCollection.insert( ptrColGrp2 );
			CollidableGroup< C1 >::AddTestCollisionWithOther< C2 >();
		}
	}
	void ProcessCollisions();
	void Cleanup();

private:

};

#endif // !COLLISIONMANAGER_H