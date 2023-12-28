TARGET_PREFIX :=  aarch64-none-linux-gnu-

all: clean writer.o check_var
	@echo "Linking writer"
	$(COMPILER) -Wall -o writer writer.o

.PHONY: check_var
check_var:
ifeq ($(filter $(TARGET_PREFIX),$(CROSS_COMPILE)), $(TARGET_PREFIX))
COMPILER := @aarch64-none-linux-gnu-gcc
else
COMPILER := @gcc
endif

writer.o: writer.c
	@echo "Compiling writer"
	$(COMPILER) -Wall -c ./writer.c

.PHONY: debug
debug:
	@echo "debug" 

.PHONY: test
test: run_test
	@echo "test"

.PHONY: clean
clean: 
	@echo "Cleaning object files"
	@rm -rf *.o
