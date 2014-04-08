#ifndef __GTK__
#define __GTK__
#include <gtk/gtk.h>
#endif
#include <iostream>
#include "repocollection.h"
#define __MENU__

class Menu {
    private:
        static Menu* instance;
        GtkWidget* menu_bar;
        GtkWidget* file_menu;
        GtkWidget* file_item;
        GtkWidget* add_repo_item;
        GtkWidget* rm_repo_item;
        GtkWidget* pref_item;
        GtkWidget* quit_item;
        Menu();
        ~Menu();

    protected:
    public:
        static GtkWidget* getMenuBar();
        static void add_repo_handler(GtkMenuItem *menuitem, gpointer user_data);
        static void rm_repo_handler(GtkMenuItem *menuitem, gpointer user_data);
        static void pref_handler(GtkMenuItem *menuitem, gpointer user_data);
        static void quit_handler(GtkMenuItem *menuitem, gpointer user_data);
};

