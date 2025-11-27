add_executable(
	test_node
	./test_node.c
)
target_link_libraries(
	test_node
	utils
	unity
)
add_test(
	test_node test_node
)
