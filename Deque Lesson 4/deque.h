/***********************************************************************
* Header:
*    DEQUE
* Summary:
*    This will contain the class definition of:
*        Deque         : A class that represents a deque
* Author
*    Scott Tolman
************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

//#include <cassert>

namespace custom
{

	/*****************************************
	* DEQUE
	* Just like the std :: deque <T> class
	****************************************/
	template <class T>
	class deque
	{
	public:
		deque()
		{
			data = NULL;
			capacity = 0;
			iFront = 0;
			iBack = -1;
		}
		deque(int capacity) : data(NULL), capacity(0), iFront(0), iBack(-1) //book shows throw
		{
			if (capacity > 0)
				resize(capacity);
		}
		deque(deque & rhs) : data(NULL), capacity(0), iFront(0), iBack(-1) //book shows throw
		{
			if (rhs.capacity > 0)
			{
				resize(rhs.capacity);
				*this = rhs;
			}
		}
		~deque() { if (size() != 0) delete[] data; }
		void		push_front(const T & t) throw (const char *);
		void		push_back(const T & t) throw (const char *);
		void		pop_front() throw (const char *); 
		void		pop_back() throw (const char *);
		T & 		front() throw (const char *);
		T 			front() const throw (const char *);
		T &         back() throw (const char *);
		T           back() const throw (const char *);
		deque <T> & operator = (const deque <T> & rhs) throw (const char *);
		int 		size() const { return iBack - iFront + 1; }
		bool 		empty() const { return size() == 0; }
		void 		clear() { iFront = 0; iBack = -1; }
	private:
		void        resize(int newCapacity) throw(const char *);
		int         iFrontNormalized() const 
		{
			int cFront = iFront;
			while (cFront < 0)
				cFront += capacity;
			return cFront % capacity; 
		}
		int         iBackNormalized() const 
		{
			int cBack = iBack;
			while (cBack < 0)
				cBack += capacity;
			return cBack % capacity; 
		}

		T * data;
		int capacity;
		int iFront;
		int iBack;
	};

	template<class T>
	inline void deque<T>::push_front(const T & t) throw(const char *)
	{
		if (capacity == 0)
		{
			resize(1);
		}
		else if (capacity == size())
			resize(capacity * 2);
		iFront--;
		data[iFrontNormalized()] = t;
	}

	template<class T>
	inline void deque<T>::push_back(const T & t) throw(const char *)
	{
		if (capacity == 0)
		{
			resize(1);
		}
		else if (capacity == size())
			resize(capacity * 2);
		iBack++;
		data[iBackNormalized()] = t;
	}

	template<class T>
	inline void deque<T>::pop_front() throw(const char *)
	{
		if (size() > 0)
		{
			iFront++;
		}
	}

	template<class T>
	inline void deque<T>::pop_back() throw(const char *)
	{
		if (size() > 0)
		{
			iBack--;
		}
	}

	template<class T>
	T & deque<T>		  ::front() throw(const char *)
	{
		if (size() < 1)
			throw "ERROR: unable to access data from an empty deque";
		return data[iFrontNormalized()];

	}

	template<class T>
	T deque<T>			  ::front() const throw(const char *)
	{
		if (size() < 1)
			throw "ERROR: unable to access data from an empty deque";
		return data[iFrontNormalized()];
	}

	template<class T>
	T & deque<T>		  ::back() throw(const char *)
	{
		if (size() < 1)
			throw "ERROR: unable to access data from an empty deque";
		return data[iBackNormalized()];
	}

	template<class T>
	T deque<T>			  ::back() const throw(const char *)
	{
		if (size() < 1)
			throw "ERROR: unable to access data from an empty deque";
		return data[iBackNormalized()];
	}

	template<class T>
	deque<T>& deque<T>	  ::operator= (const deque<T>& rhs) throw(const char *)
	{
		iBack = -1;
		iFront = 0;
		if (capacity < rhs.size())
			resize(rhs.size());
		for (int i = 0; i < rhs.size(); i++)
			push_back(rhs.data[(rhs.iFrontNormalized() + i) % rhs.capacity]);
		return *this;
	}

	template<class T>
	void deque<T>::resize(int newCapacity) throw(const char *)
	{
		T * temp;
		try
		{
			temp = new T[newCapacity];
		}
		catch (std::bad_alloc)
		{
			throw "ERROR: Unable to allocate a new buffer for deque";
		}
		for (int i = 0; i < size(); i++)
			temp[i] = data[(iFrontNormalized() + i) % capacity];
		if (data != NULL)
			delete[] data;
		data = temp;
		iBack = size() - 1;
		iFront = 0;
		capacity = newCapacity;
	}
}

#endif //DEQUE_H