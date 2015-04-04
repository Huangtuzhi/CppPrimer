# Chapter 13. Copy Control

## Exercise 13.1
拷贝构造函数：一个构造函数的第一个参数是自身类类型的引用，且任何额外参数都有默认值。则此构造函数是拷贝构造函数。

用法：
- 用=定义变量
- 将一个对象作为实参传递给一个非引用类型的形参
- 从一个返回类型为非引用类型的函数返回一个对象
- 用花括号列表初始化一个数组中的元素或一个聚合类中的成员
- 某些类类型对他们所分配的对象使用拷贝初始化(STL调用insert或push时)

## [Exercise 13.5](ex13_5.cpp)

## [Exercise 13.8](ex13_8.cpp)
注意赋值运算符里先释放了要赋值的对象的空间。
```
string* new_ps = new string(*rhs.ps);
delete ps;
```

## [Exercise 13.11](ex13_11.cpp)

## [Exercise 13.11](ex13_13.cpp)