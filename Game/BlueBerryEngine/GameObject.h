//-----------------------------------------------------------------
// GameObject class
// C++ Header File GameObejct.h
//-----------------------------------------------------------------
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Drawable.h"
#include "Inputable.h"
#include "Updatable.h"
#include "Collidable.h"
#include "Terminatable.h"

//-----------------------------------------------------------------
// GameObejct Class
//-----------------------------------------------------------------
class GameObject :public Drawable, public Inputable, public Updatable, public Collidable, public Terminatable
{
protected:
	// Member variables

public:
	// Constructor(s)/Destructors
	GameObject(GraphicsObjectColorNoTexture* _GraphicsObject);
	GameObject(GraphicsObjectFlatTexture* _GraphicsObject);
	GameObject(GraphicsObjectWireFrame* _GraphicsObject);
	GameObject(void);
	virtual ~GameObject(void);

	// General Methods
	virtual void KeyPressed(AZUL_KEY k) override;
	virtual void KeyReleased(AZUL_KEY k) override;
	virtual void Update() override;
	void RegisterUpdatable() override;
	void DeregisterUpdatable() override;
	void RegisterInputable(AZUL_KEY K, KEYPRESS_EVENT E);
	void DerigisterInputable(AZUL_KEY K, KEYPRESS_EVENT E);

private:
	
};
#endif // !GAMEOBJECT_H