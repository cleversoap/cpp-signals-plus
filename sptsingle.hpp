/*
 * Copyright (c) 2012 Cleversoap
 * cleversoap.com
 */

#ifndef __SPTSINGLE_HPP__
#define __SPTSINGLE_HPP__

#include <thread>

#include "spsingle.hpp"

template<typename...T>
class SPTSingle : public SPSingle<T...>
{
	public:
		SPTSingle(bool locked = false)
		: SPSingle<T...>(locked)
		{
		}

		virtual void operator() (T... args)
		{
			if (this->_slot != nullptr)
				std::thread(*this->_slot, args...).detach();
		}
};

#endif
