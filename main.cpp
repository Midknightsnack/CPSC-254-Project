#include <gtk/gtk.h>
#include <gtkmm.h>
#include <iostream>

int main(int argc, char *argv[]) {
    
    GtkWidget *window, *fixed;
    GtkWidget *review, *menu, *locations, *rewards, *reservation, *pay; // declare buttons

    gtk_init(&argc, &argv);

    // Initialize window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Burger Bistro");
    gtk_window_set_default_size(GTK_WINDOW(window), 1000, 800);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Review Button
    review = gtk_button_new_with_label("Write a Review");
    gtk_fixed_put(GTK_FIXED(fixed), review, 0, 0); // (x, y) coordinates
    gtk_widget_set_size_request(review, 70, 30); // size of the button

    // Menu Button
    menu = gtk_button_new_with_label("Menu");
    gtk_fixed_put(GTK_FIXED(fixed), menu, 150, 0); // (x, y) coordinates
    gtk_widget_set_size_request(menu, 70, 30); // size of the button

    // Location Button
    locations = gtk_button_new_with_label("View Locations");
    gtk_fixed_put(GTK_FIXED(fixed), locations, 250, 0); // (x, y) coordinates
    gtk_widget_set_size_request(locations, 70, 30); // size of the button

    // Rewards Button
    rewards = gtk_button_new_with_label("Rewards");
    gtk_fixed_put(GTK_FIXED(fixed), rewards, 400, 0); // (x, y) coordinates
    gtk_widget_set_size_request(rewards, 70, 30); // size of the button

    // Reservation Button
    reservation = gtk_button_new_with_label("Make a Reservation");
    gtk_fixed_put(GTK_FIXED(fixed), reservation, 500, 0); // (x, y) coordinates
    gtk_widget_set_size_request(reservation, 70, 30); // size of the button

    // Pay Online Button
    pay = gtk_button_new_with_label("Pay Online");
    gtk_fixed_put(GTK_FIXED(fixed), pay, 700, 0); // (x, y) coordinates
    gtk_widget_set_size_request(pay, 70, 30); // size of the button

    g_signal_connect(G_OBJECT(review), "clicked", 
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

    g_signal_connect(G_OBJECT(window), "destroy", 
        G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}