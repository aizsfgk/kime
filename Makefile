# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zsf/Desktop/kime

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zsf/Desktop/kime

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/zsf/Desktop/kime/CMakeFiles /home/zsf/Desktop/kime/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/zsf/Desktop/kime/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named kime

# Build rule for target.
kime: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 kime
.PHONY : kime

# fast build rule for target.
kime/fast:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/build
.PHONY : kime/fast

dict.o: dict.c.o

.PHONY : dict.o

# target to build an object file
dict.c.o:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/dict.c.o
.PHONY : dict.c.o

dict.i: dict.c.i

.PHONY : dict.i

# target to preprocess a source file
dict.c.i:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/dict.c.i
.PHONY : dict.c.i

dict.s: dict.c.s

.PHONY : dict.s

# target to generate assembly for a file
dict.c.s:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/dict.c.s
.PHONY : dict.c.s

http.o: http.c.o

.PHONY : http.o

# target to build an object file
http.c.o:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/http.c.o
.PHONY : http.c.o

http.i: http.c.i

.PHONY : http.i

# target to preprocess a source file
http.c.i:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/http.c.i
.PHONY : http.c.i

http.s: http.c.s

.PHONY : http.s

# target to generate assembly for a file
http.c.s:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/http.c.s
.PHONY : http.c.s

http_server.o: http_server.c.o

.PHONY : http_server.o

# target to build an object file
http_server.c.o:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/http_server.c.o
.PHONY : http_server.c.o

http_server.i: http_server.c.i

.PHONY : http_server.i

# target to preprocess a source file
http_server.c.i:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/http_server.c.i
.PHONY : http_server.c.i

http_server.s: http_server.c.s

.PHONY : http_server.s

# target to generate assembly for a file
http_server.c.s:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/http_server.c.s
.PHONY : http_server.c.s

ioloop.o: ioloop.c.o

.PHONY : ioloop.o

# target to build an object file
ioloop.c.o:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/ioloop.c.o
.PHONY : ioloop.c.o

ioloop.i: ioloop.c.i

.PHONY : ioloop.i

# target to preprocess a source file
ioloop.c.i:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/ioloop.c.i
.PHONY : ioloop.c.i

ioloop.s: ioloop.c.s

.PHONY : ioloop.s

# target to generate assembly for a file
ioloop.c.s:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/ioloop.c.s
.PHONY : ioloop.c.s

kime.o: kime.c.o

.PHONY : kime.o

# target to build an object file
kime.c.o:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/kime.c.o
.PHONY : kime.c.o

kime.i: kime.c.i

.PHONY : kime.i

# target to preprocess a source file
kime.c.i:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/kime.c.i
.PHONY : kime.c.i

kime.s: kime.c.s

.PHONY : kime.s

# target to generate assembly for a file
kime.c.s:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/kime.c.s
.PHONY : kime.c.s

log.o: log.c.o

.PHONY : log.o

# target to build an object file
log.c.o:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/log.c.o
.PHONY : log.c.o

log.i: log.c.i

.PHONY : log.i

# target to preprocess a source file
log.c.i:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/log.c.i
.PHONY : log.c.i

log.s: log.c.s

.PHONY : log.s

# target to generate assembly for a file
log.c.s:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/log.c.s
.PHONY : log.c.s

mod_static.o: mod_static.c.o

.PHONY : mod_static.o

# target to build an object file
mod_static.c.o:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/mod_static.c.o
.PHONY : mod_static.c.o

mod_static.i: mod_static.c.i

.PHONY : mod_static.i

# target to preprocess a source file
mod_static.c.i:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/mod_static.c.i
.PHONY : mod_static.c.i

mod_static.s: mod_static.c.s

.PHONY : mod_static.s

# target to generate assembly for a file
mod_static.c.s:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/mod_static.c.s
.PHONY : mod_static.c.s

murmurhash2.o: murmurhash2.c.o

.PHONY : murmurhash2.o

# target to build an object file
murmurhash2.c.o:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/murmurhash2.c.o
.PHONY : murmurhash2.c.o

murmurhash2.i: murmurhash2.c.i

.PHONY : murmurhash2.i

# target to preprocess a source file
murmurhash2.c.i:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/murmurhash2.c.i
.PHONY : murmurhash2.c.i

murmurhash2.s: murmurhash2.c.s

.PHONY : murmurhash2.s

# target to generate assembly for a file
murmurhash2.c.s:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/murmurhash2.c.s
.PHONY : murmurhash2.c.s

option.o: option.c.o

.PHONY : option.o

# target to build an object file
option.c.o:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/option.c.o
.PHONY : option.c.o

option.i: option.c.i

.PHONY : option.i

# target to preprocess a source file
option.c.i:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/option.c.i
.PHONY : option.c.i

option.s: option.c.s

.PHONY : option.s

# target to generate assembly for a file
option.c.s:
	$(MAKE) -f CMakeFiles/kime.dir/build.make CMakeFiles/kime.dir/option.c.s
.PHONY : option.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... kime"
	@echo "... edit_cache"
	@echo "... dict.o"
	@echo "... dict.i"
	@echo "... dict.s"
	@echo "... http.o"
	@echo "... http.i"
	@echo "... http.s"
	@echo "... http_server.o"
	@echo "... http_server.i"
	@echo "... http_server.s"
	@echo "... ioloop.o"
	@echo "... ioloop.i"
	@echo "... ioloop.s"
	@echo "... kime.o"
	@echo "... kime.i"
	@echo "... kime.s"
	@echo "... log.o"
	@echo "... log.i"
	@echo "... log.s"
	@echo "... mod_static.o"
	@echo "... mod_static.i"
	@echo "... mod_static.s"
	@echo "... murmurhash2.o"
	@echo "... murmurhash2.i"
	@echo "... murmurhash2.s"
	@echo "... option.o"
	@echo "... option.i"
	@echo "... option.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
