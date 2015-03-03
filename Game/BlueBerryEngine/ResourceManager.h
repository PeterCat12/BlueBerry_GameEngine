//-----------------------------------------------------------------
// Resource Manager Object
// C++ Header File ResourceManager.h
//-----------------------------------------------------------------

#ifndef RESOURCEMAN_H
#define RESOURCEMAN_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Subscriber.h"

//-----------------------------------------------------------------
// ResourceManager class
//-----------------------------------------------------------------
class ResourceManager
{
protected:

public:
	//Constructor(s)/Destructor
	~ResourceManager();
	// General Methods


	static void AddResource(std::string _KeyName, const char * const _ResourceName, ResourceType _Tye);
	static void AddModel(std::string _KeyName, const char* const _ResourceName);
	static void AddTexture(std::string _KeyName, const char* const _ResourceName);
	static void LoadAllResources();
	static void RemoveResource(std::string _ResourceName, ResourceType _Type);
	static Model* GetModel(std::string _name);
	static Texture* GetTexture(std::string _name);
	static void Delete();
	static GraphicsObject* GetGraphicsObject(std::string _name);

	static void ClearResources();

private:
	// Helper Methods
	static ResourceManager*	getResourceManager();

	void AddResourceHelper(std::string _KeyName, const char * const _ResourceName, ResourceType _Tye);
	void AddModelHelper(std::string _KeyName, const char * const _ResourceName);
	void AddTextureHelper(std::string _KeyName, const char * const _ResourceName);
	void LoadAllResourcesHelper();
	void RemoveResourceHelper(std::string _ResourceName, ResourceType _Type);
	Model* GetModelHelper(std::string _name);
	Texture* GetTextureHelper(std::string _name);
	GraphicsObject* GetGraphicsObjectHelper(std::string _name);
	void ClearResourcesHelper();

	// Constructor(s)/Destructors
	ResourceManager(){};
	//private singleton members
	static bool				m_bInstanceFlag;
	static ResourceManager*	m_amSingle;
};


#endif