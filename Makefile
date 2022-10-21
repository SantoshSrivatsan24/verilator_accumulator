################################################
# Configurations for building accumulator

OBJ_DIR = ./obj_dir2
GRAPH_DIR = ./graphs

TOP = accumulator

VERILATOR_ROOT ?= /home/srsrivat/F22/GRA/verilator
VERILATOR = $(VERILATOR_ROOT)/bin/verilator_bin_dbg

VL_FLAGS += --top-module $(TOP) --cc $(TOP).sv --exe
VL_FLAGS += -O2 --language 1800-2009 --assert -Wall -Wpedantic
VL_FLAGS += -Wno-DECLFILENAME -Wno-REDEFMACRO
VL_FLAGS += --x-initial unique --x-assign unique
VL_FLAGS += --trace
# VL_FLAGS += --debug
VL_FLAGS += --Mdir $(OBJ_DIR)

# Enable verilator multithreaded simulation
ifdef VL_THREADED
VL_FLAGS += --threads 4
RUN_FLAGS += numactl -m 0 -C 0,1,2,3
else
VL_FLAGS += --no-threads
endif

SRCS = $(TOP).cpp
CXXFLAGS += -std=c++11 -Wall -Wextra -Wfatal-errors -Wno-array-bounds -Wno-maybe-uninitialized

ifdef DEBUG
CXXFLAGS += -g -O0
endif

################################################

default: build

gen: $(SRCS)
	@echo 
	@echo "### VERILATE ###"
	$(VERILATOR) $(VL_FLAGS) $^ -CFLAGS '$(CXXFLAGS)'

build: gen	
	@echo
	@echo "### BUILD ###"
	$(MAKE) -C $(OBJ_DIR) -j $$(nproc) -f V$(TOP).mk

run: $(OBJ_DIR)
	@echo
	@echo "### RUN ###"
	$(RUN_FLAGS) $(OBJ_DIR)/V$(TOP)

graph: $(OBJ_DIR) | $(GRAPH_DIR)
	@echo 
	@echo "### GRAPH ###"

waves: trace.vcd
	@echo
	@echo "### TRACE ###"
	gtkwave -o trace.vcd &

$(GRAPH_DIR):
	mkdir -p $(GRAPH_DIR)

clean:
	@echo
	@echo "### Don't remove obj_dir. Abort... ###"


