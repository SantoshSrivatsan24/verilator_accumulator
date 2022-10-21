// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaccumulator.h for the primary calling header

#include "verilated.h"

#include "Vaccumulator___024root.h"

VL_ATTR_COLD void Vaccumulator___024root___settle__TOP__0(Vaccumulator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->out = vlSelf->accumulator__DOT__dff;
}

VL_ATTR_COLD void Vaccumulator___024root___eval_initial(Vaccumulator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vaccumulator___024root___eval_settle(Vaccumulator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root___eval_settle\n"); );
    // Body
    Vaccumulator___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vaccumulator___024root___final(Vaccumulator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root___final\n"); );
}

VL_ATTR_COLD void Vaccumulator___024root___ctor_var_reset(Vaccumulator___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->in = VL_RAND_RESET_I(8);
    vlSelf->out = VL_RAND_RESET_I(8);
    vlSelf->accumulator__DOT__dff = VL_RAND_RESET_I(8);
}
