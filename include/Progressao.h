/******************************************************************************
 *
 *	Progressao.h
 *
 *	Encapsulates a progression step
 *
 *	Created at:
 *	2012-01-17
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _PROGRESSAO_H
#define _PROGRESSAO_H

#include <iostream>
#include <string>
#include <utility>

#include "Beneficio.h"
#include "Colaborador.h"
#include "Categoria.h"

namespace dmd
{

class Progressao
{
private:
    dmd::MyDate dataProgressao;
    dmd::Salary salarioAnterior;
    dmd::Salary salarioNovo;

    dmd::Colaborador colaborador;
    dmd::Categoria categoria;

public:
    Progressao();

    const dmd::MyDate& getDataProgressao() const { return dataProgressao; }
    dmd::Salary getSalarioAnterior() const { return salarioAnterior; }
    dmd::Salary getSalarioActual() const { return salarioNovo; }
    const dmd::Colaborador& getColaborador() const { return colaborador; }
    const dmd::Categoria& getCategoria() const { return categoria; }

    void setDataProgressao(const dmd::MyDate &data) { dataProgressao = data; }
    void setSalarioAnterior(dmd::Salary s) { salarioAnterior = s; }
    void setSalarioNovo(dmd::Salary s) { salarioNovo = s; }
    void setColaborador(const dmd::Colaborador &colab) { colaborador = colab; }
    void setCategoria(const dmd::Categoria &cat) { categoria = cat; }
};

typedef struct _PropostaProgressao
{
    int omfg;
    dmd::Progressao prog;
    dmd::Colaborador colabId;
    int estado;
} PropostaProgressao;

}

#endif /* _PROGRESSAO_H */
