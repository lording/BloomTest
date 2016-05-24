#include "BloomFilter.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>


CBloomFilter::CBloomFilter(int itemsNum, int hasFunsNum)
{
	this->itemNum = itemsNum; // 过滤元素个数，即n
	this->hasFunsNum = hasFunsNum;	// 哈希函数的个数k
	this->bitmap.reset();			// 位图
	this->hasFunsRet = new int[this->hasFunsNum]; // k个哈希函数的返回值
}


CBloomFilter::~CBloomFilter(void)
{
}

// 读取文件中的字符串，按空格区分，然后将他们都存到位数组中
void CBloomFilter::InitialBloomFilter(char* fileName)
{
	FILE* fin = fopen(fileName, "r");
	assert(fin);

	char ch;
	char str[1000] = { '\0' };
	int  iCnt = 0;
	while (fscanf(fin, "%c", &ch) != EOF)
	{
		if (ch != ' ')
		{
			str[iCnt] = ch;
			iCnt++;
		}
		else
		{
			str[iCnt] = '\0';
			this->InsertBloomFilter(str, strlen(str));
			iCnt = 0;
		}
	}

	if (NULL != fin)
	{
		fclose(fin);
		fin = NULL;
	}
}

// 将某个元素插入到位数组中
void CBloomFilter::InsertBloomFilter(char* str, int len)
{
	this->hasFunHandle.GenerateHashValue(str, len, this->hasFunsRet, this->hasFunsNum);
	for (int i = 0; i < this->hasFunsNum; i++)
	{
		int bitMapPos = abs(this->hasFunsRet[i] % MAX_BITMAP_SIZE);
		this->bitmap.set(bitMapPos, 1);
	}
}

// 判断一个元素是否在位数组中
bool CBloomFilter::IsContain(char* str, int len)
{
	this->hasFunHandle.GenerateHashValue(str, len, this->hasFunsRet, this->hasFunsNum);
	for (int i = 0; i < this->hasFunsNum; i++)
	{
		int bitMapPos = abs(this->hasFunsRet[i] % MAX_BITMAP_SIZE);
		if (this->bitmap[bitMapPos] == 0)
		{
			return false;
		}
	}
	return true;
}