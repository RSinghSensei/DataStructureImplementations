#pragma once
#include <string>
#include <list>
#include <iostream>

class HashTable
{
public:
	HashTable() = default;
	~HashTable() = default;
	void insert(const std::string& key, int val);
	void remove(const std::string& key);
	int hash(const std::string& key);
	void print();

	void find(const std::string& key);

private:
	static const int tableSize = 10;
	std::list<std::pair<std::string, int>>hashvalues[tableSize];
};
