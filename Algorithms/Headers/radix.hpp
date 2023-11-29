//
//  radix.hpp
//  Algorithms
//
//  Created by WB Digital on 11/14/23.
//

#ifndef radix_hpp
#define radix_hpp

#include <vector>
#include <cmath>
#include <bitset>
#include <math.h>
#include "misc.hpp"

std::vector<int> counting_sort(std::vector<int>& nums, int k);

std::vector<int> radix_sort(std::vector<int>& nums, int k);
std::vector<int> change_base(int x);

int to_int(std::vector<int> vec);
#endif /* radix_hpp */
