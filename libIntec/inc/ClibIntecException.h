#ifndef INC_CLIBINTECEXCEPTION_H_
#define INC_CLIBINTECEXCEPTION_H_

#include <iostream>
#include <string>
#include <exception>

class ClibIntecException : public std::exception
{
 std::string _what;
 public:
	 ClibIntecException(std::string what) : _what(what) {}
	virtual const char* what() const throw() { return _what.c_str(); }
 };
#endif
