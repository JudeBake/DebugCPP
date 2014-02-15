/**
 * \file DebugMsgFormatter_test.cpp
 * \brief Unit test cases for DebugMsgFormatter class.
 *
 * This file is not included in the Debug and Release build of this library.
 *
 * \date Created on: Feb 8, 2014
 * \date Last change on: &DATE&
 *
 * \author Created by: julien 
 * \author Last change by: &AUTHOR&
 *
 * \version Commit Id: &REVISION&
 */

#ifdef __TEST

#include <Poco/Thread.h>

#include <boost/test/unit_test.hpp>

#include "DebugMsgFormatter_testRunnable.h"

using Poco::Thread;

/**
 * \test Test the format method of DebugMsgFormatter class.
 *
 * pass requirements:
 * 	- the output string must have the following format:
 * 	[Timestamp] from [pId] [thread] [source] at line [line number]: [message]
 */
BOOST_AUTO_TEST_CASE(formatting_debug_msg)
{
	Thread testThread;
	DebugMsgFormatter_testRunnable testRunnable;

	testThread.start(testRunnable);
}

#endif /* __TEST */
