//-----------------------------------------------------------------
// Resource Manager
// C++ Source - ResourceManager.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "ResourceManager.h"

//-----------------------------------------------------------------
// static initializers
//-----------------------------------------------------------------
bool ResourceManager::m_bInstanceFlag;
ResourceManager* ResourceManager::m_amSingle;

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------
ResourceManager* ResourceManager::getResourceManager()
{
	if( !m_bInstanceFlag)
	{
		m_amSingle = new ResourceManager();
		m_bInstanceFlag = true;
		return m_amSingle;
	}
	else
	{
		return m_amSingle;
	}
}

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------
void ResourceManager::AddResource(std::string _KeyName, const char * const _ResourceName, ResourceType _Type) 
{
	ResourceManager::getResourceManager()->AddResourceHelper(_KeyName,_ResourceName,_Type);
}
	
void ResourceManager::AddModel(std::string _KeyName, const char * const _ResourceName)
{
	ResourceManager::getResourceManager()->AddModelHelper(_KeyName, _ResourceName);
}

void ResourceManager::AddTexture(std::string _KeyName, const char * const _ResourceName)
{
	ResourceManager::getResourceManager()->AddTextureHelper(_KeyName, _ResourceName);
}

void ResourceManager::RemoveResource(std::string _ResourceName, ResourceType _Type)
{
	ResourceManager::getResourceManager()->RemoveResourceHelper(_ResourceName, _Type);
}

Model* ResourceManager::GetModel(std::string _ModelName)
{
	return ResourceManager::getResourceManager()->GetModelHelper(_ModelName); 		
}

Texture* ResourceManager::GetTexture(std::string _TextureName)
{
	return  ResourceManager::getResourceManager()->GetTextureHelper(_TextureName) ; 
}

GraphicsObject* ResourceManager::GetGraphicsObject(std::string _GraphicsObjectName)
{
	return  ResourceManager::getResourceManager()->GetGraphicsObjectHelper(_GraphicsObjectName);
}

// Have to implement this...
void ResourceManager::ClearResources()
{
	ResourceManager::getResourceManager()->ClearResourcesHelper();
}

void ResourceManager::LoadAllResources()
{
	ResourceManager::getResourceManager()->LoadAllResourcesHelper();
}

//-----------------------------------------------------------------
// Helper Methods
//-----------------------------------------------------------------


void ResourceManager::AddResourceHelper(std::string _KeyName, const char * const _ResourceName, ResourceType _Type)
{
	Subscriber::Create(_KeyName, _ResourceName, _Type);
}

void ResourceManager::AddModelHelper(std::string _KeyName, const char * const _ResourceName)
{
	Subscriber::Create(_KeyName, _ResourceName, MODEL);
}

void ResourceManager::AddTextureHelper(std::string _KeyName, const char * const _ResourceName)
{
	Subscriber::Create(_KeyName, _ResourceName, TEXTURE);
}

void ResourceManager::RemoveResourceHelper(std::string _ResourceName, ResourceType _Type)
{
	Subscriber::Unsubscribe(_ResourceName, _Type);
}

Model* ResourceManager::GetModelHelper(std::string _ModelName)
{
	return ( ((WModel*) Subscriber::GetResource(_ModelName, MODEL))->GetModel() );
}

Texture* ResourceManager::GetTextureHelper(std::string _TextureName)
{
	return  ( ((WTexture*) Subscriber::GetResource(_TextureName, TEXTURE))->GetTexture() );
}

GraphicsObject* ResourceManager::GetGraphicsObjectHelper(std::string _GraphicsObjectName)
{
	return  (((WGraphicsObject*) Subscriber::GetResource(_GraphicsObjectName, GRAPHICSOBJECT))->GetGraphicsObject());
}

void ResourceManager::ClearResourcesHelper()
{
	Subscriber::ClearAllResources();
}

void ResourceManager::Delete()
{
	if(m_bInstanceFlag)
	{
		delete ResourceManager::getResourceManager();
	}
}

ResourceManager::~ResourceManager()
{
	ResourceManager::ClearResources();
}
