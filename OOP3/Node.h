#pragma once
template<typename T>
class CNode
{
private:
	T data;
	CNode *pnext;
public:
	CNode* pNext();
	T getData();
	T& getaddressData();
	CNode(T aData, CNode *aNext);
	void setNext(CNode *aNext);
	void setData(T value);
};

template<typename T>
CNode<T>* CNode<T>::pNext()
{
	return pnext;
}

template<typename T>
T CNode<T>::getData()
{
	return data;
}

template<typename T>
T & CNode<T>::getaddressData()
{
	return data;
}

template<typename T>
CNode<T>::CNode(T aData, CNode * aNext)
{
	data = aData;
	pnext = aNext;
}

template<typename T>
void CNode<T>::setNext(CNode * aNext)
{
	pnext = aNext;
}

template<typename T>
void CNode<T>::setData(T value)
{
	data = value;
}
