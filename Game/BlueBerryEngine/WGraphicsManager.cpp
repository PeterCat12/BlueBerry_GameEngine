

#include "WGraphicsManager.h"


//-----------------------------------------------------------------
// static initializers
//-----------------------------------------------------------------
bool WGraphicsObjectMangager::m_bInstanceFlag;
WGraphicsObjectMangager* WGraphicsObjectMangager::m_wGraphicObjectManager;


//-----------------------------------------------------------------
// Constructor(s)
//-----------------------------------------------------------------
WGraphicsObjectMangager::WGraphicsObjectMangager()
	:ISubManager()
{
}



//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------

WGraphicsObjectMangager* WGraphicsObjectMangager::GetGraphicsManager()
{
	if( !m_bInstanceFlag)
		{
			m_wGraphicObjectManager = new WGraphicsObjectMangager();
			m_bInstanceFlag = true;
			return m_wGraphicObjectManager;
		}
		else
		{
			return m_wGraphicObjectManager;
		}
}

void WGraphicsObjectMangager::AddResource(std::string _GOName, IResource* _GraphicsObject)
{

	std::pair< std::map<std::string, WGraphicsObject*>::iterator , bool > ret;
	ret = WGraphicsObjectMangager::GetGraphicsManager()->m_wGraphicObjects.insert(std::pair<string,WGraphicsObject*>(_GOName, ((WGraphicsObject*) _GraphicsObject) ) );
	assert(ret.second != false);
}

void WGraphicsObjectMangager::RemoveResource(std::string _ResourceName)
{
		 std::map<std::string,WGraphicsObject*>::iterator it;
		 it = WGraphicsObjectMangager::GetGraphicsManager()->m_wGraphicObjects.find(_ResourceName);
		  // Make sure model is in list
		 assert(it !=  WGraphicsObjectMangager::GetGraphicsManager()->m_wGraphicObjects.end());
		 WGraphicsObjectMangager::GetGraphicsManager()->m_wGraphicObjects.erase(_ResourceName);
}

void WGraphicsObjectMangager::ClearResources()
{
		std::map<std::string,WGraphicsObject*>::iterator it = WGraphicsObjectMangager::GetGraphicsManager()->m_wGraphicObjects.begin();
		while (it != WGraphicsObjectMangager::GetGraphicsManager()->m_wGraphicObjects.end())
		{
			delete(it->second);
			it = WGraphicsObjectMangager::GetGraphicsManager()->m_wGraphicObjects.erase(it);
		}
}

WGraphicsObject* WGraphicsObjectMangager::GetWGraphicsObject(std::string _TextureName)
{
		 std::map<std::string,WGraphicsObject*>::iterator it;
		 it = WGraphicsObjectMangager::GetGraphicsManager()->m_wGraphicObjects.find(_TextureName);
		 //Make sure the element is returned, otherwise throw an error.
		 assert(it != WGraphicsObjectMangager::GetGraphicsManager()->m_wGraphicObjects.end());	
		 return it->second;
}

void WGraphicsObjectMangager::Delete()
{
	if(m_bInstanceFlag)
	{
		WGraphicsObjectMangager::GetGraphicsManager()->ClearResources();
		delete WGraphicsObjectMangager::GetGraphicsManager();
	}
}
