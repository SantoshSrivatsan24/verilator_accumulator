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

void Vaccumulator___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vaccumulator___024root::~Vaccumulator___024root() {
}
