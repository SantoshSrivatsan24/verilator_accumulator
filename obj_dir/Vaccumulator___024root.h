// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vaccumulator.h for the primary calling header

#ifndef VERILATED_VACCUMULATOR___024ROOT_H_
#define VERILATED_VACCUMULATOR___024ROOT_H_  // guard

#include "verilated.h"

class Vaccumulator__Syms;

class Vaccumulator___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(in,7,0);
    VL_OUT8(out,7,0);
    CData/*7:0*/ accumulator__DOT__dff;
    CData/*0:0*/ __Vclklast__TOP__clk;

    // INTERNAL VARIABLES
    Vaccumulator__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vaccumulator___024root(Vaccumulator__Syms* symsp, const char* name);
    ~Vaccumulator___024root();

    // Comment out since we want to be able to copy state
    // VL_UNCOPYABLE(Vaccumulator___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);

    // OPERATOR OVERLOADING
    Vaccumulator___024root& operator= (const Vaccumulator___024root& rhs);
    friend inline bool operator== (const Vaccumulator___024root& lhs, const Vaccumulator___024root& rhs);


} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
