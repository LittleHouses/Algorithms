
#ifndef heap_hpp
#define heap_hpp

#include <vector>
#include <stdexcept>
#include <algorithm>

template<typename T>
class maxHeap
{
private:
    std::vector<T> _array;
    int left(int i);
    int right(int i);
    int parent(int i);
    void heapify_up(int i);
    void heapify_down(int i);
    
public:
    maxHeap();
    maxHeap(std::vector<T>& arr);
    
    void insert(T x);
    T top();
    void pop();
    int size();
};

template <typename T>
maxHeap<T>::maxHeap()
{
    
}

template <typename T>
maxHeap<T>::maxHeap(std::vector<T>& arr)
{
    _array = arr;
    for(int i = (int)arr.size() / 2; i > -1; --i)
    {
        heapify_down(i);
    }
}



template <typename T>
void maxHeap<T>::heapify_down(int i)
{
    int lc = this->left(i);
    int rc = this->right(i);
    
    int mi;
    
    if(lc > -1 && rc > -1)
    {
        if(this->_array[rc] > this->_array[lc])
        {
            mi = rc;
        }
        else
        {
            mi = lc;
        }
    }
    else if(lc > -1)
    {
        mi = lc;
    }
    else if(rc > -1)
    {
        mi = lc;
    }
    else
    {
        return;
    }
    
    if(this->_array[i] < this->_array[mi])
    {
        T temp = this->_array[mi];
        this->_array[mi] = this->_array[i];
        this->_array[i] = temp;
        
        this->heapify_down(mi);
    }
        
}

template <typename T>
void maxHeap<T>::heapify_up(int i)
{
    int p = this->parent(i);
    
    if(p > -1)
    {
        if(this->_array[i] > this->_array[p])
        {
            T temp = this->_array[p];
            this->_array[p] = this->_array[i];
            this->_array[i] = temp;
            
            this->heapify_up(p);
        }
    }
    else
    {
        return;
    }
}

template <typename T>
int maxHeap<T>::parent(int i)
{
    if(i == 0)
    {
        return -1;
    }
    else
    {
        return i / 2;
    }
}

template <typename T>
int maxHeap<T>::left(int i)
{
    int c = i * 2;
    
    if(c >= this->_array.size())
    {
        return -1;
    }
    else
    {
        return c;
    }
}

template <typename T>
int maxHeap<T>::right(int i)
{
    int c = i * 2 + 1;
    
    if(c >= this->_array.size())
    {
        return -1;
    }
    else
    {
        return c;
    }
}


template <typename T>
void maxHeap<T>::insert(T x)
{
    _array.push_back(x);
    heapify_up(_array.size() - 1);
}

template <typename T>
T maxHeap<T>::top()
{
    if(_array.size() > 0)
    {
        return _array[0];
    }
    else
    {
        throw std::runtime_error("Heap Empty");
    }
}

template <typename T>
void maxHeap<T>::pop()
{
    if(_array.size() == 0)
        return;
    else
    {
        _array[0] = _array[_array.size() - 1];
        _array.pop_back();
        
        this->heapify_down(0);
    }
}

template <typename T>
int maxHeap<T>::size()
{
    return _array.size();
}


template<typename T>
class minHeap
{
private:
    std::vector<T> _array;
    
public:
    minHeap();
    minHeap(std::vector<T> arr);
};

#endif /* heap_hpp */
