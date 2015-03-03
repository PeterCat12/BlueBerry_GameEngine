
//-----------------------------------------------------------------
// Updatable class
// C++ Header File Updatable.h
//-----------------------------------------------------------------

#ifndef ALARMABLE_H
#define ALARMABLE_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "AlarmEnums.h"

/// Number of Alarm Events Available to call
const int MAX_ALARM_EVENTS = 5;
//-----------------------------------------------------------------
//Updatable class
//-----------------------------------------------------------------

/// Used to Set/Store Alarm Times
/**
	The Alarmable class is a module allowing derived objects the ability to set an alarm that goes
	off after a certain time (float). The Alarmable has a total of 5 alarms but can be easily modified for more. 
*/
class Alarmable
{
protected:
	/// Array of floats of size MAX_ALARM_EVENTS(5) that represent alarm times for different alarms.
	float m_fTimeTrigger[MAX_ALARM_EVENTS];

public:

	// Constructor(s) / Destructors
	/// Empty Constructor
	Alarmable(void);
	/// Empty Destructor
	~Alarmable(void);

	// General Methods

	/// \brief CallBack for Alarm0
	/// \ingroup ALARMS
	virtual void Alarm0();

	/// \brief CallBack for Alarm1
	/// \ingroup ALARMS
	virtual void Alarm1();

	/// \brief CallBack for Alarm2
	/// \ingroup ALARMS
	virtual void Alarm2();

	/// \brief CallBack for Alarm3
	/// \ingroup ALARMS
	virtual void Alarm3();

	/// \brief CallBack for Alarm4
	/// \ingroup ALARMS
	virtual void Alarm4();

	/// \brief Calls the correct Callback for Alarm with ID of ID
	/// \param id	The ID number of the Alarm function to call. 
	void Dispatch(ALARM_ID id);

	/// \brief Sets the time the Alarm with ID "id" to go off "time" seconds in the future
	/// \param id	The ID number of the alarm t set
	/// \param time The time(current game time + time) the alarm should be set to go off at. 
	void SetTime(ALARM_ID id, float time);

	/// \brief Registers Alarm with ID "id" and Time "time" to the Alarm Manager
	/*
		\param id The ID number of the alarm t set
		\param time The time(current game time + time) the alarm should be set to go off at. 
	*/
	void RegisterAlarmable(ALARM_ID id, float time);

	/// \brief Deregisters the Alarm with id ID from the Alarm Manager
	/// \param id The ID number of the alarm t set
	void DeregisterAlarmable(ALARM_ID id);
	/// \brief returns the time the alarm was set to go off at
	float GetTime(ALARM_ID id);
};
#endif // !ALARMABLE_H

