/**
 * \file DebugMsgFormatter.cpp
 * \brief DebugMsgFormatter class implementation.
 *
 * \date Created on: Feb 8, 2014
 * \date Last change on: &DATE&
 *
 * \author Created by: julien 
 * \author Last change by: &AUTHOR&
 *
 * \version Commit Id: &REVISION&
 */

#include <vector>

#include <Poco/DateTimeFormatter.h>
#include <Poco/NumberFormatter.h>
#include <Poco/String.h>
#include <Poco/Timezone.h>

#include "DebugMsgFormatter.h"

using Poco::DateTimeFormatter;
using Poco::NumberFormatter;
using Poco::Timezone;

namespace DebugCPP
{

DebugMsgFormatter::DebugMsgFormatter()
{
	//nothing special to do.
}

DebugMsgFormatter::~DebugMsgFormatter()
{
	//nothing special to do.
}

void DebugMsgFormatter::format(const Message& msg, std::string& text)
{
	std::vector<std::string> vectorizedOutput;

	//format the time stamp of the message.
	vectorizedOutput.push_back(DateTimeFormatter::format(msg.getTime(),
			"%d/%m/%Y %H:%M:%S", Timezone::tzd()));

	//format the message meta data.
	vectorizedOutput.push_back(std::string("from"));
	vectorizedOutput.push_back(std::string("["));
	vectorizedOutput.push_back(NumberFormatter::format(msg.getPid()));
	vectorizedOutput.push_back(std::string("]"));
	vectorizedOutput.push_back(msg.getThread());
	vectorizedOutput.push_back(msg.getSource());
	vectorizedOutput.push_back(std::string("at line"));
	vectorizedOutput.push_back(NumberFormatter::format(msg.getSourceLine()));
	vectorizedOutput.push_back(std::string(":"));

	//add the message text.
	vectorizedOutput.push_back(msg.getText());

	//construct the output string
	text = Poco::cat(std::string(" "), vectorizedOutput.begin(),
			vectorizedOutput.end());
}

} /* namespace DebugCPP */
