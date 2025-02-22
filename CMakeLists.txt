cmake_minimum_required(VERSION 3.26)

# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing executable name in this file
# for now, the project name is used as the executable name
project(oop)
# set(CMAKE_PROJECT_VERSION_MAJOR 0)
# set(CMAKE_PROJECT_VERSION_MINOR 0)
# set(CMAKE_PROJECT_VERSION_PATCH 1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/Options.cmake)

###############################################################################

# external dependencies with FetchContent
# include(FetchContent)
#
# set(FETCHCONTENT_QUIET OFF)
# set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
#
# NOTE: Also update env vars used for caching in
#         - .github/actions/configure-cmake/action.yml
#         - .github/workflows/cmake.yml
# FetchContent_Declare(
#         SomeLib
#         GIT_REPOSITORY https://github.com/<SomeUser>/<SomeLib>.git
#         GIT_TAG        <some_git_hash> # <which tag/branch @ <some_date>>
#         GIT_SHALLOW    1  # works only with branches or tags, not with arbitrary commit hashes
# )
#
# FetchContent_MakeAvailable(SomeLib)

###############################################################################

# external dependencies with find_package

# find_package(Threads REQUIRED)

###############################################################################

# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing name here
add_executable(${PROJECT_NAME}
    main.cpp
        Models/Vehicle.h
        Models/Driver.h
        Models/Route.h
        Models/FleetManager.h
        Models/Helper.h
        Models/Truck.h
        Models/VehicleService.h
        Models/Motorcycle.h
        Models/Bus.h
        Exceptions/FleetException.h
        Exceptions/DriverNotFoundException.h
        Exceptions/RouteNotFoundException.h
        Exceptions/VehicleNotFoundException.h
        generated/src/Vehicle.cpp
        generated/src/Bus.cpp
        generated/src/Motorcycle.cpp
        generated/src/Truck.cpp
        generated/src/Driver.cpp
        generated/src/Route.cpp
        generated/src/FleetManager.cpp
        generated/src/VehicleService.cpp
        generated/include/FleetContainer.cpp
        generated/headers/FleetContainer.h
        generated/headers/MaintenanceCalculator.h
        generated/include/MaintenanceCalculator.cpp
        generated/headers/ServiceObserver.h
        generated/include/ServiceObserver.cpp
        generated/headers/VehicleFactory.h
        generated/include/VehicleFactory.cpp
)

include(cmake/CompilerFlags.cmake)

###############################################################################

# use SYSTEM so cppcheck and clang-tidy do not report warnings from these directories
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE generated/include)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE Models)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE Exceptions)
# target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ext/<SomeHppLib>/include)
# target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${<SomeLib>_SOURCE_DIR}/include)
# target_link_directories(${PROJECT_NAME} PRIVATE ${<SomeLib>_BINARY_DIR}/lib)
# target_link_libraries(${PROJECT_NAME} <SomeLib>)
include_directories(
        ${CMAKE_SOURCE_DIR}/Models
        ${CMAKE_SOURCE_DIR}/Exceptions
        ${CMAKE_SOURCE_DIR}/generated/include
)

###############################################################################

# copy binaries to "bin" folder; these are uploaded as artifacts on each release
# DESTINATION_DIR is set as "bin" in cmake/Options.cmake:6
install(TARGETS ${PROJECT_NAME} DESTINATION ${DESTINATION_DIR})
if(APPLE)
    install(FILES launcher.command DESTINATION ${DESTINATION_DIR})
endif()

include(cmake/CopyHelper.cmake)
copy_files(FILES tastatura.txt)
# copy_files(FILES tastatura.txt config.json DIRECTORY images sounds)
# copy_files(DIRECTORY images sounds)
