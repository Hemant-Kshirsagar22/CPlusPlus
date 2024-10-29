#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

template<typename T>
class MyClass
{
	std::vector<T> elements;

	public:
	MyClass() : elements({ -1 })
	{
		std::cout << "Default Constructor : ";
		showElements();
	}

	MyClass(int b) : elements({ b }) 
	{
		std::cout << "Parameterized Constructor : ";
		showElements();
	}

	MyClass(std::initializer_list<T> init_list) : elements({init_list})
	{
		std::cout << "Initializer List  Constructor : ";
		showElements();
	}

	MyClass(int i,std::initializer_list<T> init_list) : elements{init_list}
	{
		std::cout << "Mixed Constructor : " << i << ", ";
		showElements();
	}

	void showElements(void)
	{
		std::cout << "{ ";
		for(auto it = elements.begin(); it != elements.end(); ++it)
		{
			std::cout << *it << ", ";
		}

		std::cout << "}\n\n";
	}
};

int main(void)
{
	MyClass<int> my_obj;
	MyClass<int> my_obj_i = MyClass<int>(500);
	MyClass<int> my_obj_il = MyClass<int>{500};
	
	
	std::initializer_list<int> init_list = {1,2,3,4,5};

	MyClass<int> my_obj_il_int = {init_list};

	std::initializer_list<std::string> il = {"Hemant", "Kshirsagar"};

	MyClass<std::string> my_obj_il_string = { il };

	MyClass<std::string> my_obj_m = {5, {"Hello", "World !!!"}};

	return(0);
}

