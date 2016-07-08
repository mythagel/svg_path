// Copyright (C) 2013  Nicholas Gill

/*
 * path.h
 *
 *  Created on: 2013-12-04
 *      Author: nicholas
 */

#ifndef PARSERS_PATH_H_
#define PARSERS_PATH_H_
#include <stdexcept>

namespace svg
{
namespace types
{
namespace parsers
{
namespace path
{

// TODO use template - the functions below don't need dynamic binding.
class parser
{
private:
	bool parse_moveto(const char*& c, const char* const end);
	bool parse_lineto(const char*& c, const char* const end);
	bool parse_horizontal_lineto(const char*& c, const char* const end);
	bool parse_vertical_lineto(const char*& c, const char* const end);
	bool parse_curveto(const char*& c, const char* const end);
	bool parse_smooth_curveto(const char*& c, const char* const end);
	bool parse_quadratic_bezier_curveto(const char*& c, const char* const end);
	bool parse_smooth_quadratic_bezier_curveto(const char*& c, const char* const end);
	bool parse_elliptical_arc(const char*& c, const char* const end);
	bool parse_closepath(const char*& c, const char* const end);
public:

    struct error : std::runtime_error
    {
        error(const std::string& what);
        virtual ~error() noexcept;
    };

	virtual void move_to(bool abs, float x, float y) =0;

	virtual void line_to(bool abs, float x, float y) =0;
	virtual void horizontal_line_to(bool abs, float x) =0;
	virtual void vertical_line_to(bool abs, float y) =0;

	virtual void curve_to(bool abs, float x1, float y1, float x2, float y2, float x, float y) =0;
	virtual void smooth_curve_to(bool abs, float x2, float y2, float x, float y) =0;

	virtual void bezier_curve_to(bool abs, float x1, float y1, float x, float y) =0;
	virtual void smooth_bezier_curve_to(bool abs, float x, float y) =0;
	virtual void elliptical_arc_to(bool abs, float rx, float ry, float x_rotation, bool large_arc, bool sweep, float x, float y) =0;

	virtual void close_path() =0;
	virtual void eof() =0;

	void parse(const char* c, const char* const end);

	virtual ~parser();
};

}
}
}
}

#endif /* PARSERS_PATH_H_ */
