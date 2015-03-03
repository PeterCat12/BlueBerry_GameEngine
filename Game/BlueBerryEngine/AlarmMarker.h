//-----------------------------------------------------------------
// AlarmMarker class
// C++ Header File AlarmMarker.h
//-----------------------------------------------------------------

#ifndef ALARMARKER_H
#define ALARMARKER_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "AlarmEnums.h"

class Alarmable;

/**********************************************************************************************//**
 * \class	AlarmMarker
 * \brief	An alarm marker.
 * 			The alarm marker class is responsible holding an alarm ID and a pointer to the relevant Alarmable
 **************************************************************************************************/
class AlarmMarker
{
protected:
	/** \brief	Identifier for the alarm. */
	ALARM_ID	m_eAlarmID;
	/** \brief	Point to an alarmable. */
	Alarmable*	m_pAlarmable;

public:

	/**********************************************************************************************//**
	 * \fn	AlarmMarker::AlarmMarker(Alarmable* pAlarm, ALARM_ID id, float time);
	 * \brief	Constructor. Allows sets an alarm on pAlarm with Time time.
	 * \param [in,out]	pAlarm	If non-null, the alarm.
	 * \param	id			  	The identifier.
	 * \param	time		  	The time.
	 **************************************************************************************************/

	AlarmMarker(Alarmable* pAlarm, ALARM_ID id, float time);
	/** \brief Destructor. */
	~AlarmMarker(void);

	/**********************************************************************************************//**
	 * \fn	Alarmable* AlarmMarker::GetAlarmable();
	 * \brief	Gets the alarmable.
	 * \return	m_pAlarmable
	 **************************************************************************************************/
	Alarmable* GetAlarmable();

	/**********************************************************************************************//**
	 * \fn	ALARM_ID AlarmMarker::GetAlarmID();
	 * \brief	Gets alarm identifier.
	 * \return	m_eAlarmID.
	 **************************************************************************************************/
	ALARM_ID GetAlarmID();

	/**********************************************************************************************//**
	 * \fn	float AlarmMarker::GetTime();
	 * \brief	Gets the time.
	 * \return	The time of the Alarm[id]; 
	 **************************************************************************************************/
	float GetTime();

private:
	AlarmMarker(void);
};
#endif // !1
