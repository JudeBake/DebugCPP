/**
 * \file DebugCPP.h
 * \brief DebugCPP namespace constant, enum, union, etc.
 *
 * \date Created on: Jan 29, 2014
 * \date Last change on: &DATE&
 *
 * \author Created by: julien 
 * \author Last change by: &AUTHOR&
 *
 * \version Commit Id: &REVISION&
 */

#ifndef DEBUGCPP_H_
#define DEBUGCPP_H_

#include <stddef.h>

/**
 * \namespace DebugCPP
 * \brief Utilities for debugging C++ programs.
 *
 * This module include multiple classes as utilities to give live debugging
 * capabilities.
 */
namespace DebugCPP
{

/**
 * \brief The maximal size of a debug log buffer.
 *
 * Used to determine the maximal possible buffer size of a debug log.
 */
static const size_t MAX_LOG_BUFFER_SIZE = 100;

/**
 * \enum PushStatus
 * \brief Constant indicating if the message pushing was successful or not.
 *
 * Possible values:
 * 	- PUSH_SUCCEDED
 * 	- PUSH_FAILED
 */
typedef enum
{
	PUSH_FAILED,
	PUSH_SUCCEDED
} PushStatus;

}

#endif /* DEBUGCPP_H_ */
