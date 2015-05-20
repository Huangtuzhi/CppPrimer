# Chapter 15. Object-Oriented Programming

## Exercise 15.1
虚成员是指希望派生类覆盖(override)的成员，即基类和派生类都有此成员的独有的实现。

## Exercise 15.2
protected: 派生类可以直接访问
private: 派生类不可以直接访问

## [Exercise 15.3](ex15_3.cpp)

## [Exercise 15.5](ex15_5.cpp)

## Exercise 15.8

+ 静态类型：在编译时总是已知的，它是变量声明时的类型或表达式生成的类型。

+ 动态类型：变量或表达式表示的内存中的对象的类型。动态类型直到运行时才可知。

## Exercise 15.10

```
istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

```
ifstream input(argv[1])的ifstream类型是istream的派生类。

## [Exercise 15.11](ex15_11.cpp)

## [Exercise 15.15](ex15_15.cpp)

## Exercise 15.17

> cannot declare variable ‘error_class’ to be of abstract type ‘Disc_quote’ because the following virtual functions are pure within ‘Disc_quote’ 

## [Exercise 15.19](ex15_19.cpp)




