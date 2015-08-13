#ifndef _RING_QUEUE_H
#define _RING_QUEUE_H

#include <vector>

template<typename T>
class RingQueue
{
	public:
		RingQueue(int capacity=1024)
		{
			_queue.resize(capcity);
			clear();
		}

		RingQueue(const RingQueue &q)=delete;

		int size()const
		{

		}

		void capacity(size_t size)
		{
			return _queue.size();
		}

		bool empty()const
		{
			return _head==_tail;
		}

		bool full()const
		{
			
		}

		void clear()
		{
			_head=_tail=0;
		}

		T& pop();
		void push(const T &);
	private:
		int next_index(int i)const
		{
			return (i+1)%_queue.size();
		}
	private:
		std::vector<T> _queue;
		size_t _head,_tail;
};

template<typename T>
RingQueue<T>::RingQueue(int size)
{
	resize(1024);
}

template<typename T>
void RingQueue<T>::resize(size_t size)
{
	_head=_tail=0;
	_queue.resize(size);
}

template<typename T>
void RingQueue<T>::size()const
{
	return _queue.size();
}

#endif
