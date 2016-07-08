
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

MACRO(CXXCAM_TEST testname)
	ADD_EXECUTABLE(${testname} EXCLUDE_FROM_ALL "${testname}.cpp")
	TARGET_LINK_LIBRARIES(${testname} svg_path)
	SET_TARGET_PROPERTIES(${testname} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
	ADD_TEST(${testname} "${MAKE_CURRENT_BINARY_DIR}/${testname}")
	ADD_DEPENDENCIES(check ${testname})
ENDMACRO()

FOREACH(test 
    test_svg_parser_numberlist
    test_svg_path
    test_svg_transform
)
	CXXCAM_TEST(${test})
ENDFOREACH()

