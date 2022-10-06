// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaccumulator.h for the primary calling header

#include "verilated.h"

#include "Vaccumulator___024root.h"

#include <iostream>
#include <pthread.h>

VL_INLINE_OPT void Vaccumulator___024root___sequent__TOP__0(Vaccumulator___024root* vlSelf) {

    std::cout<<"Evaluating the current state.\n";

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

/////////////////////////////////////////////

void *Vaccumulator___024root__sequent__NEXT__0(void *args) {

    std::cout<<"Evaluating the next state in parallel with the current state.\n";

    Vaccumulator___024root *vlNext = (Vaccumulator___024root *) args;

    if (false && vlNext) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlNext->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root___sequent__NEXT__0\n"); );
    // Body
    vlNext->accumulator__DOT__dff = ((IData)(vlNext->reset)
                                      ? 0U : (0xffU 
                                              & ((IData)(vlNext->in) 
                                                 + (IData)(vlNext->out))));
    vlNext->out = vlNext->accumulator__DOT__dff;

    pthread_exit (NULL);
}

void Vaccumulator___024root___predict(Vaccumulator___024root* vlSelf, Vaccumulator___024root* vlNext) {

    std::cout<<"Predict next state here.\n";

    // For now, the next state is the same as the current state
    vlNext->clk = vlSelf->clk;
    vlNext->reset = vlSelf->reset;
    vlNext->in = vlSelf->in;
    vlNext->out = vlSelf->out;
    vlNext->accumulator__DOT__dff = vlSelf->accumulator__DOT__dff;
    vlNext->__Vclklast__TOP__clk = vlSelf->__Vclklast__TOP__clk;
}

/////////////////////////////////////////////

void Vaccumulator___024root___eval(Vaccumulator___024root* vlSelf, Vaccumulator___024root* vlNext) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root___eval\n"); );
    // Body
    // Predict the next state when clk = 0 (negedge clk)
    if ((~(IData)(vlSelf->clk)) & (IData)(vlSelf->__Vclklast__TOP__clk)) {
        Vaccumulator___024root___predict (vlSelf, vlNext);
    }
    // Update the internal state only when clk = 1 (posedge clk)
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        // Run Vaccumulator___024root___sequent__TOP__0 on another thread with vlNext as an argument
        pthread_t thread;
        Vaccumulator___024root___sequent__TOP__0(vlSelf);
        pthread_create (&thread, NULL, &Vaccumulator___024root__sequent__NEXT__0, vlNext);
        pthread_join (thread, NULL);
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
