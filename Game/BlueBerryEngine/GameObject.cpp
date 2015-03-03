//-----------------------------------------------------------------
// GameObject 
// C++ Source - GameObject.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "GameObject.h"

//-----------------------------------------------------------------
// Constructors/ Destructors
//-----------------------------------------------------------------
GameObject::GameObject(GraphicsObjectColorNoTexture* _GraphicsObject)
	:Drawable(_GraphicsObject), Inputable(), Updatable(),Collidable()
{
	//RegisterUpdatable();
}

GameObject::GameObject(GraphicsObjectFlatTexture* _GraphicsObject)
	:Drawable(_GraphicsObject), Inputable(), Updatable(),Collidable()
{

}
GameObject::GameObject(GraphicsObjectWireFrame* _GraphicsObject)
	:Drawable(_GraphicsObject), Inputable(), Updatable(), Collidable()
{

}

GameObject::GameObject(void)
	:Drawable(), Inputable(),Updatable(),Collidable()
{

}

GameObject::~GameObject(void)
{

}

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------

void GameObject::RegisterInputable(AZUL_KEY K, KEYPRESS_EVENT E)
{
	Inputable::RegisterInputable(K, E);	
}

void GameObject::DerigisterInputable(AZUL_KEY K, KEYPRESS_EVENT E)
{
	Inputable::DerigisterInputable(K, E);	
}

void GameObject::RegisterUpdatable()
{
	Updatable::RegisterUpdatable();
}

void GameObject::DeregisterUpdatable()
{
	Updatable::DeregisterUpdatable();
}

void GameObject::KeyPressed(AZUL_KEY k)
{
	k;
}

void GameObject::KeyReleased(AZUL_KEY k) 
{
	k;
}

void GameObject::Update()
{
}