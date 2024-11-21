#include <execinfo.h>  // For backtrace()

#include <cxxabi.h>

#define UNW_LOCAL_ONLY
#include <libunwind.h>

#include <cassert>
#include <chrono>
#include <csignal>
#include <iostream>

static constexpr size_t MAX_STACKTRACE_DEPTH = 64;

std::string globMessage;

void backtrace()
{
	unw_cursor_t cursor;
	unw_context_t context;

	// Initialize cursor to current frame for local unwinding.
	unw_getcontext(&context);
	unw_init_local(&cursor, &context);

	// Unwind frames one by one, going up the frame stack.
	while (unw_step(&cursor) > 0)
	{
		unw_word_t offset, pc;
		unw_get_reg(&cursor, UNW_REG_IP, &pc);
		if (pc == 0)
		{
			break;
		}
		//printf("0x%lx:", pc);

		char sym[256];
		if (unw_get_proc_name(&cursor, sym, sizeof(sym), &offset) == 0)
        {
			//printf(" (%s+0x%lx)\n", sym, offset);

            int status;
            char* name = abi::__cxa_demangle(sym, nullptr, nullptr, &status);
            if (status == 0)
            {
                printf("symbol: %s (%s+0x%lx)\n", name, sym, offset);
                free(name);
            }
		}
        else
        {
			//printf(" -- error: unable to obtain symbol name for this frame\n");
		}
	}
}

/*void writeStackTrace(int file_descriptor)
{
	void* trace[MAX_STACKTRACE_DEPTH];
	size_t trace_depth = backtrace(trace, MAX_STACKTRACE_DEPTH);
	// Note that we skip the first frame here so this function won't show up in
	// the printed trace.
	backtrace_symbols_fd(trace + 1, trace_depth - 1, file_descriptor);
	//backtrace_symbols_fd(trace, trace_depth, file_descriptor);
}*/

/******************************************************************************/
void fatalSignalHandler(int signal)
{
	// Restore the default signal handler for SIGSEGV in case another one
	// happens, and for the re-issue below.
	std::signal(signal, SIG_DFL);

	// writeStackTrace should theoretically be safe to call here.
	static constexpr const char error_msg[] =
		"*** fatalSignalHandler stack trace: ***\n";
	// Write using safe `write` function. Skip null character.
	if (write(fileno(stderr), error_msg, sizeof(error_msg) - 1) > 0)
	{
        backtrace();

		//writeStackTrace(fileno(stderr));
	    write(fileno(stderr), globMessage.c_str(), globMessage.size());
	    write(fileno(stderr), "\n", 1);
	}

	// Now that the signal handler has been removed we can simply return. If
	// SIGSEGV/SIGABRT was triggered by an instruction, it will occur again. This
	// time it will be handled by the default handler which triggers a core dump.
	return;
}

void func1()
{
	// Trigger segfault by writing to nullptr.
	char* bad_ptr = nullptr;
	*bad_ptr = 10;
}

void func2()
{
    func1();
}

void func3()
{
    func2();
}

int main()
{
	// Use our function to handle segmentation faults.
	// Could add additional signals like: SIGSEGV, SIGSYS, etc.
	std::signal(SIGSEGV, fatalSignalHandler);

	std::cout << "Hello World." << std::endl;

    globMessage = "This is the global message";

    func3();

	std::cout << "Finished." << std::endl;

	return 0;
}

