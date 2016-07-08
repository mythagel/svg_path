// Copyright (C) 2013  Nicholas Gill

/*
 * transform.h
 *
 *  Created on: 2013-12-09
 *      Author: nicholas
 */

#ifndef PARSERS_TRANSFORM_H_
#define PARSERS_TRANSFORM_H_
#include <array>
#include <stdexcept>

namespace svg
{
namespace types
{
namespace parsers
{
namespace transform
{

struct parse_error : std::runtime_error
{
    parse_error(const std::string& what);
    virtual ~parse_error() noexcept;
};

/*
Parser that reduces all transformation lists down to a matrix

[a b c d e f] ->

[a c e]
[b d f]
[0 0 1]
*/
std::array<float, 6> parse_transforms(const char* c, const char* const end);

}
}
}
}

#endif /* PARSERS_TRANSFORM_H_ */
