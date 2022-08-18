# Copyright (c) 2013 The Native Client Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

#
# GNU Make based build file.  For details on GNU Make see:
# http://www.gnu.org/software/make/manual/make.html
#
#
THIS_MAKEFILE := $(abspath $(lastword $(MAKEFILE_LIST)))
EM_SDK_ROOT ?= $(abspath $(dir $(THIS_MAKEFILE))../..)

# Project Build flags
WARNINGS := -Wall -Werror
CXXFLAGS := -std=c++11 -g $(WARNINGS) -sMODULARIZE=1 -sEXPORT_NAME="testWasmModuleReady"
LDFLAGS := --bind
PROFILEFLAGS := -sINLINING_LIMIT=50 --profiling-funcs --cpuprofiler
SOURCEMAP := --source-map-base http://localhost:8000/

CXX := $(abspath $(EM_SDK_ROOT))/em++
AR=$(abspath $(EM_SDK_ROOT))/emar
LINK=$(abspath $(EM_SDK_ROOT))/em++
LD=$(abspath $(EM_SDK_ROOT))/emrun
RANLIB=$(abspath $(EM_SDK_ROOT))/emranlib

#
# Disable DOS PATH warning when using Cygwin based tools Windows
#
CYGWIN ?= nodosfilewarning
export CYGWIN


# Declare the ALL target first, to make the 'all' target the default build
# all: hello_tutorial.js
all: hello_tutorial.js

clean:
	rm hello_tutorial.wasm
	rm hello_tutorial.js

hello_tutorial.js: hello_tutorial.cc
	$(CXX) -o $@ $< -O0 $(CXXFLAGS) $(LDFLAGS) $(PROFILEFLAGS)

