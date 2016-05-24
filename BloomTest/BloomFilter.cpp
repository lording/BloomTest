#include "BloomFilter.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>


CBloomFilter::CBloomFilter(int itemsNum, int hasFunsNum)
{
	this->itemNum = itemsNum; // ����Ԫ�ظ�������n
	this->hasFunsNum = hasFunsNum;	// ��ϣ�����ĸ���k
	this->bitmap.reset();			// λͼ
	this->hasFunsRet = new int[this->hasFunsNum]; // k����ϣ�����ķ���ֵ
}


CBloomFilter::~CBloomFilter(void)
{
}

// ��ȡ�ļ��е��ַ��������ո����֣�Ȼ�����Ƕ��浽λ������
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

// ��ĳ��Ԫ�ز��뵽λ������
void CBloomFilter::InsertBloomFilter(char* str, int len)
{
	this->hasFunHandle.GenerateHashValue(str, len, this->hasFunsRet, this->hasFunsNum);
	for (int i = 0; i < this->hasFunsNum; i++)
	{
		int bitMapPos = abs(this->hasFunsRet[i] % MAX_BITMAP_SIZE);
		this->bitmap.set(bitMapPos, 1);
	}
}

// �ж�һ��Ԫ���Ƿ���λ������
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