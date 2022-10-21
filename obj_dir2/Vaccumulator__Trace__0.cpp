// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vaccumulator__Syms.h"


void Vaccumulator___024root__trace_chg_sub_0(Vaccumulator___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vaccumulator___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root__trace_chg_top_0\n"); );
    // Init
    Vaccumulator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaccumulator___024root*>(voidSelf);
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vaccumulator___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vaccumulator___024root__trace_chg_sub_0(Vaccumulator___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgBit(oldp+1,(vlSelf->reset));
    bufp->chgCData(oldp+2,(vlSelf->in),8);
    bufp->chgCData(oldp+3,(vlSelf->out),8);
    bufp->chgCData(oldp+4,(vlSelf->accumulator__DOT__dff),8);
}

void Vaccumulator___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccumulator___024root__trace_cleanup\n"); );
    // Init
    Vaccumulator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaccumulator___024root*>(voidSelf);
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
