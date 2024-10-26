#ifndef __LIST_H
#define __LIST_H

#include <vector>
#include <iostream>
using namespace std;

template<class T>
class List
{
	private:
		vector<T> items; // T must support T(), ~(), T(const T&) or move its traits
	public:
		void put(const T &val)
		{
			items.push_back(val);
		}

		int length(void)
		{
			return(items.size());	// vector<T>::size()
		}

		bool find(const T &val)
		{
			for(unsigned int i = 0; i < items.size(); ++i)
			{
				if(items[i] == val) // T must support operator==(). Its trait
				{
					return(true);
				}
			}

			return(false);
		}

		void print(void)
		{
			std::cout << "[";
			for(unsigned int i = 0; i < items.size() ; ++i)
			{
				std::cout << items[i] << ", ";
			}
			std::cout << "]" << std::endl;
		}
};

#endif  // __LIST_H

