//-----------------------------------------------------------------
// CollidableGroup class
// C++ Header File CollidableGroup.h
//-----------------------------------------------------------------
#ifndef COLLIDABLEGROUP_H
#define COLLIDABLEGROUP_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Collidable.h"
#include "CollidableGroupBase.h"
#include <set>

/**********************************************************************************************//**
 * \class	CollidableGroup
 *
 * \brief	A collidable group.
 *
 * \author	Peter
 * \date	2/27/2015
 *
 * \tparam	C	Type of the c. C is potentially any object derived from Collidable
 **************************************************************************************************/
template < class C > 
class CollidableGroup : public CollidableGroupBase
{
public:

	/**********************************************************************************************//**
	 * \typedef	std::set<C*> CollidableCollections
	 *
	 * \brief	Defines an alias representing the collidable collections.
	 **************************************************************************************************/
	typedef std::set<C*> CollidableCollections;
	/** \brief	Collection of collidables. */
	CollidableCollections m_sCollidableCollection;

	/**********************************************************************************************//**
	 * \typedef	void (*CollisionTestFnc)()
	 * \brief	Defines an alias representing the collision test function.
	 **************************************************************************************************/
	typedef void (*CollisionTestFnc)();

	/**********************************************************************************************//**
	 * \typedef	std::set<CollisionTestFnc> TargetTestFncs
	 * \brief	Defines an alias representing target test functions.
	 **************************************************************************************************/
	typedef std::set<CollisionTestFnc> TargetTestFncs;
	/** \brief	Target tests. */
	TargetTestFncs TargetTests;

	/** \brief	Destructor */
	virtual ~CollidableGroup(void);

	/**********************************************************************************************//**
	 * \fn	void CollidableGroup::CallAllTestFunctions() override;
	 * \brief	Call test functions.
	 **************************************************************************************************/
	void CallAllTestFunctions() override;

	/**********************************************************************************************//**
	 * \fn	static void CollidableGroup::Register(C* collidable);
	 * \brief	Registers this object.
	 * \param [in,out]	collidable	If non-null, the collidable.
	 **************************************************************************************************/
	static void Register(C* collidable);

	/**********************************************************************************************//**
	 * \fn	static void CollidableGroup::Deregister(C* collidable);
	 * \brief	Deregisters incomining Collidable.
	 * \param [in,out]	collidable	If non-null, the collidable.
	 **************************************************************************************************/
	static void Deregister(C* collidable);

	/**********************************************************************************************//**
	 * \fn	template < class C2 > static void CollidableGroup::AddTestCollisionWithOther()
	 * \brief	Adds test collision with another Collidable.
	 * \tparam	C2	Type of the c 2.
	 **************************************************************************************************/
	template < class C2 >
	static void AddTestCollisionWithOther()
	{
		Instance()->TargetTests.insert(&CollisionTest< C2 > );
	}

	/**********************************************************************************************//**
	 * \fn	static void CollidableGroup::AddPrivTestCollisionWithOther()
	 * \brief	Adds Collision Test With another Object of the same type. Ex: SpaceShip vs SpaceShip
	 **************************************************************************************************/
	static void AddPrivTestCollisionWithOther()
	{
		Instance()->TargetTests.insert(&PrivCollisionTest );
	}

	/**********************************************************************************************//**
	 * \fn	static void CollidableGroup::PrivCollisionTest()
	 * \brief	Tests priv collision.
	 **************************************************************************************************/
	static void PrivCollisionTest()
	{
		bool test_result;
		// Stop one before the end...
		for(CollidableCollections::iterator it_mine = Instance()->m_sCollidableCollection.begin(); 
			it_mine != std::prev(Instance()->m_sCollidableCollection.end()); it_mine++)
		{
			for(CollidableCollections::iterator it_other = next(it_mine); 
				it_other != Instance()->m_sCollidableCollection.end(); it_other++)
			{
				test_result = Collidable::TestCollisionPair(*it_mine, *it_other);

				if ( test_result)
				{
					(*it_mine)->Collision(*it_other);
					(*it_other)->Collision(*it_mine);
				}
			}
		}

	}

	/**********************************************************************************************//**
	 * \fn	template < class C2 > static void CollidableGroup::CollisionTest()
	 * \brief	Tests collision with two Collidable Objects
	 * \tparam	C2	Type of the c 2.
	 * 				Iterates through the appropriate collidable group and tests to see if there are any collisions.
	 * 				if there are, then each Collidable has their collision function called.
	 **************************************************************************************************/
	template < class C2 >
	static void CollisionTest()
	{
		bool test_result;

		for (CollidableCollections::iterator it_mine  = Instance()->m_sCollidableCollection.begin(); 
			it_mine != Instance()->m_sCollidableCollection.end(); it_mine++)
		{
			for (CollidableGroup<C2>::CollidableCollections::iterator it_other = CollidableGroup<C2>::Instance()->m_sCollidableCollection.begin(); 
				it_other !=CollidableGroup<C2>::Instance()->m_sCollidableCollection.end(); it_other++  )
			{
				test_result = Collidable::TestCollisionPair(*it_mine, *it_other);

				if ( test_result)
				{
					(*it_mine)->Collision(*it_other);
					(*it_other)->Collision(*it_mine);
				}
			}
		}
	}

	/**********************************************************************************************//**
	 * \fn	static CollidableGroup<C>* CollidableGroup::Instance();
	 * \brief	Gets the instance.
	 * \return	if null, a new CollidableGroup<C>, else the instance of Type C
	 **************************************************************************************************/

	static CollidableGroup<C>* Instance();

	/**********************************************************************************************//**
	 * \fn	static CollidableGroup<C>* CollidableGroup::Delete();
	 *
	 * \brief	Deletes Instance of type C
	 * \return	null if it fails, else a CollidableGroup&lt;C&gt;*.
	 **************************************************************************************************/
	static CollidableGroup<C>*	Delete();

private:
	//Constructor(s) // singleton variables
	CollidableGroup();
	static bool				m_bInstanceFlag;
	static CollidableGroup<C>*		m_cgSingle;
};

// Constructors/Destrucotrs
template < class C >
CollidableGroup<C>::CollidableGroup()
{
	 m_sCollidableCollection = std::set<C*>();
}

template < class C >
CollidableGroup<C>::~CollidableGroup(void)
{
	TargetTests.clear();
	m_sCollidableCollection.clear();
}
// Static variables
template < class C>
bool CollidableGroup<C>::m_bInstanceFlag =false;

template < class C > 
CollidableGroup<C>* CollidableGroup<C>::m_cgSingle = 0;

// General Methods
template < class C >
void CollidableGroup<C>::Deregister(C* collidable)
{
	Instance()->m_sCollidableCollection.erase(collidable);	
}

template < class C >
void CollidableGroup<C>::Register(C* collidable)
{
	Instance()->m_sCollidableCollection.insert(collidable);
}

template < class C >
void CollidableGroup<C>::CallAllTestFunctions()
{
	for (TargetTestFncs::iterator it_testfncs = TargetTests.begin(); it_testfncs!= TargetTests.end(); it_testfncs++)
	{
	(*it_testfncs)();
	}
}

template < class C >
CollidableGroup<C>* CollidableGroup<C>::Instance()
{
	if( !m_bInstanceFlag)
	{
		m_cgSingle = new CollidableGroup<C>();
		m_bInstanceFlag = true;
		return m_cgSingle;
	}
	else
	{
		return m_cgSingle;
	}
}

template < class C>
CollidableGroup<C>* CollidableGroup<C>::Delete()
{
	delete Instance();
}


#endif // !COLLIDABLEGROUP_H
