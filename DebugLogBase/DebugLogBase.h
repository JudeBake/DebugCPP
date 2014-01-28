/**
 * \file DebugLogBase.h
 * \class DebugCPP::DebugLogBase
 * \brief This is the base class for all debug log in this library.
 *
 * This class is the base class for all debug log. It encapsulate a string
 * vector as a buffer for messages to log. It give the possibility to change
 * the size of the buffer and to push new message in the log and a virtual
 * method to flush the log through the output.
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
#include <vector>

using std::string;
using std::vector;

namespace DebugCPP
{

class DebugLogBase
{
protected:
	/**
	 * The log messages.
	 */
	vector<string> messages;

public:
	/**
	 * \brief Basic constructor of DebugLogBase.
	 */
	DebugLogBase();

	/**
	 * \brief DebugLogBase constructor with initial message buffer size.
	 *
	 * \param iSize The initial message buffer size.
	 */
	DebugLogBase(size_t iSize);

	/**
	 * \brief DebugLogBase copy constructor.
	 *
	 * \param iDebugLugBase The DebugLog reference from which to initialize.
	 */
	DebugLogBase(const DebugLogBase& iDebugLogBase);

	/**
	 * \brief DebugLogBase assignment operator.
	 *
	 * \param iDebugLogBase The right hand operand DebugLogBase.
	 *
	 * \return The DebugLogBase reference of the left hand operand.
	 */
	DebugLogBase& operator=(DebugLogBase iDebugLogBase);

	/**
	 * \brief Get the message buffer size.
	 *
	 * \return The message buffer size.
	 */
	size_t getMsgBufferSize(void);

	/**
	 * \brief Resize the message buffer.
	 *
	 * \param iSize The new size of the message buffer.
	 */
	void resizeMsgBuffer(size_t iSize);

	/**
	 * \brief Get the number of messages logged.
	 *
	 * \return The number of messages logged.
	 */
	size_t getLoggedMsgNb(void);

	/**
	 * \brief Push a log message to the back.
	 *
	 * \param iMsg A reference of the message to log.
	 */
	void pushLogMsg(const string& iMsg);

	/**
	 * \brief Flush the log to the its output. Must be implemented by the
	 * 		  derived classes.
	 */
	virtual void flushLog();

	/**
	 * \brief Give the indication if the message buffer is empty or not.
	 *
	 * \return 1 if the message buffer is empty, 0 otherwise.
	 */
	bool isEmpty(void);

	/**
	 * \brief Clear the message buffer.
	 */
	void clear(void);

	/**
	 * \brief DebugLogBase destructor.
	 */
	virtual ~DebugLogBase();
};

} /* namespace DebugCPP */

#endif /* DEBUGLOGBASE_H_ */
