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

#ifdef __TEST__
#include <boost/test/unit_test.hpp>
#include <string>
#include <vector>

#include "DebugCPP.h"
#include "DebugLogBase.h"

using std::string;
using std::vector;

using DebugCPP::DebugLogBase;

/**
 * \brief Empty buffer message number constant.
 */
const size_t emptyBuffer = 0;

/**
 * \brief Constructors test cases.
 *
 * Those test cases assumes that the algorithm that fix the maximal buffer size
 * work fine, since this algorithm is pretty simple and that it cannot be tested.
 */
BOOST_AUTO_TEST_CASE(DebugLogBase_construtors)
{
	/**
	 * \test Basic constructor test case.
	 *
	 * Pass requirements:
	 * 	- The buffer must be empty.
	 * 	- The size of the buffer must be 0.
	 */
	{
		const size_t testSize = 0;
		DebugLogBase testObject;
		BOOST_CHECK_EQUAL(testObject.getLoggedMsgNb(), emptyBuffer);
		BOOST_CHECK_EQUAL(testObject.getMsgBufferSize(), testSize);
		BOOST_CHECK(testObject.isEmpty());
	}

	/**
	 * \test Constructor with initial buffer size test case.
	 *
	 * Pass requirements:
	 * 	- The buffer must be empty.
	 * 	- The size of the buffer must be equal to the desired size if the later
	 * 	  is smaller than the maximal buffer size.
	 * 	- The size of the buffer must be equal to the maximal buffer size if the
	 * 	  desired buffer size is bigger than the maximal buffer size.
	 */
	{
		//test with normal buffer size
		{
			const size_t testSize = 13;
			DebugLogBase testObject(testSize);
			BOOST_CHECK_EQUAL(testObject.getLoggedMsgNb(), emptyBuffer);
			BOOST_CHECK_EQUAL(testObject.getMsgBufferSize(), testSize);
			BOOST_CHECK(testObject.isEmpty());
		}
		//test with size over the max size
		{
			const size_t testSize = 200;
			DebugLogBase testObject(testSize);
			BOOST_CHECK_EQUAL(testObject.getLoggedMsgNb(), emptyBuffer);
			BOOST_CHECK_EQUAL(testObject.getMsgBufferSize(), testObject.getMsgBufferMaxSize());
			BOOST_CHECK(testObject.isEmpty());
		}
	}

	/**
	 * \test Copy constructor test case.
	 *
	 * Pass requirements:
	 * 	- The buffer must contain the same number of messages than the copied
	 * 	  DebugLogBase.
	 * 	- The buffer size must be the same size the the copied DebugLogBase.
	 * 	- Both DebugLogBase must contain the same messages.
	 */
	{
		DebugLogBase refObject(100);
		char testChar;
		for (int i = 0; i < 78; i += 2)
		{
			testChar = (char)(i + 0x32);
			refObject.pushLogMsg(string(&testChar));
		}
		DebugLogBase testObject(refObject);
		BOOST_CHECK_EQUAL(testObject.getLoggedMsgNb(), refObject.getLoggedMsgNb());
		BOOST_CHECK_EQUAL(testObject.getMsgBufferSize(), refObject.getMsgBufferSize());
		BOOST_CHECK_EQUAL((testObject == refObject), true);
	}
}

/**
 * \brief Operator test cases.
 *
 * Equality and non-equality comparison operators are not tested since they are
 * there only to ease the testing.
 */
BOOST_AUTO_TEST_CASE(DebugLogBase_operators)
{
	/**
	 * \test Assignment operator test case.
	 *
	 * Pass requirements:
	 * 	- The left hand operand must have the same number of messages in the
	 * 	  buffer than the right hand operand.
	 * 	- The left hand operand must have the same buffer size than the right
	 * 	  hand operand.
	 * 	- Both operand must contain the same messages.
	 */
	{
		size_t testSize = 67;
		size_t loggedMsgNb = 40;
		DebugLogBase refObject(testSize);
		char testChar;
		for (unsigned int i = 0; i < loggedMsgNb; i++)
		{
			testChar = (char)(i + 0x32);
			refObject.pushLogMsg(string(&testChar));
		}
		DebugLogBase testObject = refObject;
		BOOST_CHECK_EQUAL(testObject.getLoggedMsgNb(), refObject.getLoggedMsgNb());
		BOOST_CHECK_EQUAL(testObject.getMsgBufferSize(), refObject.getMsgBufferSize());
		BOOST_CHECK_EQUAL((testObject == refObject), true);
	}
}

/**
 * \brief Buffer manipulation test cases.
 */
BOOST_AUTO_TEST_CASE(DebugLogBase_buffer_manipulation)
{
	/**
	 * \test Buffer expansion method and size getter methods test case.
	 *
	 * Pass requirements:
	 * 	- The buffer must expand to the new size if it's smaller than the
	 * 	  maximal buffer and bigger than the actual buffer size.
	 * 	- The buffer must expand to the maximal buffer size if the new size is
	 * 	  bigger than the maximal one.
	 * 	- The buffer size must not change if the new buffer size is smaller than
	 * 	  the actual one.
	 */
	{
		const size_t refSize = 2;
		const size_t testSize1 = 10;
		const size_t testSize2 = 54;
		const size_t testSize3 = 36;
		const size_t testSizeNearMax = 99;
		const size_t testSizeOverMax = 200;
		DebugLogBase testObject(refSize);
		BOOST_REQUIRE_EQUAL(testObject.getMsgBufferSize(), refSize);
		testObject.expandMsgBuffer(testSize1);
		BOOST_CHECK_EQUAL(testObject.getMsgBufferSize(), testSize1);
		testObject.expandMsgBuffer(testSize2);
		BOOST_CHECK_EQUAL(testObject.getMsgBufferSize(), testSize2);
		testObject.expandMsgBuffer(testSize3);
		BOOST_CHECK_EQUAL(testObject.getMsgBufferSize(), testSize2);
		testObject.expandMsgBuffer(testSizeNearMax);
		BOOST_CHECK_EQUAL(testObject.getMsgBufferSize(), testSizeNearMax);
		testObject.expandMsgBuffer(testSizeOverMax);
		BOOST_CHECK_EQUAL(testObject.getMsgBufferSize(), testObject.getMsgBufferMaxSize());
	}

	/**
	 * \test Messages number getter method test case.
	 *
	 * Pass requirement:
	 * 	- The method must return the number of messages in the buffer.
	 */
	{
		const size_t testMsgNb1 = 10;
		const size_t testMsgNb2 = DebugCPP::MAX_LOG_BUFFER_SIZE;
		DebugLogBase testObject(DebugCPP::MAX_LOG_BUFFER_SIZE);
		BOOST_REQUIRE_EQUAL(testObject.getMsgBufferSize(), DebugCPP::MAX_LOG_BUFFER_SIZE);
		char testChar;
		for (unsigned int i = 0; i < testMsgNb1; i++)
		{
			testChar = (char)(i + 0x32);
			testObject.pushLogMsg(string(&testChar));
		}
		BOOST_CHECK_EQUAL(testObject.getLoggedMsgNb(), testMsgNb1);
		testObject.clear();
				BOOST_REQUIRE_EQUAL(testObject.getLoggedMsgNb(), emptyBuffer);
		for (unsigned int i = 0; i < testMsgNb2; i++)
		{
			testChar = (char)(i + 0x32);
			testObject.pushLogMsg(string(&testChar));
		}
		BOOST_CHECK_EQUAL(testObject.getLoggedMsgNb(), testMsgNb2);
	}

	/**
	 * \test Message push method test case.
	 *
	 * Pass requirements:
	 * 	- The method must add the pushed message to the message buffer.
	 * 	- The method must indicate success if the message was successfully added
	 * 	  to the buffer, otherwise it indicates a failure (buffer full).
	 */
	{
		const size_t testSize = 10;
		DebugLogBase testObject(testSize);
		char testChar;
		vector<string> testVector(testSize);
		for (unsigned int i = 0; i < testSize; i++)
		{
			testChar = (char)(i + 0x32);
			testVector[i] = string(&testChar);
			BOOST_CHECK_EQUAL(testObject.pushLogMsg(testVector[i]), DebugCPP::PUSH_SUCCEDED);
		}
		BOOST_CHECK(testObject.flushLog() == testVector);
		BOOST_CHECK_EQUAL(testObject.pushLogMsg(string(&testChar)), DebugCPP::PUSH_FAILED);
	}
}
#endif
