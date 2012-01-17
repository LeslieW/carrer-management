/******************************************************************************
 *
 *	Beneficio.h
 *
 *	Encpasulates a Beneficio
 *
 *	Created at:
 *	2012-01-17
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _BENEFICIO_H
#define _BENEFICIO_H

#include <iostream>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>

namespace dmd
{

typedef boost::gregorian::date MyDate;

class Beneficio
{
private:
    MyDate dataInicio;
    MyDate dataFim;

    Beneficio();

    Beneficio(const MyDate &di, const MyDate &df) :
            dataInicio(di), dataFim(df) {}

    const MyDate& getDataInicio() const { return dataInicio; }
    const MyDate& getDataFim() const { return dataFim; }

    void setDataInicio(const MyDate& di) { dataInicio = di; }
    void setDataFim(const MyDate& df) { dataFim = df; }
};

}

#endif /* _BENEFICIO_H */
