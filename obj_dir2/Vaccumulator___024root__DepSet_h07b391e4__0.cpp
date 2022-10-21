// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaccumulator.h for the primary calling header

#include "verilated.h"

#include "Vaccumulator___024root.h"

#include <iostream>

VL_INLINE_OPT void Vaccumulator___024root___sequent__TOP__0(Vaccumulator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->accumulator__DOT__dff = ((IData)(vlSelf->reset)
                                      ? 0U : (0xffU 
                                              & ((IData)(vlSelf->in) 
                                                 + (IData)(vlSelf->out))));
    vlSelf->out = vlSelf->accumulator__DOT__dff;
}

void Vaccumulator___024root___eval(Vaccumulator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vaccumulator___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vaccumulator___024root___eval_debug_assertions(Vaccumulator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
