#pragma once
// #include "IWindow.h"
#include <GLFW/glfw3.h>
#include "../input/InputManager.h"
#include <string>

// class GlfwWindow : public IWindow
class GlfwWindow
{
public:
    GlfwWindow();
    ~GlfwWindow();
    void Initialize(int height, int width, const std::string &window_name);
    bool ShouldClose();
    void Close();
    void PollEvent();
    GLFWwindow *GetWindow() { return m_window; }
    bool FramebufferResized() { return m_framebuffer_resized; }
    void ResetFramebufferResized() { m_framebuffer_resized = false; }
    void HandleMinimize();

    // GLFW 回调函数
    static void KeyboardCallBack(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        auto app = reinterpret_cast<GlfwWindow *>(glfwGetWindowUserPointer(window));
        app->m_input_manager->DispathKeybordEvent(key, scancode, action, mods);
    };
    static void MouseButtonCallBack(GLFWwindow *window, int button, int action, int mods)
    {
        auto app = reinterpret_cast<GlfwWindow *>(glfwGetWindowUserPointer(window));
        app->m_input_manager->DispathMouseButtonEvent(button, action, mods);
    };
    static void CursorCallBack(GLFWwindow *window, double xpos, double ypos)
    {
        auto app = reinterpret_cast<GlfwWindow *>(glfwGetWindowUserPointer(window));
        app->m_input_manager->DispathMouseMoveEvent(xpos, ypos);
    };
    static void WindowCloseCallBack(GLFWwindow *window)
    {
        auto app = reinterpret_cast<GlfwWindow *>(glfwGetWindowUserPointer(window));
        app->Close();
    };
    static void WindowSizeCallBack(GLFWwindow *window, int width, int height)
    {
        auto app = reinterpret_cast<GlfwWindow *>(glfwGetWindowUserPointer(window));
        app->m_framebuffer_resized = true;
    };

private:
    GLFWwindow *m_window;
    std::shared_ptr<InputManager> m_input_manager;
    bool m_framebuffer_resized = false;
};