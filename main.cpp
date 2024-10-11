//COMSC 210 | LAb 20 Chair Maker 3000 | Robert Stonemetz

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;


//const for array size and range
const int SIZE = 3;
const int MIN = 10000; 
const int MAX = 99999;

class Chair {
private:
    int legs;
    double * prices;

    //function to generate random prices between 100 and 999.99 dollars
    double randomPrice() {
        return (rand() % (MAX-MIN + 1) + MIN) / (double) 100.0;
    }


public:
    // constructors
    Chair() {
        prices = new double[SIZE];
        legs = (rand() % 2) +3; //random for 3 or 4 legs
        for (int i = 0; i < SIZE; i++) {
            prices[i] = randomPrice();
        }
    }

    //parameter constructor. uses legs and prices
    Chair(int l, const double p[SIZE]) {
        prices = new double[SIZE];
        legs = l;
        for (int i = 0; i < SIZE; i++) {
            prices[i] = p[i];
        }   
    }
    
    //destructor

    ~Chair() {
        delete[] prices;
    }

    //assignemnt operator

    Chair& operator=(const Chair& other) {
        if (this != &other) {
            legs = other.legs;
            delete[] prices;
            prices = new double[SIZE];
            for (int i = 0; i < SIZE; i++) {
                prices[i] = other.prices[i];
            }
        }
        return *this;
    }


    // setters and getters
    void setLegs(int l) { legs = l; }
    int getLegs() { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    //gets average prices
    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    //prints the chairs data
    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " ;
        for (int i = 0; i < SIZE; i++)
            cout << prices[i] << " ";
        cout << endl << "Historical avg price: " << getAveragePrices();
        cout << endl << endl;
    }
};

int main() {

    //seeds the rand generator
    srand(static_cast<unsigned int>(time(nullptr)));

    //sets formatting
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    cout << "Default constructed chair: " << endl;
    chairPtr -> print();

    // Create and print another chair using default constructor
    Chair* livingChair = new Chair;
    cout << "Another default constructed chair: " << endl;
    livingChair->print();

    // Clean up livingChair to demonstrate early deletion
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];

    cout << "Array of default constructed chairs:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Chair " << i + 1 << ":" << endl;
        collection[i].print();
    }

    //Clean up dynamically allocated memory
    delete chairPtr;
    delete[] collection;
    
    return 0;
}