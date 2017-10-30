#include "stack.hpp"
#include <thread>
#include <string>



void produser (stck<int> &st)
{
   for (;;)
    {
      st.push(rand()%10);
      std::this_thread::sleep_for(std::chrono::seconds(std::rand() % (3) + 1));
    }
}

void consumer (stck<int> &st)
{
   for (;;)
    {
       st.pop();
       std::this_thread::sleep_for(std::chrono::seconds(std::rand() % (3) +2 ));
    }
}

int main()
{
	stack<int> Stack;
	
	std::thread p(producer, std::ref(Stack));
	std::thread c(consumer, std::ref(Stack));
	
	p.join();
	c.join();
  return 0;
}
