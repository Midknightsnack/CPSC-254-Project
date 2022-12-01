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

#include <gtk/gtk.h>
#include <cstring>
#include <gtkmm.h>
#include <iostream>
using namespace std;

GtkWidget *reservation_date, *reservation_time, *reservation_name, *reservation_number;
GtkWidget *result, *star_result, *radio, *radio2;

void toggled_func(GtkWidget* widget, gpointer data);
void print_review(GtkWidget *submit_btn, gpointer data);

// allows css properties to load in GUI
void load_css(){
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;

    const gchar *css_style_file = "styles.css";
    GFile *css_fp = g_file_new_for_path(css_style_file);
    GError *error = 0;

    provider = gtk_css_provider_new();
    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen (display);

    gtk_style_context_add_provider_for_screen (screen, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_css_provider_load_from_file(provider, css_fp, &error);

    g_object_unref(provider); 
}


int main(int argc, char *argv[]) {
    GtkWidget *window, *fixed; 
    GtkWidget *review, *menu, *locations, *rewards,
              *reservation, *pay, *exit; // declare buttons
    GtkWidget *rating_label, *review_label, *submit_btn;
    
    gtk_init(&argc, &argv);
    load_css();

    // Initialize window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Burger Bistro");
    gtk_window_set_default_size(GTK_WINDOW(window), 1360, 600); // full window size on my screen
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Menu Button
    menu = gtk_button_new_with_label("Menu");
    gtk_fixed_put(GTK_FIXED(fixed), menu, 0, 25); // (x, y) coordinates
    gtk_widget_set_size_request(menu, 100, 50); // size of the button (x,y)

    // Review Button
    review = gtk_button_new_with_label("Write a Review");
    gtk_widget_set_name(review, "btn_red"); // button only turns red when clicked on
    gtk_fixed_put(GTK_FIXED(fixed), review, 225, 25); 
    gtk_widget_set_size_request(review, 100, 50); 
    
    // Location Button
    locations = gtk_button_new_with_label("View Locations");
    gtk_fixed_put(GTK_FIXED(fixed), locations, 450, 25); 
    gtk_widget_set_size_request(locations, 100, 50); 

    // Rewards Button
    rewards = gtk_button_new_with_label("Rewards");
    gtk_fixed_put(GTK_FIXED(fixed), rewards, 775, 25); 
    gtk_widget_set_size_request(rewards, 100, 50); 

    // Reservation Button
    reservation = gtk_button_new_with_label("Make a Reservation");
    gtk_widget_set_name(reservations, "resbutton");
    gtk_fixed_put(GTK_FIXED(fixed), reservation, 1000, 25); 
    gtk_widget_set_size_request(reservation, 100, 50); 

    // Pay Online Button
    pay = gtk_button_new_with_label("Pay/Order Online");
    gtk_fixed_put(GTK_FIXED(fixed), pay, 1240, 25); 
    gtk_widget_set_size_request(pay, 100, 50); 

    reservation_date = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixed), reservation_date, 200, 130); 
    gtk_widget_set_size_request(reservation_date, 400, 200); 

    reservation_time = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixed), reservation_time, 200, 130); 
    gtk_widget_set_size_request(reservation_time, 400, 200);

    reservation_name = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixed), reservation_name, 200, 130); 
    gtk_widget_set_size_request(reservation_name, 400, 200);

    reservation_number = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixed), reservation_number, 200, 130); 
    gtk_widget_set_size_request(reservation_number, 400, 200);

    result = gtk_label_new("Reservation is complete, Thank You!");
    gtk_widget_set_name(result, "reservation_con");
    gtk_fixed_put(GTK_FIXED(fixed), result, 700, 200); 
    gtk_widget_set_size_request(result, 100, 100); 

    g_signal_connect(G_OBJECT(window), "destroy", 
        G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
/*
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
*/