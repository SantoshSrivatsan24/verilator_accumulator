// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vaccumulator__Syms.h"
#include "Vaccumulator.h"
#include "Vaccumulator___024root.h"

// FUNCTIONS
Vaccumulator__Syms::~Vaccumulator__Syms()
{
}

Vaccumulator__Syms::Vaccumulator__Syms(VerilatedContext* contextp, const char* namep, Vaccumulator* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
