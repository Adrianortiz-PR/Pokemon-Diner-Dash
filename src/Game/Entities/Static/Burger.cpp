//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item)
{
    ingredients.push_back(item);
}
void Burger::RemoveIngredient()
{
    if (!ingredients.empty())
    { // Only removes ingredients when the vector has ingredients inside
        ingredients.pop_back();
    }
}

void Burger::render()
{
    int counter = 1;
    for (Item *ingredient : ingredients)
    {
        ingredient->sprite.draw(x - 5, y - (counter * 10) + 55, width * 0.70, height * 0.70);
        counter++;
    }
}

void Burger::clear()
{
    ingredients.clear(); // Changed from .empty()
}

bool Burger::equals(Burger *b)
{
    // check if sizes of ingredient vectors are equal
    if (ingredients.size() != b->GetCopyOfVector().size())
    {
        return false;
    }
    // check if top and bottom buns are in correct positions
    if (ingredients[0]->getName() != "bottomBun" || b->GetCopyOfVector()[0]->getName() != "bottomBun")
    {
        return false;
    }
    if (ingredients[ingredients.size() - 1]->getName() != "topBun" || b->GetCopyOfVector()[b->GetCopyOfVector().size() - 1]->getName() != "topBun")
    {
        return false;
    }

    for (int i = 0; i < (int)ingredients.size(); i++)
    {
        for (int j = 0; j < (int)b->GetCopyOfVector().size(); j++)
        {
            if (ingredients[i] == b->GetCopyOfVector()[j])
            {
                // Once a matching element is found for the current element, 'break' skips unnecesary comparasions.
                break;
            }
            if (j == (int)b->GetCopyOfVector().size() - 1)
            {
                // checks if the inner for loop has iterated through all the elements of vector b without finding a matching element.
                return false;
            }
        }
    }
    return true;
}
