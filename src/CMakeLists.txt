

add_subdirectory(SummingExamples)


add_executable(TheEXE)

target_sources(TheEXE PRIVATE main.cpp)

target_link_libraries( TheEXE PRIVATE SummingExamples)