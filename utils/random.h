#ifndef RANDOM_H
#define RANDOM_H

namespace algo
{
	class Random
	{
	public:
		template<typename T>
		static void shuffle(T* array, int size);

	};
}

#endif
