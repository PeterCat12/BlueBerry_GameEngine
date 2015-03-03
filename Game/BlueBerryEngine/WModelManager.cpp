

#include "WModelManager.h"


//-----------------------------------------------------------------
// static initializers
//-----------------------------------------------------------------
bool WModelManager::m_bInstanceFlag;
WModelManager* WModelManager::m_wModelManager;

//-----------------------------------------------------------------
// Constructor(s)
//-----------------------------------------------------------------
WModelManager::WModelManager()
	:ISubManager()
{
}

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------

WModelManager* WModelManager::getModelManager()
{
	if( !m_bInstanceFlag)
		{
			m_wModelManager = new WModelManager();
			m_bInstanceFlag = true;
			return m_wModelManager;
		}
		else
		{
			return m_wModelManager;
		}
}

void WModelManager::AddResource(std::string _ModelName, IResource* _Model)
{
	 std::pair<std::map<std::string, WModel*>::iterator, bool> ret;
	 ret= WModelManager::getModelManager()->m_mWModels.insert( std::pair<std::string, WModel*>(_ModelName, (WModel*)_Model)  );
	 assert(ret.second != false);
}

void WModelManager::RemoveResource(std::string _ResourceName)
{
		 std::map<std::string,WModel*>::iterator it;
		 it = WModelManager::getModelManager()->m_mWModels.find(_ResourceName);
		  // Make sure model is in list
		 assert(it !=  WModelManager::getModelManager()->m_mWModels.end());
		 WModelManager::getModelManager()->m_mWModels.erase(_ResourceName);
}

void WModelManager::ClearResources()
{
		std::map<std::string,WModel*>::iterator it = WModelManager::getModelManager()->m_mWModels.begin();
		while (it != WModelManager::getModelManager()->m_mWModels.end())
		{
			delete(it->second);
			it = WModelManager::getModelManager()->m_mWModels.erase(it);
		}
}

WModel* WModelManager::GetWModel(std::string _ModelName)
{
		 std::map<std::string,WModel*>::iterator it;
		 it = WModelManager::getModelManager()->m_mWModels.find(_ModelName);
		 //Make sure the element is returned, otherwise throw an error.
		 assert(it != WModelManager::getModelManager()->m_mWModels.end());	
		 return it->second;
}

void WModelManager::Delete()
{
	if(m_bInstanceFlag)
	{
		WModelManager::getModelManager()->ClearResources();
		delete WModelManager::getModelManager();
	}
}
