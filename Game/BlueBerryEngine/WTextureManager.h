


#ifndef WTEXTUREMANAGER_H
#define WTEXTUREMANAGER_H

#include "Resource.h"

class WTextureManager : public ISubManager
{
protected:

	// Member Variables
	std::map<std::string, WTexture*>			m_wTextures;
public:
	 static WTextureManager* getTextureManager();
	 static void	Delete();
	 void AddResource(std::string _TextureName, IResource* _Resource) override;
	 void RemoveResource(std::string _TextureName) override;
	 void ClearResources()  override;

	 WTexture* GetWTexture(std::string _TextureName);
	 	
private:
	WTextureManager();
	static bool m_bInstanceFlag;
	static WTextureManager* m_wTextureManager;
};
#endif