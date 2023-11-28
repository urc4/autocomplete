# Create the executable
add_executable(autocomplete main.cpp)

# Add includes
target_link_libraries(autocomplete PRIVATE ncurses)
set_source_files_properties(main.cpp PROPERTIES COMPILE_FLAGS "-lncurses")

# Link the libraries to the executable
target_link_libraries(autocomplete PRIVATE minimal_fst)

#a