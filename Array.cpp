// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
Array::Array (void):
data_(nullptr),
cur_size_(0),
max_size_(0)
{
    data_=new char[max_size_];
}

//
// Array(size_t)
//
Array::Array (size_t length):
data_(new char[length]),
cur_size_(length),
max_size_(length)
{
}

//
// Array(size_t, char)
//
Array::Array (size_t length, char fill):
data_(new char[length]),
cur_size_(length),
max_size_(length)
{
    for(int i=0;i<this->cur_size_;i++){
        this->data_[i]=fill;
    }
}

//
// Array(Array)
//
Array::Array (const Array & array):
data_(new char[array.size()]),
cur_size_(array.cur_size_),
max_size_(array.max_size_)
{
    for(int i=0;i<this->cur_size_;i++){
        this->data_[i]=array.data_[i];
    }
}

//
// ~Array()
//
Array::~Array (void)
{
    if(data_!=nullptr)
    {
        delete [] data_;
    }
}

//
// operator =
//
const Array & Array::operator = (const Array & rhs)
{
    if(*this!=rhs){
        char *temp=new char[rhs.cur_size_];
        this->max_size_=rhs.max_size_;
        this->cur_size_=rhs.cur_size_;
        for(int i=0;i<this->cur_size_;i++){
            temp[i]=rhs.data_[i];
        }
        for(int i=0;i<this->cur_size_;i++){
            this->data_[i]=temp[i];
        }
    }
    return *this;
}

//
// operator []
//
char & Array::operator [] (size_t index)
{
    if (index < this->max_size_) {
        this->cur_size_=index;
        return this->data_[index];
    }
    throw std::out_of_range ("Array Out of Bound Exception");
}

//
// operator []
//
const char & Array::operator [] (size_t index) const
{
    if (index < this->max_size_) {
        return this->data_[index];
    }
    throw std::out_of_range ("Array Out of Bound Exception");
}

//
// get(size_t)
//
char Array::get (size_t index) const
{
    if (index < this->max_size_) {
        return this->data_[index];
    }
    throw std::out_of_range ("Array Out of Bound Exception");
}


//
// set(size_t,char)
//
void Array::set (size_t index, char value)
{
    if (index < this->max_size_) {
        this->data_[index]=value;
    }
    else{
    throw std::out_of_range ("Array Out of Bound Exception");
    }
}

//
// resize(size_t)
//
void Array::resize (size_t new_size)
{
    if(new_size!=this->cur_size_)
        {
        char * resize_data_=new char[new_size];
        if(new_size>this->max_size_){
            for(int i=0;i<this->cur_size_;i++){
                resize_data_[i]=this->data_[i];
            }
            std::swap(resize_data_,data_);
            this->max_size_=new_size;
        }
        this->cur_size_=new_size;
        delete [ ] resize_data_;
        }
        else{
			this->cur_size_=new_size;
		}
}

//
// find (char)
//
int Array::find (char ch) const
{
    int flag=-1;
    for(int i=0;i<this->cur_size_;i++){
        if(this->data_[i]==ch){
            flag=i;
            break;
        }
    }
    return (flag==-1)? -1 : flag;
}

//
// find (char,size_t)
//
int Array::find (char ch, size_t start) const
{
    if (start < this->max_size_ && start >= 0) {
        int flag=-1;
        for(int i=start;i<this->cur_size_;i++){
        if(this->data_[i]==ch){
            flag=i;
            break;
        }
    }
    return (flag==-1)? -1 : flag;
    }
    throw std::out_of_range ("Array Out of Bound Exception");   
}

//
// operator ==
//
bool Array::operator == (const Array & rhs) const
{
    if(cur_size_==rhs.cur_size_){
        for(int i=0;i<this->cur_size_;i++){
            if(this->data_[i]!=rhs.data_[i]){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

//
// operator !=
//
bool Array::operator != (const Array & rhs) const
{
    return !(*this==rhs);
}

//
// fill(char)
//
void Array::fill (char ch)
{
    for(int i=0;i<max_size_;i++){
        this->data_[i]=ch;
    }
    this->cur_size_=this->max_size_;
}

//
// shrink()
//
void Array::shrink (void)
{
    char * shrink_data_=new char[this->cur_size_];
    for(int i=0;i<this->cur_size_+1;i++){
        shrink_data_[i]=this->data_[i];
    }
    delete [ ] this->data_;
    for(int i=0;i<this->cur_size_+1;i++){
        this->data_[i]=shrink_data_[i];
    }
    this->max_size_=this->cur_size_+1;
    delete [ ] shrink_data_;
}

//
// reverse()
//
void Array::reverse (void)
{
    for (int start = 0, end = this->max_size_ - 1; start < end; start++, end--) {
        char temp = this->data_[start];
        this->data_[start] = this->data_[end];
        this->data_[end] = temp;
    }
}

//
// slice(size_t)
//
Array Array::slice (size_t begin) const
{
    Array temp(this->max_size_);
    for(int i=begin;i<this->max_size_;i++){
        temp.data_[i]=this->data_[i];
    }
    return temp;
}

//
// slice(size_t,size_t)
//
Array Array::slice (size_t begin, size_t end) const
{
    Array temp(this->max_size_);
    for(int i=begin;i<end;i++){
        temp.data_[i]=this->data_[i];
    }
    return temp;
}
