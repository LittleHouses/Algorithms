//
//  misc.cpp
//  Algorithms
//
//  Created by WB Digital on 11/14/23.
//

#include "misc.hpp"

bool check_sorted(std::vector<int> vec)
{
    for(int i = 0; i < vec.size() - 1; ++i)
    {
        if(vec[i] > vec[i + 1])
        {
            return false;
        }
    }
    
    return true;
}

