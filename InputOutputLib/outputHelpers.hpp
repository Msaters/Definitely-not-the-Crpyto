#pragma once

#include <iostream>
#include <vector>
#include <concepts>

template <typename P>
concept Printable = requires(std::ostream& os, const P& obj) 
{
    { os << obj } -> std::same_as<std::ostream&>;
};

// output vector
template <Printable T>
void printVec(const std::vector<T>& vec, const std::string& str)
{
    std::cout << "-- PRINTING VECTOR " << str << " --" << std::endl;
    for (const auto& elem : vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl << "-- FINISHED PRINTING VECTOR --" << std::endl;
}