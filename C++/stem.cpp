// C++ program to find the stem of given list of
// words
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
//#include <nlohmann/json.hpp>

//using namespace std;
//using json = nlohmann::json;
 
using Strings = std::vector<std::string>;

// function to find the stem (longest common
// substring) from the string array
Strings findstem(Strings& arr)
{
    // Sort words from short to long
    std::sort(arr.begin(), arr.end(), []
        (const std::string& first, const std::string& second)
    {
        return first.size() < second.size();
    });
    
    size_t n = arr.size();

    // Take first word from array as reference
    std::string s = arr[0];

    size_t len = s.length();
 
    Strings res;

    for (size_t i = len; i > 0; i--) 
    {
        for (size_t j = 0; j < len-i+1; j++) 
        {
            // generating all possible substrings
            // of our reference string arr[0]
            std::string stem = s.substr(j, i);

            size_t k;

            for (k = 1; k < n; k++) 
            {
                // Check if the generated stem is
                // common to all words
                if (arr[k].find(stem) == std::string::npos)
                    // not found
                    break;
            }
            // cout << "looking for " << stem << " and found in " << k << " end " << n << endl;
            // If current substring is present in all strings
            if (k == n)
                 res.push_back(stem);
        }
        if (!res.empty())
          break;
    }
 
    return res;
}
 
void load(std::istream& is, Strings& words)
{
    std::string word;
    while (is >> word)
        words.emplace_back(word);
}

int main(int argc, char* argv[])
{
   // vector<string> arr{ "grace", "graceful", "disgraceful",
   //                     "gracefully" };
    //json stems;
    Strings stems;
    std::string fileName = "strings.json";
    if (argv[1])
       fileName = argv[1];
    std::ifstream stem_file(fileName);
    load(stem_file, stems);

    // Function call
    Strings stem1 = findstem(stems);
    std::cout << "[  ";
    for (std::string const& i : stem1)
        std::cout << i << "  ";
    std::cout << "]" << std::endl;

    return 0;
}
 
