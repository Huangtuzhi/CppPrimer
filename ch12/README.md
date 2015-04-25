# Chapter 12. Dynamic Memory

##[Exercise 12.2](ex12_2.cpp)
StrBlob这个类的目的是用来保存一组string，内部实现用了STL的vector。Blob对象的不同拷贝之间共享相同的元素。

##[Exercise 12.19](ex12_19.cpp)

## Exercise 12.27
在TextQuery和QueryResult类中直接实例化map，vector等。

[Exercise 12.27](ex12_27.cpp)

## Exercise 12.28
在TextQuery和QueryResult类中使用shared_ptr指向map，vector等。在使用时进行内存分配。

[Exercise 12.28](ex12_28.cpp)

## Exercise 12.31
vector的行号会重复，这里用无重复的set更好。
