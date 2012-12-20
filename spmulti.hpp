/*
 * Copyright (c) 2012 Cleversoap
 * cleversoap.com
 */

#ifndef __SPMULTI_HPP__
#define __SPMULTI_HPP__
	
#include <vector>

#include "sigplus.hpp"

template<typename...T>
class SPMulti : public SigPlus<T...>
{
	public:
		typedef typename SigPlus<T...>::SlotFunc SlotFunc;
		typedef typename SigPlus<T...>::SlotDelegate SlotDelegate;

		SPMulti()
		{
		}

		virtual void operator() (T... args)
		{
			for(auto i = _slots.begin(); i < _slots.end(); ++i)
				(*i)(args...);
		}

		virtual void connect(SlotFunc slotFunc)
		{
			_slots.push_back(slotFunc);
		}

		virtual void remove(SlotFunc slotFunc)
		{
			for(auto i = _slots.begin(); i < _slots.end(); ++i)
			{
				if (slotFunc.template target<SlotDelegate*>() ==
					static_cast<SlotFunc>(*i).template target<SlotDelegate*>())
				{
					_slots.erase(i);
				}
			}
		}

		virtual void removeAt(int i)
		{
		}

		virtual void clear()
		{
			_slots.clear();
		}

	protected:
		std::vector<SlotFunc> _slots;
};

#endif
