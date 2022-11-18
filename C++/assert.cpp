#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

template<typename C, typename F>
void myassert(C c, F f)
{
    if (!c)
    {
        throw std::runtime_error(f());
    }
}

int main()
{
    try
    {
        //int i = 0;
        //myassert(i != 0, [&]() { std::ostringstream oss; oss << "value of i: " << i << " must not be 0"; return oss.str(); });
        
        std::string fname{ "non_existing_file" };
        std::ifstream ifs(fname);
        myassert(ifs.is_open(), [&]() { 
            std::ostringstream oss; oss << "Failed to open file: " << fname << " for reading, error: " << strerror(errno); 
            return oss.str(); });
    }
    catch (std::exception const& e)
    {
        std::cerr << "std::exception: " << e.what() << std::endl;
    }
    return -1;
}

