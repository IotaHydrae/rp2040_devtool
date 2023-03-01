file(GLOB_RECURSE UI_SOURCES  "src/*.c" "handlers/*.c")

add_library(ui ${UI_SOURCES})
