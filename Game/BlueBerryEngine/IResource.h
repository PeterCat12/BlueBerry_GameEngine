
#ifndef IRESOURCE_H
#define IRESOURCE_H

#include "Resource.h"

class IResource
{
public:
	IResource(){};
	virtual ~IResource(){};
	//virtual void Subscribe(std::string _ResourceName) = 0;
	//virtual void Unsubscribe() = 0;

};

#endif