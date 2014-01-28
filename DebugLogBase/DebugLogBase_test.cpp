/**
 * \file DebugLogBase_test.cpp
 * \brief DebugLogBase unit test cases.
 *
 * This file is not included in the Debug or Release build.
 *
 * \date Created on: Jan 24, 2014
 * \date Last change on: &DATE&
 *
 * \author Created by: julien 
 * \author Last change by: &AUTHOR&
 *
 * \version Commit Id: &REVISION&
 */

#include <boost/test/unit_test.hpp>
#include <string>

#include "DebugLogBase.h"

using std::string;
using DebugCPP::DebugLogBase;

/**
 * \brief Constructors test cases.
 */
BOOST_AUTO_TEST_CASE(DebugLogBase_construtors)
{
	const size_t emptyBuffer = 0;

	//test the basic constructor
	const size_t testSize1 = 0;
	DebugLogBase testObject1;
	BOOST_CHECK_EQUAL(testObject1.getLoggedMsgNb(), emptyBuffer);
	BOOST_CHECK_EQUAL(testObject1.getMsgBufferSize(), testSize1);
	BOOST_CHECK(testObject1.isEmpty());

	//test the constructor with initial buffer size
	const size_t testSize2 = 13;
	DebugLogBase testObject2(testSize2);
	BOOST_CHECK_EQUAL(testObject2.getLoggedMsgNb(), emptyBuffer);
	BOOST_CHECK_EQUAL(testObject2.getMsgBufferSize(), testSize2);
	BOOST_CHECK(testObject2.isEmpty());

	//test the copy constructor
	DebugLogBase refObject(100);
	char testChar;
	for (int i = 0; i < 78; i += 2)
	{
		testChar = (char)(i + 0x32);
		refObject.pushLogMsg(string(&testChar));
	}
	DebugLogBase testObject3(refObject);
	BOOST_CHECK_EQUAL(testObject3.getLoggedMsgNb(), refObject.getLoggedMsgNb());
	BOOST_CHECK_EQUAL(testObject3.getMsgBufferSize(), refObject.getMsgBufferSize());
	BOOST_CHECK_EQUAL((testObject3 == refObject), true);
}

/**
 * \brief Operator test cases.
 *
 * Equality and non-equality comparison operators are not tested since they are
 * there only to ease the testing.
 */
BOOST_AUTO_TEST_CASE(DebugLogBase_operators)
{
	//test the assignment operator
	size_t testSize = 67;
	size_t loggedMsgNb = 40;
	DebugLogBase refObject(testSize);
	char testChar;
	for (unsigned int i = 0; i < loggedMsgNb; i++)
	{
		testChar = (char)(i + 0x32);
		refObject.pushLogMsg(string(&testChar));
	}
	DebugLogBase testObject1 = refObject;
	BOOST_CHECK_EQUAL(testObject1.getLoggedMsgNb(), refObject.getLoggedMsgNb());
	BOOST_CHECK_EQUAL(testObject1.getMsgBufferSize(), refObject.getMsgBufferSize());
	BOOST_CHECK_EQUAL((testObject1 == refObject), true);
}

/**
 * \brief Buffer size manip tes cases.
 */
BOOST_AUTO_TEST_CASE(DebugLogBase_beffer_size_manip)
{

}
