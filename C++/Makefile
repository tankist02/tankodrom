CXX := g++13

ifeq ($(BUILD_TYPE),)
    BUILD_TYPE=release
endif

#BUILD_TYPE:=debug

COMP_FLAGS=-Wall -Wextra -Wpedantic -Werror -Wfloat-equal -Wno-unused-parameter -std=c++20
#COMP_FLAGS=-Wall -Wextra -Wpedantic -Werror -Wfloat-equal -Wno-unused-parameter -std=c++20 -fanalyzer

LDFLAGS += -lpthread

clean:
	find . -type f -perm -555 | grep -v \.sh$ | xargs rm -f
	rm -f *.o

