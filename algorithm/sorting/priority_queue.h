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
		bool less(int i, int j) { return pq[i] < pq[j]; }
		void exch(int i, int j) { T temp = pq[i]; pq[i] = pq[j]; pq[j] = temp; }
		void swim(int k)
		{
			while (k > 1 && less(k / 2, k))
			{
				exch(k / 2, k);
				k = k / 2;
			}
		}

		void sink(int k)
		{
			while (2 * k <= N)
			{
				int j = 2 * k;
				if (j < N && less(j, j + 1))
					++j;
				if (!less(k, j))
					break;
				k = j;
			}
		}
	};

	template<typename T>
	MaxPQ<T>::MaxPQ(int max_size)
	{
		// only [1, max_size] position has elements
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
