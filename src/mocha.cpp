#include "mocha.h"
#include "cappuccino.h"
#include "sub_ingredients.h"
#include <iostream>
// constructor
Mocha::Mocha() : EspressoBased() {
    name = "Mocha";
    ingredients = std::vector<Ingredient*>{};
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));
    ingredients.push_back(new Chocolate(1));

}

// destructor
Mocha::~Mocha() {
    // for(const auto& i : side_items)
    //     delete i;
    // do not delete the same element twice
    side_items.clear();
}

std::string Mocha::get_name() {
    return name;
}

void Mocha::brew() {
    std::cout << "a cup of Mocha has been brewed" << std::endl;
}

void Mocha::operator=(const Mocha& cap) {
    if (this != &cap) {
        for (auto &i : side_items) {
            delete i;
        }
        side_items.clear();

        side_items.reserve(cap.side_items.size());
        for (Ingredient* elem: cap.side_items) {
            side_items.push_back(elem->copy());
        }
    }
}

double Mocha::price() {
    double result = 0.0;
    for (auto& i: ingredients) {
        result += i->price();
    }
    return result;
}

void Mocha::add_side_item(Ingredient* side) {
    ingredients.push_back(side);
    side_items.push_back(side);
}

std::vector<Ingredient*>& Mocha::get_side_items() {
    return side_items;
}
