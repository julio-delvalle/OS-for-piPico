# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\RaspberryPiPico\pico-sdk\tools\pioasm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\RaspberryPiPico\pico-projects\build\pioasm

# Include any dependencies generated for this target.
include CMakeFiles\pioasm.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\pioasm.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\pioasm.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\pioasm.dir\flags.make

CMakeFiles\pioasm.dir\main.cpp.obj: CMakeFiles\pioasm.dir\flags.make
CMakeFiles\pioasm.dir\main.cpp.obj: C:\RaspberryPiPico\pico-sdk\tools\pioasm\main.cpp
CMakeFiles\pioasm.dir\main.cpp.obj: CMakeFiles\pioasm.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\RaspberryPiPico\pico-projects\build\pioasm\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pioasm.dir/main.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\pioasm.dir\main.cpp.obj.d --working-dir=C:\RaspberryPiPico\pico-projects\build\pioasm --filter-prefix="Nota: inclusi�n del archivo: " -- "C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\pioasm.dir\main.cpp.obj /FdCMakeFiles\pioasm.dir\ /FS -c C:\RaspberryPiPico\pico-sdk\tools\pioasm\main.cpp
<<

CMakeFiles\pioasm.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/main.cpp.i"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" > CMakeFiles\pioasm.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\RaspberryPiPico\pico-sdk\tools\pioasm\main.cpp
<<

CMakeFiles\pioasm.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/main.cpp.s"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\pioasm.dir\main.cpp.s /c C:\RaspberryPiPico\pico-sdk\tools\pioasm\main.cpp
<<

CMakeFiles\pioasm.dir\pio_assembler.cpp.obj: CMakeFiles\pioasm.dir\flags.make
CMakeFiles\pioasm.dir\pio_assembler.cpp.obj: C:\RaspberryPiPico\pico-sdk\tools\pioasm\pio_assembler.cpp
CMakeFiles\pioasm.dir\pio_assembler.cpp.obj: CMakeFiles\pioasm.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\RaspberryPiPico\pico-projects\build\pioasm\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pioasm.dir/pio_assembler.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\pioasm.dir\pio_assembler.cpp.obj.d --working-dir=C:\RaspberryPiPico\pico-projects\build\pioasm --filter-prefix="Nota: inclusi�n del archivo: " -- "C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\pioasm.dir\pio_assembler.cpp.obj /FdCMakeFiles\pioasm.dir\ /FS -c C:\RaspberryPiPico\pico-sdk\tools\pioasm\pio_assembler.cpp
<<

CMakeFiles\pioasm.dir\pio_assembler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/pio_assembler.cpp.i"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" > CMakeFiles\pioasm.dir\pio_assembler.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\RaspberryPiPico\pico-sdk\tools\pioasm\pio_assembler.cpp
<<

CMakeFiles\pioasm.dir\pio_assembler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/pio_assembler.cpp.s"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\pioasm.dir\pio_assembler.cpp.s /c C:\RaspberryPiPico\pico-sdk\tools\pioasm\pio_assembler.cpp
<<

CMakeFiles\pioasm.dir\pio_disassembler.cpp.obj: CMakeFiles\pioasm.dir\flags.make
CMakeFiles\pioasm.dir\pio_disassembler.cpp.obj: C:\RaspberryPiPico\pico-sdk\tools\pioasm\pio_disassembler.cpp
CMakeFiles\pioasm.dir\pio_disassembler.cpp.obj: CMakeFiles\pioasm.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\RaspberryPiPico\pico-projects\build\pioasm\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/pioasm.dir/pio_disassembler.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\pioasm.dir\pio_disassembler.cpp.obj.d --working-dir=C:\RaspberryPiPico\pico-projects\build\pioasm --filter-prefix="Nota: inclusi�n del archivo: " -- "C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\pioasm.dir\pio_disassembler.cpp.obj /FdCMakeFiles\pioasm.dir\ /FS -c C:\RaspberryPiPico\pico-sdk\tools\pioasm\pio_disassembler.cpp
<<

CMakeFiles\pioasm.dir\pio_disassembler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/pio_disassembler.cpp.i"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" > CMakeFiles\pioasm.dir\pio_disassembler.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\RaspberryPiPico\pico-sdk\tools\pioasm\pio_disassembler.cpp
<<

CMakeFiles\pioasm.dir\pio_disassembler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/pio_disassembler.cpp.s"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\pioasm.dir\pio_disassembler.cpp.s /c C:\RaspberryPiPico\pico-sdk\tools\pioasm\pio_disassembler.cpp
<<

CMakeFiles\pioasm.dir\gen\lexer.cpp.obj: CMakeFiles\pioasm.dir\flags.make
CMakeFiles\pioasm.dir\gen\lexer.cpp.obj: C:\RaspberryPiPico\pico-sdk\tools\pioasm\gen\lexer.cpp
CMakeFiles\pioasm.dir\gen\lexer.cpp.obj: CMakeFiles\pioasm.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\RaspberryPiPico\pico-projects\build\pioasm\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/pioasm.dir/gen/lexer.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\pioasm.dir\gen\lexer.cpp.obj.d --working-dir=C:\RaspberryPiPico\pico-projects\build\pioasm --filter-prefix="Nota: inclusi�n del archivo: " -- "C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\pioasm.dir\gen\lexer.cpp.obj /FdCMakeFiles\pioasm.dir\ /FS -c C:\RaspberryPiPico\pico-sdk\tools\pioasm\gen\lexer.cpp
<<

CMakeFiles\pioasm.dir\gen\lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/gen/lexer.cpp.i"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" > CMakeFiles\pioasm.dir\gen\lexer.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\RaspberryPiPico\pico-sdk\tools\pioasm\gen\lexer.cpp
<<

CMakeFiles\pioasm.dir\gen\lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/gen/lexer.cpp.s"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\pioasm.dir\gen\lexer.cpp.s /c C:\RaspberryPiPico\pico-sdk\tools\pioasm\gen\lexer.cpp
<<

CMakeFiles\pioasm.dir\gen\parser.cpp.obj: CMakeFiles\pioasm.dir\flags.make
CMakeFiles\pioasm.dir\gen\parser.cpp.obj: C:\RaspberryPiPico\pico-sdk\tools\pioasm\gen\parser.cpp
CMakeFiles\pioasm.dir\gen\parser.cpp.obj: CMakeFiles\pioasm.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\RaspberryPiPico\pico-projects\build\pioasm\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/pioasm.dir/gen/parser.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\pioasm.dir\gen\parser.cpp.obj.d --working-dir=C:\RaspberryPiPico\pico-projects\build\pioasm --filter-prefix="Nota: inclusi�n del archivo: " -- "C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\pioasm.dir\gen\parser.cpp.obj /FdCMakeFiles\pioasm.dir\ /FS -c C:\RaspberryPiPico\pico-sdk\tools\pioasm\gen\parser.cpp
<<

CMakeFiles\pioasm.dir\gen\parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/gen/parser.cpp.i"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" > CMakeFiles\pioasm.dir\gen\parser.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\RaspberryPiPico\pico-sdk\tools\pioasm\gen\parser.cpp
<<

CMakeFiles\pioasm.dir\gen\parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/gen/parser.cpp.s"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\pioasm.dir\gen\parser.cpp.s /c C:\RaspberryPiPico\pico-sdk\tools\pioasm\gen\parser.cpp
<<

CMakeFiles\pioasm.dir\c_sdk_output.cpp.obj: CMakeFiles\pioasm.dir\flags.make
CMakeFiles\pioasm.dir\c_sdk_output.cpp.obj: C:\RaspberryPiPico\pico-sdk\tools\pioasm\c_sdk_output.cpp
CMakeFiles\pioasm.dir\c_sdk_output.cpp.obj: CMakeFiles\pioasm.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\RaspberryPiPico\pico-projects\build\pioasm\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/pioasm.dir/c_sdk_output.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\pioasm.dir\c_sdk_output.cpp.obj.d --working-dir=C:\RaspberryPiPico\pico-projects\build\pioasm --filter-prefix="Nota: inclusi�n del archivo: " -- "C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\pioasm.dir\c_sdk_output.cpp.obj /FdCMakeFiles\pioasm.dir\ /FS -c C:\RaspberryPiPico\pico-sdk\tools\pioasm\c_sdk_output.cpp
<<

CMakeFiles\pioasm.dir\c_sdk_output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/c_sdk_output.cpp.i"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" > CMakeFiles\pioasm.dir\c_sdk_output.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\RaspberryPiPico\pico-sdk\tools\pioasm\c_sdk_output.cpp
<<

CMakeFiles\pioasm.dir\c_sdk_output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/c_sdk_output.cpp.s"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\pioasm.dir\c_sdk_output.cpp.s /c C:\RaspberryPiPico\pico-sdk\tools\pioasm\c_sdk_output.cpp
<<

CMakeFiles\pioasm.dir\python_output.cpp.obj: CMakeFiles\pioasm.dir\flags.make
CMakeFiles\pioasm.dir\python_output.cpp.obj: C:\RaspberryPiPico\pico-sdk\tools\pioasm\python_output.cpp
CMakeFiles\pioasm.dir\python_output.cpp.obj: CMakeFiles\pioasm.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\RaspberryPiPico\pico-projects\build\pioasm\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/pioasm.dir/python_output.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\pioasm.dir\python_output.cpp.obj.d --working-dir=C:\RaspberryPiPico\pico-projects\build\pioasm --filter-prefix="Nota: inclusi�n del archivo: " -- "C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\pioasm.dir\python_output.cpp.obj /FdCMakeFiles\pioasm.dir\ /FS -c C:\RaspberryPiPico\pico-sdk\tools\pioasm\python_output.cpp
<<

CMakeFiles\pioasm.dir\python_output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/python_output.cpp.i"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" > CMakeFiles\pioasm.dir\python_output.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\RaspberryPiPico\pico-sdk\tools\pioasm\python_output.cpp
<<

CMakeFiles\pioasm.dir\python_output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/python_output.cpp.s"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\pioasm.dir\python_output.cpp.s /c C:\RaspberryPiPico\pico-sdk\tools\pioasm\python_output.cpp
<<

CMakeFiles\pioasm.dir\hex_output.cpp.obj: CMakeFiles\pioasm.dir\flags.make
CMakeFiles\pioasm.dir\hex_output.cpp.obj: C:\RaspberryPiPico\pico-sdk\tools\pioasm\hex_output.cpp
CMakeFiles\pioasm.dir\hex_output.cpp.obj: CMakeFiles\pioasm.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\RaspberryPiPico\pico-projects\build\pioasm\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/pioasm.dir/hex_output.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\pioasm.dir\hex_output.cpp.obj.d --working-dir=C:\RaspberryPiPico\pico-projects\build\pioasm --filter-prefix="Nota: inclusi�n del archivo: " -- "C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\pioasm.dir\hex_output.cpp.obj /FdCMakeFiles\pioasm.dir\ /FS -c C:\RaspberryPiPico\pico-sdk\tools\pioasm\hex_output.cpp
<<

CMakeFiles\pioasm.dir\hex_output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/hex_output.cpp.i"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" > CMakeFiles\pioasm.dir\hex_output.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\RaspberryPiPico\pico-sdk\tools\pioasm\hex_output.cpp
<<

CMakeFiles\pioasm.dir\hex_output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/hex_output.cpp.s"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\pioasm.dir\hex_output.cpp.s /c C:\RaspberryPiPico\pico-sdk\tools\pioasm\hex_output.cpp
<<

CMakeFiles\pioasm.dir\ada_output.cpp.obj: CMakeFiles\pioasm.dir\flags.make
CMakeFiles\pioasm.dir\ada_output.cpp.obj: C:\RaspberryPiPico\pico-sdk\tools\pioasm\ada_output.cpp
CMakeFiles\pioasm.dir\ada_output.cpp.obj: CMakeFiles\pioasm.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\RaspberryPiPico\pico-projects\build\pioasm\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/pioasm.dir/ada_output.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\pioasm.dir\ada_output.cpp.obj.d --working-dir=C:\RaspberryPiPico\pico-projects\build\pioasm --filter-prefix="Nota: inclusi�n del archivo: " -- "C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\pioasm.dir\ada_output.cpp.obj /FdCMakeFiles\pioasm.dir\ /FS -c C:\RaspberryPiPico\pico-sdk\tools\pioasm\ada_output.cpp
<<

CMakeFiles\pioasm.dir\ada_output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/pioasm.dir/ada_output.cpp.i"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" > CMakeFiles\pioasm.dir\ada_output.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\RaspberryPiPico\pico-sdk\tools\pioasm\ada_output.cpp
<<

CMakeFiles\pioasm.dir\ada_output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/pioasm.dir/ada_output.cpp.s"
	"C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\pioasm.dir\ada_output.cpp.s /c C:\RaspberryPiPico\pico-sdk\tools\pioasm\ada_output.cpp
<<

# Object files for target pioasm
pioasm_OBJECTS = \
"CMakeFiles\pioasm.dir\main.cpp.obj" \
"CMakeFiles\pioasm.dir\pio_assembler.cpp.obj" \
"CMakeFiles\pioasm.dir\pio_disassembler.cpp.obj" \
"CMakeFiles\pioasm.dir\gen\lexer.cpp.obj" \
"CMakeFiles\pioasm.dir\gen\parser.cpp.obj" \
"CMakeFiles\pioasm.dir\c_sdk_output.cpp.obj" \
"CMakeFiles\pioasm.dir\python_output.cpp.obj" \
"CMakeFiles\pioasm.dir\hex_output.cpp.obj" \
"CMakeFiles\pioasm.dir\ada_output.cpp.obj"

# External object files for target pioasm
pioasm_EXTERNAL_OBJECTS =

pioasm.exe: CMakeFiles\pioasm.dir\main.cpp.obj
pioasm.exe: CMakeFiles\pioasm.dir\pio_assembler.cpp.obj
pioasm.exe: CMakeFiles\pioasm.dir\pio_disassembler.cpp.obj
pioasm.exe: CMakeFiles\pioasm.dir\gen\lexer.cpp.obj
pioasm.exe: CMakeFiles\pioasm.dir\gen\parser.cpp.obj
pioasm.exe: CMakeFiles\pioasm.dir\c_sdk_output.cpp.obj
pioasm.exe: CMakeFiles\pioasm.dir\python_output.cpp.obj
pioasm.exe: CMakeFiles\pioasm.dir\hex_output.cpp.obj
pioasm.exe: CMakeFiles\pioasm.dir\ada_output.cpp.obj
pioasm.exe: CMakeFiles\pioasm.dir\build.make
pioasm.exe: CMakeFiles\pioasm.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\RaspberryPiPico\pico-projects\build\pioasm\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable pioasm.exe"
	"C:\Program Files\CMake\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\pioasm.dir --rc="C:\PROGRA~2\Windows Kits\10\bin\10.0.22621.0\x86\rc.exe" --mt="C:\PROGRA~2\Windows Kits\10\bin\10.0.22621.0\x86\mt.exe" --manifests -- "C:\PROGRA~2\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.40.33807\bin\Hostx86\x86\link.exe" /nologo @CMakeFiles\pioasm.dir\objects1.rsp @<<
 /out:pioasm.exe /implib:pioasm.lib /pdb:C:\RaspberryPiPico\pico-projects\build\pioasm\pioasm.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\pioasm.dir\build: pioasm.exe
.PHONY : CMakeFiles\pioasm.dir\build

CMakeFiles\pioasm.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pioasm.dir\cmake_clean.cmake
.PHONY : CMakeFiles\pioasm.dir\clean

CMakeFiles\pioasm.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\RaspberryPiPico\pico-sdk\tools\pioasm C:\RaspberryPiPico\pico-sdk\tools\pioasm C:\RaspberryPiPico\pico-projects\build\pioasm C:\RaspberryPiPico\pico-projects\build\pioasm C:\RaspberryPiPico\pico-projects\build\pioasm\CMakeFiles\pioasm.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles\pioasm.dir\depend

