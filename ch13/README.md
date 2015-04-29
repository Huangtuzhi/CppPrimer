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

## [Exercise 13.13](ex13_13.cpp)

## Exercise 13.14
生成完全一样的序号，因为默认构造函数只在a生成时调用，b=a时调用合成的拷贝函数，这个函数并不生成唯一的序号。

## Exercise 13.15
生成三个不同的序号。

## Exercise 13.16
生成相同的序号，没有拷贝构造函数。引用传值不调用拷贝构造函数。

## [Exercise 13.17](ex13_17.cpp)

## [Exercise 13.18](ex13_18.cpp)

## [Exercise 13.22](ex13_22.cpp)

## Exercise 13.24
HasPtr未定义析构函数会导致内存泄漏。
未定义拷贝构造函数，指针可能会指向多个对象，析构时多次删除指针。

## Exercise 13.25
拷贝构造函数和拷贝赋值运算符应该动态为它自己分配内存，而不是和共享对象。

StrBlob不需要构造函数原因：智能指针管理动态内存，当计数为0会自动释放内存。

StrBlob is using smart pointers which can be managed with synthesized destructor, If an object of StrBlob is out of scope, the destructor for std::shared_ptr will be called automatically to free the memory dynamically allocated when the use_count goes to 0.

## [Exercise 13.26](ex13_26.cpp)

## [Exercise 13.27](ex13_27.cpp)
注意处理自赋值

## [Exercise 13.28](ex13_28.cpp)

## Exercise 13.29
swap(HasPtr& lhs, HasPtr& rhs)中的参数是引用类型。

## [Exercise 13.30](ex13_30.cpp)

## [Exercise 13.31](ex13_31.cpp)

## Exercise 13.33
因为需要对传进来的参数Folder进行修改。

## [Exercise 13.34](ex13_34.cpp)