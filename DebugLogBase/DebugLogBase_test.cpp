/**
 * \file DebugLogBase_test.cpp
 * \brief DebugLogBase unit test cases.
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
BOOST_AUTO_TEST_CASE(construtors_test_cases)
{
	const size_t emptyBuffer = 0;

	const size_t testSize1 = 0;
	DebugLogBase testObject1;
	BOOST_CHECK_EQUAL(testObject1.getLoggedMsgNb(), emptyBuffer);
	BOOST_CHECK_EQUAL(testObject1.getMsgBufferSize(), testSize1);
	BOOST_CHECK(testObject1.isEmpty());

	const size_t testSize2 = 13;
	DebugLogBase testObject2(testSize2);
	BOOST_CHECK_EQUAL(testObject2.getLoggedMsgNb(), emptyBuffer);
	BOOST_CHECK_EQUAL(testObject2.getMsgBufferSize(), testSize2);
	BOOST_CHECK(testObject2.isEmpty());

	DebugLogBase constObject(100);
	char testChar;
	for (int i = 0; i < 78; i += 2)
	{
		testChar = (char)(i + 0x32);
		constObject.pushLogMsg(string(&testChar));
	}
	DebugLogBase testObject3(constObject);
	BOOST_CHECK_EQUAL(testObject3.getLoggedMsgNb(), constObject.getLoggedMsgNb());
	BOOST_CHECK_EQUAL(testObject3.getMsgBufferSize(), constObject.getMsgBufferSize());
	BOOST_CHECK_EQUAL((testObject3 == constObject), true);
}
