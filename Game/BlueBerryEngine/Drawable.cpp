//-----------------------------------------------------------------
// Drawable 
// C++ Source - Drawable.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Drawable.h"
#include "GraphicsObject_ColorNoTexture.h"
#include "GraphicsObject_FlatTexture.h"
#include "GraphicsObject_WireFrame.h"
#include "GraphicsObject.h"
#include "SceneManager.h"

//-----------------------------------------------------------------
// Constructor(s) / Destructors
//-----------------------------------------------------------------
Drawable::Drawable(GraphicsObjectColorNoTexture* _GraphicsObject)
{
	m_gGraphicsObject = (GraphicsObject*)_GraphicsObject;
	m_bIsHidden = false;

}

Drawable::Drawable(GraphicsObjectFlatTexture* _GraphicsObject)
{
	m_gGraphicsObject = (GraphicsObject*)_GraphicsObject;
	m_bIsHidden = false;

}

Drawable::Drawable(GraphicsObjectWireFrame* _GraphicsObject)
{
	m_gGraphicsObject = (GraphicsObject*)_GraphicsObject;
	m_bIsHidden = false;

}

Drawable::Drawable(void)
{
	m_gGraphicsObject = 0;
	m_bIsHidden = false;
}


Drawable::~Drawable(void)
{
}

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------
void Drawable::RegisterDrawable()
{
	PrivSceneManager::GetCurrentScene()->GetDrawableManager()->Register(this);
}

void Drawable::SetHidden(bool bHidden)
{
	m_bIsHidden = bHidden;
}

bool Drawable::IsHidden()
{
	return m_bIsHidden;
}

void Drawable::Draw()
{
	 if(!m_bIsHidden && m_gGraphicsObject != 0)
		m_gGraphicsObject->Render();
}

void Drawable::DeregisterDrawable()
{
	PrivSceneManager::GetCurrentScene()->GetDrawableManager()->Deregister(this);
}

GraphicsObject* Drawable::GetGraphicsObject()
{
	return m_gGraphicsObject;
}

void Drawable::SetGraphicsObject(GraphicsObject* _GraphicsObject)
{
	m_gGraphicsObject = _GraphicsObject;
}
