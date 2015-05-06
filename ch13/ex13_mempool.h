#include <iostream>
using namespace std;

class CMemPool
{
private:
	struct _Unit
	{
		struct _Unit *pPrev, *pNext;
	};

	void* m_pMemBlock;

	struct _Unit* m_pAllocatedMemBlock;
	struct _Unit* m_pFreeMemBlock;

	unsigned long m_ulUnitSize;  //一个单元的内存大小
	unsigned long m_ulBlockSize; //整个内存池的内存大小

public:
	CMemPool(unsigned long lUnitNum = 50, unsigned long lUnitSize = 1024);
	~CMemPool();

	void* Alloc(unsigned long ulSize, bool bUseMemPool = true);
	void Free(void* p);
};

CMemPool::CMemPool(unsigned long ulUnitNum, unsigned long ulUnitSize):
	m_pMemBlock(NULL), m_pAllocatedMemBlock(NULL), m_pFreeMemBlock(NULL),
	m_ulBlockSize(ulUnitNum * (ulUnitSize+sizeof(struct _Unit))),
	m_ulUnitSize(ulUnitSize)
{
	m_pMemBlock = malloc(m_ulBlockSize);

	if(NULL != m_pMemBlock)
	{
		for(unsigned long i = 0; i<ulUnitNum; i++)
		{
			struct  _Unit* pCurUnit = (struct _Unit*)((char*)m_pMemBlock + i*(ulUnitSize+sizeof(struct _Unit)) );

			pCurUnit->pPrev = NULL;
			pCurUnit->pNext = m_pFreeMemBlock;

			if(NULL != m_pFreeMemBlock)
			{
				m_pFreeMemBlock->pPrev = pCurUnit;
			}
			m_pFreeMemBlock = pCurUnit;
		}
	}
}

CMemPool::~CMemPool()
{
	free(m_pMemBlock);
}

void* CMemPool::Alloc(unsigned long ulSize, bool bUseMemPool)
{
	if(ulSize > m_ulUnitSize || false == bUseMemPool ||
	NULL == m_pMemBlock || NULL == m_pFreeMemBlock)
	{
		//cout << "System Call" << endl;
		return malloc(ulSize);		
	}

	struct _Unit *pCurUnit = m_pFreeMemBlock;
	m_pFreeMemBlock = pCurUnit->pNext;
	if(NULL != m_pFreeMemBlock)
	{
		m_pFreeMemBlock->pPrev = NULL;
	}

	pCurUnit->pNext = m_pAllocatedMemBlock;

	if(NULL != m_pAllocatedMemBlock)
	{
		m_pAllocatedMemBlock->pPrev = pCurUnit;
	}
	m_pAllocatedMemBlock = pCurUnit;

	//cout << "Memory Pool" << endl;
	//略过管理头
	return (void*)((char*)pCurUnit + sizeof(struct _Unit));
}

void CMemPool::Free(void* p)
{
	//注意p是要释放的内存地址，在test中使用。
	if(m_pMemBlock<p && p<(void*)((char*)m_pMemBlock + m_ulBlockSize))
	{
		//cout << "Memory Pool Free" << endl;
		struct _Unit* pCurUnit = (struct _Unit*)((char*)p - sizeof(struct _Unit));

		m_pAllocatedMemBlock = pCurUnit->pNext;
		if(NULL != m_pAllocatedMemBlock)
		{
			m_pAllocatedMemBlock->pPrev == NULL;
		}

		pCurUnit->pNext = m_pFreeMemBlock;
		if(NULL != m_pFreeMemBlock)
		{
			m_pFreeMemBlock->pPrev = pCurUnit;
		}

		m_pFreeMemBlock = pCurUnit;
	}
	else
	{
		//cout << "System Free" << endl;
		free(p);
	}
}

// int main()
// {
// 	CMemPool Pool1(50, 1024);
// 	auto addr1 = Pool1.Alloc(16, true);
// 	cout << addr1 << endl;

// 	CMemPool Pool2(50, 1024);
// 	auto addr2 = Pool2.Alloc(16, false);
// 	cout << addr2 << endl;

// 	return 0;
// }