//-----------------------------------------------------------------
// Collidable Class 
// C++ Source - Collidable.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Collidable.h"
#include "CollidableGroup.h"
#include "ResourceManager.h"

//-----------------------------------------------------------------
// Constructor(s)
//-----------------------------------------------------------------
Collidable::Collidable(void)
{
	m_pGameObjectModel = 0;
	m_pWorldMatrix = 0;
	m_DebugSphere =  new GraphicsObjectWireFrame(ResourceManager::GetModel("Sphere"));
	m_bHit = false;
}

Collidable::Collidable(Model* _GameObjectModel, Matrix* world)
{
	m_pWorldMatrix = world;
	m_pGameObjectModel = _GameObjectModel;
	m_DebugSphere = new GraphicsObjectWireFrame(ResourceManager::GetModel("Sphere"));
	m_bHit = false;

}

Collidable::Collidable(Model* _GameObjectModel)
{
	m_pGameObjectModel = _GameObjectModel;
	m_DebugSphere = new GraphicsObjectWireFrame(ResourceManager::GetModel("Sphere"));
	m_bHit = false;
}


Collidable::~Collidable(void)
{
	delete m_DebugSphere;
}


//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------
void Collidable::Collision(Collidable* c1)
{
	c1;
}

bool Collidable::TestCollisionPair(Collidable* c1, Collidable* c2)
{
	// Should Test Right here..
	Vect zero = Vect(0,0,0);
	Vect one  = Vect(0,0,1);
	// compute the base transform/// 
	Matrix M_base1 = Matrix(SCALE, c1->GetModel()->radius, c1->GetModel()->radius,c1->GetModel()->radius)  
		* Matrix(TRANS, c1->GetModel()->center);
	Matrix M1 = M_base1 * (*c1->GetWorldMatrix()); 

	Vect center1 = zero * M1;
	Vect temp = one * M1;
	float radius1 = (center1 - temp).mag();

	Matrix M_base2 = Matrix(SCALE, c2->GetModel()->radius, c2->GetModel()->radius,c2->GetModel()->radius)  
		* Matrix(TRANS, c2->GetModel()->center);
	Matrix M2 = M_base2 * (*c2->GetWorldMatrix()); 

	Vect center2 = zero * M2;
	Vect temp2 = one * M2;
	float radius2 = (center2 - temp2).mag();

	float radiusSum = radius1 + radius2;
	
	//Calculate distance...
	Vect dist = center1 - center2;

	float distance  = dist.mag();

	if(distance <= radiusSum)
	{
		return true;
	}
	return false;
}

void Collidable::DrawDebugSphere( float x, float y, float z)
{
	if(m_pGameObjectModel != 0 && m_pWorldMatrix != 0)
	{
		Matrix M_base = Matrix(SCALE, m_pGameObjectModel->radius, m_pGameObjectModel->radius,m_pGameObjectModel->radius)  
			* Matrix(TRANS, m_pGameObjectModel->center);
		Matrix M = M_base * (*m_pWorldMatrix); 

		m_DebugSphere->setWorld(M);
		//m_DebugSphere->setWorld(*m_pWorldMatrix);
		m_DebugSphere->color.set(x,y ,z);
		m_DebugSphere->Render();
	}
		m_bHit = false;
}
//-----------------------------------------------------------------
// Setters/Getters
//-----------------------------------------------------------------
void Collidable::SetWorldMatrix(Matrix* world)
{
	m_pWorldMatrix = world;
}

Matrix* Collidable::GetWorldMatrix()
{
	return m_pWorldMatrix;
}

void Collidable::SetModel(Model& _Model)
{
	m_pGameObjectModel = &_Model;
}

Model* Collidable::GetModel()
{
	return m_pGameObjectModel;
}

void Collidable::SetHit(bool _Hit)
{
	m_bHit = _Hit;
}
