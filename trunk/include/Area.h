/******************************************************************************
 *
 *	Area.h
 *
 *	Main header for Area class
 *
 *	Created at:
 *	2012-01-10
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _AREA_H_
#define _AREA_H_

#include <iostream>
#include <string>

namespace dmd
{

class Area
{
private:
    std::string description;
    std::string name;

public:
    Area();

    Area(const std::string &desc, const std::string &n) :
            description(desc), name(n) {}

    const std::string& getDescription() const { return description; }
    const std::string& getName() const { return name; }

    void setDescription(const std::string &desc) { description = desc; }
    void setName(const std::string &_name) { name = _name; }
};

}

#endif
