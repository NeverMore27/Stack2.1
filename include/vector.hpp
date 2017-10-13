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
	void stack_print();
private:
	T * array_;
	size_t array_size_;
	size_t count_;
	void swap(size_t, size_t, const T*, T*&);
};
template <typename T>
void stack<T>::swap(size_t count, size_t size, const T* _ar, T*& ar)
{
	ar = new T[size];
	std::copy(_ar, _ar + count, ar);
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
	swap(count_, array_size_, object.array_, array_, );
}
template <typename T>
stack<T>& stack<T>:: operator =(const stack<T>&object)
{
	if (this != &object)
	{
		array_size_ = object.array_size_;
		count_ = object.count_;
		delete[] array_;
		swap(count_, array_size_, object.array_, array_, );
	}
	return *this;
}
template <typename T>
void stack<T>::push(T const &value)
{
	if (array_size_ == 0)
	{
		count_=2; 
		array_size_++;
		array_ = new T[array_size_];
		array_[0] = value;
	}
	if (array_size_ == count_)
	{
		T *ptr = array_;
		int capacity = count_ * 2;
		swap(count_, array_size_, ptr, array_);
		count_ = capacity;
		delete[] ptr;
	}
	array_[count_++] = value;
}
template <typename T>
T stack<T>::pop()
{
	if (count_ == 0) throw "Stack is empty";
	--count_;
	return array_[count_];
}
template <typename T>
size_t stack<T>::count() const
{
	return count_;
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
