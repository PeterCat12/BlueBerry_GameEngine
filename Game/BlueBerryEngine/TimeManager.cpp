//-----------------------------------------------------------------
// TimeManager class
// C++ Source File TimeManager.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
//Include Files
//-----------------------------------------------------------------
#include "TimeManager.h"
//#include "StopWatch.h"

//-----------------------------------------------------------------
// static initializers
//-----------------------------------------------------------------
bool TimeManager::m_bInstanceFlag;
TimeManager* TimeManager::m_tmSingle;

//-----------------------------------------------------------------
// Constructor(s)/Destructors
//-----------------------------------------------------------------
TimeManager::TimeManager(void)
{
	// Initialize timer
	StopWatch::initStopWatch();

	// Start timer
	m_pTotalWatch.tic();
	m_pStopWatch.tic();
}


TimeManager::~TimeManager(void)
{

}
//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------
float TimeManager::GetFrameTime()
{
	return TimeManager::GetTimeManager()->GetFrameTimeHelper();

}

float TimeManager::GetTotalTime()
{
	return TimeManager::GetTimeManager()->GetToalTimeHelper();
}

TimeManager* TimeManager::GetTimeManager()
{
	if( !m_bInstanceFlag)
	{
		_trace("time Manager not initialized. Returning null reference.\n");
		return 0;
	}
	else
	{
		return m_tmSingle;
	}
}


void TimeManager::InitTimeManager()
{

	if(!m_bInstanceFlag)
	{
		m_tmSingle = new TimeManager();
		m_bInstanceFlag = true;
	}
}

//-----------------------------------------------------------------
// Helper Methods
//-----------------------------------------------------------------

float TimeManager::GetFrameTimeHelper()
{
	return m_pStopWatch.timeInSeconds();
}

float TimeManager::GetToalTimeHelper()
{
	return m_pTotalWatch.timeInSeconds();
}

void TimeManager::TickTock()
{
	TimeManager::GetTimeManager()->TickTockHelper();
	
}

void TimeManager::TickTockHelper()
{
	m_pStopWatch.toc();
	m_pStopWatch.tic();
	m_pTotalWatch.toc();
}

StopWatch* TimeManager::GetTotalWatch()
{
	return TimeManager::GetTimeManager()->GetTotalWatchHelper();
}

StopWatch* TimeManager::GetStopWatch()
{
	return TimeManager::GetTimeManager()->GetStopWatchHelper();
}

StopWatch* TimeManager::GetTotalWatchHelper()
{
	return &m_pTotalWatch;
}

StopWatch* TimeManager::GetStopWatchHelper()
{
	return &m_pStopWatch;
}

void TimeManager::Delete()
{
	if(m_bInstanceFlag)
		delete TimeManager::GetTimeManager();
}
