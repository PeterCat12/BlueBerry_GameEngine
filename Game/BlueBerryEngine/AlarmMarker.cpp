//-----------------------------------------------------------------
// AlarmMarker Class 
// C++ Source - AlarmMarker.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "AlarmMarker.h"
#include "Alarmable.h"

//-----------------------------------------------------------------
// Constructor(s) / Destructors
//-----------------------------------------------------------------
AlarmMarker::AlarmMarker(Alarmable* pAlarm, ALARM_ID id, float time)
{
	m_pAlarmable = pAlarm;
	m_eAlarmID =  id;
	m_pAlarmable->SetTime(id,time);
}

AlarmMarker::~AlarmMarker(void)
{
}

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------

Alarmable* AlarmMarker::GetAlarmable()
{
	return m_pAlarmable;
}

ALARM_ID AlarmMarker::GetAlarmID()
{
	return m_eAlarmID;
}

float AlarmMarker::GetTime()
{
	return m_pAlarmable->GetTime(m_eAlarmID);
}