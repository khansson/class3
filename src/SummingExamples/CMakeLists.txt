

add_library(SummingExamples)

target_sources(SummingExamples PRIVATE  CppStyleArrays.cpp  CStyleArrays.cpp)

target_compile_features(SummingExamples PUBLIC cxx_std_17)


target_include_directories(SummingExamples PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>  
$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}> )