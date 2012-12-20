#ifndef __SIGPLUS_HPP__
#define __SIGPLUS_HPP__

#include <functional>

template<typename...T>
class SigPlus 
{
	public:
		// Type Definitions
		typedef std::function<void(T...)> SlotFunc;
		typedef void (*SlotDelegate) (T...);

		// Deconstructor
		virtual ~SigPlus()
		{
			clear();
		}

		// Signal calling operator
		virtual void operator() (T... args)
		{
		}

		// Slot connection 
		virtual void connect(SlotFunc slotFunc)
		{
		}

		// Removing a slot
		virtual void remove(SlotFunc slotFunc)
		{
		}

		virtual void removeAt(int i)
		{
		}

		// Clear all conencted slots
		virtual void clear()
		{
		}
};

#endif

