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
#include <cstring>
#include <gtkmm.h>
#include <iostream>
using namespace std;

GtkWidget *review_input;
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
//*radio, *radio2,
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
    gtk_fixed_put(GTK_FIXED(fixed), reservation, 1000, 25); 
    gtk_widget_set_size_request(reservation, 100, 50); 

    // Pay Online Button
    pay = gtk_button_new_with_label("Pay/Order Online");
    gtk_fixed_put(GTK_FIXED(fixed), pay, 1240, 25); 
    gtk_widget_set_size_request(pay, 100, 50); 

    //Star Rating
    rating_label = gtk_label_new("Rate our Restaurant:");
    gtk_widget_set_name(rating_label, "rating_label");
    gtk_fixed_put(GTK_FIXED(fixed), rating_label, 0, 65); 
    gtk_widget_set_size_request(rating_label, 100, 100); 

    radio = gtk_radio_button_new_with_label(NULL, "1 star");
    gtk_fixed_put(GTK_FIXED(fixed), radio, 0, 125); 
    gtk_widget_set_size_request(radio, 50, 20); 
    g_signal_connect(radio, "clicked", G_CALLBACK(toggled_func), (gpointer)"1"); 
    //putting "toggled" instead of "clicked" works too

    radio2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio)), "2 stars");
    gtk_fixed_put(GTK_FIXED(fixed), radio2, 0, 150); 
    gtk_widget_set_size_request(radio2, 50, 20); 
    g_signal_connect(radio2, "clicked", G_CALLBACK(toggled_func), (gpointer)"2");

    radio2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio)), "3 stars");
    gtk_fixed_put(GTK_FIXED(fixed), radio2, 0, 175); 
    gtk_widget_set_size_request(radio2, 50, 20);
    g_signal_connect(radio2, "clicked", G_CALLBACK(toggled_func), (gpointer)"3");

    radio2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio)), "4 stars");
    gtk_fixed_put(GTK_FIXED(fixed), radio2, 0, 200); 
    gtk_widget_set_size_request(radio2, 50, 20);
    g_signal_connect(radio2, "clicked", G_CALLBACK(toggled_func), (gpointer)"4");

    radio2 = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio)), "5 stars");
    gtk_fixed_put(GTK_FIXED(fixed), radio2, 0, 225); 
    gtk_widget_set_size_request(radio2, 50, 20);
    g_signal_connect(radio2, "clicked", G_CALLBACK(toggled_func), (gpointer)"5");

    //Writing a Review
    review_label = gtk_label_new("Write a Review:");
    gtk_widget_set_name(review_label, "rating_label");
    gtk_fixed_put(GTK_FIXED(fixed), review_label, 200, 65); 
    gtk_widget_set_size_request(review_label, 100, 100); 

    review_input = gtk_entry_new();
    gtk_fixed_put(GTK_FIXED(fixed), review_input, 200, 130); 
    gtk_widget_set_size_request(review_input, 400, 200); 

    submit_btn = gtk_button_new_with_label("Submit");
    gtk_fixed_put(GTK_FIXED(fixed), submit_btn, 200, 330); 
    gtk_widget_set_size_request(submit_btn, 100, 50); 
    g_signal_connect(submit_btn, "clicked", G_CALLBACK(print_review), NULL);
    //g_signal_connect(submit_btn, "clicked", G_CALLBACK(toggled_func), NULL);

    // Printing results
    result = gtk_label_new("Review will appear here");
    gtk_widget_set_name(result, "review_results");
    gtk_fixed_put(GTK_FIXED(fixed), result, 700, 200); 
    gtk_widget_set_size_request(result, 100, 100); 

    star_result = gtk_label_new("1 star");
    gtk_widget_set_name(star_result, "review_results");
    gtk_fixed_put(GTK_FIXED(fixed), star_result, 700, 125); 
    gtk_widget_set_size_request(star_result, 100, 100); 

    g_signal_connect(G_OBJECT(window), "destroy", 
        G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}


void print_review(GtkWidget *submit_btn, gpointer data){
    const char* review = gtk_entry_get_text(GTK_ENTRY(review_input));
    //const char* review = "wow";
    gtk_label_set_text(GTK_LABEL(result), review);
}


void toggled_func(GtkWidget* radio, gpointer data){
    if(strcmp((char*)data, "1") == 0){
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio))){
            g_print("Button %s is set to active\n", (char*)data);
            const char* stars = "1 star";
            gtk_label_set_text(GTK_LABEL(star_result), stars);
        }else{
            g_print("Button %s is set to deactive\n", (char*)data);
        }
    }

    if(strcmp((char*)data, "2") == 0){
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio))){
            g_print("Button %s is set to active\n", (char*)data);
            const char* stars = "2 stars";
            gtk_label_set_text(GTK_LABEL(star_result), stars);
        }else{
            g_print("Button %s is set to deactive\n", (char*)data);
        }
    }

    if(strcmp((char*)data, "3") == 0){
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio))){
            g_print("Button %s is set to active\n", (char*)data);
            const char* stars = "3 stars";
            gtk_label_set_text(GTK_LABEL(star_result), stars);
        }else{
            g_print("Button %s is set to deactive\n", (char*)data);
        }
    }

    if(strcmp((char*)data, "4") == 0){
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio))){
            g_print("Button %s is set to active\n", (char*)data);
            const char* stars = "4 stars";
            gtk_label_set_text(GTK_LABEL(star_result), stars);
        }else{
            g_print("Button %s is set to deactive\n", (char*)data);
        }
    }

    if(strcmp((char*)data, "5") == 0){
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio))){
            g_print("Button %s is set to active\n", (char*)data);
            const char* stars = "5 stars";
            gtk_label_set_text(GTK_LABEL(star_result), stars);
        }else{
            g_print("Button %s is set to deactive\n", (char*)data);
        }
    }

}