#include<iostream>
#include<string>
#include "Node.h"
#include "CellData.h"

using std::cout;


// Default constructor
// remember to initialize next to nullptr
Node::Node() : next(nullptr) {} 

// Parameterized constructor
// remember to initialize next to nullptr
Node::Node(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y) : next(nullptr)
{
    data.fov = fov;
    data.id = id;
    data.center_x = center_x;
    data.center_y = center_y;
    data.min_x = min_x;
    data.min_y = min_y;
    data.max_x = max_x;
    data.max_y = max_y;
    data.volume = volume;
}

bool Node::operator<(const Node& b) {
    if (this->data < b.data) {
        //std::cout << this->data.fov << " is less than " << b.data.fov << std::endl;
        return true;
    }
    else {
        // std::cout << this->data.fov << " is greater than " << b.data.fov << std::endl;
        return false;
    }
}

bool Node::operator==(const Node& b) {
    if (this->data == b.data) {
        return true;
    }
    else {
        return false;
    }
}
