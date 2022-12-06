//     Burger Bistro is a web application that allows users to interact with a restaurant website.
//     Copyright (C) <2022>  <Vanessa Ayala>

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

    string date;
    string time;
    string name;
    string number;
    
    //Display the page currently on
    cout << "Make a reservation!" << endl;

    //Ask for customers info
    cout << "Please enter the date for your reservation (ex: 02/25): ";
    cin >> date;

    cout << "Please enter the time for your reservation: ";
    cin >> time;

    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter your phone number: ";
    cin >> number;

    cout << "Thank you, " << name << " for making a reservation with Burger Bistro on " << date << " at " << time << "." << endl;
    
    return 0;

}
