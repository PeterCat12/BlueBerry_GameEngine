#pragma once

#include "GameObject.h"

class Floor : public GameObject
{
protected:
	Matrix m_mWorldMatrix;
	GraphicsObjectColorNoTexture* pGObj_Axis;
	GraphicsObjectFlatTexture* pGObj_Plane;

public:
	Floor(void);
	~Floor(void);

	virtual void Draw();

	virtual void RegisterCollidable();

	virtual void DeregisterCollidable();

};

