//-----------------------------------------------------------------
// GraphicsObject Wrapper Object
// C++ Header File WGraphicsObject.h
//-----------------------------------------------------------------

#ifndef WGRAPHICS_OBJECT_H
#define WGRAPHICS_OBJECT_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Resource.h"

//-----------------------------------------------------------------
//Wrapper class for GraphicsObject class
//-----------------------------------------------------------------
class WGraphicsObject : public IResource
{
protected:
	// Member Variables
	GraphicsObject* m_goGraphicsObject;

public:
	// Constructor(s) / destructor
	WGraphicsObject(GraphicsObject* _graphicsObject) { m_goGraphicsObject = _graphicsObject; }
	~WGraphicsObject(){}

	//	void Subscribe(std::string _name) override   { //Subscriber::Subscribe(_name, this);
	//};

	// General Methods
	Model *getModel() const {return m_goGraphicsObject->getModel(); }
	RenderMaterial *getRender() const { return m_goGraphicsObject->getRender(); }

	GraphicsObject* GetGraphicsObject() { return m_goGraphicsObject; } 


	Matrix &getWorld() { return m_goGraphicsObject->getWorld(); }
	void setWorld( Matrix &_world) { m_goGraphicsObject->setWorld(_world); }

private:
	WGraphicsObject(): IResource()  {};
};
#endif