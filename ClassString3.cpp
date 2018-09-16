#pragma

#include <iostream>
#include <string.h>
using namespace std;
#pragma once

//简洁版string类（一行可以写完的代码为什么要写两行 =_=!)
class String
{
public:
	String():_str(new char[1]){*_str = '\0';}
	String(const char* s):_str(new char[strlen(s)+1]){strcpy(_str, s);}
	String(const String& s):_str(new char[strlen(s.str)+1]){strcpy(_str, s.str);}
	~String(){delete[] _str;}
	String& operator=(String s){std::swap(_str,s.str);return *this;}
	size_t Size()const{return strlen(_str);}
	size_t Lengh()const{return strlen(_str);}
	bool operator>(const String& s){return((strcmp(_str,s._str)==1)?1:0);}
	bool operator<(const String& s){return((strcmp(_str,s._str)==-1)?1:0);}
	bool operator>=(const String& s){return((strcmp(_str,s._str)!=(-1))?1:0);}
	bool operator<=(const String& s){return((strcmp(_str,s._str)!=(1))?1:0);}
	bool operator==(const String& s){return((strcmp(_str,s._str)==0)?1:0);}
	bool operator!=(const String& s){return!(*this==s);}
	char operator[](size_t i){return *((*this)._str+i);}
	char* str(){return _str;}
private:
	char* _str;
};

void f1(String x){}
void f2(const String& x){}
String f3(){String s("hello");return s;}

int main()
{
	String s1("bbbb");
	String s2("aaaa");

	cout<<(s1>s2)<<endl;

	return 0;
}

	//C++ 11
	/*String(String&& s):_str(s._str){s._str = nullptr;}
	String& operator=(String&& s){std::swap(_str, s._str); return *this;}*/
	//未调用系统函数
	/*bool operator>(const String& s){if((_str!=NULL)||(s._str!=NULL)){char* s1=_str,*s2=s._str;while((*s1!='\0')&&(*s2!='\0'))		{if(*s1<*s2||*s1==*s2)return 0;s1++;s2++;}return (*s2=='\0');}return 0;}
	bool operator<(const String& s){return !((*this>s)||(*this==s));}
	bool operator==(const String& s){if((_str!=NULL)&&(s._str!=NULL)){char*s1=_str,*s2=s._str;while((*s1!='\0')&&(*s2!='\0')){if	(*s1!=*s2)return 0;s1++;s2++;}return 1;}return 0;}
	bool operator!=(const String& s){return (!(*this==s));}*/

