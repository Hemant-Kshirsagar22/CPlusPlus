#pragma once
class String
{
private:
	char *string;
	size_t length; // here if we declare the length first then it will initializes first and gives error to the constructor initializeation(Line 14)

public:
	String(char *s);
	~String(void);
	void print(void);
	size_t len(void);
};
