// COMSC-210 | SP26-Final-2 | Gabriel Marquez

#include <iostream>
#include <string>
using namespace std;

int ARR_SIZE = 15;

struct Node {
    string name;
    string order;
    Node *next;
};

int main() {
    Node *head = nullptr;
    
    string names[ARR_SIZE] = {
        "Oliver", "Emma", "Liam", "Ava", "Noah",
        "Sophia", "Lucas", "Isabella", "Mason", "Mia",
        "Ethan", "Harper", "James", "Evelyn", "Alexander"};
    string drinks[ARR_SIZE] = {
        "Espresso","Macchiato","Cortado","Cappuccino","Flat White",
        "Caffè Latte","Americano","Mocha","Cold Brew","Chai Latte",
        "Matcha Latte","Affogato","Water","Refresher","Juice"};

    

    return 0;
}