#include "headers/Managers.h"
int main() {
    Window window;
    window.initializeOpenGL();
    RenderManager renderManager = RenderManager(&window);
    window.open(1600, 900, "Window");
    renderManager.testFunction();
    return 0;
}