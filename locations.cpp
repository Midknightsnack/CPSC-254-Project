//     Burger Bistro is a web application that allows users to interact with a restaurant website.
//     Copyright (C) <2022>  <Jose Delgadillo>

//     Burger Bistro is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.

//     Burger Bistro is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.

//     You should have received a copy of the GNU General Public License
//     along with Burger Bistro. If not, see <https://www.gnu.org/licenses/>.

#include <iostream>

using namespace std;

int main(){

    int zipcode;

    cout << "Welcome to the Burger Bistro Locater!" << endl;

    cout << "Please enter your zipcode to find the nearest 3 locations ";
    cin >> zipcode;

    if (zipcode == 92831){
        cout << "\n825 W Chapman Ave\n"
                    "Placentia,CA 92870\n"
                        "United States" << endl;
        cout << "\n1130 E Imperial Hwy\n"
                    "Brea,CA 92821\n"
                        "United States" << endl;
        cout << "\n1180 S Harbor Blvd\n"
                    "Fullerton,CA 92832\n"
                        "United States" << endl;
    }
    else 
    {
        cout << "\n14341 Firestone Blvd\n"
                    "La Mirada,CA 90638\n"
                        "United States" << endl;
        cout << "\n7926 Valley View St\n"
                    "Buena Park,CA 90620\n"
                        "United States" << endl;
        cout << "\n1761 W Whittier Blvd\n"
                    "La Habra,CA 90631\n"
                        "United States" << endl;
    }
    return 0;
}