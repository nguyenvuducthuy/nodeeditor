file(GLOB_RECURSE CPPS  ./*.cpp ./*.hpp ./*.h)

add_executable(example2Thuy ${CPPS})

target_link_libraries(example2Thuy nodes)
