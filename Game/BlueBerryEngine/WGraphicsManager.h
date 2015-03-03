


#ifndef WGRAPHICS_MANAGER_H
#define WGRAPHICS_MANAGER_H

#include "Resource.h"

class WGraphicsObjectMangager : public ISubManager
{
protected:
	// Member Variables
	std::map<std::string, WGraphicsObject*>			m_wGraphicObjects;
public:
	 static WGraphicsObjectMangager* GetGraphicsManager();
	 static void Delete();
	 void AddResource(std::string _GOName, IResource* _Resource) override;
	 void RemoveResource(std::string _GOName) override;
	 void ClearResources()  override;

	 WGraphicsObject* GetWGraphicsObject(std::string _GOName);
	 	
private:
	WGraphicsObjectMangager();
	static bool m_bInstanceFlag;
	static WGraphicsObjectMangager* m_wGraphicObjectManager;
};
#endif