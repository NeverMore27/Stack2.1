#include <algorithm>


template <class Iterator>
void ItSort(Iterator begin, Iterator end)
{
	if (begin == end) return;
	for (Iterator i = begin + 1; i != end; i++)
		for (Iterator j = i; (j != first) && (*(j - 1)<*(j)); j--)
		{
			std::iter_swap(j, j - 1);
		}
}