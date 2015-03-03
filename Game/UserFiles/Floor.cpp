#include "Floor.h"
#include "ResourceManager.h"

Floor::Floor(void)
{
	 pGObj_Axis = new GraphicsObjectColorNoTexture(ResourceManager::GetModel("Axis") );
	 pGObj_Plane = new GraphicsObjectFlatTexture(ResourceManager::GetModel("Plane"), ResourceManager::GetTexture("PlaneTexture")); 

	m_mWorldMatrix = Matrix(IDENTITY);
	pGObj_Axis->setWorld(m_mWorldMatrix);
	m_mWorldMatrix = Matrix(SCALE, 400,400,400);
	pGObj_Plane->setWorld(m_mWorldMatrix);

	Drawable::RegisterDrawable();
}


Floor::~Floor(void)
{
	delete pGObj_Plane;
	delete pGObj_Axis;
	printf("Deleting Floor.\n");
}

void Floor::Draw()
{
	pGObj_Axis->Render();
	pGObj_Plane->Render();
}

void Floor::RegisterCollidable()
{
	//throw std::logic_error("The method or operation is not implemented.");
}

void Floor::DeregisterCollidable()
{
	//throw std::logic_error("The method or operation is not implemented.");
}

