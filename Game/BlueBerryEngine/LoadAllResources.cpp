

#include "ResourceManager.h"


void ResourceManager::LoadAllResourcesHelper()
{

	/*Model *pModelSpaceFrigate = GpuModel::Create("space_frigate.azul");

	Model *pModelAxis = GpuModel::Create("Axis.azul");
	Model *pModelPlane = GpuModel::Create("Plane.azul");*/
		
	//Model Loading  //Maybe "AddModel/ Add Texture would be cleaner... 
	//ResourceManager::AddResource("SpaceFrigate", "space_frigate.azul",MODEL);
	//ResourceManager::AddResource("Axis", "Axis.azul", MODEL);
	//ResourceManager::AddResource("Plane","Plane.azul",MODEL);

	ResourceManager::AddModel("SpaceFrigate", "space_frigate.azul");
	ResourceManager::AddModel("Axis", "Axis.azul");
	ResourceManager::AddModel("Plane", "Plane.azul");
	ResourceManager::AddModel("Sphere", "BoundingSphere.azul");
	ResourceManager::AddModel("Cottage", "Cottage.azul");

	// Texture Loading
	//ResourceManager::AddResource("SpaceFrigateTexture", "space_frigate.tga", TEXTURE);
	//ResourceManager::AddResource("PlaneTexture","grid.tga",TEXTURE);
		
	ResourceManager::AddTexture("SpaceFrigateTexture", "space_frigate.tga");
	ResourceManager::AddTexture("PlaneTexture", "grid.tga");
	//Cottages 
	for(int i = 0; i< 4; i++)
	{
		char *pTextureName = ResourceManager::GetModel("Cottage")->getTextureName(i);
		ResourceManager::AddTexture(pTextureName, pTextureName);
		printf("\tTexture %i: %s\n", i, &pTextureName[0]);
	}
	


	//Model *pModelSphere = GpuModel::Create("BoundingSphere.azul");


	// Texture Loading  --------------------------------

		// Test code on how to create a texture
		//WTexture *pTextureTest = new WTexture(*GpuTexture::Create("space_frigate.tga") );

		// Space Ship texture
		//Texture *pTexSpaceFrigate = GpuTexture::Create("space_frigate.tga");
	//	Texture *pTextPlane = GpuTexture::Create("grid.tga");
		
		
	// Create Graphic Objects: Combinations of a model, a shader and whatever information a shader needs)
	
		// Shaders
	/*	pGObj_SpaceshipWithTexture = new GraphicsObjectFlatTexture( pModelSpaceFrigate, pTexSpaceFrigate );
		pGObj_Axis = new GraphicsObjectColorNoTexture( pModelAxis );
		pGObj_Plane = new GraphicsObjectFlatTexture( pModelPlane, pTextPlane );*/



	// Creating matrices for in-world placement
	//	Matrix world;

	// Axis and Plane
	//	world = Matrix(IDENTITY);
	//	pGObj_Axis->setWorld(world);
	//	world = Matrix(SCALE, 400,400,400);
	//	pGObj_Plane->setWorld(world);

	//// Spaceship
	//	ShipPos.set(0, 20, 0);
	//	world = Matrix( TRANS, ShipPos );
	//	pGObj_SpaceshipWithTexture->setWorld(world);


}