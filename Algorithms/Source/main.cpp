//
//  main.cpp
//  Algorithms
//
//  Created by WB Digital on 11/14/23.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cassert>
#include <algorithm>

#include "radix.hpp"
#include "misc.hpp"
#include "bst.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    
    vector<int> vals {2,5,8,6,3,35,4,23,1};
    bst_avl<int> tree = bst_avl<int>(vals);
    
    cout << tree.root->key << endl;
    
    cout << tree.mimimum(tree.root)->key << endl;
    
    vector<int> order = tree.order_keys();
    
    print_vector(order);
    
    vector<bst_node<int>*> nodes = tree.order_nodes();
    
    for(auto node : nodes)
    {
        cout << "Key : " << node->key << " Height : " << node->height << " Skew :" << tree.skew(node) << endl;
    }
    
    return 0;
}
