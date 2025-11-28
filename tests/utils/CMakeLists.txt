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

add_executable(
	test_LinkedList
	./test_LinkedList.c
)
target_link_libraries(
	test_LinkedList
	utils
	unity
)
add_test(
	test_LinkedList test_LinkedList
)
