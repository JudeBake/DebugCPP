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

#include <sstream>

#include <Poco/DateTimeFormatter.h>
#include <Poco/Timezone.h>

#include "DebugMsgFormatter.h"

using Poco::DateTimeFormatter;
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
	std::ostringstream converter;

	//format the time stamp of the message.
	text = DateTimeFormatter::format(msg.getTime(), "%d/%m/%Y %H:%M:%S",
									 Timezone::tzd());

	//format the message meta data.
	text += " from ";
	text +="[";
	converter << msg.getPid();
	text += converter.str();
	text += "] ";
	text += msg.getThread();
	text += " ";
	text += msg.getSource();
	text += " at line ";
	converter.str("");
	converter << msg.getSourceLine();
	text += converter.str();
	text += ": ";

	//add the message text.
	text += msg.getText();
}

} /* namespace DebugCPP */
