/*
 * RtRelation.cpp
 *
 *  Created on: Jun 12, 2017
 *      Author: bieschke
 */

#include "RtRelation.h"

using namespace std;

//TODO Change all doc to vector and variable length (Nov. 14, 2018)

/**
 * Constructor. Initializes a RtRelation object.
 *
 * @brief ctor
 *
 * @author Stefan Bieschke
 * @version Alpha 2.0
 * @date June 26, 2017
 *
 * @param data unique_ptr to an std::array<double,800> containing the rt-relation raw data.
 */
RtRelation::RtRelation(unique_ptr<vector<double>> data) : Data(move(data))
{
}


/**
 * Copy constructor. Initializes a copy of a passed RtRelation object.
 *
 * @brief copy ctor
 *
 * @author Stefan Bieschke
 * @version Alpha 2.0
 * @date June 26, 2017
 *
 * @param original
 */
RtRelation::RtRelation(const RtRelation& original) : Data(original)
{
}

/**
 * dtor. Doing nothing special.
 *
 * @brief dtor
 */
RtRelation::~RtRelation()
{
}

/**
 * Assignment operator for RtRelations.
 *
 * @brief Assignment operator
 *
 * @author Stefan Bieschke
 * @date July 19, 2017
 * @version Alpha 2.0
 *
 * @param rhs RtRelation on the right hand side of the assignment
 * @return Reference to the RtRelation object to be stored to the left hand side of the assignment
 */
RtRelation& RtRelation::operator=(const RtRelation& rhs)
{
	Data::operator=(rhs);

	return *this;
}
