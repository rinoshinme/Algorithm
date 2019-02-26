#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

namespace algo
{
	template<typename Key, typename Value>
	class SymbolTable
	{
	public:
		virtual int size() = 0;
		virtual void put(const Key& key, const Value& val) = 0;
		virtual bool get(const Key& key, Value& val) = 0;
		// void delete(Key& key);
		// bool contains(Key& key);
		// bool isEmpty();
		
	protected:
		virtual int compare(Key& k1, Key& k2)
		{
			if (k1 < k2)
				return -1;
			else if (k1 > k2)
				return 1;
			else
				return 0;
		}
	};
}

#endif
