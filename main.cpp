#include <gtk/gtk.h>
#include "window.h"

int main(int argc, char** argv) {
    gtk_init(&argc, &argv);
    Window* application = new Window();
    gtk_main();
    delete application;
    return 0;
}
