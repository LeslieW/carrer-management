/******************************************************************************
 *
 *	Operacao.h
 *
 *      Encapsulates an operation/feature in the system.
 *
 *	Created at:
 *	2012-01-17
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _OPERACAO_H
#define _OPERACAO_H

#include <iostream>
#include <string>

namespace dmd
{

class Operacao
{
private:
    std::string description;

    Operacao(const std::string &desc = "") :
            description(desc) {}

    const std::string& getDescription() const { return description; }

    void setDescription(const std::string& desc) { description = desc; }
};

}

#endif /* _OPERACAO_H */
