# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = "E:\CLion 2022.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2022.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\QtProject\image_process

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\QtProject\image_process\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles\image_process.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\image_process.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\image_process.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\image_process.dir\flags.make

image_process_autogen\6WJNPILU4A\qrc_resource.cpp: ..\resource\resource.qrc
image_process_autogen\6WJNPILU4A\qrc_resource.cpp: CMakeFiles\image_process_autogen.dir\AutoRcc_resource_6WJNPILU4A_Info.json
image_process_autogen\6WJNPILU4A\qrc_resource.cpp: ..\resource\detect.png
image_process_autogen\6WJNPILU4A\qrc_resource.cpp: ..\resource\save.png
image_process_autogen\6WJNPILU4A\qrc_resource.cpp: ..\resource\DrawPolyLines.png
image_process_autogen\6WJNPILU4A\qrc_resource.cpp: ..\resource\edit.png
image_process_autogen\6WJNPILU4A\qrc_resource.cpp: ..\resource\revocation.png
image_process_autogen\6WJNPILU4A\qrc_resource.cpp: ..\resource\DrawRect.png
image_process_autogen\6WJNPILU4A\qrc_resource.cpp: ..\resource\editModel.png
image_process_autogen\6WJNPILU4A\qrc_resource.cpp: ..\resource\eraser.png
image_process_autogen\6WJNPILU4A\qrc_resource.cpp: E:\qt\5.9.5\msvc2017_64\bin\rcc.exe
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=G:\QtProject\image_process\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for resource/resource.qrc"
	echo >nul && "E:\CLion 2022.2\bin\cmake\win\bin\cmake.exe" -E cmake_autorcc G:/QtProject/image_process/cmake-build-release/CMakeFiles/image_process_autogen.dir/AutoRcc_resource_6WJNPILU4A_Info.json Release

CMakeFiles\image_process.dir\image_process_autogen\mocs_compilation.cpp.obj: CMakeFiles\image_process.dir\flags.make
CMakeFiles\image_process.dir\image_process_autogen\mocs_compilation.cpp.obj: image_process_autogen\mocs_compilation.cpp
CMakeFiles\image_process.dir\image_process_autogen\mocs_compilation.cpp.obj: CMakeFiles\image_process.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\QtProject\image_process\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/image_process.dir/image_process_autogen/mocs_compilation.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\image_process.dir\image_process_autogen\mocs_compilation.cpp.obj.d --working-dir=G:\QtProject\image_process\cmake-build-release --filter-prefix="注意: 包含文件:  " -- G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\image_process.dir\image_process_autogen\mocs_compilation.cpp.obj /FdCMakeFiles\image_process.dir\ /FS -c G:\QtProject\image_process\cmake-build-release\image_process_autogen\mocs_compilation.cpp
<<

CMakeFiles\image_process.dir\image_process_autogen\mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_process.dir/image_process_autogen/mocs_compilation.cpp.i"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe > CMakeFiles\image_process.dir\image_process_autogen\mocs_compilation.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\QtProject\image_process\cmake-build-release\image_process_autogen\mocs_compilation.cpp
<<

CMakeFiles\image_process.dir\image_process_autogen\mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_process.dir/image_process_autogen/mocs_compilation.cpp.s"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\image_process.dir\image_process_autogen\mocs_compilation.cpp.s /c G:\QtProject\image_process\cmake-build-release\image_process_autogen\mocs_compilation.cpp
<<

CMakeFiles\image_process.dir\main.cpp.obj: CMakeFiles\image_process.dir\flags.make
CMakeFiles\image_process.dir\main.cpp.obj: ..\main.cpp
CMakeFiles\image_process.dir\main.cpp.obj: CMakeFiles\image_process.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\QtProject\image_process\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/image_process.dir/main.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\image_process.dir\main.cpp.obj.d --working-dir=G:\QtProject\image_process\cmake-build-release --filter-prefix="注意: 包含文件:  " -- G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\image_process.dir\main.cpp.obj /FdCMakeFiles\image_process.dir\ /FS -c G:\QtProject\image_process\main.cpp
<<

CMakeFiles\image_process.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_process.dir/main.cpp.i"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe > CMakeFiles\image_process.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\QtProject\image_process\main.cpp
<<

CMakeFiles\image_process.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_process.dir/main.cpp.s"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\image_process.dir\main.cpp.s /c G:\QtProject\image_process\main.cpp
<<

CMakeFiles\image_process.dir\widget.cpp.obj: CMakeFiles\image_process.dir\flags.make
CMakeFiles\image_process.dir\widget.cpp.obj: ..\widget.cpp
CMakeFiles\image_process.dir\widget.cpp.obj: CMakeFiles\image_process.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\QtProject\image_process\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/image_process.dir/widget.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\image_process.dir\widget.cpp.obj.d --working-dir=G:\QtProject\image_process\cmake-build-release --filter-prefix="注意: 包含文件:  " -- G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\image_process.dir\widget.cpp.obj /FdCMakeFiles\image_process.dir\ /FS -c G:\QtProject\image_process\widget.cpp
<<

CMakeFiles\image_process.dir\widget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_process.dir/widget.cpp.i"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe > CMakeFiles\image_process.dir\widget.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\QtProject\image_process\widget.cpp
<<

CMakeFiles\image_process.dir\widget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_process.dir/widget.cpp.s"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\image_process.dir\widget.cpp.s /c G:\QtProject\image_process\widget.cpp
<<

CMakeFiles\image_process.dir\MyLabel.cpp.obj: CMakeFiles\image_process.dir\flags.make
CMakeFiles\image_process.dir\MyLabel.cpp.obj: ..\MyLabel.cpp
CMakeFiles\image_process.dir\MyLabel.cpp.obj: CMakeFiles\image_process.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\QtProject\image_process\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/image_process.dir/MyLabel.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\image_process.dir\MyLabel.cpp.obj.d --working-dir=G:\QtProject\image_process\cmake-build-release --filter-prefix="注意: 包含文件:  " -- G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\image_process.dir\MyLabel.cpp.obj /FdCMakeFiles\image_process.dir\ /FS -c G:\QtProject\image_process\MyLabel.cpp
<<

CMakeFiles\image_process.dir\MyLabel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_process.dir/MyLabel.cpp.i"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe > CMakeFiles\image_process.dir\MyLabel.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\QtProject\image_process\MyLabel.cpp
<<

CMakeFiles\image_process.dir\MyLabel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_process.dir/MyLabel.cpp.s"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\image_process.dir\MyLabel.cpp.s /c G:\QtProject\image_process\MyLabel.cpp
<<

CMakeFiles\image_process.dir\Image_adjust\image_adjust.cpp.obj: CMakeFiles\image_process.dir\flags.make
CMakeFiles\image_process.dir\Image_adjust\image_adjust.cpp.obj: ..\Image_adjust\image_adjust.cpp
CMakeFiles\image_process.dir\Image_adjust\image_adjust.cpp.obj: CMakeFiles\image_process.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\QtProject\image_process\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/image_process.dir/Image_adjust/image_adjust.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\image_process.dir\Image_adjust\image_adjust.cpp.obj.d --working-dir=G:\QtProject\image_process\cmake-build-release --filter-prefix="注意: 包含文件:  " -- G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\image_process.dir\Image_adjust\image_adjust.cpp.obj /FdCMakeFiles\image_process.dir\ /FS -c G:\QtProject\image_process\Image_adjust\image_adjust.cpp
<<

CMakeFiles\image_process.dir\Image_adjust\image_adjust.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_process.dir/Image_adjust/image_adjust.cpp.i"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe > CMakeFiles\image_process.dir\Image_adjust\image_adjust.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\QtProject\image_process\Image_adjust\image_adjust.cpp
<<

CMakeFiles\image_process.dir\Image_adjust\image_adjust.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_process.dir/Image_adjust/image_adjust.cpp.s"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\image_process.dir\Image_adjust\image_adjust.cpp.s /c G:\QtProject\image_process\Image_adjust\image_adjust.cpp
<<

CMakeFiles\image_process.dir\energy\energy.cpp.obj: CMakeFiles\image_process.dir\flags.make
CMakeFiles\image_process.dir\energy\energy.cpp.obj: ..\energy\energy.cpp
CMakeFiles\image_process.dir\energy\energy.cpp.obj: CMakeFiles\image_process.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\QtProject\image_process\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/image_process.dir/energy/energy.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\image_process.dir\energy\energy.cpp.obj.d --working-dir=G:\QtProject\image_process\cmake-build-release --filter-prefix="注意: 包含文件:  " -- G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\image_process.dir\energy\energy.cpp.obj /FdCMakeFiles\image_process.dir\ /FS -c G:\QtProject\image_process\energy\energy.cpp
<<

CMakeFiles\image_process.dir\energy\energy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_process.dir/energy/energy.cpp.i"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe > CMakeFiles\image_process.dir\energy\energy.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\QtProject\image_process\energy\energy.cpp
<<

CMakeFiles\image_process.dir\energy\energy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_process.dir/energy/energy.cpp.s"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\image_process.dir\energy\energy.cpp.s /c G:\QtProject\image_process\energy\energy.cpp
<<

CMakeFiles\image_process.dir\graphics\graphics.cpp.obj: CMakeFiles\image_process.dir\flags.make
CMakeFiles\image_process.dir\graphics\graphics.cpp.obj: ..\graphics\graphics.cpp
CMakeFiles\image_process.dir\graphics\graphics.cpp.obj: CMakeFiles\image_process.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\QtProject\image_process\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/image_process.dir/graphics/graphics.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\image_process.dir\graphics\graphics.cpp.obj.d --working-dir=G:\QtProject\image_process\cmake-build-release --filter-prefix="注意: 包含文件:  " -- G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\image_process.dir\graphics\graphics.cpp.obj /FdCMakeFiles\image_process.dir\ /FS -c G:\QtProject\image_process\graphics\graphics.cpp
<<

CMakeFiles\image_process.dir\graphics\graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_process.dir/graphics/graphics.cpp.i"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe > CMakeFiles\image_process.dir\graphics\graphics.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\QtProject\image_process\graphics\graphics.cpp
<<

CMakeFiles\image_process.dir\graphics\graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_process.dir/graphics/graphics.cpp.s"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\image_process.dir\graphics\graphics.cpp.s /c G:\QtProject\image_process\graphics\graphics.cpp
<<

CMakeFiles\image_process.dir\graphics\graphicsview.cpp.obj: CMakeFiles\image_process.dir\flags.make
CMakeFiles\image_process.dir\graphics\graphicsview.cpp.obj: ..\graphics\graphicsview.cpp
CMakeFiles\image_process.dir\graphics\graphicsview.cpp.obj: CMakeFiles\image_process.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\QtProject\image_process\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/image_process.dir/graphics/graphicsview.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\image_process.dir\graphics\graphicsview.cpp.obj.d --working-dir=G:\QtProject\image_process\cmake-build-release --filter-prefix="注意: 包含文件:  " -- G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\image_process.dir\graphics\graphicsview.cpp.obj /FdCMakeFiles\image_process.dir\ /FS -c G:\QtProject\image_process\graphics\graphicsview.cpp
<<

CMakeFiles\image_process.dir\graphics\graphicsview.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_process.dir/graphics/graphicsview.cpp.i"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe > CMakeFiles\image_process.dir\graphics\graphicsview.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\QtProject\image_process\graphics\graphicsview.cpp
<<

CMakeFiles\image_process.dir\graphics\graphicsview.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_process.dir/graphics/graphicsview.cpp.s"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\image_process.dir\graphics\graphicsview.cpp.s /c G:\QtProject\image_process\graphics\graphicsview.cpp
<<

CMakeFiles\image_process.dir\graphics\graphicsscene.cpp.obj: CMakeFiles\image_process.dir\flags.make
CMakeFiles\image_process.dir\graphics\graphicsscene.cpp.obj: ..\graphics\graphicsscene.cpp
CMakeFiles\image_process.dir\graphics\graphicsscene.cpp.obj: CMakeFiles\image_process.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\QtProject\image_process\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/image_process.dir/graphics/graphicsscene.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\image_process.dir\graphics\graphicsscene.cpp.obj.d --working-dir=G:\QtProject\image_process\cmake-build-release --filter-prefix="注意: 包含文件:  " -- G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\image_process.dir\graphics\graphicsscene.cpp.obj /FdCMakeFiles\image_process.dir\ /FS -c G:\QtProject\image_process\graphics\graphicsscene.cpp
<<

CMakeFiles\image_process.dir\graphics\graphicsscene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_process.dir/graphics/graphicsscene.cpp.i"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe > CMakeFiles\image_process.dir\graphics\graphicsscene.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\QtProject\image_process\graphics\graphicsscene.cpp
<<

CMakeFiles\image_process.dir\graphics\graphicsscene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_process.dir/graphics/graphicsscene.cpp.s"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\image_process.dir\graphics\graphicsscene.cpp.s /c G:\QtProject\image_process\graphics\graphicsscene.cpp
<<

CMakeFiles\image_process.dir\graphics\graphicsPathItem.cpp.obj: CMakeFiles\image_process.dir\flags.make
CMakeFiles\image_process.dir\graphics\graphicsPathItem.cpp.obj: ..\graphics\graphicsPathItem.cpp
CMakeFiles\image_process.dir\graphics\graphicsPathItem.cpp.obj: CMakeFiles\image_process.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\QtProject\image_process\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/image_process.dir/graphics/graphicsPathItem.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\image_process.dir\graphics\graphicsPathItem.cpp.obj.d --working-dir=G:\QtProject\image_process\cmake-build-release --filter-prefix="注意: 包含文件:  " -- G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\image_process.dir\graphics\graphicsPathItem.cpp.obj /FdCMakeFiles\image_process.dir\ /FS -c G:\QtProject\image_process\graphics\graphicsPathItem.cpp
<<

CMakeFiles\image_process.dir\graphics\graphicsPathItem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_process.dir/graphics/graphicsPathItem.cpp.i"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe > CMakeFiles\image_process.dir\graphics\graphicsPathItem.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\QtProject\image_process\graphics\graphicsPathItem.cpp
<<

CMakeFiles\image_process.dir\graphics\graphicsPathItem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_process.dir/graphics/graphicsPathItem.cpp.s"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\image_process.dir\graphics\graphicsPathItem.cpp.s /c G:\QtProject\image_process\graphics\graphicsPathItem.cpp
<<

CMakeFiles\image_process.dir\image_process_autogen\6WJNPILU4A\qrc_resource.cpp.obj: CMakeFiles\image_process.dir\flags.make
CMakeFiles\image_process.dir\image_process_autogen\6WJNPILU4A\qrc_resource.cpp.obj: image_process_autogen\6WJNPILU4A\qrc_resource.cpp
CMakeFiles\image_process.dir\image_process_autogen\6WJNPILU4A\qrc_resource.cpp.obj: CMakeFiles\image_process.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\QtProject\image_process\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/image_process.dir/image_process_autogen/6WJNPILU4A/qrc_resource.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\image_process.dir\image_process_autogen\6WJNPILU4A\qrc_resource.cpp.obj.d --working-dir=G:\QtProject\image_process\cmake-build-release --filter-prefix="注意: 包含文件:  " -- G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\image_process.dir\image_process_autogen\6WJNPILU4A\qrc_resource.cpp.obj /FdCMakeFiles\image_process.dir\ /FS -c G:\QtProject\image_process\cmake-build-release\image_process_autogen\6WJNPILU4A\qrc_resource.cpp
<<

CMakeFiles\image_process.dir\image_process_autogen\6WJNPILU4A\qrc_resource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image_process.dir/image_process_autogen/6WJNPILU4A/qrc_resource.cpp.i"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe > CMakeFiles\image_process.dir\image_process_autogen\6WJNPILU4A\qrc_resource.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\QtProject\image_process\cmake-build-release\image_process_autogen\6WJNPILU4A\qrc_resource.cpp
<<

CMakeFiles\image_process.dir\image_process_autogen\6WJNPILU4A\qrc_resource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image_process.dir/image_process_autogen/6WJNPILU4A/qrc_resource.cpp.s"
	G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\image_process.dir\image_process_autogen\6WJNPILU4A\qrc_resource.cpp.s /c G:\QtProject\image_process\cmake-build-release\image_process_autogen\6WJNPILU4A\qrc_resource.cpp
<<

# Object files for target image_process
image_process_OBJECTS = \
"CMakeFiles\image_process.dir\image_process_autogen\mocs_compilation.cpp.obj" \
"CMakeFiles\image_process.dir\main.cpp.obj" \
"CMakeFiles\image_process.dir\widget.cpp.obj" \
"CMakeFiles\image_process.dir\MyLabel.cpp.obj" \
"CMakeFiles\image_process.dir\Image_adjust\image_adjust.cpp.obj" \
"CMakeFiles\image_process.dir\energy\energy.cpp.obj" \
"CMakeFiles\image_process.dir\graphics\graphics.cpp.obj" \
"CMakeFiles\image_process.dir\graphics\graphicsview.cpp.obj" \
"CMakeFiles\image_process.dir\graphics\graphicsscene.cpp.obj" \
"CMakeFiles\image_process.dir\graphics\graphicsPathItem.cpp.obj" \
"CMakeFiles\image_process.dir\image_process_autogen\6WJNPILU4A\qrc_resource.cpp.obj"

# External object files for target image_process
image_process_EXTERNAL_OBJECTS =

image_process.exe: CMakeFiles\image_process.dir\image_process_autogen\mocs_compilation.cpp.obj
image_process.exe: CMakeFiles\image_process.dir\main.cpp.obj
image_process.exe: CMakeFiles\image_process.dir\widget.cpp.obj
image_process.exe: CMakeFiles\image_process.dir\MyLabel.cpp.obj
image_process.exe: CMakeFiles\image_process.dir\Image_adjust\image_adjust.cpp.obj
image_process.exe: CMakeFiles\image_process.dir\energy\energy.cpp.obj
image_process.exe: CMakeFiles\image_process.dir\graphics\graphics.cpp.obj
image_process.exe: CMakeFiles\image_process.dir\graphics\graphicsview.cpp.obj
image_process.exe: CMakeFiles\image_process.dir\graphics\graphicsscene.cpp.obj
image_process.exe: CMakeFiles\image_process.dir\graphics\graphicsPathItem.cpp.obj
image_process.exe: CMakeFiles\image_process.dir\image_process_autogen\6WJNPILU4A\qrc_resource.cpp.obj
image_process.exe: CMakeFiles\image_process.dir\build.make
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib
image_process.exe: E:\qt\5.9.5\msvc2017_64\lib\Qt5MultimediaWidgets.lib
image_process.exe: E:\qt\5.9.5\msvc2017_64\lib\Qt5Sql.lib
image_process.exe: E:\qt\5.9.5\msvc2017_64\lib\Qt5PrintSupport.lib
image_process.exe: E:\qt\5.9.5\msvc2017_64\lib\Qt5Multimedia.lib
image_process.exe: E:\qt\5.9.5\msvc2017_64\lib\Qt5Network.lib
image_process.exe: E:\qt\5.9.5\msvc2017_64\lib\Qt5Widgets.lib
image_process.exe: E:\qt\5.9.5\msvc2017_64\lib\Qt5Gui.lib
image_process.exe: E:\qt\5.9.5\msvc2017_64\lib\Qt5Core.lib
image_process.exe: CMakeFiles\image_process.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\QtProject\image_process\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable image_process.exe"
	"E:\CLion 2022.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\image_process.dir --rc="G:\Windows Kits\10\bin\10.0.17763.0\x64\rc.exe" --mt="G:\Windows Kits\10\bin\10.0.17763.0\x64\mt.exe" --manifests -- G:\develop\vscode\vvss\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\link.exe /nologo @CMakeFiles\image_process.dir\objects1.rsp @<<
 /out:image_process.exe /implib:image_process.lib /pdb:G:\QtProject\image_process\cmake-build-release\image_process.pdb /version:0.0 -Wl,--stack,16777216 /INCREMENTAL:NO /subsystem:console   -LIBPATH:G:\develop\halcon\halcon-21.11.0.0-x64-win64\HALCON-21.11-Progress\lib\x64-win64  E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\opencv\opencv\build\x64\vc15\lib\opencv_world411.lib E:\qt\5.9.5\msvc2017_64\lib\Qt5MultimediaWidgets.lib E:\qt\5.9.5\msvc2017_64\lib\Qt5Sql.lib E:\qt\5.9.5\msvc2017_64\lib\Qt5PrintSupport.lib halcon.lib halconcpp.lib E:\qt\5.9.5\msvc2017_64\lib\Qt5Multimedia.lib E:\qt\5.9.5\msvc2017_64\lib\Qt5Network.lib E:\qt\5.9.5\msvc2017_64\lib\Qt5Widgets.lib E:\qt\5.9.5\msvc2017_64\lib\Qt5Gui.lib E:\qt\5.9.5\msvc2017_64\lib\Qt5Core.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\image_process.dir\build: image_process.exe
.PHONY : CMakeFiles\image_process.dir\build

CMakeFiles\image_process.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\image_process.dir\cmake_clean.cmake
.PHONY : CMakeFiles\image_process.dir\clean

CMakeFiles\image_process.dir\depend: image_process_autogen\6WJNPILU4A\qrc_resource.cpp
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" G:\QtProject\image_process G:\QtProject\image_process G:\QtProject\image_process\cmake-build-release G:\QtProject\image_process\cmake-build-release G:\QtProject\image_process\cmake-build-release\CMakeFiles\image_process.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\image_process.dir\depend

