#include <iostream>
#include <string>

template <typename T>
class stack
{
public:
	stack();
	~stack() noexcept;
	stack(const stack<T>&);
	stack<T>& operator =(const stack<T>&);
	void push(T const &);
	void pop();
	T top () const;
	size_t size() const noexcept;
	bool empty() const noexcept;
private:
	T * array_;
	size_t array_size_;
	size_t count_;
	void swap(stack<T>&) noexcept;
};

template <typename T>
void stack<T>::swap(stack<T>& object) noexcept
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
stack<T>::~stack() noexcept
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
stack<T>& stack<T>:: operator =(const stack<T>&object) noexcept
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
		array_size_ = array_size_ == 0 ? 1 : array_size_ * 2;
		T *ptr = new T [array_size_];
		std::copy(array_, array_ + count_, ptr);
		delete[] array_;
		array_ = ptr;
	}
	array_[count_++] = value;
}

template <typename T>
void stack<T>::pop()
{
	if (count_==0)
		throw "Stack is empty";
	count_--;
}

template <typename T>
T stack<T>::top() const
{
	return array_[count_];
}

template <typename T>
size_t stack<T>::size() const noexcept
{
	return count_;
}

template <typename T>
bool stack<T>::empty() const noexcept
{	
	 return count_==0;
}
