/**
 * \file DebugLogBase.cpp
 * TODO: add description of the class/file.
 *
 * \date Created on: Jan 24, 2014
 * \date Last change on: &DATE&
 *
 * \author Created by: julien 
 * \author Last change by: &AUTHOR&
 *
 * \version Commit Id: &REVISION&
 */

#include "DebugLogBase.h"

namespace DebugCPP
{

DebugLogBase::DebugLogBase()
{
	//Do nothing since there's nothing special to do.
}

DebugLogBase::DebugLogBase(size_t iSize)
{
	messages.reserve(iSize);
}

DebugLogBase::DebugLogBase(const DebugLogBase& iDebugLogBase)
{
	if (this != &iDebugLogBase)
	{
		messages.reserve(iDebugLogBase.getMsgBufferSize());
		messages = iDebugLogBase.messages;
	}
}

DebugLogBase& DebugLogBase::operator=(DebugLogBase iDebugLogBase)
{
	std::swap(messages, iDebugLogBase.messages);
	return *this;
}

bool DebugLogBase::operator==(const DebugLogBase& iDebugLogBaseY)
{
	return (this->messages.capacity() == iDebugLogBaseY.messages.capacity()) &&
			(this->messages == iDebugLogBaseY.messages);
}

bool DebugLogBase::operator!=(const DebugLogBase& iDebugLogBaseY)
{
	return !(*this == iDebugLogBaseY);
}

size_t DebugLogBase::getMsgBufferSize(void) const
{
	return messages.capacity();
}

void DebugLogBase::resizeMsgBuffer(size_t iSize)
{
	messages.reserve(iSize);
}

size_t DebugLogBase::getLoggedMsgNb(void) const
{
	return messages.size();
}

void DebugLogBase::pushLogMsg(const string& iMsg)
{
	messages.push_back(iMsg);
}

void DebugLogBase::flushLog(void)
{
	//Do nothing, need to be implemented by derived classes.
}

bool DebugLogBase::isEmpty(void) const
{
	return messages.empty();
}

void DebugLogBase::clear(void)
{
	messages.clear();
}

DebugLogBase::~DebugLogBase()
{
	//Do nothing since there's nothing special to do.
}

} /* namespace DebugCPP */
