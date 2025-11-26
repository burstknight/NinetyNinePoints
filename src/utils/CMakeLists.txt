aux_source_directory(./ Utils_Sources)
add_library(
	utils
	STATIC
	${Utils_Sources}
)
