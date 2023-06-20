SRC_DIR := src
BUILD_DIR := build
BUILD_ARGS := -Wall -Wextra -Wpedantic
NAME := terminal

# compile to binary.
compile: mkDirs
	gcc $(BUILD_ARGS) ./$(SRC_DIR)/*.c -o ./$(BUILD_DIR)/$(NAME)

# create build directory.
mkDirs:
	if [ -d "$(BUILD_DIR)" ]; then rm -Rf $(BUILD_DIR); fi
	mkdir $(BUILD_DIR)

# build and run for testing.
test: compile
	./$(BUILD_DIR)/$(NAME)

# remove build dir.
rem:
	if [ -d "$(BUILD_DIR)" ]; then rm -Rf $(BUILD_DIR); fi