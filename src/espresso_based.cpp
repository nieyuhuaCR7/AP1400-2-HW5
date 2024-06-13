#include "espresso_based.h"
#include <vector>
#include "ingredient.h"
#include <string>

std::vector<Ingredient*>& EspressoBased::get_ingredients() {
    return ingredients;
}

EspressoBased::~EspressoBased()
{
    for(const auto& i : ingredients)
        delete i;
    ingredients.clear();
}

EspressoBased::EspressoBased() {
    ingredients = std::vector<Ingredient*>{};
    name = std::string{};
}

EspressoBased::EspressoBased(const EspressoBased& esp) {
    ingredients.reserve(esp.ingredients.size());
    for (Ingredient* elem: esp.ingredients) {
        ingredients.push_back(elem->copy());
    }
    name = esp.name;
}

void EspressoBased::operator=(const EspressoBased& esp) {
    if (this != &esp) {
        for (auto& i : ingredients) {
            delete i;
        }
        ingredients.clear();

        // Reserve space and copy new ingredients
        ingredients.reserve(esp.ingredients.size());
        for (auto& elem : esp.ingredients) {
            ingredients.push_back(elem->copy());
        }

        // Assign name
        name = esp.name;
    }
}