#ifndef __SPTMULTI_HPP__
#define __SPTMULTI_HPP__

#include <thread>

#include "spmulti.hpp"

template<typename...T>
class SPTMulti : public SPMulti<T...>
{
	public:
		SPTMulti()
		{
		}
		
		virtual void operator() (T... args)
		{
			for (auto i = this->_slots.begin(); i < this->_slots.end(); ++i)
				std::thread(*i, args...).detach();
		}
};

#endif

