// Copyright (C) 2013  Nicholas Gill

/*
 * basic.cpp
 *
 *  Created on: 2013-12-05
 *      Author: nicholas
 */

#include "basic.h"
#include <cctype>
#include <stdexcept>
#include <cstdlib>

namespace svg
{
namespace types
{
namespace parsers
{

namespace
{
inline bool throw_if(bool cond, const std::string& what)
{
    if(cond) throw std::invalid_argument(what);
    return cond;
}
}

bool ws_p(const char c)
{
	switch(c)
	{
		case '\t':
		case '\n':
		case '\r':
		case ' ':
			return true;
		default:
			return false;
	}
}

bool parse_whitespace(const char*& c, const char* const end)
{
    if(!ws_p(*c))
        return false;

    while(c != end && ws_p(*c))
        ++c;
    return true;
}

bool number_p(const char c)
{
	switch(c)
	{
		case '+':
		case '-':
		case '.':
			return true;
		default:
			return std::isdigit(c);
	}
}

bool nonnegative_number_p(const char c)
{
	switch(c)
	{
		case '.':
			return true;
		default:
			return std::isdigit(c);
	}
}

bool parse_number(const char*& c, const char* const end, float& x)
{
    if(!number_p(*c))
        return false;

    const auto begin = c;

    errno = 0;
    x = strtof(c, const_cast<char**>(&c));
    throw_if(c == begin || errno, "expected number");
    throw_if(c > end, "unexpected eof; strtof consumed too much");
    return true;
}

bool parse_nonnegative_number(const char*& c, const char* const end, float& x)
{
    if(!nonnegative_number_p(*c))
        return false;

    const auto begin = c;

    errno = 0;
    x = strtof(c, const_cast<char**>(&c));
    throw_if(c == begin || errno, "expected number");
    throw_if(c > end, "unexpected eof; strtof consumed too much");
    return true;
}

bool parse_comma_wsp(const char*& c, const char* const end)
{
    if(!ws_p(*c) && *c != ',')
        return false;

    if(parse_whitespace(c, end) && c == end)
        return true;

    if(*c == ',' && ++c == end)
        return true;

    parse_whitespace(c, end);
    return true;
}

bool parse_flag(const char*& c, const char* const, bool& flag)
{
    if(*c == '0')
    {
        ++c;
        flag = false;
        return true;
    }
    else if (*c == '1')
    {
        ++c;
        flag = true;
        return true;
    }
    return false;
}

}
}
}

