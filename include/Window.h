#ifndef WINDOW_H
#define WINDOW_H

class Window {
    // Functions
    public:
        Window(int width, int height) {
            window_height = height;
            window_width = width;
        }
        void Start();
    private:
        void Loop();
        void Close();

    // Data fields
    private:
        // Basic properties for the window
        int window_height;
        int window_width;
};

#endif