/**
 * \file DebugLogBase.cpp
 * \brief DebugLogBase class implementation.
 *
 * \date Created on: Jan 24, 2014
 * \date Last change on: &DATE&
 *
 * \author Created by: julien 
 * \author Last change by: &AUTHOR&
 *
 * \version Commit Id: &REVISION&
 */

#include "DebugCPP.h"
#include "DebugLogBase.h"

namespace DebugCPP
{

DebugLogBase::DebugLogBase()
{
	MAX_BUFFER_SIZE = MAX_LOG_BUFFER_SIZE < messages.max_size() ?
			MAX_LOG_BUFFER_SIZE : messages.max_size();
}

DebugLogBase::DebugLogBase(size_t iSize)
{
	MAX_BUFFER_SIZE = MAX_LOG_BUFFER_SIZE < messages.max_size() ?
			MAX_LOG_BUFFER_SIZE : messages.max_size();

	if (iSize <= MAX_BUFFER_SIZE)
	{
		messages.reserve(iSize);
	}
	else
	{
		messages.reserve(MAX_BUFFER_SIZE);
	}
}

DebugLogBase::DebugLogBase(const DebugLogBase& iDebugLogBase)
{
	MAX_BUFFER_SIZE = MAX_LOG_BUFFER_SIZE < messages.max_size() ?
			MAX_LOG_BUFFER_SIZE : messages.max_size();

	if (this != &iDebugLogBase)
	{
		messages.reserve(iDebugLogBase.getMsgBufferSize());
		messages = iDebugLogBase.messages;
	}
}

DebugLogBase& DebugLogBase::operator=(DebugLogBase& iDebugLogBase)
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

size_t DebugLogBase::getMsgBufferMaxSize(void) const
{
	return MAX_BUFFER_SIZE;
}

size_t DebugLogBase::getMsgBufferSize(void) const
{
	return messages.capacity();
}

void DebugLogBase::expandMsgBuffer(size_t iSize)
{
	if (iSize <= MAX_BUFFER_SIZE)
	{
		messages.reserve(iSize);
	}
	else
	{
		messages.reserve(MAX_BUFFER_SIZE);
	}
}

size_t DebugLogBase::getLoggedMsgNb(void) const
{
	return messages.size();
}

PushStatus DebugLogBase::pushLogMsg(const string& iMsg)
{
	PushStatus result = PUSH_FAILED;

	if (messages.size() < messages.capacity())
	{
		messages.push_back(iMsg);
		result = PUSH_SUCCEDED;
	}

	return result;
}

bool DebugLogBase::isFull(void) const
{
	return messages.size() == messages.capacity();
}

#ifdef __TEST__
vector<string>& DebugLogBase::flushLog(void)
{
	//Here only to ease test.
	return messages;
}
#endif

bool DebugLogBase::isEmpty(void) const
{
	return messages.empty();
}

void DebugLogBase::clear(void)
{
	messages.clear();
}

#ifdef __TEST__
DebugLogBase::~DebugLogBase()
{
	//Do nothing since there's nothing special to do.
}
#endif

} /* namespace DebugCPP */
