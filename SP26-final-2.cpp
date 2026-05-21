// COMSC-210 | SP26-Final-2 | Gabriel Marquez

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <list>
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
    deque<string> muffinLine;
    vector<string> braceletLine;
    list<string> popcornLine;
    
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
    cout << endl;

    for (int i = 0; i < ROUNDS; ++i) {
        cout << "\tRound: " << i + 1 << endl;
        cout << "Coffee queue:" << endl;
        if (!head) {
            int prob = rand() % 100 + 1;
            if (prob <= JOIN_PROB)
                addToTail(head, names, drinks);
            else
                cout << "No change" << endl;
        }
        else {
            Node *current = head;
            cout << current->name << " was served a(n) " << current->order << endl;
            head = current->next;
            delete current;
            current = nullptr;
            int prob = rand() % 100 + 1;
            if (prob <= JOIN_PROB)
                addToTail(head, names, drinks);
        }

        //Milestone 3 deque simulation
        cout << "\nMuffin queue:" << endl;
        if (muffinLine.empty()) {
            int prob = rand() % 100 + 1;
            if (prob <= JOIN_PROB) {
                muffinLine.push_back(names[rand() % ARR_SIZE]);
                cout << muffinLine.back() << " joined the muffin queue" << endl;
            }
            else
                cout << "No change" << endl;
        }
        else {
            cout << muffinLine.front() << " was served a muffin" << endl;
            muffinLine.pop_front();
            int prob = rand() % 100 + 1;
            if (prob <= JOIN_PROB) {
                muffinLine.push_back(names[rand() % ARR_SIZE]);
                cout << muffinLine.back() << " joined the muffin queue" << endl;
            }
        }

        //Milestone 4 vector simulation
        cout << "\nBracelet queue:" << endl;
        if (braceletLine.empty()) {
            int prob = rand() % 100 + 1;
            if (prob <= JOIN_PROB) {
                string name = names[rand() % ARR_SIZE];
                braceletLine.push_back(name);
                cout << name << " joined the bracelet queue" << endl;
            }
            else
                cout << "No change" << endl;
        }
        else {
            cout << braceletLine[0] << " bought a friendship bracelet" << endl;
            braceletLine.erase(braceletLine.begin());
            int prob = rand() % 100 + 1;
            if (prob <= JOIN_PROB) {
                string name = names[rand() % ARR_SIZE];
                braceletLine.push_back(name);
                cout << name << " joined the bracelet queue" << endl;
            }
        }

        //Milestone 5 list simulation
        cout << "\nPopcorn queue:" << endl;
        if (popcornLine.empty()) {
             int prob = rand() % 100 + 1;
            if (prob <= JOIN_PROB) {
                string name = names[rand() % ARR_SIZE];
                popcornLine.push_back(name);
                cout << name << " joined the popcorn queue" << endl;
            }
            else
                cout << "No change" << endl;
        }
        else {
            cout << popcornLine.front() << " was served popcorn" << endl;
            popcornLine.pop_front();
            int prob = rand() % 100 + 1;
            if (prob <= JOIN_PROB) {
                popcornLine.push_back(names[rand() % ARR_SIZE]);
                cout << popcornLine.back() << " joined the popcorn queue" << endl;
            }
        }
        cout << endl;
    }

    cout << "Remaining customers:" << endl;
    cout << "Coffee queue:" << endl;
    Node *current = head;
    while (current) {
        cout << current->name << endl;
        current = current->next;
    }

    cout << "\nMuffin queue:" << endl;
    for (int i = 0; i < muffinLine.size(); ++i)
        cout << muffinLine[i] << endl;

    cout << "\nBracelet queue:" << endl;
    for (int i; i < braceletLine.size(); ++i)
        cout << braceletLine[i] << endl;

    cout << "\nPopcorn queue:" << endl;
    for (const auto &person : popcornLine)
        cout << person << endl;

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
        cout << newCustomer->name << " joined the coffee queue" << endl;
    }
    else {
        Node *current = head;
        while (current->next)
            current = current->next;
        current->next = newCustomer;
        newCustomer->next = nullptr;
        newCustomer->name = person;
        newCustomer->order = drink;
        cout << newCustomer->name << " joined the coffee queue" << endl;
    }
}