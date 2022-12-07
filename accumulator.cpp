#include <iostream>
#include <random>
#include <iomanip>
#include <time.h>
#include "accumulator.h"

#include <verilated.h>
#include <Vaccumulator.h>
#include <Vaccumulator__Syms.h>

#define SIM_TIME 20

uint64_t timestamp;

///////////////////////////////////////

int generate_rand (int min, int max) {
	int range = max - min + 1;
	return rand() % range + min;
}

///////////////////////////////////////

class Accumulator::Impl {

public:
    Impl();
    ~Impl();
    void run();

private:
    Vaccumulator *dut_;

    void eval();
    void step();
    void reset();
    void attach();
};

Accumulator::Impl::Impl()
    : dut_ (new Vaccumulator)
    {
    }

Accumulator::Impl::~Impl() {
    delete dut_;
}

void Accumulator::Impl::eval() {
    dut_->eval();
    timestamp++;
}

void Accumulator::Impl::step() {
    dut_->clk = 0;
    this->eval();
    dut_->clk = 1;
    this->eval();
}

void Accumulator::Impl::reset() {
    dut_->reset = 1;
    this->step();
    dut_->reset = 0;
    this->step();
}

void Accumulator::Impl::attach() {

    int in = 1;
    dut_->in = in;
    int out = dut_->out;
    // std::cout<<"In = "<<std::setw(3)<<in<<"\tAccumulate out = "<<std::setw(3)<<out<<std::endl;
}

void Accumulator::Impl::run() {

    this->reset();

    while (timestamp < SIM_TIME) {
        this->step();
        this->attach();
    }
    std::cout<<"=================================\n";
}

///////////////////////////////////////

Accumulator::Accumulator() 
    : impl_ (new Impl)
    {
        std::cout<<"This is an accumulator designed in RTL!\n";
    }

Accumulator::~Accumulator() {

    delete impl_;
}

void Accumulator::run() {

    impl_->run();
}

///////////////////////////////////////

// int main () {

//     clock_t start, end;
//     start = clock();
//     Accumulator *accumulator = new Accumulator();
//     accumulator->run();
//     delete accumulator;
//     end = clock();
//     double time = double (end - start) / CLOCKS_PER_SEC;
//     std::cout<<"Time = "<<time<<std::setprecision(5)<<std::endl;

//     return 0;
// }

///////////////////////////////////////