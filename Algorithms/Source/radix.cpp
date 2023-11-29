//
//  radix.cpp
//  Algorithms
//
//  Created by WB Digital on 11/14/23.
//

#include "radix.hpp"

using namespace std;

std::vector<vector<int>> counting_sort(vector<vector<int>> nums, int index)
{
    int const base = 256;

    int n = (int)nums.size();
    
    vector<vector<vector<int>>> holder(base);
    vector<vector<int>> sorted;
    
    //How many of each number from 0 to k do we have.
    // O(n)
    for(int i = 0; i < n; ++i)
    {
        int num = nums[i][index];
        holder[num].push_back(nums[i]);
    }
        
    //O(k)
    for(int i = 0; i < base + 1; ++i)
    {
        vector<vector<int>> set = holder[i];
        
        for(vector<int> x : set)
        {
            sorted.push_back(x);
        }
    }
    
    return sorted;
}

// Represent each integer in base b.
// The number of digits d = log_b(k).
// Sort the integers by the least signigicant digit to the most significant digit. ( d iterations)
// Sort for each digit using counting sort.
std::vector<int> radix_sort(std::vector<int>& nums, int k)
{
    int const shift = 8;
    int const word_size = 32;
    int const factor = word_size / shift;
    
    //int n = (int)nums.size();
    
    std::vector<int> scalers;
    
    vector<vector<int>> tuples;
    
    for(int x : nums)
    {
        tuples.push_back(change_base(x));
    }
    
     
    for(int i = 0; i < factor; ++i)
    {
        tuples = counting_sort(tuples, i);
    }
    
    std::vector<int> sorted;

    for(vector<int> v : tuples)
    {
        int x = to_int(v);
        
        sorted.push_back(x);
    }
    
    return sorted;
}

vector<int> change_base(int x)
{
    int const shift = 8;
    int const word_size = 32;
    int const factor = word_size / shift;
    
    bitset<word_size> x_bits = bitset<word_size>(x);
    bitset<shift> alpha = bitset<shift>();
    
    vector<int> out;
    
    for(int c = 0; c < factor; ++c)
    {
        for(int i = 0; i < shift; ++i)
        {
            alpha[i] = x_bits[i];
        }
        
        x_bits = x_bits >> shift;
        
        out.push_back((int)alpha.to_ulong());
    }
    
    return out;
    
}

int to_int(vector<int> vec)
{
    int out = 0;
    
    for(int i = 0; i < vec.size(); ++i)
    {
        out += vec[i] * pow(256,i);
    }
    
    return out;
}



