#include <iostream>
using namespace std;

template<typename T>
struct ListNode
{
	ListNode(const T& x = T())
		:_prev(0)
		,_next(0)
		,_value(0)
	{}

	ListNode<T>* _prev;
	ListNode<T>* _next;
	T value;
};

template<typename T, typename Ref, typename Ptr>
struct __ListIterator__
{
	typedef __ListIterator__ <T, T&, T*> Iterator;
	typedef __ListIterator__ <const T, const T&, const T*> ConstIterator;
	typedef __ListIterator__ <T, Ref, Ptr> Self;
	typedef T ValueType;
	typedef Ref Reference;
	typedef Ptr Pointer;
	typedef ListNode<T>* LinkType;
	typedef size_t Sizetype;

	LinkType _node;

	__ListIterator__(LinkType x){}
	__ListIterator__(){}
	__ListIterator__(const Iterator& x){}
	bool operator==(const Iterator& x){}
	bool operator!=(const Iterator& x){}
	Reference operator*(){}
	Pointer operator->(){}
	Self& operator++(){}
	Self operator++(int){}
	Self& operator--(){}
	Self operator--(int){}

};

template<typename T>
struct List
{
public:
	typedef ListNode<T> Node;
	typedef T ValueType;
	typedef ValueType* Pointer;
	typedef const ValueType* ConstPointer;
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference; 
	typedef Node* LinkType;
	typedef size_t SizeType;
	typedef __ListIterator__<T, T&, T*> Iterator;
	typedef __ListIterator__<const T, const T&, const T*> ConstIterator;
	List(){}
	Iterator Begin(){}
	ConstIterator Begin()const{}
	Iterator End(){}
	ConstIterator End()const{}
	bool Empty()const{}
	SizeType Size()const{}
	Reference Front()const{}
	ConstReference Front()const{}
	Reference Back(){}
	ConstReference Back()const{}
	Iterator Insert(Iterator pos, const T& x){}
	void PushFront(const T& x){}
	void PushBack(const T& x){}
	Iterator Erase(Iterator pos){}
	void PopFront(){}
	void PopBack(){}
	void Clear(){}
	List(const List<T>& l){}
	List& operator=(const List& l){}
	~List(){}

protected:
	LinkType _node;
};

int main()
{

	return 0;
}

