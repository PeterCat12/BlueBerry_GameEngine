#include "Cottage.h"
#include "ResourceManager.h"
#include "CollidableGroup.h"

Cottage::Cottage(void)
	:GameObject()
{
	Model* pModelCottage = ResourceManager::GetModel("Cottage");
	m_pGraphicsObject = new GraphicsObjectFlatTexture( pModelCottage,
		ResourceManager::GetTexture("brick-wall.tga"), ResourceManager::GetTexture("Rooftexture.tga"), 
		ResourceManager::GetTexture("Cabintexture.tga"), ResourceManager::GetTexture("Chimneytexture.tga") );

	Drawable::SetGraphicsObject(m_pGraphicsObject);
	RegisterDrawable();
	RegisterCollidable();
	RegisterUpdatable();
	m_fAngle = 0.0f;
	m_mScale.set(SCALE,2,2,2);
	m_mRot.set( ROT_XYZ, 0, 0, 0 );
	m_vPos.set(0,10,-70);

	m_mWorldMatrix = m_mScale * m_mRot * Matrix(TRANS,m_vPos);
	m_pGraphicsObject->setWorld(m_mWorldMatrix);
	Drawable::SetHidden(false);
	Collidable::SetWorldMatrix(&m_mWorldMatrix);
	Collidable::SetModel(*m_pGraphicsObject->getModel());
}


Cottage::~Cottage(void)
{
	DeregisterCollidable();
	DeregisterUpdatable();
	DeregisterDrawable();

	delete m_pGraphicsObject;
	printf("Deleting cottage\n");
}

void Cottage::Update()
{
	m_fAngle += 0.02f;
	m_mRot.set( ROT_XYZ, 0, m_fAngle, 0 );
	m_mWorldMatrix = m_mScale * m_mRot * Matrix(TRANS,m_vPos);
	m_pGraphicsObject->setWorld(m_mWorldMatrix);
	Collidable::SetWorldMatrix(&m_mWorldMatrix);
}

void Cottage::RegisterCollidable()
{
	CollidableGroup<Cottage>::Register(this);
}

void Cottage::DeregisterCollidable()
{
	CollidableGroup<Cottage>::Deregister(this);
}

void Cottage::Draw()
{
	Drawable::Draw();
	if(m_bHit)
	{
		Collidable::DrawDebugSphere(1.0f,0.0f,0.0f);
	}
	else
	{
		Collidable::DrawDebugSphere( 0.0f, 1.0f, 0.0f );
	}
}

void Cottage::Collision(Collidable* c1)
{
	c1;
}

void Cottage::Collision(SpaceShip* _SpaceShip)
{
	_SpaceShip;
	m_bHit = true;
	printf("Cottage is Colliding with SpaceShip!\n");
	Terminatable::MarkForTermination();
}



void Cottage::Terminate()
{
	Terminatable::FinalMan(this);
}

