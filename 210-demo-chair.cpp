#include <iostream>
#include <iomanip>
#include <random>

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double * prices;
public:

    // constructors
    Chair() {
        // Seeds the random number generator to the time
        // Uses random_device as seed srand instead of time
        random_device rd;
        uniform_int_distribution<int> dist(100,1000);
        int seed = dist(rd);

        srand(seed);

        prices = new double[SIZE];
        legs = (rand() % 2)+3;

        for (int i = 0; i < SIZE; i++)
            // Calculates the larger integer than adds a decimal value
            prices[i] = (rand()%900 + 99) + (((double)(rand()%100))/100);
    }
    Chair(int l, double* Prices) {
        prices = Prices;
        legs = l;
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

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
    cout << fixed << setprecision(2);

    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    Chair *chairPtr1 = new Chair;
    chairPtr1->print();
    Chair *chairPtr2 = new Chair;
    chairPtr2->print();
    Chair *chairPtr3 = new Chair;
    chairPtr3->print();
    Chair *chairPtr4 = new Chair;
    chairPtr4->print();


    //creating dynamic chair object with constructor
    double* priceList = new double[SIZE];
    priceList[0] = 525.25;
    priceList[1] = 434.34;
    priceList[2] = 252.52;


    Chair *livingChair = new Chair(3, priceList);
    livingChair->print();
    delete livingChair;

    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++){
        collection[i].print();
    }


    return 0;
}