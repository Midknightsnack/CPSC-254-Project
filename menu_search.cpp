#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;

int main(){
    vector<string> cheeseburger = {"burgers", "sesame buns", "beef", "onions", "cheeseburger",
                                    "tomato", "lettuce", "cheese", "bacon", "ketchup"}; 
    vector<string> chicken_sandwich = {"burgers", "chicken", "brioche buns", "fried chicken", "pickles", "bistro sauce", "chicken sandwich"};
    vector<string> pretzel_bun = {"burgers", "pretzel buns", "beef", "lettuce", "cheese", "bacon", 
                                    "fried onions", "onions", "pickles", "bistro sauce", "pretzel bun burger"};
    vector<string> fish_burger = {"burgers", "fish", "brioche buns", "battered cod", "tomato", "lettuce", "tartar sauce", "fish burger"};

    vector<string> western_bacon = {"burgers", "deluxe", "deluxe burgers", "brioche buns", "beef", 
                                    "onion rings", "onions", "cheese", "bacon", "BBQ sauce", "western bacon cheeseburger"}; 
    vector<string> wagyu_burger = {"burgers", "deluxe", "deluxe burgers", "brioche buns", "wagyu beef", "wagyu",
                                    "cheese", "pickles", "ketchup", "cheese sauce", "bistro sauce", "wagyu burger"};
    vector<string> bistro_burger = {"burgers", "deluxe", "deluxe burgers", "sesame buns", "beef", "lettuce", "tomato", 
                                    "onion rings", "onions", "cheese", "bistro sauce", "BBQ sauce", "bistro burger"};
    vector<string> gold_burger = {"burgers", "deluxe", "deluxe burgers", "gold sesame buns", "gold", "wagyu",
                                    "wagyu beef", "cheese", "tomato", "lettuce", "bistro sauce", "gold burger"};

    vector<string> chicken_nuggets = {"sides", "chicken", "chicken nuggets"};
    vector<string> onion_rings = {"sides", "onions", "onion rings"};
    vector<string> fries = {"sides", "fries"};

    vector<string> soda = {"drinks", "soda"};
    vector<string> lemonade = {"drinks", "lemonade"};
    vector<string> milkshake = {"drinks", "strawberry", "vanilla", "chocolate", "milkshake"};
    vector<string> blue_bistro = {"drinks", "soda", "blue bistro"};

    vector <string> menu_list;

    string menu_item;
    cout << "Input food item to search: ";
    getline(cin, menu_item);
  
    // Burgers
    for (int i = 0; i < cheeseburger.size(); i++){
        if (menu_item == cheeseburger[i]){
            cout << "Cheeseburger" << endl;
            menu_list.push_back("Cheeseburger");
        }
    }

    for (int i = 0; i < chicken_sandwich.size(); i++){
        if (menu_item == chicken_sandwich[i]){
            cout << "Chicken Sandwich" << endl;
            menu_list.push_back("Chicken Sandwich");
        }
    }

    for (int i = 0; i < pretzel_bun.size(); i++){
        if (menu_item == pretzel_bun[i]){
            cout << "Pretzel Bun Burger" << endl;
            menu_list.push_back("Pretzel Bun Burger");
        }
    }

    for (int i = 0; i < fish_burger.size(); i++){
        if (menu_item == fish_burger[i]){
            cout << "Fish Burger" << endl;
            menu_list.push_back("Fish Burger");
        }
    }

    // Deluxe burgers
    for (int i = 0; i < western_bacon.size(); i++){
        if (menu_item == western_bacon[i]){
            cout << "Western Bacon Cheeseburger" << endl;
            menu_list.push_back("Western Bacon Cheeseburger");
        }
    }

    for (int i = 0; i < wagyu_burger.size(); i++){
        if (menu_item == wagyu_burger[i]){
            cout << "Wagyu Burger" << endl;
            menu_list.push_back("Wagyu Burger");
        }
    }

    for (int i = 0; i < bistro_burger.size(); i++){
        if (menu_item == bistro_burger[i]){
            cout << "Bistro Burger" << endl;
            menu_list.push_back("Bistro Burger");
        }
    }

    for (int i = 0; i < gold_burger.size(); i++){
        if (menu_item == gold_burger[i]){
            cout << "Gold Burger" << endl;
            menu_list.push_back("Gold Burger");
        }
    }

    //Sides
    for (int i = 0; i < chicken_nuggets.size(); i++){
        if (menu_item == chicken_nuggets[i]){
            cout << "Chicken Nuggets" << endl;
            menu_list.push_back("Chicken Nuggets");
        }
    }

    for (int i = 0; i < onion_rings.size(); i++){
        if (menu_item == onion_rings[i]){
            cout << "Onion Rings" << endl;
            menu_list.push_back("Onion Rings");
        }
    }

    for (int i = 0; i < fries.size(); i++){
        if (menu_item == fries[i]){
            cout << "Fries" << endl;
            menu_list.push_back("Fries");
        }
    }

    // Drinks
    for (int i = 0; i < soda.size(); i++){
        if (menu_item == soda[i]){
            cout << "Soda" << endl;
            menu_list.push_back("Soda");
        }
    }

    for (int i = 0; i < lemonade.size(); i++){
        if (menu_item == lemonade[i]){
            cout << "Lemonade" << endl;
            menu_list.push_back("Lemonade");
        }
    }

    for (int i = 0; i < milkshake.size(); i++){
        if (menu_item == milkshake[i]){
            cout << "Milkshake" << endl;
            menu_list.push_back("Milkshake");
        }
    }

    for (int i = 0; i < blue_bistro.size(); i++){
        if (menu_item == blue_bistro[i]){
            cout << "Blue Bistro" << endl;
            menu_list.push_back("Blue Bistro");
        }
    }

    //showing vector list of results
    for (int i = 0; i < menu_list.size(); i++){
        cout << menu_list[i] << endl;
    }
    cout << typeid(menu_list).name() << endl;

    // converting vector to string
    stringstream ss;
    for(size_t i = 0; i < menu_list.size(); i++){
        if (i != 0){
            ss << "\n";
        }
        ss << menu_list[i];
    }
    string menu_string = ss.str();
    cout << menu_string << endl;
    cout << typeid(menu_string).name() << endl;

    //converting string to const char*
    const char* results = menu_string.c_str();
    cout << results << endl;
    cout << typeid(results).name() << endl;

    return 0;
}