/**
 * \file DebugMsgFormatter_testRunnable.h
 * \brief DebugMsgFormatter_testRunnable class declaration.
 * \class DebugMsgFormatter_testRunnable
 * \brief This class implement the test cases for the DebugMsgFormatter class.
 *
 * Since log Message are made to log in a threading context, the
 * DebugMsgFormatter class test cases are implemented as a thread. There by the
 * necessity of a Runnable derived class. This class is only build on test mode.
 *
 * \date Created on: Feb 14, 2014
 * \date Last change on: &DATE&
 *
 * \author Created by: julien 
 * \author Last change by: &AUTHOR&
 *
 * \version Commit Id: &REVISION&
 */

//TODO: conditional build on __TEST
#ifndef DEBUGMSGFORMATTERTESTRUNNABLE_H_
#define DEBUGMSGFORMATTERTESTRUNNABLE_H_

#include <Poco/Runnable.h>

using Poco::Runnable;

class DebugMsgFormatter_testRunnable: public Runnable
{
public:
	/**
	 * \brief DebugMsgFormatter_testRunnable default constructor.
	 */
	DebugMsgFormatter_testRunnable();

	/**
	 * \brief DebugMsgFormatter_testRunnable destructor.
	 */
	virtual ~DebugMsgFormatter_testRunnable();

	/**
	 * \brief DebugMsgFormatter_testRunnable run method implementation.
	 *
	 * This method implement the DebugMsgFormatter test cases.
	 */
	virtual void run(void);
};

#endif /* DEBUGMSGFORMATTERTESTRUNNABLE_H_ */
