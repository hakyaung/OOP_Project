#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "MyStringClass.h"
using namespace std;

String::String() {
	int len = 0;
	str = NULL;
}

String::String(const char* s) {
	int len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& otherString) {
	int len = strlen(otherString.str) + 1;
	str = new char[len];
	strcpy(str, otherString.str);
}

String::String(int len) {
	str = new char[len];
}

String::~String() {
	cout << str << "[String °´Ã¼ ¼Ò¸ê]" << endl;
	if (str != NULL) {
		delete[]str;
	}
}

String& String::operator=(const String& otherString) {
	delete[]str;
	int len = strlen(otherString.str) + 1;
	str = new char[len];
	strcpy(str, otherString.str);
	return *this;
}

String String::operator+(const String& otherString) {
	int len = strlen(str) + strlen(otherString.str) + 1;
	String tmp(len);
	strcpy(tmp.str, str);
	strcat(tmp.str, otherString.str);
	return tmp;
}

String& String::operator+=(const String& otherString) {
	int len = strlen(str) + strlen(otherString.str) + 1;
	String tmp(len);
	strcpy(tmp.str, str);
	strcat(tmp.str, otherString.str);
	delete[] str;
	str = new char[len];
	strcpy(str, tmp.str);
	return *this;
}

bool String::operator==(const String& otherString) {
	if (strcmp(str, otherString.str) == 0) {
		return true;
	}
	else {
		return false;
	}
}

ostream& operator<<(ostream& os, const String& myString) {
	os << myString.str << endl;
	return os;
}

istream& operator>>(istream& is, String& myString) {
	char c[100];
	is >> c;
	myString = String(c);
	return is;
}