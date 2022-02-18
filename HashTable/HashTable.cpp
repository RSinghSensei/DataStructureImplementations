#include "HashTable.h"


int HashTable::hash(const std::string& key)
{
	// Polynomial Rolling Hash Function
	// IDK what i was doing but yeah, let's just keep it simpler

	/*const int p = key.size();
	long long p_pow = 1;
	long long hash_val{};

	for (size_t i = 0; i < key.size(); i++)
	{
		long long tempsum = (((key[i] - 'a') + 1) * p_pow) % tableSize;
		hash_val += tempsum;
		p_pow = (p_pow * p) % tableSize;
	}*/
	int hash_val{};
	for (int i = 0; i < key.size(); i++)
	{
		hash_val = (hash_val + key[i]) % tableSize;
	}
	std::cout << "For Key: " << key << " hash value is: " << hash_val << std::endl;
	return hash_val;


}

void HashTable::insert(const std::string& key, int val)
{

	int hashVal = hash(key);


	for (auto& x : hashvalues[hashVal])
	{
		if (x.first == key)
		{
			std::cout << "String hashing collision found, value added" << std::endl;
			x.second = val;
			return;
		}
	}

	hashvalues[hashVal].push_back(std::pair<std::string, int>(key, val));
}

void HashTable::print()
{

	for (size_t i = 0; i < tableSize; i++)
	{
		std::cout << "Bucket " << i << ": ";
		for (const auto& x : hashvalues[i])
		{
			std::cout << x.first << " -> ";
		}
		std::cout << std::endl;
	}
}

void HashTable::find(const std::string& key)
{
	int hashVal = hash(key);
	for (const auto& x : hashvalues[hashVal])
	{
		if (x.first == key) { std::cout << x.second << std::endl; return; }
	}


}

void HashTable::remove(const std::string& key)
{
	int hashVal = hash(key);

	for (auto x = hashvalues[hashVal].begin(); x != hashvalues[hashVal].end();)
	{
		if (x->first == key) { x = hashvalues[hashVal].erase(x); std::cout << "Key/Value Pair Removed" << std::endl; }
	}

}