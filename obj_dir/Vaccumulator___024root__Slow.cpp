// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaccumulator.h for the primary calling header

#include "verilated.h"

#include "Vaccumulator__Syms.h"
#include "Vaccumulator___024root.h"

#include <iostream>

void Vaccumulator___024root___ctor_var_reset(Vaccumulator___024root* vlSelf);

Vaccumulator___024root::Vaccumulator___024root(Vaccumulator__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
{
    // Reset structure values
    Vaccumulator___024root___ctor_var_reset(this);
}

Vaccumulator___024root::~Vaccumulator___024root() {
}

void Vaccumulator___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

// Overload '==' operator to check if the predicted state is correct
inline bool operator== (const Vaccumulator___024root& lhs, const Vaccumulator___024root& rhs) {

    // std::cout<<"LHS: "<<(int)lhs.accumulator__DOT__dff<<" RHS: "<<(int)rhs.accumulator__DOT__dff<<'\n';
    if (lhs.accumulator__DOT__dff != rhs.accumulator__DOT__dff) return false;
    return true;
}

Vaccumulator___024root& Vaccumulator___024root::operator= (const Vaccumulator___024root& rhs) {

    this->clk = rhs.clk;
    this->reset = rhs.reset;
    this->in = rhs.in;
    this->out = rhs.out;
    this->accumulator__DOT__dff = rhs.accumulator__DOT__dff;
    this->__Vclklast__TOP__clk = rhs.__Vclklast__TOP__clk;
    return *this;
 }
