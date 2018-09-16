#include <iostream>
using namespace std;

//日期类
class Date
{
	//友元函数:
	// 重载'<<'
	friend ostream& operator <<(ostream& _cout, const Date& d);

public:
	//构造函数
	Date(int year = 1970, int month = 1, int day = 1)
		:_year(year),
		_month(month),
		_day(day)
	{
		if(!IsValidDate(year, month, day))
		{
			_year = 1970;
			_month = 1;
			_day = 1;
		}
	}

	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//判断是否闰年
	bool IsLeapYear()
	{
		return (((*this)._year%4 == 0 && (*this)._year%100 != 0) \
			|| (*this)._year%400 == 0);
	}
             
	//运算符重载：
	// '='
	Date& operator =(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	// '+'count
	Date operator +(int count)
	{
		//Date temp(_year, _month, _day-count);

		Date temp(*this);
		temp._day += count;
		if(!IsValidDate(temp._year, temp._month, temp._day))
		{
			ToValid(temp);
		}
		return temp;
	}

	// '-'count
	Date operator -(int count)
	{
		//Date temp(_year, _month, _day-count);
		
		Date temp(*this);
		temp._day -= count;
		if(!IsValidDate((*this)._year, (*this)._month, (*this)._day))
		{
			ToValid(temp);
		}

		return temp;
	}

	// "+="
	Date operator +=(int count)
	{
		*this = *this + count;

		return *this;
	}

	// "-="
	Date operator -=(int count)
	{
		*this = *this - count;

		return *this;
	}

	//前置'++'
	Date& operator ++()
	{
		*this += 1;

		return *this;
	}

	//后置'++'
	Date operator ++(int)
	{
		Date temp(*this);
		*this += 1;

		return temp;
	}

	//前置'--'
	Date& operator --()
	{
		*this -= 1;

		return *this;
	}

	//后置'--'
	Date operator --(int)
	{
		Date temp(*this);
		*this -= 1;

		return temp;
	}
	
	////'+'Date
	//Date& operator +(const Date& d)
	//{
	//	_year += d._year;
	//	_month += d._month;
	//	_day += d._day;

	//	ToValid(*this);

	//	return *this;
	//}

	//'-'Date
	int operator -(const Date& d)
	{
		int count = 0;
		int flag = 1;
		Date max = *this;
		Date min = d;
		if(*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}

		while(max != min)
		{
			++min;
			count++;
			//cout<<count<<endl;
		}

		return count*flag;
	}

	//'=='
	bool operator ==(const Date& d)
	{
		return (_year == d._year \
			&& _month == d._month \
			&& _day == d._day);
	}

	//'!='
	bool operator !=(const Date& d)
	{
		return !(*this==d); 
	}

	//'>'
	bool operator >(const Date& d)
	{
		return (_year > d._year \
			|| (_year == d._year && _month > d._month) \
			|| (_year == d._year && _month == d._month && _day > d._day));
	}

	//'>='
	bool operator >=(const Date& d)
	{
		return (*this>d) || (*this == d);
	}
		
	//'<'maxDaysOfMonth
	bool operator <(const Date& d)
	{
		return !(*this>=d);
	}

	//'<='
	bool operator <=(const Date& d)
	{
		return !(*this>d);
	}

private:

	//某一月的天数
	int DaysOfMonth(int year, int month)
	{
		int day = 1;
		int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		day = days[month];

		if(2 == month && IsLeapYear(year))
		{
			day += 1;
		}
		
		return day;
	}

	//判断是否闰年
	bool IsLeapYear(int year)
	{
		return ((year%4 == 0 && year%100 != 0) || year%400 == 0);
	}


	//判断年月日是否合法
	bool IsValidDate(int year, int month, int day)
	{
		return ((year>0) \
			&& (month>0 && month<=12) \
			&& (day>0 && day<=DaysOfMonth(year, month)));
	}

	//将日期转为合法的
	Date ToValid(Date& d)
	{
		int maxDaysOfMonth = DaysOfMonth(d._year, d._month);
		if(d._day>maxDaysOfMonth)
		{
			while(d._day>maxDaysOfMonth)
			{
				d._day -= maxDaysOfMonth; 
				if(d._month == 12)
				{
					d._month = 1;
					d._year++;
				}
				else
				{
					++d._month;
				}
				maxDaysOfMonth = DaysOfMonth(d._year, d._month);
			}
		}
		else
		{
			while(d._day <= 0)
			{
				if(d._month == 1)
				{
					d._year--;
					d._month = 12;
				}
				else
				{
					--d._month;
				}
				maxDaysOfMonth = DaysOfMonth(d._year, d._month);
				d._day += maxDaysOfMonth;
			}
		}
		return d;
	}

private:
	int _year;
	int _month;
	int _day;
};

//Date友元函数:
// '<<'重载
ostream& operator <<(ostream& _cout, const Date& d)
{
	_cout<<d._year<<'-'<<d._month<<'-'<<d._day;
	return _cout;
}

int main()
{
	int count = 0;
	Date d1(1996, 9, 16);

	Date d2 = d1 + 36500;

	
	cout<<d2-d1<<endl;

	/*Date d2 (d1);

	d2 = d1 + 366;


	cout<<"d1:"<<d1<<endl;
	cout<<"d2:"<<d2<<endl;

	d2 -= 100;
	cout<<"d2:"<<d2<<endl;

	d2 += 100;
	cout<<"d2:"<<d2<<endl;

	count = d1 - d2;
	cout<<"count:"<<count<<endl;

	cout<<"d1>d2:"<<(d1>d2)<<endl;
	cout<<"d1<d2:"<<(d1<d2)<<endl;
	cout<<"d1==d2:"<<(d1==d2)<<endl;
	cout<<"d1!=d2:"<<(d1!=d2)<<endl;

	d2 = d1 - 50;
	cout<<"d2:"<<d2<<endl;
*/

	system("pause");

	return 0;
}