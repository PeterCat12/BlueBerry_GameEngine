#include "Terminatable.h"
#include "SceneManager.h"

Terminatable::Terminatable(void)
{
	m_bMarkedForTermination = false;
	PrivSceneManager::GetCurrentScene()->GetDumpster()->Register(this);
	FinalMan = Dumpster::SetUnused;
}


Terminatable::~Terminatable(void)
{

}

void Terminatable::MarkForTermination()
{
	//call scene manager
	PrivSceneManager::GetCurrentScene()->GetTerminationManager()->Register(this);
}

void Terminatable::Terminate()
{
	m_bMarkedForTermination = true;
}

void Terminatable::SetFinalManagerReturnFnc(ReturnToFinalManagerFnc f)
{
	if(f != 0)
		FinalMan = f;
	else
	{
		// Nothing as of now.
	}

}
