#ifndef INGREDIENT_H
#define INGREDIENT_H


#include <string>  // For std::string
#include <cstddef> // For std::size_t

class Ingredient
{
public:
    virtual ~Ingredient() = default;
    virtual Ingredient *copy() = 0;
    double get_price_unit();
    size_t get_units();
    virtual std::string get_name() = 0;

    double price();
    

protected:
    // Constructor
    Ingredient(double price_unit, size_t units);
    // Protected member variables
    double price_unit;
    size_t units;
    std::string name;
};

// Implementations

// Constructor
inline Ingredient::Ingredient(double price_unit, size_t units) {
    this->price_unit = price_unit;
    this->units = units;
}

// get price per unit
inline double Ingredient::get_price_unit() {
    return price_unit;
}

// get units
inline size_t Ingredient::get_units() {
    return units;
}

// get total price
inline double Ingredient::price() {
    return units * price_unit;
}

#endif // INGREDIENT_H