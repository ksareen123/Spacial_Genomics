#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

LinkedList::LinkedList() : head(nullptr), tail(nullptr){
	  // Implement this function
}

LinkedList::~LinkedList() {
	clear();  // Implement this function
}

LinkedList::LinkedList(const LinkedList& source) {
    //cout << "clearing" << endl;
    head = nullptr;
    tail = nullptr;
    clear();
    
    if (source.head == nullptr) {
        //cout << "checking if empty" << endl;
    }
    else if (source.head == source.tail) {
        //cout << "checking if one element" << endl;
        CellData mydata = source.head->data;
        // this->insert("",0,0,0,0,0,0,0,0);
        this->insert(mydata.id, mydata.fov, mydata.volume, mydata.center_x, mydata.center_y, mydata.min_x, mydata.max_x, mydata.min_y, mydata.max_y);
    }
    else {
        //cout << "multiple elements" << endl;
        CellData mydata;
        Node* currnode = source.head;
        //cout << "created node to represent head" << endl;
        while (currnode != nullptr) {
            //cout << "hello" << endl;
            mydata = currnode->data; 
            //cout << "celldata" << endl;
            this->insert(mydata.id, mydata.fov, mydata.volume, mydata.center_x, mydata.center_y, mydata.min_x, mydata.max_x, mydata.min_y, mydata.max_y);
            //cout << "added " << mydata.id << endl;
            currnode = currnode->next;
        }
    }
}

LinkedList& LinkedList::operator=(const LinkedList& source) 
{
    //cout << "clearing" << endl;
    clear();
    
    //cout << "checking if empty" << endl;
    if (source.head == nullptr) {
        return *this;
    }
    //cout << "checking if one element" << endl;
    if (source.head == source.tail) {
        insert(source.head->data.id, source.head->data.fov, source.head->data.volume, source.head->data.center_x, source.head->data.center_y, source.head->data.min_x, source.head->data.max_x, source.head->data.min_y, source.head->data.max_y);
        return *this;
    }
    //cout << "proceeding with default case" << endl;
    insert(source.head->data.id, source.head->data.fov, source.head->data.volume, source.head->data.center_x, source.head->data.center_y, source.head->data.min_x, source.head->data.max_x, source.head->data.min_y, source.head->data.max_y);
    //cout << "inserting head at head" << endl;
    Node* currnode = source.head;
    //cout << "iterator node" << endl;
    while (currnode->next != nullptr) {
        currnode = currnode->next;
        //cout << "inserting node " << currnode->data.id << endl;
        insert(currnode->data.id, currnode->data.fov, currnode->data.volume, currnode->data.center_x, currnode->data.center_y, currnode->data.min_x, currnode->data.max_x, currnode->data.min_y, currnode->data.max_y);
    }
    //cout << this->getHead()->data.id << endl;
    
    return *this;

    // Implement this function
}

void LinkedList::insert(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
{
    Node* mynode = new Node(id, fov, volume, center_x, center_y, min_x, max_x, min_y, max_y);

    if (head == nullptr) {
        // std::cout << mynode->data.fov << std::endl;
        // std::cout << "empty list" << std::endl;
        // std::cout << "---------------------------------------------------------" << std::endl;
        head = mynode;
        tail = mynode;
    }
    else if (*mynode < *head) {
        // std::cout << mynode->data.fov << " is less than head: " << head->data.fov << std::endl;
        // std::cout << "inserting at head" << std::endl;
        // std::cout << "---------------------------------------------------------" << std::endl;
        mynode->next = head;
        head = mynode;
    }
    else if (*tail < *mynode) {
        // std::cout << mynode->data.fov << " is greater than tail: " << tail->data.fov << std::endl;
        // std::cout << "inserting at tail" << std::endl;
        // std::cout << "---------------------------------------------------------" << std::endl;
        tail->next = mynode;
        tail = mynode;
    }
    else {
        Node* currnode = head;
        Node* prevnode = nullptr;
        while(currnode->data < mynode->data && currnode->next != nullptr) {
            prevnode = currnode;
            currnode = currnode->next;
        }
        // std::cout << mynode->data.fov << " is less than " << currnode->data.fov << std::endl;
        // std::cout << "inserting in middle" << std::endl;
        // std::cout << "---------------------------------------------------------" << std::endl;
        prevnode->next = mynode;
        mynode->next = currnode;
    }
    // Implement this function
}

void LinkedList::remove(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
{
    Node* mynode = new Node(id, fov, volume, center_x, center_y, min_x, max_x, min_y, max_y);
    //cout << "attempting to delete node " << mynode->data.id << endl;
    if (head == nullptr) {
        return;
    }
    if (mynode->data == head->data) {
        //cout << "node found at head" << endl;
        Node* currnode = head; 
        //cout << "created other node" << endl;
        head = head->next;
        //cout << "moved head" << endl;
        delete currnode;
        //cout << "deleted original head" << endl;
        delete mynode;
        return;
    }
    else {
        //cout << "default case" << endl;
        Node* currnode = head;
        Node* prevnode = nullptr;
        while (!(currnode->data == mynode->data) && currnode != nullptr) {
            prevnode = currnode;
            currnode = currnode->next;
        }
        if (currnode->data == mynode->data && prevnode == tail) {
            tail = prevnode;
            tail->next = nullptr;
            delete currnode;
            //mynode = nullptr;
        }
        else if (currnode->data == mynode->data) {
            prevnode->next = currnode->next;
            delete currnode;
            currnode = nullptr;
            //mynode = nullptr;
        }
        //prevnode = nullptr;
    }
    delete mynode;
    mynode = nullptr;
    // Implement this function
}

void LinkedList::clear() 
{	
    // Implement this function 
    if (head == nullptr) {
        return;
    }
    else if (head == tail && head != nullptr) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node* currnode = head;
        while (head != nullptr) { 
            currnode = head;
            head = currnode->next;
            delete currnode;
        }
        head = nullptr;
        tail = nullptr;
    }
}

Node* LinkedList::getHead() const 
{
    return head;// Implement this function it will be used to help grade other functions
}

string LinkedList::print() const 
{
    if (head == nullptr) {
        return "";
    }
    std::stringstream mydata;
    mydata << "fov,volume,center_x,center_y,min_x,max_x,min_y,max_y\n";
    // string stringdata = "fov,volume,center_x,center_y,min_x,max_x,min_y,max_y\n";
    Node* currnode = head;
    CellData mycell;
    while (currnode != nullptr) {
        mycell = currnode->data;
        mydata << mycell.id << "," << mycell.fov << "," << mycell.volume << "," << mycell.center_x << "," << mycell.center_y << "," << mycell.min_x << "," << mycell.max_x << "," << mycell.min_y << "," << mycell.max_y << endl;
        // stringdata+= string(mycell.fov);
        // stringdata+= ",";
        // stringdata+= string(mycell.volume);
        // stringdata+= ",";
        // stringdata+= string(mycell.center_x);
        // stringdata+= ",";
        // stringdata+= string(mycell.center_y);
        // stringdata+= ",";
        // stringdata+= string(mycell.min_x);
        // stringdata+= ",";
        // stringdata+= string(mycell.max_x);
        // stringdata+= ",";
        // stringdata+= string(mycell.min_y);
        // stringdata+= ",";
        // stringdata+= string(mycell.max_y);
        // stringdata+= "\n";
        currnode = currnode->next;
    }
   string finalstr = mydata.str();
    return finalstr;
    // Implement this function
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}

// given a fov number, count the cells observed in that fov
int LinkedList::countN(int fov)
{
	/* Do not modify this function */
    int count = 0;
    Node* cur = head;
    while (cur)
    {
        if (cur->data.fov == fov)
            count++;
        cur = cur->next;
    }
    return count;
}

/* given a fov number, compute the average volume of all the cells observed in
 * that fov
 */
double LinkedList::average(int fov)
{
    if (head == nullptr) {
        return 0;
    } 
    else {
        double avg = -1;
        double total = 0;
        double count = 0;
        Node* mynode = head;
        while (mynode != nullptr) {
            if (mynode->data.fov == fov) {
                total+= mynode->data.volume;
                count+= 1;
            }
            mynode = mynode->next;
        }
        if (count != 0) {
            avg = total / count;
        }
        return avg;
    }
        // Implement this function
}

/* given a fov number, compute the variance volume of all the cells observed in
 * that fov
 */
double LinkedList::variance(int fov)
{
	/* Do not modify this function */
    double sum = 0;
    double avg = average(fov);
    int count = countN(fov);

    if (count == 0) {
        return -1;
    }
    Node* cur = head;
    while (cur)
    {
        if (fov == cur->data.fov)
            sum += (cur->data.volume - avg) * (cur->data.volume - avg);
        cur = cur->next;
    }

    return sum/count;
}

/* given a fov number, remove outliers
 */
string LinkedList::outliers(int fov, int k, int N)
{
    string ret = "";
    double delta;
    double min;
    double max;
    int count = 0;
    if (countN(fov) < N) {
        ret += "Less than ";
        ret += std::to_string(N);
        ret += " cells in fov ";
        ret += std::to_string(fov);
        return ret;
    }
    else {
        delta = sqrt(variance(fov));
        min = average(fov) - k * delta;
        max = average(fov) + k * delta;
    }
    Node* mynode = head;
    Node* nextnode = nullptr;
    while (mynode != nullptr) {
        nextnode = mynode->next;
        CellData currdata = mynode->data;
        if (currdata.fov == fov && (currdata.volume < min || currdata.volume > max)) {
            //cout << "removing " << currdata.id << endl;
            remove(currdata.id, currdata.fov, currdata.volume, currdata.center_x, currdata.center_y, currdata.min_x, currdata.max_x, currdata.min_y, currdata.max_y);
            count++;
        }
        mynode = nextnode;
    }
    ret = std::to_string(count) + " cells are removed.";
    return ret;
    // Implement this function
}

