################################################
# Configurations for building accumulator

TOP = accumulator

VERILATOR_ROOT = /opt/verilator
VERILATOR = verilator

VL_FLAGS += --top-module $(TOP) --cc $(TOP).sv --exe
VL_FLAGS += -O2 --language 1800-2009 --assert -Wall -Wpedantic
VL_FLAGS += -Wno-DECLFILENAME -Wno-REDEFMACRO
VL_FLAGS += --x-initial unique --x-assign unique

SRCS = $(TOP).cpp
CXXFLAGS += -std=c++11 -Wall -Wextra -Wfatal-errors -Wno-array-bounds -Wno-maybe-uninitialized -fPIC

################################################

default: lib$(TOP).a

lib$(TOP).a: $(SRCS)
	$(VERILATOR) --build $(VL_FLAGS) $^ -CFLAGS '$(CXXFLAGS)' -LDFLAGS '-shared' -o ../$@ 

driver: $(PROJECT)
	@echo
	@echo "### BUILD ###"
	g++ -L. driver.cpp -o driver -laccumulator

run: driver
	@echo
	@echo "### RUN ###"
	./$^

# $(TOP): $(SRCS) driver.cpp
# 	$(VERILATOR) --build $(VL_FLAGS) $^ -CFLAGS '$(CXXFLAGS)' -o ../accum

# gen: $(SRCS)
# 	@echo 
# 	@echo "### VERILATE ###"
# 	$(VERILATOR) $(VL_FLAGS) $^ -CFLAGS '$(CXXFLAGS)'

# build: gen	
# 	@echo
# 	@echo "### BUILD ###"
# 	$(MAKE) -C obj_dir -j $$(nproc) -f V$(TOP).mk

# run: obj_dir
# 	@echo
# 	@echo "### RUN ###"
# 	$(RUN_FLAGS) obj_dir/V$(TOP)



clean:
	@echo
	@echo "### Clean ###"
	rm -rf obj_dir/ $(PROJECT)


