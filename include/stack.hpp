#include <iostream>
#include <string>
#include <mutex>

template <typename T>
class stack
{
public:
	stack() /*noexcept*/ noexcept; 
	~stack()  /*noexcept*/ noexcept;
	stack(const stack<T>&) /*strong*/;
	stack<T>& operator =(const stack<T>&) noexcept;
	void push(T const &) /*strong*/;
	void pop() /*strong*/;
	T top () /*strong*/;
	size_t size() const /*noexcept*/ noexcept;
	bool empty() const /*noexcept*/ noexcept;
private:
	mutable std::mutex mutex_;
	T * array_;
	size_t array_size_;
	size_t count_;
	void swap(stack<T>&) /*noexcept*/ noexcept;
};

template <typename T>
void stack<T>::swap(stack<T>& object) noexcept
{	mutex_.lock();
	std::swap(object.array_size_, array_size_);
	std::swap(count_, object.count_);
	std::swap(object.array_, array_);
 	mutex_.unlock();
}

template <typename T>
stack<T>::stack() noexcept: count_{0}, array_size_{0}, array_{nullptr} 
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
	mutex_.lock();
	array_size_ = object.array_size_;
	count_ = object.count_;
	array_= new T[count_];
	try 
	{
		std::copy(object.array_,object.array_+count_, array_);
	}
	catch (...)
	{ 
      		delete[] array_;
		throw;
	}
	mutex_.unlock();
}

template <typename T>
stack<T>& stack<T>:: operator =(const stack<T>&object) noexcept
{
	mutex_.lock();
	if (this != &object)
	{
		stack{object}.swap(*this);
	}
	return *this;
	mutex_.unlock();
}

template <typename T>
void stack<T>::push(T const &value)
{
	mutex_.lock();
	if (array_size_ == count_)
	{
		array_size_ = array_size_ == 0 ? 1 : array_size_ * 2;
		T *ptr = new T [array_size_];
		try 
		{
			std::copy(array_, array_ + count_, ptr);
		}
		catch (...)
		{  
      			delete[] ptr;
			throw;
		}
		
		delete[] array_;
		array_ = ptr;
	}
	
	array_[count_] = value;
	++count_;
	mutex_.unlock();
}

template <typename T>
void stack<T>::pop()
{
	mutex_.lock();
	if (empty())
	{
		throw "Stack is empty!";
	}
	count_--;
	mutex_.unlock();
}

template <typename T>
T stack<T>::top()
{
	mutex_.lock();
	if (empty())
	{
		throw "Stack is empty!";
	}
	return array_[count_ - 1];
	mutex_.unlock();
}

template <typename T>
size_t stack<T>::size() const noexcept
{
	mutex_.lock();
	return count_;
	mutex_.lock();
}

template <typename T>
bool stack<T>::empty() const noexcept
{	mutex_.lock();
	 return count_==0;
	 mutex_.unlock();
}
