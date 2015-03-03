//-----------------------------------------------------------------
// AlarmManager class
// C++ Source File AlarmManager.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include files
//-----------------------------------------------------------------
#include "Alarmable.h"
#include "AlarmManager.h"
#include "TimeManager.h"

  typedef std::multimap<float, AlarmMarker>::iterator iterator;

//-----------------------------------------------------------------
// Constructor(s)/ Destructors
//-----------------------------------------------------------------
AlarmManager::AlarmManager(void)
{
	m_mTimeLine = std::multimap<float, AlarmMarker,compare>();
	m_lObjectsToDeregister = std::list<AlarmMarker*>();
}

AlarmManager::~AlarmManager(void)
{
}

//-----------------------------------------------------------------
// General Methods
//-----------------------------------------------------------------

void AlarmManager::Register(Alarmable* a, ALARM_ID id, float time)
{
	float tmpTime = TimeManager::GetTotalTime() + time;
	AlarmMarker tmp(a,id,tmpTime);
	m_mTimeLine.insert(std::pair<float,AlarmMarker>(tmpTime,tmp) );
}

//Add corresponding Alarm marker to a delete list. 
void AlarmManager::Deregister(Alarmable* a, ALARM_ID id)
{
	std::pair<iterator, iterator> iterpair = m_mTimeLine.equal_range((a)->GetTime(id) );

	iterator it = iterpair.first;
	for (; it != iterpair.second; ++it) {
		if (it->second.GetAlarmID() == id) { 
			//mymap.erase(it); 
			AlarmMarker* ptmp =   &(it->second);
			ptmp;
			m_lObjectsToDeregister.push_front(	&(it->second)  );
			break;
		}
	}
}

//Removes necessary Alarm markers from the multi-map and then checks the top entry for dispatch.
void AlarmManager::UpdateAlarms()
{
	// First check the delete list, remove those marked in list from map.
	if(m_lObjectsToDeregister.size() > 0)
	{
		std::list<AlarmMarker*>::iterator itList = m_lObjectsToDeregister.begin();
		//W(itList).GetTime();
		AlarmMarker* ptemp = *itList;
		ptemp;
		while(itList != m_lObjectsToDeregister.end())
		{
			std::pair<iterator, iterator> iterpair = m_mTimeLine.equal_range((*itList)->GetTime() );

			iterator it = iterpair.first;
			for (; it != iterpair.second; ++it) 
			{
				if ( &(it->second) == (*itList) ) 
				{ 
					m_mTimeLine.erase(it);
					break;
				}
			}
		itList++;
		}
		m_lObjectsToDeregister.clear();
	}

	// Check the top alarm against the current time... 
	if(m_mTimeLine.size() > 0 )
	{
		std::pair<iterator,iterator> ret;
		//Grab an iterator over the first entry
		ret = m_mTimeLine.equal_range(m_mTimeLine.begin()->first);
		//Iterate over entry
		  for (iterator it= ret.first; it != ret.second; ++it)
		  {
			  float totaltime = TimeManager::GetTotalTime();
			  totaltime;
			  float alarmtime = it->first;
			  alarmtime;
			  if(TimeManager::GetTotalTime() >= it->first)
			  {
				  it->second.GetAlarmable()->Dispatch(it->second.GetAlarmID());
			  }
		  }
	}
}

void AlarmManager::CleanUpAlarms()
{
	m_mTimeLine.clear();
}