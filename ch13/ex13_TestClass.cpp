#include "mempool.h"
#include <time.h> 
CMemPool g_MemPool;

class CTestClass
{
public:
	void *operator new(size_t);	
	void  operator delete(void *p);
	
private:
	char m_chBuf[1000];
};

void *CTestClass::operator new(size_t uiSize)
{
	return g_MemPool.Alloc(uiSize);
}


void  CTestClass::operator delete(void *p)
{
	g_MemPool.Free(p);
}

class CTestClass2
{
private:
	char m_chBuf[1000];
};

timespec diff(timespec start, timespec end)
{
    timespec temp;
    temp.tv_sec = end.tv_sec-start.tv_sec;
    temp.tv_nsec = end.tv_nsec-start.tv_nsec;
    return temp;
}

#define LOOP_TIMES 100000*iTestCnt	
int main()
{
    timespec time1, time2;

	for(int iTestCnt=1; iTestCnt<=10; iTestCnt++)
	{
	
		unsigned int i;

		//使用内存池测试
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
		for(i=0; i<LOOP_TIMES; i++)
		{
			
			CTestClass *p = new CTestClass;	    //Using memory pool
			delete p;
		}
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
		
		cout << "[ Repeat " << LOOP_TIMES << " Times ]" << "Memory Pool Interval = " << diff(time1,time2).tv_nsec << "ns" << endl;
		
		//使用系统调用测试
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
		for(i=0; i<LOOP_TIMES; i++)
		{
			CTestClass2 *p = new CTestClass2;	//No memory pool
			delete p;
		}
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
		cout << "[ Repeat " << LOOP_TIMES << " Times ]" << "System Call Interval = " << diff(time1,time2).tv_nsec << "ns" << endl;
	}
	
	return 0;
}
