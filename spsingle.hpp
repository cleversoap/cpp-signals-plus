#ifndef __SPSINGLE_HPP__
#define __SPSINGLE_HPP__

#include "sigplus.hpp"

template <typename...T>
class SPSingle : public SigPlus<T...>
{
	public:
		typedef typename SigPlus<T...>::SlotFunc SlotFunc;
		typedef typename SigPlus<T...>::SlotDelegate SlotDelegate;

		SPSingle(bool locked = false)
		: _locked(locked)
		{
		}

		virtual void operator() (T... args)
		{
			if (_slot != nullptr)
				(*_slot)(args...);
		}

		virtual void connect(SlotFunc slotFunc)
		{
			if (!_locked)
				_slot = &slotFunc;
		}

		virtual void remove(SlotFunc slotFunc)
		{
			if (_slot != nullptr)
			{
				if (slotFunc.template target<SlotDelegate*>() ==
					static_cast<SlotFunc>(*_slot).template target<SlotDelegate*>())
				{
					clear();
				}
			}
		}

		virtual void removeAt(int i)
		{
			if (i == 0)
				clear();
		}

		virtual void clear()
		{
			if (_slot != nullptr)
				_slot = nullptr;
			// TODO: See if a delete should be used
		}

	protected:
		bool _locked; 
		SlotFunc* _slot;
};

#endif
