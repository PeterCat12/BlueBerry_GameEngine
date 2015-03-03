

#include "Subscriber.h"

// Constructor(s)/ Destructors
Subscriber::Subscriber()
{}
Subscriber::~Subscriber()
{}




void Subscriber::Create(std::string _KeyName, const char * const _ResourceName, ResourceType _Type)
{
	if(_Type == MODEL)
	{
		WModel *pModelTest = new WModel(*WGpuModel::Create(_ResourceName) );
		Subscriber::Subscribe(_KeyName, pModelTest);
	}
	else
	{
		WTexture *pTextureTest = new WTexture(*GpuTexture::Create(_ResourceName) );
		Subscriber::Subscribe(_KeyName,pTextureTest);
	}
}
	


void Subscriber::Subscribe(std::string _KeyName, WModel* _Model)
{
	WModelManager::getModelManager()->AddResource(_KeyName,_Model);
}

void Subscriber::Subscribe(std::string _KeyName, WTexture* _texture)
{
	WTextureManager::getTextureManager()->AddResource(_KeyName, _texture);
}


void Subscriber::Subscribe(std::string _ResourceName, WGraphicsObject* _WGraphicsObject)
{
	WGraphicsObjectMangager::GetGraphicsManager()->AddResource(_ResourceName, _WGraphicsObject);
}	
	
void Subscriber::Unsubscribe(std::string _ResourceName, ResourceType _Type)
{
	if(_Type == MODEL)
	{
		WModelManager::getModelManager()->RemoveResource(_ResourceName);
	}
	else if(_Type == TEXTURE)
	{
		WTextureManager::getTextureManager()->RemoveResource(_ResourceName);
	}
	else if(_Type == GRAPHICSOBJECT)
	{
		WGraphicsObjectMangager::GetGraphicsManager()->RemoveResource(_ResourceName);
	}
}
	
IResource*	Subscriber::GetResource(std::string _ResourceName, ResourceType _Type)
{
	if( _Type == MODEL)
		return WModelManager::getModelManager()->GetWModel(_ResourceName);
	else if( _Type == TEXTURE)
		return WTextureManager::getTextureManager()->GetWTexture(_ResourceName);
	else //if( _Type == GRAPHICSOBJECT)
	{
		return WGraphicsObjectMangager::GetGraphicsManager()->GetWGraphicsObject(_ResourceName);
	}
}


void Subscriber::ClearAllResources()
{
	WModelManager::Delete();
	WTextureManager::Delete();
	WGraphicsObjectMangager::Delete();
}