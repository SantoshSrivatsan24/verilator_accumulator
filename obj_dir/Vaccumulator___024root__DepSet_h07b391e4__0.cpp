// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaccumulator.h for the primary calling header

#include "verilated.h"

#include "Vaccumulator___024root.h"

// #include <iostream>
#include <pthread.h>

struct state_t {
    Vaccumulator___024root* vlPredict;
    Vaccumulator___024root* vlNext;
};

VL_INLINE_OPT void Vaccumulator___024root___sequent__TOP__0(Vaccumulator___024root* vlSelf) {

    // std::cout<<"(vlSelf BEFORE EVAL): accumulator__DOT__dff = "<<(int)vlSelf->accumulator__DOT__dff<<'\n';

    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->accumulator__DOT__dff = ((IData)(vlSelf->reset)
                                      ? 0U : (0xffU 
                                              & ((IData)(vlSelf->in) 
                                                 + (IData)(vlSelf->out))));
    vlSelf->out = vlSelf->accumulator__DOT__dff;

    // std::cout<<"(vlSelf AFTER EVAL): accumulator__DOT__dff = "<<(int)vlSelf->accumulator__DOT__dff<<'\n';
}

/////////////////////////////////////////////

static void Vaccumulator___024root___predict(Vaccumulator___024root* vlSelf, Vaccumulator___024root* vlPredict) {

    // Copy the current state to the next state. Uses operator overloading
    *vlPredict = *vlSelf;

    // Predict the next state
    vlPredict->accumulator__DOT__dff += 1;

    // Modify output of predicted state based on the prediction
    vlPredict->out = vlPredict->accumulator__DOT__dff;

    // std::cout<<"(vlPredict): accumulator__DOT__dff = "<<(int)vlPredict->accumulator__DOT__dff<<'\n';
}

void *Vaccumulator___024root__sequent__NEXT__0(void *args) {

    // The next state is based on some prediction on the current state
    state_t *state = (state_t *) args;
    Vaccumulator___024root* vlPredict = state->vlPredict;
    Vaccumulator___024root* vlNext = state->vlNext;


    if (false && vlNext) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlPredict->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root___sequent__NEXT__0\n"); );
    // Body
    vlNext->accumulator__DOT__dff = ((IData)(vlPredict->reset)
                                      ? 0U : (0xffU 
                                              & ((IData)(vlPredict->in) 
                                                 + (IData)(vlPredict->out))));
    vlNext->out = vlNext->accumulator__DOT__dff;

    // std::cout<<"(vlNext AFTER EVAL): accumulator__DOT__dff = "<<(int)vlNext->accumulator__DOT__dff<<'\n';

    pthread_exit (NULL);
}

static void Vaccumulator___024root___check (Vaccumulator___024root* vlSelf, Vaccumulator___024root* vlPredict, Vaccumulator___024root* vlNext) {

    extern uint64_t timestamp; // must be declared in sim_main.cpp (i.e. accumulator.cpp)
    // std::cout<<"(check): ";
    // If prediction is correct, vlSelf = vlNext
    if (*vlSelf == *vlPredict) {
        // std::cout<<"Our prediction was CORRECT!\n"; 
        *vlSelf = *vlNext; // Copy result of eval on vlPredict (i.e. vlNext) to vlSelf
        timestamp += 2; // We also need to increment the no. of cycles everytime a prediction is correct
    } else {
        // std::cout<<"Our prediction was WRONG\n";
    }
}

/////////////////////////////////////////////

void Vaccumulator___024root___eval(Vaccumulator___024root* vlSelf, Vaccumulator___024root* vlNext, Vaccumulator___024root* vlPredict) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root___eval\n"); );
    // Body
    // Update the internal state only when clk = 1 (posedge clk)
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        // std::cout<<"====== clk = 1 ======\n";
        // Run Vaccumulator___024root___sequent__NEXT__0 on another thread with vlNext as an argument

        // What if I want to create a new thread every 10 cycles instead of every cycle
        // How would I do that?
        pthread_t thread;
        // This function should create a new object of type Vaccumulator__024root and return a pointer to it
        // Why do we introduce two new states?
        // Because NEXT () is going to act on the predicted state `vlPredict` and change it
        // We want to preserve the old value of the predicted state so that we can do a comparison
        // This is why we store the result of eval() in a new state called `vlNext`
        state_t state = {vlPredict, vlNext};
        pthread_create (&thread, NULL, &Vaccumulator___024root__sequent__NEXT__0, &state);
        Vaccumulator___024root___sequent__TOP__0(vlSelf);
        pthread_join (thread, NULL);
        // Compare current state (after `eval()`) and predicted state here
        // Update current state based on the above comparison
        // This is the function that skips ahead and gives us performance
        Vaccumulator___024root___check (vlSelf, vlPredict, vlNext);
    }
    // Predict the next state when clk = 0 (negedge clk)
    else {
        // std::cout<<"\n====== clk = 0 ======\n";
        Vaccumulator___024root___predict (vlSelf, vlPredict);
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
