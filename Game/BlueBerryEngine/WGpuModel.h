//-----------------------------------------------------------------
// GpuModel Wrapper Object
// C++ Header File WGPUModel.h
//-----------------------------------------------------------------

#ifndef WGPUMODEL_H
#define WGPUMODEL_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Resource.h"

//-----------------------------------------------------------------
//Wrapper class for Model class
//-----------------------------------------------------------------

class WModel : public IResource
{

protected:
	// Member variables
	Model* m_mModel;
	
public:
	// Constructor(s)/ Destructors
	WModel( Model& _model) : IResource(){ m_mModel = &_model; } //Takes a model as an argument
	virtual ~WModel()
	{

	};

	void setGpuModel(const char * const _modelName)
	{
		m_mModel = GpuModel::Create(_modelName);
	}
	Model* GetModel() { return m_mModel; }

	//Add WModel to Model Manager
	/*void Subscribe(std::string _name) override   { Subscriber::Subscribe(_name, this);
	};*/

	char *getTextureName(int index){return  m_mModel->getTextureName(index) ; };
	Vect *getVectList(void){ return m_mModel->getVectList(); };
	TriangleIndex *getTriangleList(void) { return m_mModel->getTriangleList(); };

private:
	WModel() : IResource() {};

};
//-----------------------------------------------------------------
// Wrapper class for GpuModel
//-----------------------------------------------------------------
class WGpuModel
{
public:
	static Model* Create( const char * const _modelName ) {
		return GpuModel::Create(_modelName);
	}
	static void Unload( void )
	{
		GpuModel::Unload();
	}

private:
	WGpuModel();
};
#endif