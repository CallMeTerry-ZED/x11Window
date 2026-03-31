#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>

int main(void)
{
    Display *display;
    Window window;
    XEvent e;
    const char* msg;

    display = XOpenDisplay(NULL);
    msg = "Hello, World!";

    if (display == NULL)
    {
        printf("Could not open display!!\n");
        exit(1);
    }

    int screen = DefaultScreen(display);
    window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, 1280, 720, 1, BlackPixel(display, screen), WhitePixel(display, screen));
    XSelectInput(display, window, ExposureMask | KeyPressMask);
    XMapWindow(display, window);

    while (1)
    {
        XNextEvent(display, &e);
        
        if (e.type == Expose)
        {
            XFillRectangle(display, window, DefaultGC(display, screen), 20, 20, 10, 10);
            XDrawString(display, window, DefaultGC(display, screen), 10, 50, msg, strlen(msg));
        }
        if (e.type == KeyPress)
            break;
    }

    XCloseDisplay(display);
    return 0;
}