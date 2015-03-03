#ifndef COTTAGE_H
#define COTTAGE_H

#include "GameObject.h"

class GraphicsObjectFlatTexture;
class SpaceShip;

class Cottage : public GameObject
{
protected:
	GraphicsObjectFlatTexture* m_pGraphicsObject;
	float		m_fAngle;
	Matrix		m_mWorldMatrix;
	Matrix		m_mScale;
	Vect		m_vPos;
	Matrix		m_mRot;

public:
	Cottage(void);
	~Cottage(void);

	virtual void Update() override;
	void Draw() override;
	virtual void Collision(Collidable* c1);
	void Collision(SpaceShip* _SpaceShip);

	virtual void RegisterCollidable();
	virtual void DeregisterCollidable();
	void Terminate() override;


private:
	
};

#endif // !COTTAGE_H