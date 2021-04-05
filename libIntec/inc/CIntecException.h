#ifndef _CIntec_Exception_H_
#define _CIntec_Exception_H_
#pragma warning ( disable : 4290 4995 4996)
#include <iostream>
#include <exception>
class CIntecException : public std::exception
{
 std::string _what;

 public:

	 CIntecException(std::string what) : _what(what) {}
	virtual const char* what() const throw() { return _what.c_str(); }

 };
#endif

