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
	void push(T const &);
	T pop();
	size_t size() const;
private:
	T * array_;
	size_t array_size_;
	size_t count_;
	void swap(stack<T>&);
};

template <typename T>
void stack<T>::swap(stack<T>& object)
{
	std::swap(object.array_size_, array_size_);
	std::swap(count_, object.count_);
	std::swap(object.array_, array_);
}

template <typename T>
stack<T>::stack() : count_{0}, array_size_{0}, array_{nullptr}
{
}

template <typename T>
stack<T>::~stack()
{
	delete[] array_;
}

template <typename T>
stack<T>::stack(const stack& object)
{
	array_size_ = object.array_size_;
	count_ = object.count_;
	array_=new T[count_];
	std::copy(object.array_,object.array_+count_, array_);
}

template <typename T>
stack<T>& stack<T>:: operator =(const stack<T>&object)
{
	if (this != &object)
	{
		stack{object}.swap(*this);
	}
	return *this;
}

template <typename T>
void stack<T>::push(T const &value)
{
	if (array_size_ == count_)
	{
		array_size_ = array_size == 0 ? 1 : array_size_ * 2;
		T *ptr = new T [array_size_];
		std::copy(array_, array_ + count_, ptr);
		delete[] array_;
		array_ = ptr;
	}
	array_[count_++] = value;
}
template <typename T>
T stack<T>::pop()
{
	if (count_==0)
		throw "Stack is empty";
	count_--;
	return array_[count_];
}
template <typename T>
size_t stack<T>::size() const
{
	return count_;
}
