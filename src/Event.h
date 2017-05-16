/*
 * Event.h
 *
 *  Created on: May 15, 2017
 *      Author: bieschke
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <array>
#include <memory>
#include <cstdlib>

/**
 * Class that represents the data for one event.
 * This is basically a wrapper class for a std::array. It contains an array and an integer which holds the number of the event. So for the third
 * triggered event of the detector, the event number will be 2, as counting starts at zero
 *
 * @brief Event class
 *
 * @author Stefan Bieschke
 * @version 0.1
 * @date May 15, 2017
 */
class Event
{
	//TODO TESTING
public:
	Event(const unsigned int eventNumber, std::unique_ptr<std::array<uint16_t,800>> data);
	~Event();

	const std::array<uint16_t,800>& getData();
	const unsigned int getEventNumber();

	//TODO check if offering this is bad design and if getData() should be all that is available
	uint16_t& operator[](const unsigned short bin) const;

private:
	std::unique_ptr<std::array<uint16_t,800>> m_data;
	unsigned int m_event_number;
};

#endif /* EVENT_H_ */
