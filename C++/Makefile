ifndef BUILD_TYPE
	BUILD_TYPE=release
endif

ifeq ($(BUILD_TYPE),)
    BUILD_TYPE=release
endif

ifeq ($(BUILD_TYPE),debug)
	CXXFLAGS += -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter -std=c++20 -O0 -g3
else ifeq ($(BUILD_TYPE),release)
	CXXFLAGS += -Wall -Wextra -Wpedantic -Werror -Wno-unused-parameter -std=c++20 -O3
else
$(error: Invalid BUILD_TYPE: $(BUILD_TYPE))
endif

LDFLAGS += -lfmt

clean:
	find . -type f -executable | xargs rm -f
	rm -f *.o

