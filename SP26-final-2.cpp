// COMSC-210 | SP26-Final-2 | Gabriel Marquez

#include <iostream>
#include <string>
using namespace std;

int ARR_SIZE = 15, ROUNDS = 10, LIST_START = 3;
int JOIN_PROB = 50;

struct Node {
    string name;
    string order;
    Node *next;
};

void addToTail(Node *&, string[], string[]);

int main() {
    srand(time(0));
    Node *head = nullptr;
    
    string names[ARR_SIZE] = {
        "Oliver", "Emma", "Liam", "Ava", "Noah",
        "Sophia", "Lucas", "Isabella", "Mason", "Mia",
        "Ethan", "Harper", "James", "Evelyn", "Alexander"};
    string drinks[ARR_SIZE] = {
        "Espresso","Macchiato","Cortado","Cappuccino","Flat White",
        "Caffè Latte","Americano","Mocha","Cold Brew","Chai Latte",
        "Matcha Latte","Affogato","Water","Refresher","Juice"};

    //simulation for Milestone 2
    for (int i = 0; i < LIST_START; ++i) {
        addToTail(head, names, drinks);
    }

    cout << "Initial queue for coffee shop:" << endl;
    Node *current = head;
    while (current) {
        cout << current->name << endl;
        current = current->next;
    }

    for (int i = 0; i < ROUNDS; ++i) {
        cout << "Round: " << i + 1 << endl;
        if (!head) {
            int prob = rand() % 100 + 1;
            if (prob <= JOIN_PROB)
                addToTail(head, names, drinks);
        }
        else {
            Node *current = head;
            head = current->next;
            delete current;
            current = nullptr;
            int prob = rand() % 100 + 1;
            if (prob <= JOIN_PROB)
                addToTail(head, names, drinks);
        }
    }

    current = head;
    while (current) {
        cout << current->name << " " << current->order << endl;
        current = current->next;
    }

    return 0;
}

void addToTail(Node *&head, string n[], string d[]) {
    string person = n[rand() % ARR_SIZE];
    string drink = d[rand() % ARR_SIZE];

    Node *newCustomer = new Node;
    if (!head) {
        head = newCustomer;
        newCustomer->next = nullptr;
        newCustomer->name = person;
        newCustomer->order = drink;
        cout << newCustomer->name << " joined the queue" << endl;
    }
    else {
        Node *current = head;
        while (current->next)
            current = current->next;
        current->next = newCustomer;
        newCustomer->next = nullptr;
        newCustomer->name = person;
        newCustomer->order = drink;
        cout << newCustomer->name << " joined the queue" << endl;
    }
}