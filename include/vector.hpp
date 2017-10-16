#include <iostream>
#include <string>
template <typename T>
class stack
{
public:
	stack();
	~stack();
	stack(const stack<T>&);
	stack<T>& operator =(const stack<T>&);
	size_t count() const;
	void push(T const &);
	T pop();
	size_t size() const;
	void stack_print();
private:
	T * array_;
	size_t array_size_;
	size_t count_;
	void swap(stack<T>&);
};
template <typename T>
void stack<T>::swap(stack<T>& object)
{
	array_ = new T[object.count];
	array_size_ = object.array_size_;
	count_ = object.count_;
	std::copy(object.array_, object.array_ + count_, array_);
}
template <typename T>
stack<T>::stack()
{
	array_size_ = 0;
	count_ = 0;
	array_ = nullptr;
}
template <typename T>
stack<T>:: ~stack()
{
	array_size_ = 0;
	count_ = 0;
	delete[] array_;
}
template <typename T>
stack<T>::stack(const stack& object)
{
	array_size_ = object.array_size_;
	count_ = object.count_;
	array_=new T[count_];
	std::copy(object.array_,object.array_+array_size_, array_);
}
template <typename T>
stack<T>& stack<T>:: operator =(const stack<T>&object)
{
	if (this != &object)
	{
		
		delete[] array_;
		swap(object);
	}
	return *this;
}
template <typename T>
void stack<T>::push(T const &value)
{
	if (count_ == 0)
	{
		
			count_ = 1;
			array_size_ = 1;
			array_ = new T[count_];
			array_[0] = value;
	}
	else 
	{
		if (array_size_ == count_)
		{
			
		int capacity = count_ + 2;
		int *ptr = new int[capacity];
		copy(array_, array_ + count_, ptr);
		delete[] array_;
		array_ = ptr;
		count_ = capacity;
		}
		array_[array_size_++] = value;
	}
}
template <typename T>
T stack<T>::pop()
{
	if (count_==0)
		throw "Stack is empty";
	count--;
	return array[count];
}
template <typename T>
size_t stack<T>::count() const
{
	return count_;
}
template <typename T>
size_t stack<T>::size() const
{
	return array_size_;
}
template <typename T>
void stack<T>::stack_print()
{
	if (count_ == 0) std::cout << "Stack is empty" << std::endl;
	else
	{
		for (int i = 0; i<count_; i++)
			std::cout << array_[i] << ' ';
	}
	std::cout << std::endl;
}
