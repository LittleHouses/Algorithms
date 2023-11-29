//
//  misc.hpp
//  Algorithms
//
//  Created by WB Digital on 11/14/23.
//

#ifndef misc_hpp
#define misc_hpp

#include <iostream>
#include <string>
#include <vector>

template <class T> void print_vector(std::vector<T> vec)
{
    std::string output = "< ";
    
    for(int i = 0; i < vec.size(); ++i)
    {
        output += std::to_string(vec[i]) + " ";
    }
    
    output += ">";
    
    std::cout << output << std::endl;
}

bool check_sorted(std::vector<int> vec);

#endif /* misc_hpp */
