#ifndef _RING_QUEUE_H
#define _RING_QUEUE_H

#include <vector>
#include <glob.h>

template<typename T>
class RingQueue
{
	public:
		RingQueue(int capacity=1024)
		{
			_queue.resize(capacity+1);
			clear();
		}

		RingQueue(const RingQueue &q)=delete;

		size_t size()const
		{
			if(_queue.size()==0)
				return 0;
			return (_tail-_head+_queue.size())%_queue.size();
		}

		size_t capacity()const
		{
			return _queue.size()-1;
		}

		bool empty()const
		{
			return _head==_tail;
		}

		bool full()const
		{
			return size()==capacity();
		}

		void clear()
		{
			_head=_tail=0;
		}

		T& front()
		{
			return _queue.at(_head);
		}

		const T& front()const
		{
			return _queue.at(_head);
		}

		bool pop()
		{
			if(empty())
				return false;
			_head=next_index(_head);
			return true;
		}

		bool push(const T &t)
		{
			if(full())
				return false;
			_queue.at(_tail)=t;
			_tail=next_index(_tail);
			return true;
		}
	private:
		int next_index(int i)const
		{
			return (i+1)%_queue.size();
		}
	private:
		std::vector<T> _queue;
		size_t _head,_tail;
};
#endif
