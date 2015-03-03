#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H

// Include Files
#include "GameObject.h"
#include "Alarmable.h"

class SimpleSphere;
class Cottage;

class SpaceShip :public GameObject, public Alarmable
{
protected:
	// Member variables
	bool		m_bUpdatable;
	bool		m_bPlayer;
	Matrix		m_mWorldMatrix;
	Matrix		m_mShipScale;
	Vect		m_vShipPos;
	Matrix		m_mShipRot;
	const float m_fShipTransSpeed;// = 1;
	const float m_fShipRotAng; // = .05f;
	GraphicsObjectFlatTexture* m_pGraphicsObject;


public:
	// Constructor(s)/ Destructors
	//SpaceShip(GraphicsObjectFlatTexture* _GraphicsObejct);
	SpaceShip();
	virtual ~SpaceShip(void);


	virtual void KeyPressed(AZUL_KEY k) override;
	virtual void KeyReleased(AZUL_KEY k) override;
	void RegisterUpdatable() override;
	void DeregisterUpdatable() override;
	virtual void Update() override;

	void Alarm0() override;
	void Alarm1() override;
	void Alarm2() override;
	void Alarm3() override;
	void Alarm4() override;

	virtual void Collision(Collidable* c1);
	void Collision(Cottage* cottage);
	void Collision(SpaceShip* _other);
	virtual void RegisterCollidable() override;
	virtual void DeregisterCollidable() override;
	virtual void Draw() override;

	// Setters
	void SetPos(float x, float y, float z);
	void SetRot(float x, float y, float z);
	void SetScale(float x, float y, float z);

	void setPlayer(bool _player);

private:
	// Constructor(s)
	SpaceShip(const SpaceShip& cpy);
	void RegisterGameObject();

	//Operators
	void operator=(const SpaceShip &rhs);
	






};

#endif // !1

