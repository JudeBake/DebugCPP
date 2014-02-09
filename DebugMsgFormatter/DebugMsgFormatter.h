/**
 * \file DebugMsgFormatter.h
 * \brief DebugMsgFormatter class declaration.
 * \class DebugCPP::DebugMsgFormatter
 * \brief This class is the formatter for the debug message logs.
 *
 * TODO: class description.
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

using Poco::Formatter;

namespace DebugCPP
{

class DebugMsgFormatter: public Formatter
{
public:
	/**
	 *
	 */
	DebugMsgFormatter();
	virtual ~DebugMsgFormatter();
};

} /* namespace DebugCPP */

#endif /* DEBUGMSGFORMATTER_H_ */
