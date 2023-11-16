#include <GLFW/glfw3.h>

#include <functional>

#include "imgui.h"

using WindowCloseCallback = std::function<void()>;

void loopWindowShouldClose(WindowCloseCallback callback, GLFWwindow* window,
                           ImGuiIO* io) {
#ifdef __EMSCRIPTEN__
  io.IniFilename = nullptr;
  EMSCRIPTEN_MAINLOOP_BEGIN
#else
  while (!glfwWindowShouldClose(window))
#endif
  {
    callback();
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_MAINLOOP_END;
#endif
  }
}