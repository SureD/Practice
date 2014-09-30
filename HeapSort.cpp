// HeapSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<assert.h>
#include <stdio.h>
#include<math.h>

class Heap
{
public:
	// construction & dec
	Heap(){};
	~Heap(){};
	//method
	bool init(int *pArray,int arraySize){
		assert(pArray);
		m_pArray = pArray;
		m_iArraySize = arraySize;
		return true;

	};
	// get index with shift  heapsize = arraysize+1
	const int parent(int iHeap_index) {return iHeap_index/2-1;};
	const int left(int iHeap_index) {return 2*iHeap_index-1;};
	const int right(int iHeap_index) {return 2*iHeap_index;};
	// MAX-HEAPIFY(A,i)
	void maxHeapify(int iHeap_index){
		int largestIndex; 
		int iArray_index = iHeap_index-1;
		int leftArrayIndex = left(iHeap_index);
		int rightArrayIndex = right(iHeap_index);
		if (leftArrayIndex<m_iArraySize&&m_pArray[leftArrayIndex]>m_pArray[iArray_index])
		{
			largestIndex = leftArrayIndex;
		}else 
			largestIndex = iArray_index;
		if (rightArrayIndex<m_iArraySize&&m_pArray[rightArrayIndex]>m_pArray[largestIndex])
		{
			largestIndex = rightArrayIndex;
		}
		if (largestIndex!=iArray_index)
		{
			int temp = m_pArray[iArray_index];
			m_pArray[iArray_index] = m_pArray[largestIndex];
			m_pArray[largestIndex] = temp;
			maxHeapify(largestIndex+1);

		}


	};
	// BUILD MAX HEAP 
	void buildMaxHeap(){
	int istartNode = m_iArraySize/2;
	for (int i = istartNode; i>0 ; i--)
	{
		maxHeapify(i);
	}
	};
	// sort the heap
	void heapSort(){
		int itempSiez = m_iArraySize;
		buildMaxHeap();
		for (int i = m_iArraySize; i > 1; i--)
		{
			int temp = m_pArray[i-1];
			m_pArray[i-1] = m_pArray[0];
			m_pArray[0] = temp;
			--m_iArraySize;
			maxHeapify(1);


		}
		m_iArraySize=itempSiez;
	};
	// print
	void printarray(){
		for (int i = 0; i < m_iArraySize; i++)
		{
			printf("%d\n",m_pArray[i]);

		}
	};


private:
	int* m_pArray;
	int m_iArraySize; 
};


int _tmain(int argc, _TCHAR* argv[])
{
	//int a[]={16,4,10,14,7,9,3,2,8,1};
	int a[]={4,1,3,2,16,9,10,14,8,7,7};
	Heap heapp;
	if(heapp.init(a,11))
	{
		//heapp.maxHeapify(2);
		//heapp.buildMaxHeap();
		heapp.heapSort();
		heapp.printarray();
	}

	return 0;
}