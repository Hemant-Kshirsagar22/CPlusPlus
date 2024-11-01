#include <iostream>
#include <functional> // std::placeholders

class MyClass 
{
	typedef std::function<void(float result)> TCallback; 

	void longRunningFunction(TCallback callback) 
	{
		double result = 2.7;	// this function takes long time
		// do some long running task ...
		// ...
		// ...
		callback(result);
	}

	void callback(float result)
	{
		std::cout << result << std::endl; // called by longRunningFunction after its done
	}

	public:
	void longRunningFunctionAsync(void)
	{
		auto callback = std::bind(&MyClass::callback, this, std::placeholders::_1); // mem fn, object, future param

		longRunningFunction(callback);
	}
};

int main(void)
{
	MyClass().longRunningFunctionAsync();

	return(0);
}

