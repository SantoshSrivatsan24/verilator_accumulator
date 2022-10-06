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

// Returns predicted state
static void *predict(void *args) {

    Vaccumulator___024root *CURRENT_STATE = (Vaccumulator___024root *) args;

    std::cout<<"CURRENT STATE: in = "<<(int) CURRENT_STATE->in<<" dff = "<<(int) CURRENT_STATE->accumulator__DOT__dff<<" out = "<<(int) CURRENT_STATE->out<<'\n';

    // Copy current state to another state so it can be modified without affecting the original state
    Vaccumulator___024root *NEXT_STATE = new Vaccumulator___024root (CURRENT_STATE);

    // Right now the next state is a copy of the current state
    // TODO: Modify the next state here
    NEXT_STATE->accumulator__DOT__dff += 1;

    std::cout<<"NEXT STATE: in = "<<(int) NEXT_STATE->in<<" dff = "<<(int) NEXT_STATE->accumulator__DOT__dff<<" out = "<<(int) NEXT_STATE->out<<'\n';

    pthread_exit (NULL);
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
        pthread_t thread;
        // Create a new thread that executes the function `predict()`
        // Takes the current state as an argument. Predicts new state based on current state and inputs
        // Calls Vaccumulator___024root___eval by passing the predicted state
        // Returns predicted state and the state as a result of the prediction
        pthread_create (&thread, NULL, &predict, &(vlSymsp->TOP));
        // Wait for the created thread to terminate
        Vaccumulator___024root___eval(&(vlSymsp->TOP));
        pthread_join (thread, NULL);
        // Compare actual state and predicted state
        // If they are the same, skip the computation of the next state by the main thread
        // Skip ahead to the state that is the result of the prediction
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
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vaccumulator___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
