cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set(test_sources
	mwStackTests.cxx
	mwQueueTests.cxx
   )

add_executable(StackTests mwStackTests.cxx)
add_executable(QueueTests mwQueueTests.cxx)

set_target_properties(StackTests PROPERTIES FOLDER "Tests")
set_target_properties(QueueTests PROPERTIES FOLDER "Tests")

target_link_libraries(StackTests PUBLIC gtest gtest_main core)
target_link_libraries(QueueTests PUBLIC gtest gtest_main core)
