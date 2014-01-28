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

#include "DebugLogBase.h"

using DebugCPP::DebugLogBase;

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
	BOOST_CHECK_EQUAL(testObject2.getLoggedMsgNb(), (size_t)0);
	BOOST_CHECK_EQUAL(testObject2.getMsgBufferSize(), testSize2);
}
