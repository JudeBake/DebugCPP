/**
 * \file DebugMsgFormatter_testRunnable.cpp
 * \brief DebugMsgFormatter_testRunable class implementation.
 *
 * This class is used to run DebugMsgFormatter class test cases as a thread.
 * In consequences this file is build only on test mode.
 *
 * \date Created on: Feb 14, 2014
 * \date Last change on: &DATE&
 *
 * \author Created by: julien 
 * \author Last change by: &AUTHOR&
 *
 * \version Commit Id: &REVISION&
 */

#ifdef __TEST

#include <string>
#include <sstream>

#include <boost/test/unit_test.hpp>

#include <Poco/DateTimeFormatter.h>
#include <Poco/Message.h>
#include <Poco/Timezone.h>

#include "DebugMsgFormatter_testRunnable.h"
#include "../../DebugMsgFormatter/DebugMsgFormatter.h"

using std::string;

using Poco::DateTimeFormatter;
using Poco::Message;
using Poco::Timezone;

using DebugCPP::DebugMsgFormatter;

DebugMsgFormatter_testRunnable::DebugMsgFormatter_testRunnable()
{
	// TODO Auto-generated constructor stub

}

DebugMsgFormatter_testRunnable::~DebugMsgFormatter_testRunnable()
{
	// TODO Auto-generated destructor stub
}

void DebugMsgFormatter_testRunnable::run()
{
	//test variables.
	DebugMsgFormatter testedObject;
	string testMsgText("hello world!!!");
	string testMsgSource("testing");
	Message testMsg(testMsgSource, testMsgText, Message::PRIO_DEBUG, __FILE__,
			__LINE__);

	//manually formatting the output string.
	string attendedResult;
	std::ostringstream converter;
	attendedResult += DateTimeFormatter::format(testMsg.getTime(),
			"%d/%m/%Y %H:%M:%S", Timezone::tzd());
	attendedResult += " from ";
	converter << testMsg.getPid();
	attendedResult += converter.str();
	converter.str("");
	attendedResult += " ";
	attendedResult += testMsg.getThread();
	attendedResult += " ";
	attendedResult += testMsg.getSource();
	attendedResult += " at line ";
	converter << testMsg.getSourceLine();
	attendedResult += converter.str();
	attendedResult += ": ";
	attendedResult += testMsg.getText();

	//testing the formatter
	string result;
	testedObject.format(testMsg, result);
	BOOST_CHECK_MESSAGE(result == attendedResult,
			"The formatted Debug message is not in the good format.");
}

#endif /* __TEST */
