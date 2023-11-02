# Add the state library
add_library(state state.cpp state.h)

# Add the minimal_fst library
add_library(minimal_fst minimal_fst.cpp minimal_fst.h)

# Link the state library to the minimal_fst library
target_link_libraries(minimal_fst state)