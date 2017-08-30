#include <immer/vector.hpp>
#include <string>
#include <iostream>

// include:fizzbuzz/start
immer::vector<std::string> fizzbuzz(immer::vector<std::string> v, int first, int last)
{
    for (auto i = first; i < last; ++i)
        v = std::move(v).push_back(
            i % 15 == 0 ? "FizzBuzz" :
            i % 5  == 0 ? "Buzz" :
            i % 3  == 0 ? "Fizz" :
            /* else */    std::to_string(i));
    return v;
}
// include:fizzbuzz/end

int main()
{
    auto v = fizzbuzz({}, 0, 100);
    std::copy(v.begin(), v.end(),
              std::ostream_iterator<std::string>{
                  std::cout, "\n"});
}
