#pragma once
class CHashFuns
{
public:
	CHashFuns(void);
	CHashFuns(int num);
	~CHashFuns(void);

	// 生成retlen个 随机hash值
	int GenerateHashValue(char* str, unsigned int len, int* Ret, int retLen);

	// 生成第hasFunIndex个 hash值
	int GenerateHashValue(char* str, unsigned int len, int hasFunIndex);

	unsigned int RSHash(char* str, unsigned int len);

	unsigned int JSHash(char* str, unsigned int len);

	unsigned int PJWHash(char* str, unsigned int len);

	unsigned int ELFHash(char* str, unsigned int len);

	unsigned int BKDRHash(char* str, unsigned int len);

	unsigned int SDBMHash(char* str, unsigned int len);

	unsigned int DJBHash(char* str, unsigned int len);

	unsigned int DEKHash(char* str, unsigned int len);

	unsigned int BPHash(char* str, unsigned int len);

	unsigned int FNVHash(char* str, unsigned int len);

	unsigned int APHash(char* str, unsigned int len);

private:
	int hasNum;
	unsigned int* hashVal;
};

