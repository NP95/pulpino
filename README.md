# PULPino

PULPino uses IPs from the PULP project to build a small-scale single-core SoC.
PULPino aims to be simple and lightweight, but still includes some advanced
features like debugging the core via JTAG.

It is currently compatible RTL simulation only, but it is planned to be
supported in FPGA and ASIC synthesis flows eventually.


## Requirements

PULPino has the following requirements

- ModelSim in reasonably recent version (we tested it with versions >= 10.2c)
- CMake >= 2.8.0, versions greater than 3.1.0 recommended due to support for ninja
- riscv-toolchain, specifically you need riscv32-unknown-elf-gcc compiler and friends

## Editions

There are two PULPino editions available, one for OR1K based on the OR10N core
and one for RISCV based on the RI5CY core.
The software included in this repository is compatible with both ISAs and
automatically targets the correct ISA based on the compiler used.

The simulator (modelsim) must be explicitely told which edition you want to build.
Use the environment variable `PULP_CORE` and set it to either OR10N or riscv. It
defaults to riscv when not set.



## Version Control

PULPino uses git submodules

To initialize all submodules

    git submodule update --init --recurisve

To update to the current versions

    git submodule update --recursive


## Documentation

There is a preliminary datasheet available that includes a block diagram and a memory map of PULPino.
See docs/datasheet/ in this repository.

It is written in LaTeX and there is no pdf included in the repository. Simply type

    make all

inside the folder to generate the pdf. Note that you need a working version of latex for this step.


## Running simulations

The software is built using CMake.
Create a build folder somewhere, e.g. in the sw folder

    mkdir build

Copy the cmake-configure.{or1k/riscv}.{gcc/llvm}.sh bash script to the build folder.
This script can be found in the sw subfolder of the git repository.

Modify the cmake-configure script to your needs and execute it inside the build folder.
This will setup everything to perform simulations using modelsim.

Inside the build folder, execute

    make vcompile

to compile the RTL libraries. CMake automatically takes care of setting the
`PULP_CORE` environment variable to the correct value based on the compiler you
specified when configuring cmake.

To run a simulation in the modelsim GUI use

    make helloworld_vsim


To run simulations in the modelsim console use

    make helloworld_vsim_batch

This will output a summary at the end of the simulation.
This is intended for batch processing of a large number of tests.

Replace helloworld with the test/application you want to run.


### Using ninja instead of make

You can use ninja instead make to build software for PULPino, just replace all
occurences of make with ninja.
The same targets are supported on both make and ninja.



## Debugging the core

To interactively debug the core via gdb, you need the jtag bridge as well as a
working version of gdb for the ISA you want to debug.

TODO: more information required



## FPGA

PULPino can be synthesized and run on a ZedBoard.
Take a look at the fpga subfolder for more information.
