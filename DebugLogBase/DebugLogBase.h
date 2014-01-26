/**
 * \file DebugLogBase.h
 * \class DebugCPP::DebugLogBase
 * \brief This is the base class for all debug log in this library.
 *
 * This class is the base class for all debug log. It encapsulate a string
 * queue that contains the messages to log and give access to it.
 *
 * \date Created on: Jan 24, 2014
 * \date Last change on: &DATE&
 *
 * \author Created by: julien 
 * \author Last change by: &AUTHOR&
 *
 * \version Commit Id: &REVISION&
 */

#ifndef DEBUGLOGBASE_H_
#define DEBUGLOGBASE_H_

#include <string>
#include <queue>

using std::string;
using std::deque;

namespace DebugCPP
{

class DebugLogBase
{
private:
	/**
	 * the log messages.
	 */
	deque<string*> messages;

public:
	/**
	 * \brief Basic constructor of DebugLogBase.
	 */
	DebugLogBase();

	/**
	 * \brief DebugLogBase copy constructor.
	 *
	 * \param iDebugLug The DebugLog reference from which to initialize.
	 */
	DebugLogBase(const DebugLogBase& iDebugLog);

	/**
	 * \brief DebugLogBase assignment operator.
	 *
	 * \param iDebugLogBase The right hand operand DebugLogBase.
	 *
	 * \return The DebugLogBase reference of the left hand operand.
	 */
	DebugLogBase& operator=(const DebugLogBase iDebugLogBase);

	/**
	 * \brief Get the number of messages logged.
	 *
	 * \return The number of messages logged.
	 */
	size_t getLoggedMsgNb(void);

	/**
	 * \brief Log a message.
	 *
	 * \param iMsg A reference of the message to log.
	 */
	void pushLogMsg(const string& iMsg);

	/**
	 * \brief Pop the next message.
	 *
	 * \return A read-only reference to the first message in the log.
	 */
	const string& popLogMsg(void);

	/**
	 * \brief DebugLogBase destructor.
	 */
	virtual ~DebugLogBase();
};

} /* namespace DebugCPP */

#endif /* DEBUGLOGBASE_H_ */
