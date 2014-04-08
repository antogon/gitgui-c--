#ifndef __GTK__
#define __GTK__
#include <gtk/gtk.h>
#endif
#ifndef __MENU__
#include "menu.h"
#endif
#define __WINDOW__

class Window {
    private:
        GtkWidget* window; 
        GtkWidget* grid; 
        GtkWidget* list_box;
        GtkWidget* main_box;
        GtkCssProvider* css_provider;
    protected:
    public:
        Window();
        ~Window();
};
