#include "cappuccino.h"
#include "sub_ingredients.h"
#include <iostream>
// constructor
Cappuccino::Cappuccino() : EspressoBased() {
    name = "Cappuccino";
    ingredients = std::vector<Ingredient*>{};
    ingredients.push_back(new Espresso(2));
    ingredients.push_back(new Milk(2));
    ingredients.push_back(new MilkFoam(1));

}

// destructor
Cappuccino::~Cappuccino() {
    // for(const auto& i : side_items)
    //     delete i;
    // do not delete the same element twice
    side_items.clear();
}

std::string Cappuccino::get_name() {
    return name;
}

void Cappuccino::brew() {
    std::cout << "a cup of Cappuccino has been brewed" << std::endl;
}

void Cappuccino::operator=(const Cappuccino& cap) {
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

double Cappuccino::price() {
    double result = 0.0;
    for (auto& i: ingredients) {
        result += i->price();
    }
    return result;
}

void Cappuccino::add_side_item(Ingredient* side) {
    ingredients.push_back(side);
    side_items.push_back(side);
}

std::vector<Ingredient*>& Cappuccino::get_side_items() {
    return side_items;
}
