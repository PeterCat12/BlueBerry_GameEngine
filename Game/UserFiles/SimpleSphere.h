#ifndef SIMPLESPHERE_H
#define SIMPLESPHERE_H

#include "GameObject.h"

class SpaceShip;

class SimpleSphere : public GameObject
{
protected:
	// Member Variables
	GraphicsObjectWireFrame* m_pGraphicsObject;
	float		m_fAngle;
	Matrix		m_mWorldMatrix;
	Matrix		m_msphereScale;
	Vect		m_vspherePos;
	Matrix		m_msphereRot;
	//const float m_fRotAngle; // = .05f;
	
public:
	// Constructor(s)/Destructors
	SimpleSphere(GraphicsObjectWireFrame* _GraphicsObject);
	SimpleSphere();
	~SimpleSphere(void);
	// General Methods
	virtual void KeyPressed(AZUL_KEY k) override;
	virtual void KeyReleased(AZUL_KEY k) override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void RegisterUpdatable() override;
	virtual void DeregisterUpdatable() override;
	virtual void Collision(Collidable* c1);
	void Collision(SpaceShip* ship);
	virtual void RegisterCollidable();
	virtual void DeregisterCollidable();



private:
};
#endif // !SIMPLESPHERE_H

