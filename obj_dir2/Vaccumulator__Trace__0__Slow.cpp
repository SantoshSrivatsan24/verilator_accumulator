// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vaccumulator__Syms.h"


VL_ATTR_COLD void Vaccumulator___024root__trace_init_sub__TOP__0(Vaccumulator___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"reset", false,-1);
    tracep->declBus(c+3,"in", false,-1, 7,0);
    tracep->declBus(c+4,"out", false,-1, 7,0);
    tracep->pushNamePrefix("accumulator ");
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"reset", false,-1);
    tracep->declBus(c+3,"in", false,-1, 7,0);
    tracep->declBus(c+4,"out", false,-1, 7,0);
    tracep->declBus(c+5,"dff", false,-1, 7,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vaccumulator___024root__trace_init_top(Vaccumulator___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root__trace_init_top\n"); );
    // Body
    Vaccumulator___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vaccumulator___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vaccumulator___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vaccumulator___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vaccumulator___024root__trace_register(Vaccumulator___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vaccumulator___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vaccumulator___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vaccumulator___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vaccumulator___024root__trace_full_sub_0(Vaccumulator___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vaccumulator___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root__trace_full_top_0\n"); );
    // Init
    Vaccumulator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaccumulator___024root*>(voidSelf);
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vaccumulator___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vaccumulator___024root__trace_full_sub_0(Vaccumulator___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->clk));
    bufp->fullBit(oldp+2,(vlSelf->reset));
    bufp->fullCData(oldp+3,(vlSelf->in),8);
    bufp->fullCData(oldp+4,(vlSelf->out),8);
    bufp->fullCData(oldp+5,(vlSelf->accumulator__DOT__dff),8);
}
