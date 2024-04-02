#pragma once
#include <iostream>
#include <utility>


template<class T>
class UniquePtr
{
private:
	T* _ptr = nullptr;

public:
	UniquePtr() { std::cout << "Constructor called  " << '\n'; };
	UniquePtr(T* ptr) : _ptr(ptr) { std::cout << this << '\n'; };
	UniquePtr(const UniquePtr&) = delete; // запрещаем конструктор копирования
	UniquePtr& operator=(const UniquePtr&) = delete; // запрещаем оператор присваивания
	T& operator*() const
	{
		return *_ptr;
	}

	T* operator->() const
	{
		return _ptr;
	}

	T* release() noexcept
	{
		T* _TempPtr = _ptr;
		_ptr = nullptr;
		return _TempPtr;
	}

	UniquePtr(UniquePtr&& other) : _ptr(other._ptr)
	{
		std::cout << "UniquePtr&& " << this << '\n';
		other._ptr = nullptr;
	}

	~UniquePtr()
	{
		std::cout << "Destructor called" << '\n';
		delete _ptr;
	};
};

