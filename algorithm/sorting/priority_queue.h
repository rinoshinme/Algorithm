#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

namespace algo
{
	template<typename T>
	class MaxPQ
	{
	private:
		T* pq;
		int max_size;
		int N;
	public:
		MaxPQ(int max_size);

		void insert(const T& v);
		T max() { return pq[1]; }
		T delMax();
		bool isEmpty() { return N == 0; }
		int size() { return N; }

	private:
		bool less(int i, int j);
		void exch(int i, int j);
		void swim(int k);
		void sink(int k);
	};

	template<typename T>
	MaxPQ<T>::MaxPQ(int max_size)
	{
		pq = new T[max_size + 1];
		this->max_size = max_size;
		N = 0;
	}

	template<typename T>
	void MaxPQ<T>::insert(const T& v)
	{
		if (N >= max_size)
			return; // do nothing
		pq[++N] = v;
		swim(N);
	}

	template<typename T>
	T MaxPQ<T>::delMax()
	{
		T max_value = pq[1];
		exch(1, N--);
		sink(1);
		return max_value;
	}

}

#endif
