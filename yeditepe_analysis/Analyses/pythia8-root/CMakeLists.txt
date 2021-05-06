#author : Serhat Istin

# We can compile and link pythia examples with ROOT by this CMakeLists 



set(INSTALLATION ${PROJECT_BINARY_DIR}/INSTALL)
set(BINDIR ${INSTALLATION}/bin)


#Pick up PYTHIA8 from the environment and link against the precompiled library
set(PYTHIA8 $ENV{PYTHIA8})
find_library(PYTHIA8LIB NAMES libpythia8.so PATHS ${PYTHIA8}/lib )
message("Found pythia8 library ${PYTHIA8LIB}")
include_directories(${PYTHIA8}/include)


#Integrates ROOT quite well

find_package(ROOT REQUIRED COMPONENTS RIO Net)
include(${ROOT_USE_FILE})
list(APPEND CMAKE_PREFCMAKE_INCLUDE_CURRENT_DIRIX_PATH $ENV{ROOTSYS})

#Search for git package / this may be necessary in the future
find_package(Git QUIET)


#any soruce file here with .cc extension is considered to be a main program
FILE(GLOB CPPFiles *.cc *.cpp)

FILE(GLOB UserHeaders *.h)

#compile and link all the mains

foreach(EXECSRC ${CPPFiles})
    get_filename_component(appname ${EXECSRC} NAME_WE  )
    add_executable(${appname} ${EXECSRC} )
    target_link_libraries( ${appname} ${PYTHIA8LIB} ${ROOT_LIBRARIES} )
    install (TARGETS ${appname} DESTINATION ${BINDIR} )
endforeach()


#create a helper script to append to PATH 
#makes life easier while running compiled executables
# I couldnt find a better way of doing that yet ...

set(SETUPSCRIPTS ${PROJECT_BINARY_DIR})
FILE(WRITE ${SETUPSCRIPTS}/setup.sh "export PATH=$PATH:${BINDIR}\n")
