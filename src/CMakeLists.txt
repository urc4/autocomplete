# Create the executable
add_executable(autocomplete main.cpp)

# Link the libraries to the executable
target_link_libraries(autocomplete minimal_fst)