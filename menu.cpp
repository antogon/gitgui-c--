#include "menu.h"

Menu* Menu::instance = NULL;

Menu::Menu() {
        menu_bar = gtk_menu_bar_new();
        file_menu = gtk_menu_new();
        file_item = gtk_menu_item_new_with_label("File");
        add_repo_item = gtk_menu_item_new_with_label("Add Repository");
        rm_repo_item = gtk_menu_item_new_with_label("Remove Repository");
        pref_item = gtk_menu_item_new_with_label("Preferences...");
        quit_item = gtk_menu_item_new_with_label("Quit");
        gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), add_repo_item);
        gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), rm_repo_item);
        gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), pref_item);
        gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), quit_item);
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_item), file_menu);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_item);
        g_signal_connect(add_repo_item, "activate", G_CALLBACK(&Menu::add_repo_handler), NULL);
        g_signal_connect(rm_repo_item, "activate", G_CALLBACK(&Menu::rm_repo_handler), NULL);
        g_signal_connect(pref_item, "activate", G_CALLBACK(&Menu::pref_handler), NULL);
        g_signal_connect(quit_item, "activate", G_CALLBACK(&Menu::quit_handler), NULL);
}

Menu::~Menu() {
}

GtkWidget* Menu::getMenuBar() {
    if(instance==NULL) {
        instance = new Menu();
    }
    return instance->menu_bar;
}

void Menu::add_repo_handler(GtkMenuItem *menuitem, gpointer user_data) {
    std::cout << "Add Repository clicked" << std::endl;
    RepoCollection* repos = RepoCollection::getInstance();
    repos->add("Test Click","nothing");
    repos->print();
}

void Menu::rm_repo_handler(GtkMenuItem *menuitem, gpointer user_data) {
    std::cout << "Remove Repo" << std::endl;
}

void Menu::pref_handler(GtkMenuItem *menuitem, gpointer user_data) {
    std::cout << "Preferences" << std::endl;
}

void Menu::quit_handler(GtkMenuItem *menuitem, gpointer user_data) {
    gtk_main_quit();
}
