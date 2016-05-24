#pragma once
#include <bitset>
#include "HashFuns.h"

const int MAX_BITMAP_SIZE = 100;

class CBloomFilter
{
public:
	CBloomFilter(int itemsNum, int hasFunsNum);
	~CBloomFilter(void);

	void InitialBloomFilter(char* fileName);
	void InsertBloomFilter(char* str, int len);
	bool IsContain(char* str, int len);
private:
	int itemNum;
	int hasFunsNum;
	std::bitset<MAX_BITMAP_SIZE> bitmap;
	CHashFuns hasFunHandle;
	int* hasFunsRet;
};

