//-----------------------------------------------------------------
// TimeManager class
// C++ Header File TimeManager.h
//-----------------------------------------------------------------
#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

//-----------------------------------------------------------------
// Include files
//-----------------------------------------------------------------
#include "Trace.h"
#include "StopWatch.h"
//class StopWatch;

//-----------------------------------------------------------------
// TimeManager Class
//-----------------------------------------------------------------
class TimeManager
{
protected:

	StopWatch m_pStopWatch;
	StopWatch m_pTotalWatch;

public:
	// Constructor(s) /Destructors
	~TimeManager(void);
	// General Methods
	static void InitTimeManager(); //StopWatch* _StopWatch, StopWatch* _TotalWatch);
	static void Delete();
	static void TickTock();
	static float GetFrameTime();
	static float GetTotalTime();
	static StopWatch* GetTotalWatch();
	static StopWatch* GetStopWatch();
	//static void Update();

private:
	// Constructor(s)
	//TimeManager(StopWatch* _StopWatch, StopWatch* _TotalWatch);
	TimeManager();

	// Helper Methods
	static TimeManager* GetTimeManager();
	float GetFrameTimeHelper();
	float GetToalTimeHelper();
	void  TickTockHelper();
	StopWatch* GetTotalWatchHelper();
	StopWatch* GetStopWatchHelper();
	//void UpdateHelper();

	//private singleton members
	static bool				m_bInstanceFlag;
	static TimeManager*	m_tmSingle;
};
#endif // !TIMEMANAGER_H


//Time (Displayed for illustration only)
//	printf("TotalTime: %.2f s lastFrame: %.4f s (%.0f FPS)\n",TimeManager::GetTotalTime(), TimeManager::GetFrameTime(), 1/TimeManager::GetStopWatch()->timeInSeconds());

//char buff[50];
//sprintf_s(buff, "TotalTime: %.2f s lastFrame: %.4f s (%.0f FPS)", TimeManager::GetTotalWatch()->timeInSeconds(),TimeManager::GetStopWatch()->timeInSeconds(), 1/TimeManager::GetStopWatch()->timeInSeconds());
//glfwSetWindowTitle( this->window, buff );