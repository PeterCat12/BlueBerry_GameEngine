//-----------------------------------------------------------------
// AlarmMarker class
// C++ Header File AlarmMarker.h
//-----------------------------------------------------------------

#ifndef ALARMMANAGER_H
#define ALARMMANAGER_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include <map>
#include <list>
#include "AlarmEnums.h"
#include "AlarmMarker.h"

class Alarmable;

/**********************************************************************************************//**
 * \struct	compare
 * \brief	A compare function for map Ordering.
 **************************************************************************************************/
struct compare
{
	bool operator()(const float l, const float r)
	{
		return l < r;
	}
};

/**********************************************************************************************//**
 * \class	AlarmManager
 * \brief	Manager for alarmable objects.
 * \author	Peter
 * \date	2/27/2015
 **************************************************************************************************/
class AlarmManager
{
protected:
	/** \brief	Multimap that can be read as a timeline of Alarms. Key is a float representing a time for an alarm*/
	std::multimap<float, AlarmMarker, compare> m_mTimeLine;
	/** \brief	The objects to deregister for the next update. */
	std::list<AlarmMarker*> m_lObjectsToDeregister;

public:

	/** \brief default constructor*/
	AlarmManager(void);
	/** \brief destructor*/
	~AlarmManager(void);

	/**
	 * \fn	void AlarmManager::Register(Alarmable* a, ALARM_ID id, float time);
	 * \brief	Registers this object.
	 * \param [in,out]	a	If non-null, the Alarmable* to process.
	 * \param	id		 	The identifier.
	 * \param	time	 	The time.
	 */
	void Register(Alarmable* a, ALARM_ID id, float time);

	/**********************************************************************************************//**
	 * \fn	void AlarmManager::Deregister(Alarmable* a, ALARM_ID id);
	 * \brief	Deregisters this object.
	 * \param [in,out]	a	If non-null, the Alarmable* to process.
	 * \param	id		 	The identifier.
	 **************************************************************************************************/

	void Deregister(Alarmable* a, ALARM_ID id);

	/**********************************************************************************************//**
	 * \fn	void AlarmManager::UpdateAlarms();
	 * \brief	If the total Game time is < or = to the first Alarm time, the alarm is dispatched 
	 **************************************************************************************************/
	void UpdateAlarms();

	/**********************************************************************************************//**
	 * \fn	void AlarmManager::CleanUpAlarms();
	 * \brief	Clean up alarms.
	 **************************************************************************************************/
	void CleanUpAlarms();
};

#endif // !ALARMMANAGER_H

