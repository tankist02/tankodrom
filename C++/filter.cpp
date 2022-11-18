#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> words { "", "one", "two", "", "three", "" };

    std::for_each(begin(words), end(words), [](std::string const& s) { std::cout << s << ", "; });
    std::cout << std::endl;
    
    auto last = std::remove_if(begin(words), end(words), [](std::string const& s) { return s.empty(); });
    words.erase(last, end(words));
    std::for_each(begin(words), end(words), [](std::string const& s) { std::cout << s << ", "; });
    std::cout << std::endl;

    auto isPalindrome = [](std::string const& s) { auto mid = s.begin() + s.size() / 2; return std::equal(s.begin(), mid, s.rbegin()); };
    std::vector<std::string> w2 { "dad", "mom", "brother", "sister" };
    std::for_each(begin(w2), end(w2), [](std::string const& s) { std::cout << s << ", "; });
    std::cout << std::endl;

    w2.erase(std::remove_if(begin(w2), end(w2), isPalindrome), w2.end());
    std::for_each(begin(w2), end(w2), [](std::string const& s) { std::cout << s << ", "; });

    return 0;
}

