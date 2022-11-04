#include <gtk/gtk.h>
#include <gtkmm.h>
#include <iostream>


int main(int argc, char *argv[]) {
    
    GtkWidget *window, *fixed; //, *layout;
    GtkWidget *review, *menu, *locations, *rewards,
              *reservation, *pay, *exit; // declare buttons
    // GtkWidget *burger_icon;

    gtk_init(&argc, &argv);

    // Initialize window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Burger Bistro");
    gtk_window_set_default_size(GTK_WINDOW(window), 1360, 600); // full window size on my screen
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // layout = gtk_layout_new(NULL, NULL);
    // gtk_container_add(GTK_CONTAINER(window), layout);
    // gtk_widget_show(layout);

    // burger_icon = gtk_image_new_from_file("/images/burger_icon.png"); //bro this should work wtf
    // gtk_layout_put(GTK_LAYOUT(layout), burger_icon, 0,0); //(x, y) coordinates

    // Review Button
    review = gtk_button_new_with_label("Write a Review");
    //gtk_layout_put(GTK_LAYOUT(layout), review, 0, 0);
    gtk_fixed_put(GTK_FIXED(fixed), review, 0, 0); // (x, y) coordinates
    gtk_widget_set_size_request(review, 70, 30); // size of the button

    // Menu Button
    menu = gtk_button_new_with_label("Menu");
    //gtk_layout_put(GTK_LAYOUT(layout), menu, 150, 0);
    gtk_fixed_put(GTK_FIXED(fixed), menu, 0, 50); 
    gtk_widget_set_size_request(menu, 70, 30); 

    // Location Button
    locations = gtk_button_new_with_label("View Locations");
    //gtk_layout_put(GTK_LAYOUT(layout), locations, 250, 0);
    gtk_fixed_put(GTK_FIXED(fixed), locations, 0, 100); 
    gtk_widget_set_size_request(locations, 70, 30); 

    // Rewards Button
    rewards = gtk_button_new_with_label("Rewards");
    //gtk_layout_put(GTK_LAYOUT(layout), rewards, 400, 0);
    gtk_fixed_put(GTK_FIXED(fixed), rewards, 0, 150); 
    gtk_widget_set_size_request(rewards, 70, 30); 

    // Reservation Button
    reservation = gtk_button_new_with_label("Make a Reservation");
    //gtk_layout_put(GTK_LAYOUT(layout), reservation, 500, 0);
    gtk_fixed_put(GTK_FIXED(fixed), reservation, 0, 200); 
    gtk_widget_set_size_request(reservation, 70, 30); 

    // Pay Online Button
    pay = gtk_button_new_with_label("Pay Online");
    //gtk_layout_put(GTK_LAYOUT(layout), pay, 700, 0);
    gtk_fixed_put(GTK_FIXED(fixed), pay, 0, 250); 
    gtk_widget_set_size_request(pay, 70, 30); 

    // Exit Button
    exit = gtk_button_new_with_label("Exit");
    //gtk_layout_put(GTK_LAYOUT(layout), exit, 1200, 0);
    gtk_fixed_put(GTK_FIXED(fixed), exit, 0, 300); // (x, y) coordinates
    gtk_widget_set_size_request(exit, 70, 30); // size of the button


    g_signal_connect(G_OBJECT(exit), "clicked", 
        G_CALLBACK(gtk_main_quit), G_OBJECT(window));

    g_signal_connect(G_OBJECT(window), "destroy", 
        G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}