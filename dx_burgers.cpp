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
    GtkWidget *wbacon_btn, *wbacon_info, *wagyu_btn, *wagyu_info,
              *bistro_btn, *bistro_info, *gold_btn, *gold_info;

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
    
    // Western Bacon Image/ Button
    wbacon_btn = gtk_button_new();
    gtk_widget_set_name(wbacon_btn, "wbacon_btn");

    gtk_fixed_put(GTK_FIXED(fixed), wbacon_btn, 0, 100); 
    gtk_widget_set_size_request(wbacon_btn, 200, 200);

    wbacon_info = gtk_button_new_with_label("Western Bacon Cheeseburger: "
                            "\nbrioche buns, wagyu beef, onion rings, cheese, bacon, BBQ sauce "
                            "\nPrice: $20.00 \nCombo: $25.00");
    gtk_fixed_put(GTK_FIXED(fixed), wbacon_info, 200, 100); 
    gtk_widget_set_size_request(wbacon_info, 200, 200);

    // Wagyu Image/ Button
    wagyu_btn = gtk_button_new();
    gtk_widget_set_name(wagyu_btn, "wagyu_btn");
    gtk_fixed_put(GTK_FIXED(fixed), wagyu_btn, 0, 350); 
    gtk_widget_set_size_request(wagyu_btn, 200, 200);

    wagyu_info = gtk_button_new_with_label("Wagyu Burger: "
                            "\nbrioche buns, wagyu beef, cheese, pickles, " 
                            "\nketchup, cheese sauce, bistro sauce \nPrice: $30.00 \nCombo: $35.00");
    gtk_fixed_put(GTK_FIXED(fixed), wagyu_info, 200, 350); 
    gtk_widget_set_size_request(wagyu_info, 200, 200);

    // Bistro Burger Image/ Button
    bistro_btn = gtk_button_new();
    gtk_widget_set_name(bistro_btn, "bistro_btn");
    gtk_fixed_put(GTK_FIXED(fixed), bistro_btn, 700, 100); 
    gtk_widget_set_size_request(bistro_btn, 200, 200);

    bistro_info = gtk_button_new_with_label("Bistro Burger: "
                            "\nsesame buns, wagyu beef, lettuce, tomato, "
                            "\nonion rings, cheese, bistro sauce, BBQ sauce \nPrice: $30.00 \nCombo: $35.00");
    gtk_fixed_put(GTK_FIXED(fixed), bistro_info, 900, 100); 
    gtk_widget_set_size_request(bistro_info, 200, 200);

    // Gold Burger Image/ Button
    gold_btn = gtk_button_new();
    gtk_widget_set_name(gold_btn, "gold_btn");
    gtk_fixed_put(GTK_FIXED(fixed), gold_btn, 700, 350); 
    gtk_widget_set_size_request(gold_btn, 200, 200);

    gold_info = gtk_button_new_with_label("Gold Burger: \ngold sesame buns,"
                            " wagyu beef, cheese, tomato, lettuce, bistro sauce" 
                            " \nPrice: $1500.00 \nCombo: $1505.00");
    gtk_fixed_put(GTK_FIXED(fixed), gold_info, 900, 350); 
    gtk_widget_set_size_request(gold_info, 200, 200); 

    g_signal_connect(G_OBJECT(window), "destroy", 
        G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}