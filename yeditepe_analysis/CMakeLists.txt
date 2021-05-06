#author : Serhat Istin

# We can compile and link pythia examples with ROOT by this CMakeLists 
#currently we have one subfolder with pythua examples
# as we extend our analyses we will be adding more subfolders 

cmake_minimum_required (VERSION  3.0)
project(pythia8Analysis)

#this is logically wrong but ok.(GNU)
if(UNIX AND NOT APPLE)
        set(LINUX TRUE)
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_BUILD_TYPE "Release")

add_subdirectory(Analyses/pythia8-root)
list(APPEND SUBDIRS "Analyses/pythia8-root")
