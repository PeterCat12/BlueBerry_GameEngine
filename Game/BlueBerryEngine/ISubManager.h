

#ifndef SUB_MANAGER_H
#define SUB_MANAGER_H

#include "Resource.h"
using namespace std;

class ISubManager
{
	// What do I want this class to look like???

public :
	// AddResource
	string _name;

	ISubManager(){};
	virtual void AddResource(string _ResourceName, IResource* _Resource ) = 0;
	virtual void RemoveResource(string _ResourceName) = 0;
	virtual void ClearResources() = 0;




};
#endif