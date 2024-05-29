ifndef BUILD_TYPE
	BUILD_TYPE=release
endif

ifeq ($(BUILD_TYPE),)
    BUILD_TYPE=release
endif

COMP_FLAGS=-Wall -Wextra -Wpedantic -Werror -Wfloat-equal -Wno-unused-parameter -std=c++20
#COMP_FLAGS=-Wall -Wextra -Wpedantic -Werror -Wfloat-equal -Wno-unused-parameter -std=c++20 -fanalyzer

ifeq ($(BUILD_TYPE),debug)
	CXXFLAGS += $(COMP_FLAGS) -O0 -g3
else ifeq ($(BUILD_TYPE),release)
	CXXFLAGS += $(COMP_FLAGS) -O2 -g
else ifeq ($(BUILD_TYPE),checked)
	CXXFLAGS += $(COMP_FLAGS) -O0 -g -D_GLIBCXX_DEBUG
else ifeq ($(BUILD_TYPE),protect)
	CXXFLAGS += $(COMP_FLAGS) -O0 -g -fstack-protector-all -fstack-protector-strong -fsanitize=undefined -fsanitize=address -fno-omit-frame-pointer
else ifeq ($(BUILD_TYPE),profile)
	CXXFLAGS += $(COMP_FLAGS) -O2 -pg -g
	LFLAGS += -pg
else
$(error: Invalid BUILD_TYPE: $(BUILD_TYPE))
endif

#LDFLAGS += -lfmt

clean:
	find . -type f -executable | grep -v \.sh$ | xargs rm -f
	rm -f *.o

