#include "vector.hpp"

vector_t::vector_t() noexcept
{
	size_ = capacity_ = 0;
	ptr_ = nullptr;
};
vector_t::vector_t(const vector_t& other)
{
	size_ = other.size_;
	capacity_ = other.capacity_;
	ptr_ = new int[capacity_];
	for (unsigned int i = 0; i < size_; i++)
		ptr_[i] = other.ptr_[i];
}
vector_t::vector_t(unsigned int size)
{
	size_ = size;
	capacity_ = size;
	ptr_ = new int[capacity_];
	unsigned int i = 0;
	for (i; i <size_;i++)
	{
		ptr_[i] = 0;
	}
}
vector_t:: ~vector_t() noexcept
{
	size_ = capacity_ = 0;
	delete[] ptr_;
}
auto vector_t:: operator=(const vector_t& other)->vector_t&
{
	if (ptr_ == other.ptr_) return *this; else {
		size_ = other.size_;
		capacity_ = other.capacity_;
		delete[] ptr_;
		ptr_ = new int[capacity_];
		for (unsigned int i = 0; i < size_; i++)
			ptr_[i] = other.ptr_[i];
		return *this;
	}
}
auto vector_t::capacity() const noexcept -> unsigned int
{
	return capacity_;
}
auto  vector_t::size() const noexcept -> unsigned int
{
	return size_;
}
auto vector_t::push_back(int value) -> void
{
	if (size_ == capacity_)
	{
		int capacity = capacity_ + 2;

		int *ptr = new int[capacity];
		copy(ptr_, ptr_ + size_, ptr);

		delete[] ptr_;
		ptr_ = ptr;
		capacity_ = capacity;
	}
	ptr_[size_++] = value;
}
auto vector_t::pop_back() -> void
{
	int capacity = size_ - 1;
	int *ptr = new int[capacity];
	for (int i = 0; i < capacity; i++)
		ptr[i] = ptr_[i];
	delete[] ptr_;

	ptr_ = ptr;
	capacity_ = capacity;
	size_--;
}
vector_t:: vector_t(initializer_list<int> list)
{
	size_ = capacity_ = 0;
	ptr_ = nullptr;
	for (auto& item : list)
	{
		push_back(item);
	}

}
auto vector_t:: operator[](unsigned int index) const noexcept -> int
{
	return ptr_[index];
}
auto vector_t:: operator==(vector_t vector) const noexcept -> bool;
{
	for (int i=0;i<size_; i++)
	{
		int k=0;
		if (ptr_[i]==vector.ptr_[i]) k++;
	}
	if (k==size_) return true;
	return false;
}
