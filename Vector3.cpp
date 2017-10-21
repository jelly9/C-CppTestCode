#include <iostream>
using namespace std;

template<class T>
class Vector
{
public:
	typedef T ValueType;
	typedef ValueType* Pointer;
	typedef const ValueType* ConstPointer;
	typedef ValueType* Iterator;
	typedef const ValueType* ConstIterator;	
	typedef ValueType& Reference;
	typedef const ValueType& ConstReference;
	typedef size_t SizeType;
	
public:
	Vector()
		:_start(0)
		,_end(0)
		,_endOfStorage(0)
	{}

	Vector(SizeType n)
	{
		FillAndInit(n, T());
	}

	Vector(SizeType n, const T& Value)
	{
		FillAndInit(n, Value);
	}
	
	Vector(const Vector<T>& v)
	{
		_start = new T[v.Capacity()];
		_end += _start + v.Size();
		_endOfStorage = _start + v.Capacity();

		for (size_t idx = 0; idx < v.Size(); ++idx)
			_start[idx] = v[idx];
	}

	Vector<T>& operator=(const Vector<T>& v);
	~Vector();


	/////////////////////Capacity//////////////////////
	SizeType Capacity()const;
	SizeType Size()const;
	SizeType MaxSize()const;
	bool Empty()const;

        //////////////Acess/////////////////////
	Reference operator[](size_t index)
	{

	}

	ConstReference operator[](size_t index)const;
	Reference Front()
	{
		return *_start;
	}

	ConstReference Front()const
	{
		return *_start;
	}
	Reference Back()
	{
		return *_end;
	}
	ConstReference Back()const
	{
		return *_end;
	}



	/////////////Iterator//////////////////
	Iterator Begin()
	{
		return _start:
	}
	ConstIterator Begin()const
	{
		return _start;
	}
	Iterator End()
	{
		return _end;
	}
	ConstIterator End()const
	{
		return end;
	}


        //////////////Modify///////////////////
	void PushBack(const T& value);
	void PopBack();

	// 在position位置插入元素data
	Iterator Insert(Iterator position, const T& data);
        
        // 删除position位置的元素
	Iterator Erase(Iterator position);


protected:
	void FillInitalize(SizeType n, const T& Value)
	{
		FillAndInit(n, Value);
	}
	void CheckCapacity();
//private:
	//void FillAndIni(SizeType n, const T& Value)
	//{
	//	_start = new T[n];
	//	for(SizeType idx = 0; idx < n; idx++)
	//	{
	//		ret[idx] = Value;
	//	}
	//}

protected:
	Iterator _start;
	Iterator _end;
	Iterator _endOfStorage;
};