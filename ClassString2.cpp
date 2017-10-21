#if 1

#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
	String(const char *str = "")
		:_pStr(new char[strlen(str)+5])
	{
		*(int*)_pStr = 1;
		_pStr += 4;
		cout<<*(int*)(_pStr-4)<<endl;
		strcpy(_pStr, str);
	}

	String(const String& s)
		:_pStr(s._pStr)
	{
		++GetCount();
		cout<<*((int*)(_pStr-4))<<endl;

	}

	String& operator=(const String& s)
	{
		if(this != &s)
		{
			//Release();
			_pStr = s._pStr;
			++GetCount();
		}
		return *this;
	}

	~String()
	{
		if(NULL != _pStr)
		{
			Release();
		}
	}

private:
	int& GetCount()
	{
		return *(int*)(_pStr-4);
	}

	void Release()
	{
		if(--GetCount() == 0)
		{
			delete[] (_pStr-4);
		}
	}


private:
	char *_pStr;
};

int main()
{
	String s1;
	String s2("Hello world");
	String s3(s2);
	String s4;
	String s5;
	String s6;
	s4=s3;
	s5=s3;
	s6=s3;

	

	return 0;
}

#endif