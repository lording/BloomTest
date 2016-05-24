#include "BloomFilter.h"

int main(int argc, char* argv[])
{
	CBloomFilter bf = CBloomFilter(100, 1);
	bf.InitialBloomFilter("bloomFilter.txt");
	char ch[] = "1234567890";
	bool ret = bf.IsContain(ch, strlen(ch));
	printf("%d \n", ret);

	return 0;
}