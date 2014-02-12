/**
 * \file DebugMsgFormatter.h
 * \brief DebugMsgFormatter class declaration.
 * \class DebugCPP::DebugMsgFormatter
 * \brief This class is the formatter for the debug message logs.
 *
 * The DebugMsgFormatter is directly derived from the Formatter class of the
 * Poco library in the logging framework. This class is used by a
 * FormattingChannel, from the same framework, to format debug log messages
 * before to send them to their corresponding output channel.
 *
 * The output format take this form:
 * [Timestamp] from [pId] [thread] [source] at line [line number]: [message]
 *
 * \date Created on: Feb 8, 2014
 * \date Last change on: &DATE&
 *
 * \author Created by: julien 
 * \author Last change by: &AUTHOR&
 *
 * \version Commit Id: &REVISION&
 */

#ifndef DEBUGMSGFORMATTER_H_
#define DEBUGMSGFORMATTER_H_

#include <Poco/Formatter.h>
#include <Poco/Message.h>

using Poco::Formatter;
using Poco::Message;

namespace DebugCPP
{

class DebugMsgFormatter: public Formatter
{
public:
	/**
	 * \brief DebugMsgFormatter default constructor.
	 */
	DebugMsgFormatter();

	/**
	 * \brief DebugMsgFormatter destructor.
	 */
	virtual ~DebugMsgFormatter();

	/**
	 * \brief Format the given message.
	 *
	 * \param msg A reference to the debug log message to format.
	 * \param text A reference to the output string.
	 */
	virtual void format(const Message& msg, std::string& text);
};

} /* namespace DebugCPP */

#endif /* DEBUGMSGFORMATTER_H_ */
