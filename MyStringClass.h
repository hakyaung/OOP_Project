#ifndef __MYSTRINGCLASS_H__
#define __MYSTRINGCLASS_H__

#include <iostream>
using namespace std;

class String {
private:
	char* str;

public:
	String();
	String(const char* s);
	String(const String& otherString);
	String(int len);
	~String();

	String& operator=(const String& otherString);
	String operator+(const String& otherString);
	String& operator+=(const String& otherString);
	bool operator==(const String& otherString);

	friend ostream& operator<<(ostream& os, const String& str);
	friend istream& operator>>(istream& is, String& str); 
};

#endif // !__MYSTRINGCLASS_H__
