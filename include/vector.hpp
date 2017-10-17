#include <iostream>
#include <string>

template <typename T>
class stack
{
public:
	stack() noexcept;
	~stack() noexcept;
	stack(const stack<T>&) noexcept;
	stack<T>& operator =(const stack<T>&) noexcept;
	void push(T const &) noexcept;
	void() noexcept;
	T top () const noexcept;
	size_t size() const noexcept;
private:
	T * array_;
	size_t array_size_;
	size_t count_;
	void swap(stack<T>&);
};

template <typename T>
void stack<T>::swap(stack<T>& object) noexcept
{
	std::swap(object.array_size_, array_size_);
	std::swap(count_, object.count_);
	std::swap(object.array_, array_);
}

template <typename T>
stack<T>::stack() noexcept : count_{0}, array_size_{0}, array_{nullptr}
{
}

template <typename T>
stack<T>::~stack() noexcept
{
	delete[] array_;
}

template <typename T>
stack<T>::stack(const stack& object) noexcept
{
	array_size_ = object.array_size_;
	count_ = object.count_;
	array_=new T[count_];
	std::copy(object.array_,object.array_+count_, array_);
}

template <typename T>
stack<T>& stack<T>:: operator =(const stack<T>&object) noexcept
{
	if (this != &object)
	{
		stack{object}.swap(*this);
	}
	return *this;
}

template <typename T>
void stack<T>::push(T const &value) noexcept
{
	if (array_size_ == count_)
	{
		array_size_ = array_size_ == 0 ? 1 : array_size_ * 2;
		T *ptr = new T [array_size_];
		std::copy(array_, array_ + count_, ptr);
		delete[] array_;
		array_ = ptr;
	}
	array_[count_++] = value;
}
template <typename T>
void stack<T>::pop() noexcept
{
	if (count_==0)
		throw "Stack is empty";
	count_--;
}
template <typename T>
void stack<T>::top() noexcept
{
	return array_[count];
}
template <typename T>
size_t stack<T>::size() const noexcept
{
	return count_;
}
template <typename T>
bool stack<T>::empty() const noexcept
{	
	if (count_==0) return false;
	else return true;
}
