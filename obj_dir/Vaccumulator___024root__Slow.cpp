// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaccumulator.h for the primary calling header

#include "verilated.h"

#include "Vaccumulator__Syms.h"
#include "Vaccumulator___024root.h"

void Vaccumulator___024root___ctor_var_reset(Vaccumulator___024root* vlSelf);

Vaccumulator___024root::Vaccumulator___024root(Vaccumulator__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vaccumulator___024root___ctor_var_reset(this);
}

// Copy constructor
Vaccumulator___024root::Vaccumulator___024root(Vaccumulator___024root *rootp)
    : VerilatedModule{"TOP"}
    , vlSymsp{rootp->vlSymsp}
 {
    // Reset structure values
    Vaccumulator___024root___ctor_var_reset(this);

    this->clk   = rootp->clk;
    this->reset = rootp->reset;
    this->in    = rootp->in;
    this->out   = rootp->out;
    this->accumulator__DOT__dff = rootp->accumulator__DOT__dff;
    this->__Vclklast__TOP__clk  = rootp->__Vclklast__TOP__clk; 
}

void Vaccumulator___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vaccumulator___024root::~Vaccumulator___024root() {
}
