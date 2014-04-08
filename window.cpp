#include "window.h"

Window::Window() {
    //Initialize root window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //Configure window specific parameters
    gtk_window_set_title(GTK_WINDOW(window), "GitGUI-C++");
    gtk_window_set_default_size(GTK_WINDOW(window), 230, 150);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    //Hook up events at window level
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GdkDisplay *display;
    GdkScreen *screen;
    css_provider = gtk_css_provider_new();
    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen(display);

    gtk_style_context_add_provider_for_screen(screen,
                                 GTK_STYLE_PROVIDER(css_provider),
                                 GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    gtk_css_provider_load_from_file(css_provider, g_file_new_for_path("./app_style.css"), NULL);

    main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), main_box);

    //Initialize the menu
    gtk_box_pack_start(GTK_BOX(main_box), Menu::getMenuBar(), false, false, 0);
    grid = gtk_grid_new();
    list_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget* label = gtk_label_new("Omnomnom");
    gtk_box_pack_start(GTK_BOX(list_box), label, false, false, 0);
    gtk_grid_attach(GTK_GRID(grid), list_box, 0, 0, 1, 3);
    gtk_box_pack_start(GTK_BOX(main_box), grid, false, false, 0);

    //Finally, display it all.
    gtk_widget_show_all(window);
}

Window::~Window() {
}
