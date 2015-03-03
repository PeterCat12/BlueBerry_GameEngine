

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "Resource.h"

class IResource;
class WModel;
class Model;
struct WTexture;
class WGpuModel;
class WGraphicsObject;
class WGpuTexture;
class WModelManager;

class Subscriber
{
public:
	// Destructor
	~Subscriber();

	// General Methods
	//static void		Subscribe(std::string ResourceName, WModel* _model) ;
	static void     Create(std::string _KeyName, const char * const _ResourceName, ResourceType _Type); 

	static void		Subscribe(std::string _KeyName, WModel* _Model);
	static void		Subscribe(std::string _KeyName, WTexture* _texture);
	static void		Subscribe(std::string _KeyName, WGraphicsObject* _WGraphicsObject);
	
	static void		Unsubscribe(std::string _ResourceName, ResourceType _Type);
	
	static IResource*	GetResource(std::string _ResourceName, ResourceType _Type);

	static void		ClearAllResources();

private:
	// Constructor(s)
	Subscriber();

};
#endif