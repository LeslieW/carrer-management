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
    int opId;
    std::string description;

    Operacao(int _opId = 0, const std::string &desc = "") :
            opId(_opId), description(desc) {}

    const std::string& getDescription() const { return description; }
    int getOpId() const { return opId; }

    void setDescription(const std::string& desc) { description = desc; }
    void setOpId(int _opId) { opId = _opId; }
};

}

#endif /* _OPERACAO_H */
