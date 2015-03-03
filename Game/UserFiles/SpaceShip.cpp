//-----------------------------------------------------------------
// Space Ship object
// C++ source file Spaceship.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include files
//-----------------------------------------------------------------
#include "SpaceShip.h"
#include "CollidableGroup.h"
#include "SimpleSphere.h"
#include "ResourceManager.h"

//-----------------------------------------------------------------
// Constructor(s)/Destructors
//-----------------------------------------------------------------

SpaceShip::SpaceShip()
	:GameObject(),m_fShipTransSpeed(1), m_fShipRotAng(0.05f)
{
	m_pGraphicsObject = new GraphicsObjectFlatTexture(ResourceManager::GetModel("SpaceFrigate"),ResourceManager::GetTexture("SpaceFrigateTexture")) ;

	RegisterGameObject();
	Collidable::SetModel(*m_pGraphicsObject->getModel());

	// Make these default values...
	m_mShipScale.set(SCALE, 0.5f, 0.5f, 0.5f);
	m_vShipPos.set(0,20,0);
	m_mShipRot.set(ROT_XYZ,0,0,0);
	m_mWorldMatrix = m_mShipScale * m_mShipRot * Matrix(TRANS,m_vShipPos);
	m_pGraphicsObject->setWorld(m_mWorldMatrix);
	Collidable::SetWorldMatrix(&m_mWorldMatrix);
}


SpaceShip::~SpaceShip(void)
{
	delete m_pGraphicsObject;
	printf("Deleting Space Ship\n");
}

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------

void SpaceShip::KeyPressed(AZUL_KEY k)
{
	if (k == KEY_I)
	{
			m_vShipPos += Vect(0,0,2) * m_mShipRot * m_fShipTransSpeed;
	}
	else if(k == KEY_K)
	{
		m_vShipPos += Vect(0,0,2) * m_mShipRot * - m_fShipTransSpeed;
	}
	// Ship Rotation movement (not using time-based values for simplicity)
	else if (k == KEY_J)
	{
		m_mShipRot *= Matrix(ROT_Y, m_fShipRotAng);
	}
	else if(k == KEY_L)
	{
		m_mShipRot *= Matrix(ROT_Y, -m_fShipRotAng);
	}
}

void SpaceShip::KeyReleased(AZUL_KEY k)
{
	k;
}

void SpaceShip::Update()
{
	m_mWorldMatrix = m_mShipScale * m_mShipRot * Matrix(TRANS,m_vShipPos);
	m_pGraphicsObject->setWorld(m_mWorldMatrix);
	Collidable::SetWorldMatrix(&m_mWorldMatrix);
}

void SpaceShip::RegisterUpdatable()
{
	GameObject::RegisterUpdatable();
}

void SpaceShip::DeregisterUpdatable()
{
	GameObject::DeregisterUpdatable();
}

void SpaceShip::Alarm0()
{
	printf("ALARM 0 GOING OFF INSIDE SPACESHIP CLASS\n");
	Alarmable::DeregisterAlarmable(ALARM_ID_0);
}

void SpaceShip::Alarm1()
{
	printf("ALARM 1 GOING OFF INSIDE SPACESHIP CLASS\n");
	Alarmable::DeregisterAlarmable(ALARM_ID_1);
}

void SpaceShip::Alarm2()
{
	printf("ALARM 2 GOING OFF INSIDE SPACESHIP CLASS\n");
	Alarmable::DeregisterAlarmable(ALARM_ID_2);
}

void SpaceShip::Alarm3()
{
	printf("ALARM 3 GOING OFF INSIDE SPACESHIP CLASS\n");
	Alarmable::DeregisterAlarmable(ALARM_ID_3);
}

void SpaceShip::Alarm4()
{
	printf("ALARM 4 GOING OFF INSIDE SPACESHIP CLASS\n");
	Alarmable::DeregisterAlarmable(ALARM_ID_4);
}

void SpaceShip::Collision(Collidable* c1)
{
	c1;
}

void SpaceShip::Collision(Cottage* cottage)
{
	cottage;
	printf("SpaceShip is Colliding with Cottage!\n");
	m_bHit = true;
}

void SpaceShip::Collision(SpaceShip* _other)
{
	m_bHit = true;
	_other;
	if(m_bPlayer == true)
		printf("Player colliding with Other Ship!\n");
	else
		printf("Ship Colliding with other Ship\n");
}

void SpaceShip::RegisterCollidable()
{
	CollidableGroup<SpaceShip>::Register(this);
}

void SpaceShip::DeregisterCollidable()
{
	CollidableGroup<SpaceShip>::Deregister(this);
}

void SpaceShip::Draw()
{
	m_pGraphicsObject->Render();
	//Draw Collision Sphere for Debug purposes
	if(m_bHit)
	{
		Collidable::DrawDebugSphere(1.0f,0.0f,0.0f);
	}
	else
	{
		Collidable::DrawDebugSphere( 0.0f, 1.0f, 0.0f );
	}
}

void SpaceShip::SetPos(float x, float y, float z)
{
	m_vShipPos.set(x,y,z);
}

void SpaceShip::SetRot(float x, float y, float z)
{
	m_mShipRot.set(ROT_XYZ,x,y,z);
}

void SpaceShip::SetScale(float x, float y, float z)
{
	m_mShipScale.set(SCALE,x,y,z);
}

void SpaceShip::setPlayer(bool _player)
{
	m_bPlayer = _player;
		RegisterInputable(AZUL_KEY::KEY_I, KEYPRESS_EVENT::KEY_PRESSED);
		RegisterInputable(AZUL_KEY::KEY_K, KEYPRESS_EVENT::KEY_PRESSED);
		RegisterInputable(AZUL_KEY::KEY_J, KEYPRESS_EVENT::KEY_PRESSED);
		RegisterInputable(AZUL_KEY::KEY_L, KEYPRESS_EVENT::KEY_PRESSED);
}

void SpaceShip::RegisterGameObject()
{
	RegisterUpdatable();
	RegisterDrawable();
	m_bPlayer = false;
	m_bUpdatable = true;
	//Alarmable::RegisterAlarmable(ALARM_ID_0,10.0f);
	//Alarmable::RegisterAlarmable(ALARM_ID_1, 10.0f);
	//Alarmable::RegisterAlarmable(ALARM_ID_2, 5.0f );
	//Alarmable::RegisterAlarmable(ALARM_ID_3, 15.0f );
	//Alarmable::RegisterAlarmable(ALARM_ID_4, 20.0f);
	RegisterCollidable();
}
