# Chapter 14. Overloaded Operations and Conversions

## Exercise 14.4
- (a) % 对称     非成员
- (b) %= 改变对象 成员
- (c) ++ 改变对象 成员
- (d) -> 解引用   成员
- (e) <<         非成员
- (f) &&         非成员
- (g) == 对称     非成员
- (h) ()         成员

<<定义为非成员的例子

```
ostream& operator<<(ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " "
	   << item.revenue << " " << item.avg_price();
	return os;
}

```
注意第一个形参是非const ostream对象的引用，定义为非const的原因是向流写入内容会改变其状态;第二个形参是const引用，定义为const的原因是因为打印对象不会改变对象的内容。

## [Exercise 14.6](ex14_6.cpp)

## [Exercise 14.7](ex14_7.cpp)

## [Exercise 14.9](ex14_6.cpp)

## Exercise 14.14
operator+需要两个参数，需要一个临时对象。

operator+=只需要一个参数，在this对象上作更改。

见[SO](http://stackoverflow.com/questions/21071167/why-is-it-more-efficient-to-define-operator-to-call-operator-rather-than-the)。

## [Exercise 14.16](ex14_16.cpp)

## [Exercise 14.23](ex14_23.cpp)

## [Exercise 14.34](ex14_34.cpp)

## [Exercise 14.35](ex14_35.cpp)

## [Exercise 14.36](ex14_36.cpp)



