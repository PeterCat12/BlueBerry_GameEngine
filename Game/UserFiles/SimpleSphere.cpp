#include "SimpleSphere.h"
#include "CollidableGroup.h"
#include "SpaceShip.h"
#include "ResourceManager.h"

// Constructor(s)/Destructors

SimpleSphere::SimpleSphere(GraphicsObjectWireFrame* _GraphicsObject)
	:GameObject(_GraphicsObject)
{
	RegisterDrawable();
	RegisterUpdatable();
	RegisterCollidable();
	Collidable::SetModel(*_GraphicsObject->getModel());
	m_fAngle = 0.0f;

	m_msphereScale.set(SCALE, 20.0f, 20.0f, 20.0f);
	m_vspherePos.set(0,20,40);
	m_msphereRot.set(ROT_XYZ,0,0,0);
	m_mWorldMatrix = m_msphereScale * m_msphereRot * Matrix(TRANS,m_vspherePos);
	Drawable::GetGraphicsObject()->setWorld(m_mWorldMatrix);
	Collidable::SetWorldMatrix(&m_mWorldMatrix);
}

SimpleSphere::SimpleSphere()
{
	m_pGraphicsObject = new GraphicsObjectWireFrame(ResourceManager::GetModel("Sphere"));
	m_pGraphicsObject->color.set(.5f, .5f, .5f);

	RegisterDrawable();
	RegisterUpdatable();
	RegisterCollidable();
	Collidable::SetModel(*m_pGraphicsObject->getModel());
	m_fAngle = 0.0f;

	m_msphereScale.set(SCALE, 20.0f, 20.0f, 20.0f);
	m_vspherePos.set(0,20,40);
	m_msphereRot.set(ROT_XYZ,0,0,0);
	m_mWorldMatrix = m_msphereScale * m_msphereRot * Matrix(TRANS,m_vspherePos);
	m_pGraphicsObject->setWorld(m_mWorldMatrix);
	Collidable::SetWorldMatrix(&m_mWorldMatrix);
}

SimpleSphere::~SimpleSphere(void)
{
	delete m_pGraphicsObject;
	printf("Deleting simple Sphere\n");
}

void SimpleSphere::KeyPressed(AZUL_KEY k)
{
	k;
	//throw std::logic_error("The method or operation is not implemented.");
}

void SimpleSphere::KeyReleased(AZUL_KEY k)
{
	k;
	//throw std::logic_error("The method or operation is not implemented.");
}

void SimpleSphere::Update()
{
	m_fAngle += 0.02f;
	// BoundingSphere
	m_msphereRot.set( ROT_XYZ, 0, m_fAngle, 0.25f*m_fAngle );
	m_mWorldMatrix = m_msphereScale * m_msphereRot * Matrix(TRANS,m_vspherePos);
	m_pGraphicsObject->setWorld(m_mWorldMatrix); 
}

void SimpleSphere::RegisterUpdatable()
{
	GameObject::RegisterUpdatable();
}

void SimpleSphere::DeregisterUpdatable()
{
	GameObject::DeregisterUpdatable();
}

void SimpleSphere::Collision(Collidable* c1)
{
	c1;
}

void SimpleSphere::Collision(SpaceShip* ship)
{
	ship;
	printf("Simple Sphere is colliding with SpaceShip!\n");
}

void SimpleSphere::RegisterCollidable()
{
	CollidableGroup<SimpleSphere>::Register(this);
}

void SimpleSphere::DeregisterCollidable()
{
	CollidableGroup<SimpleSphere>::Register(this);
}

void SimpleSphere::Draw()
{
	m_pGraphicsObject->Render();
}

