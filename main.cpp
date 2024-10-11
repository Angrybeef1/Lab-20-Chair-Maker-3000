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

    //creating dynamic chair object with constructor
    Chair *livingChair = new Chair(3);
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    collection[0].setLegs(4);
    collection[0].setPrices(441.41, 552.52, 663.63);
    collection[1].setLegs(4);
    collection[1].setPrices(484.84, 959.59, 868.68);
    collection[2].setLegs(4);
    collection[2].setPrices(626.26, 515.15, 757.57);
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}