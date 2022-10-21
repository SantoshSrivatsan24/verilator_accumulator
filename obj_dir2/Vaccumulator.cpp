// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vaccumulator.h"
#include "Vaccumulator__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vaccumulator::Vaccumulator(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vaccumulator__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , in{vlSymsp->TOP.in}
    , out{vlSymsp->TOP.out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vaccumulator::Vaccumulator(const char* _vcname__)
    : Vaccumulator(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vaccumulator::~Vaccumulator() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vaccumulator___024root___eval_initial(Vaccumulator___024root* vlSelf);
void Vaccumulator___024root___eval_settle(Vaccumulator___024root* vlSelf);
void Vaccumulator___024root___eval(Vaccumulator___024root* vlSelf);
#ifdef VL_DEBUG
void Vaccumulator___024root___eval_debug_assertions(Vaccumulator___024root* vlSelf);
#endif  // VL_DEBUG
void Vaccumulator___024root___final(Vaccumulator___024root* vlSelf);

static void _eval_initial_loop(Vaccumulator__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vaccumulator___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vaccumulator___024root___eval_settle(&(vlSymsp->TOP));
        Vaccumulator___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vaccumulator::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vaccumulator::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vaccumulator___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    vlSymsp->__Vm_activity = true;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vaccumulator___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

const char* Vaccumulator::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vaccumulator::final() {
    Vaccumulator___024root___final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vaccumulator::hierName() const { return vlSymsp->name(); }
const char* Vaccumulator::modelName() const { return "Vaccumulator"; }
unsigned Vaccumulator::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vaccumulator::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vaccumulator___024root__trace_init_top(Vaccumulator___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vaccumulator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vaccumulator___024root*>(voidSelf);
    Vaccumulator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vaccumulator___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vaccumulator___024root__trace_register(Vaccumulator___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vaccumulator::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vaccumulator::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vaccumulator___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
