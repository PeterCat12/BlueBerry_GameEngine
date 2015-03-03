


#ifndef WMODELMANAGER_H
#define WMODELMANAGER_H

#include "Resource.h"

using namespace std;

class WModelManager : public ISubManager
{
protected:
	// Member Variables
	 std::map<std::string, WModel*>			m_mWModels;
public:
	static WModelManager* getModelManager();
	 void AddResource(std::string _ModelName, IResource* _Resource) override;
	 void RemoveResource(std::string _ModelName) override;
	 void ClearResources()  override;
	 static void Delete();
	 
	 //Accessors
	 WModel* GetWModel(std::string _ModelName);
	 	
private:
	WModelManager();


	static bool m_bInstanceFlag;
	static WModelManager* m_wModelManager;
};
#endif