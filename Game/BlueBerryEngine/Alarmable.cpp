//-----------------------------------------------------------------
// Alarmable Class 
// C++ Source - Alarmable.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Alarmable.h"
#include "SceneManager.h"

//-----------------------------------------------------------------
// Constructor(s) /Destructors
//-----------------------------------------------------------------
Alarmable::Alarmable(void)
{
}

Alarmable::~Alarmable(void)
{
}

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------
void Alarmable::Alarm0()
{
	//printf("ALARM 0, GOING OFF!\n");
	DeregisterAlarmable(ALARM_ID_0);
}

void Alarmable::Alarm1()
{
	DeregisterAlarmable(ALARM_ID_1);
	//printf("Alarm 1 GOING OFF!!!\n");
}

void Alarmable::Alarm2()
{
	DeregisterAlarmable(ALARM_ID_2);
	//printf("Alarm 2 GOING OFF!!!\n");
}

void Alarmable::Alarm3()
{
	DeregisterAlarmable(ALARM_ID_3);
	//printf("Alarm 3 GOING OFF!!!\n");
}

void Alarmable::Alarm4()
{
	DeregisterAlarmable(ALARM_ID_4);
	//printf("Alarm 4 GOING OFF!!!\n");
}

void Alarmable::Dispatch(ALARM_ID id)
{
	switch (id)
	{
	case ALARM_ID_0:
		Alarm0();
		break;
	case ALARM_ID_1:
		Alarm1();
		break;
	case ALARM_ID_2:
		Alarm2();
		break;
	case ALARM_ID_3:
		Alarm3();
		break;
	case ALARM_ID_4:
		Alarm4();
		break;
	default:
		break;
	}
	id;
}

void Alarmable::SetTime(ALARM_ID id, float time)
{
	m_fTimeTrigger[id] = time; 
}

void Alarmable::RegisterAlarmable(ALARM_ID id, float time)
{
	PrivSceneManager::GetCurrentScene()->GetAlarmManager()->Register(this,id,time);
}

void Alarmable::DeregisterAlarmable(ALARM_ID id)
{
	PrivSceneManager::GetCurrentScene()->GetAlarmManager()->Deregister(this,id);
}

float Alarmable::GetTime(ALARM_ID id)
{
	return m_fTimeTrigger[id];
}
