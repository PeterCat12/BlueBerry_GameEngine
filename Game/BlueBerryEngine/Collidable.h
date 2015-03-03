//-----------------------------------------------------------------
// Collidable class
// C++ Header File Collidable.h
//-----------------------------------------------------------------
#ifndef COLLIDABLE_H
#define COLLIDABLE_H

//-----------------------------------------------------------------
// Include Files & Forward Declarations
//-----------------------------------------------------------------
class GraphicsObjectWireFrame;
class Model;
#include "Azul.h"

/**********************************************************************************************//**
 * \class	Collidable
 * \brief	A collidable object
 * 			Module that allows derived objects to collide with other collidables
 * \author	Peter
 * \date	2/27/2015
 **************************************************************************************************/
class Collidable
{
protected:
	/** \brief	The game object model. */
	Model*						m_pGameObjectModel;
	/** \brief	The world matrix. */
	Matrix*						m_pWorldMatrix;
	/** \brief	The debug sphere. */
	GraphicsObjectWireFrame*	m_DebugSphere;
	/** \brief	true if (this) is colliding with another collidable.*/
	bool						m_bHit;

public:
	/** \brief Default constructor.
	*    // Creates a debug sprite, sets m_bHit to false, initializes m_pGameObjectModel and m_pWorldMatrix to 0.
	*/
	Collidable(void);

	/**********************************************************************************************//**
	 * \fn	Collidable::Collidable(Model* _GameObjectModel, Matrix* world);
	 * \brief	Constructor.
	 * \param [in,out]	_GameObjectModel	If non-null, the game object model.
	 * \param [in,out]	world				If non-null, the world.
	 **************************************************************************************************/
	Collidable(Model* _GameObjectModel, Matrix* world);

	/**********************************************************************************************//**
	 * \fn	Collidable::Collidable(Model* _GameObjectModel);
	 * \brief	Constructor.
	 * \param [in,out]	_GameObjectModel	If non-null, the game object model.
	 * 					Initializes m_pDebugSphere, sets m_pWorldMatrix to 0
	 **************************************************************************************************/
	Collidable(Model* _GameObjectModel);
	/** \brief Destructor 
	*    Deletes m_pDebugSphere	
	*/
	virtual ~Collidable(void);

	/**********************************************************************************************//**
	 * \fn	virtual void Collidable::Collision(Collidable* c1);
	 * \brief	Collisions the given c 1.
	 * \param [in,out]	c1	If non-null, the first Collidable.
	 * 					Not sure of the point of this method be... Should ask Andre
	 **************************************************************************************************/
	virtual void Collision(Collidable* c1);

	/**********************************************************************************************//**
	 * \fn	static bool Collidable::TestCollisionPair(Collidable& c1, Collidable& c2);
	 * \brief	Tests collision pairs.
	 * \param [in,out]	c1	The first Collidable.
	 * \param [in,out]	c2	The second Collidable.
	 * 					Tests to see if the distance between two collidables is less than the sum of of the radi of their
	 * 					bounding spheres
	 * \return	true if the test passes, false if the test fails.
	 **************************************************************************************************/
	static bool TestCollisionPair(Collidable* c1, Collidable* c2);

	/**********************************************************************************************//**
	 * \fn	virtual void Collidable::RegisterCollidable() = 0;
	 * \brief	Registers the collidable to the Collidable Manager.
	 * 			See Collidable Example
	 **************************************************************************************************/
	virtual void RegisterCollidable() = 0;

	/**********************************************************************************************//**
	 * \fn	virtual void Collidable::DeregisterCollidable() = 0;
	 * \brief	Deregisters the collidable.
	 **************************************************************************************************/
	virtual void DeregisterCollidable() = 0;

	/**********************************************************************************************//**
	 * \fn	void Collidable::DrawDebugSphere( float x, float y, float z);
	 * \brief	Draws the Debug Sphere.
	 * \param	x	The x coordinate.
	 * \param	y	The y coordinate.
	 * \param	z	The z coordinate.
	 **************************************************************************************************/
	void DrawDebugSphere( float x, float y, float z);

	//Accessors

	/**********************************************************************************************//**
	 * \fn	void Collidable::SetModel(Model& _CollisionModel);
	 * \brief	Sets a model.
	 * \param [in,out]	_CollisionModel	The collision model.
	 **************************************************************************************************/
	void SetModel(Model& _CollisionModel);

	/**********************************************************************************************//**
	 * \fn	Model* Collidable::GetModel();
	 * \brief	Gets the model.
	 * \return	m_pGameObjectModel;
	 **************************************************************************************************/
	Model* GetModel();

	/**********************************************************************************************//**
	 * \fn	void Collidable::SetWorldMatrix(Matrix* world);
	 * \brief	Sets world matrix.
	 * \param [in,out]	world	If non-null, the world.
	 **************************************************************************************************/
	void SetWorldMatrix(Matrix* world);

	/**********************************************************************************************//**
	 * \fn	Matrix* Collidable::GetWorldMatrix();
	 * \brief	Gets world matrix.
	 * \return	null if it fails, else the world matrix.
	 **************************************************************************************************/
	Matrix*	GetWorldMatrix();

	/**********************************************************************************************//**
	 * \fn	void Collidable::SetHit(bool _Hit);
	 * \brief	Sets a hit.
	 * \param	_Hit	true to hit.
	 **************************************************************************************************/
	void SetHit(bool _Hit);
};
#endif // !COLLIDABLE_H

