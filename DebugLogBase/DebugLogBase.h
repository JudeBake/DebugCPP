/**
 * \file DebugLogBase.h
 * \brief DebugLogBase class declaration.
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

/**
 * \brief The maximal size of a debug log buffer.
 *
 * Used to determine the maximal possible buffer size of a debug log.
 */
static const size_t MAX_LOG_BUFFER_SIZE = 100;

class DebugLogBase
{
protected:
	/**
	 * \brief The log message buffer.
	 */
	vector<string> messages;

	/**
	 * \brief The maximal buffer size of the debug log.
	 */
	size_t MAX_BUFFER_SIZE;

public:
	/**
	 * \brief Basic constructor of DebugLogBase.
	 */
	DebugLogBase();

	/**
	 * \brief DebugLogBase constructor with initial message buffer size.
	 *
	 * If the desired size is bigger than the maximal size (MAX_BUFFER_SIZE),
	 * the buffer size is set to the maximal size
	 *
	 * \param iSize The initial message buffer size.
	 */
	DebugLogBase(size_t iSize);

	/**
	 * \brief DebugLogBase copy constructor.
	 *
	 * \param iDebugLogBase The DebugLog reference from which to initialize.
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
	 * \brief DebugLogBase equality comparison operator.
	 *
	 * This operator is not really useful in a debug log context, but it's used
	 * in the unit test cases.
	 *
	 * \param iDebugLogBaseY The right hand operand DebugLogBase.
	 *
	 * \return True both DebugLogBase message buffer have the same size, same
	 * 		   number of messages in them and that those messages are the same,
	 * 		   False otherwise.
	 */
	bool operator==(const DebugLogBase& iDebugLogBaseY);

	/**
	 * \brief DebugLogBase non-equality comparison operator.
	 *
	 * This operator is not really useful in a debug log context, but it's used
	 * in the unit test cases.
	 *
	 * \param iDebugLogBaseY The right hand operand DebugLogBase.
	 *
	 * \return The opposite than the equality operator.
	 */
	bool operator!=(const DebugLogBase& iDebugLogBaseY);

	/**
	 * \brief Get the maximal possible size of the buffer for the debug log.
	 *
	 * \return The maximal possible size of the debug log.
	 */
	size_t getMsgBufferMaxSize(void) const;

	/**
	 * \brief Get the message buffer size.
	 *
	 * \return The message buffer size.
	 */
	size_t getMsgBufferSize(void) const;

	/**
	 * \brief Expand the message buffer.
	 *
	 * If the desired size is bigger than the maximal size (MAX_BUFFER_SIZE),
	 * the buffer size is set to the maximal size. If the desired size is
	 * smaller than the actual buffer size, nothing is done.
	 *
	 * \param iSize The new size of the message buffer.
	 */
	void expandMsgBuffer(size_t iSize);

	/**
	 * \brief Get the number of messages logged.
	 *
	 * \return The number of messages logged.
	 */
	size_t getLoggedMsgNb(void) const;

	/**
	 * \brief Push a log message to the back.
	 *
	 * \param iMsg A reference of the message to log.
	 *
	 * \return True if the operation was successful, false otherwise meaning the buffer
	 * 		   is full and need to be flush.
	 */
	bool pushLogMsg(const string& iMsg);

	/**
	 * \brief Give the indication if the the message buffer is full.
	 *
	 * \return True if the message buffer is full, false otherwise.
	 */
	bool isFull(void);

	/**
	 * \brief Flush the log to the its output. Must be implemented by the
	 * 		  derived classes.
	 */
	virtual void flushLog();

	/**
	 * \brief Give the indication if the message buffer is empty or not.
	 *
	 * \return True if the message buffer is empty, false otherwise.
	 */
	bool isEmpty(void) const;

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
