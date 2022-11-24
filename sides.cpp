//     This file is part of Burger Bistro.

//     Burger Bistro is a web application that allows users to interact with a restaurant website.
//     Copyright (C) <2022>  <Bradley Diep>

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
#include <cairo.h>
#include <gtkmm.h>
#include <iostream>
#include "click.h"
using namespace std;

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
    
    GtkWidget *window, *fixed, *back_button; 
    GtkWidget *review, *locations, *rewards,
              *reservation, *pay;
    GtkWidget *nuggets_btn, *nuggets_info, *fries_btn, *fries_info,
              *onion_rings_btn, *onion_rings_info;

    gtk_init(&argc, &argv);
    load_css();

    // Initialize window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Burger Bistro");
    gtk_window_set_default_size(GTK_WINDOW(window), 1360, 600); 
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Back Button
    back_button = gtk_button_new_with_label("Back");
    gtk_fixed_put(GTK_FIXED(fixed), back_button, 0, 25); 
    gtk_widget_set_size_request(back_button, 100, 50); 

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
    gtk_fixed_put(GTK_FIXED(fixed), reservation, 1000, 25); 
    gtk_widget_set_size_request(reservation, 100, 50); 

    // Pay Online Button
    pay = gtk_button_new_with_label("Pay Online");
    gtk_fixed_put(GTK_FIXED(fixed), pay, 1260, 25); 
    gtk_widget_set_size_request(pay, 100, 50);
    
    // Chicken Nuggets Image/ Button
    nuggets_btn = gtk_button_new();
    gtk_widget_set_name(nuggets_btn, "nuggets_btn");

    gtk_fixed_put(GTK_FIXED(fixed), nuggets_btn, 0, 100); 
    gtk_widget_set_size_request(nuggets_btn, 200, 200);

    nuggets_info = gtk_button_new_with_label("Chicken Nuggets: \n5 pc: $3.00 \n10 pc: $4.50");
    gtk_fixed_put(GTK_FIXED(fixed), nuggets_info, 200, 100); 
    gtk_widget_set_size_request(nuggets_info, 200, 200);

    // Fries Image/ Button
    fries_btn = gtk_button_new();
    gtk_widget_set_name(fries_btn, "fries_btn");
    gtk_fixed_put(GTK_FIXED(fixed), fries_btn, 0, 350); 
    gtk_widget_set_size_request(fries_btn, 200, 200);

    fries_info = gtk_button_new_with_label("Fries: \nSmall: $1.50 \nMedium: $1.75 \nLarge: $2.00");
    gtk_fixed_put(GTK_FIXED(fixed), fries_info, 200, 350); 
    gtk_widget_set_size_request(fries_info, 200, 200);

    // Onion Rings Image/ Button
    onion_rings_btn = gtk_button_new();
    gtk_widget_set_name(onion_rings_btn, "onion_rings_btn");
    gtk_fixed_put(GTK_FIXED(fixed), onion_rings_btn, 700, 100); 
    gtk_widget_set_size_request(onion_rings_btn, 200, 200);

    onion_rings_info = gtk_button_new_with_label("Onion Rings (10 pc): \nPrice: $4.00");
    gtk_fixed_put(GTK_FIXED(fixed), onion_rings_info, 900, 100); 
    gtk_widget_set_size_request(onion_rings_info, 200, 200);

    g_signal_connect(G_OBJECT(window), "destroy", 
        G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}