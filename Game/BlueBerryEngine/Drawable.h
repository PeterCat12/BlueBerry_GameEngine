//-----------------------------------------------------------------
// Drawable class
// C++ Header File Drawable.h
//-----------------------------------------------------------------

#ifndef DRAWABLE_H
#define DRAWABLE_H

//-----------------------------------------------------------------
// Forward Decls and Include Files
//-----------------------------------------------------------------

class GraphicsObjectColorNoTexture;
class GraphicsObjectFlatTexture;
class GraphicsObjectWireFrame;
class GraphicsObject;

//-----------------------------------------------------------------
// Drawable class
//-----------------------------------------------------------------
class Drawable
{
protected:
	GraphicsObject* m_gGraphicsObject;
	bool m_bIsHidden;
	GraphicsObject* GetGraphicsObject();

public:
	Drawable(GraphicsObjectColorNoTexture* _GraphicsObject);
	Drawable(GraphicsObjectFlatTexture* _GraphicsObject);
	Drawable(GraphicsObjectWireFrame* _GraphicsObject);
	Drawable(void);
	virtual ~Drawable(void);

	//General methods
	virtual void Draw();
	void RegisterDrawable();
	void DeregisterDrawable();
	void SetHidden(bool bHidden);
	bool IsHidden(); 
	void SetGraphicsObject(GraphicsObject* _GraphicsObject);

private:
	
};

#endif