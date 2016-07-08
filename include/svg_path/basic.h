// Copyright (C) 2013  Nicholas Gill

/*
 * basic.h
 *
 *  Created on: 2013-12-05
 *      Author: nicholas
 */

#ifndef PARSERS_BASIC_H_
#define PARSERS_BASIC_H_
#include <string>

namespace svg
{
namespace types
{
namespace parsers
{

bool ws_p(const char c);
bool parse_whitespace(const char*& c, const char* const end);

bool number_p(const char c);
bool nonnegative_number_p(const char c);
bool parse_number(const char*& c, const char* const end, float& x);
bool parse_nonnegative_number(const char*& c, const char* const end, float& x);

bool parse_comma_wsp(const char*& c, const char* const end);

bool parse_flag(const char*& c, const char* const end, bool& flag);

}
}
}

#endif /* PARSERS_BASIC_H_ */
