

#include "WTextureManager.h"


//-----------------------------------------------------------------
// static initializers
//-----------------------------------------------------------------
bool WTextureManager::m_bInstanceFlag;
WTextureManager* WTextureManager::m_wTextureManager;

//-----------------------------------------------------------------
// Constructor(s)
//-----------------------------------------------------------------
WTextureManager::WTextureManager()
	:ISubManager()
{
}

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------

WTextureManager* WTextureManager::getTextureManager()
{
	if( !m_bInstanceFlag)
		{
			m_wTextureManager = new WTextureManager();
			m_bInstanceFlag = true;
			return m_wTextureManager;
		}
		else
		{
			return m_wTextureManager;
		}
}

void WTextureManager::AddResource(std::string _TextureName, IResource* _Texture)
{

	 std::pair<std::map<std::string, WTexture*>::iterator, bool> ret;
	 ret = WTextureManager::getTextureManager()->m_wTextures.insert(std::pair<std::string, WTexture*>(_TextureName, (WTexture*)_Texture) );
	 assert(ret.second != false);
}

void WTextureManager::RemoveResource(std::string _ResourceName)
{
		 std::map<std::string,WTexture*>::iterator it;
		 it = WTextureManager::getTextureManager()->m_wTextures.find(_ResourceName);
		  // Make sure Texture is in list
		 assert(it !=  WTextureManager::getTextureManager()->m_wTextures.end());
		 WTextureManager::getTextureManager()->m_wTextures.erase(_ResourceName);
}

void WTextureManager::ClearResources()
{
		std::map<std::string,WTexture*>::iterator it = WTextureManager::getTextureManager()->m_wTextures.begin();
		while (it != WTextureManager::getTextureManager()->m_wTextures.end())
		{
			delete(it->second);
			it = WTextureManager::getTextureManager()->m_wTextures.erase(it);
		}
}

WTexture* WTextureManager::GetWTexture(std::string _TextureName)
{
		 std::map<std::string,WTexture*>::iterator it;
		 it = WTextureManager::getTextureManager()->m_wTextures.find(_TextureName);
		 //Make sure the element is returned, otherwise throw an error.
		 assert(it != WTextureManager::getTextureManager()->m_wTextures.end());	
		 return it->second;
}

void WTextureManager::Delete()
{
	if(m_bInstanceFlag)
	{
		WTextureManager::getTextureManager()->ClearResources();
		delete WTextureManager::getTextureManager();
	}
}
