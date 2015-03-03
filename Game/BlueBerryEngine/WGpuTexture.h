//-----------------------------------------------------------------
// GpuTexture Wrapper Object
// C++ Header File WGPUTexture.h
//-----------------------------------------------------------------

#ifndef WGPUTEXTURE_H
#define WGPUTEXTURE_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "Resource.h"

//-----------------------------------------------------------------
//Wrapper class for Texture class
//-----------------------------------------------------------------
struct WTexture : public IResource
{
public:
	WTexture(Texture& _texture): IResource(), m_tTexture(&_texture) {};
	~WTexture()
	{

	};

	// General Methods
	Texture* GetTexture() { return m_tTexture; } ;
	//void Subscribe(std::string _name) override   {	//Subscriber::Subscribe(_name, this); 
	//};

private:
	Texture* m_tTexture;
	WTexture() : IResource(){};
};

//-----------------------------------------------------------------
//Wrapper class for GpuTexture class
//-----------------------------------------------------------------
class WGpuTexture
{
	static Texture* Create( const char * const textNameString ) {return GpuTexture::Create(textNameString); };
	static void Unload( void ) { GpuTexture::Unload(); };
	static Texture* DefaultTexture() { return GpuTexture::DefaultTexture(); };
};
#endif