#include <iostream>
#include <sstream>
#include <cstring>

template<typename F>
void run(long loops, int argc, char* argv[], F f)
{
    clock_t c = clock();
    for (long l = 0; l < loops; ++l)
    {
        for (int i = 1; i < argc; ++i)
        {
            double res = f(argv[i]);
            if (res < 0.0)
            {
                std::cout << "argv: " << argv[i] << ", res: " << res << std::endl;
            }
        }
    }
    std::cout << "Time: " << double(clock() - c) / CLOCKS_PER_SEC << std::endl;
}

int main(int argc, char* argv[])
{
    try
    {
        std::size_t pos;
        auto res = std::stod(argv[1], &pos);
        std::cout << "res: " << res << ", pos: " << pos << ", input len: " << strlen(argv[1]) << std::endl;

        /*if (argc < 3)
        {
            std::ostringstream os;
            os << "Usage: " << argv[0] << " <loops> <arg1 [arg2...]>";
            throw std::runtime_error(os.str());
        }

        long loops = atoi(argv[1]);
        std::cout << "loops: " << loops << std::endl;

        run(loops, argc, argv, atof);
        run(loops, argc, argv, std::stod);*/

        //std::cout.precision(16);
        //std::cout.setf(std::ios_base::scientific);
        /*for (int i = 1; i < argc; ++i)
        {
            double res = std::stod(argv[i]);
            std::cout << "argv: " << argv[i] << ", res: " << res << std::endl;
        }

        for (int i = 1; i < argc; ++i)
        {
            auto res = std::stold(argv[i]);
            std::cout << "argv: " << argv[i] << ", res: " << res << std::endl;
        }*/

        /*
        clock_t c = clock();
        for (long l = 0; l < loops; ++l)
        {
            for (int i = 1; i < argc; ++i)
            {
                double res = atof(argv[i]);
                if (res < 0.0)
                {
                    std::cout << "argv: " << argv[i] << ", res: " << res << std::endl;
                }
            }
        }
        std::cout << "Time: " << double(clock() - c) / CLOCKS_PER_SEC << std::endl;

        c = clock();
        for (long l = 0; l < loops; ++l)
        {
            for (int i = 1; i < argc; ++i)
            {
                double res = atof(argv[i]);
                if (res < 0.0)
                {
                    std::cout << "argv: " << argv[i] << ", res: " << res << std::endl;
                }
            }
        }
        std::cout << "Time: " << double(clock() - c) / CLOCKS_PER_SEC << std::endl;

        c = clock();
        for (long l = 0; l < loops; ++l)
        {
            for (int i = 1; i < argc; ++i)
            {
                double res = atof(argv[i]);
                if (res < 0.0)
                {
                    std::cout << "argv: " << argv[i] << ", res: " << res << std::endl;
                }
            }
        }
        std::cout << "Time: " << double(clock() - c) / CLOCKS_PER_SEC << std::endl;
        */
    }
    catch (std::exception const& e)
    {
        std::cerr << "std::exception: " << e.what() << std::endl;
    }
}

