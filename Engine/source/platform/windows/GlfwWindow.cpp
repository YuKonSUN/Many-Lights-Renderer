#include "GlfwWindow.h"
#include <iostream>

GlfwWindow::GlfwWindow() : m_window(nullptr)
{
}

GlfwWindow::~GlfwWindow()
{
    if (m_window)
    {
        glfwDestroyWindow(m_window);
    }
    glfwTerminate();
}

void GlfwWindow::Initialize(int width, int height, const std::string &window_name)
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    if (m_window = glfwCreateWindow(width, height, window_name.c_str(), nullptr, nullptr))
    {
        std::cout << "Window is created successfully!" << std::endl;
    }
    else
    {
        std::cout << "Window failed to be created!" << std::endl;
    }

    glfwSetWindowUserPointer(m_window, this);
    glfwSetKeyCallback(m_window, KeyboardCallBack);
    glfwSetMouseButtonCallback(m_window, MouseButtonCallBack);
    glfwSetCursorPosCallback(m_window, CursorCallBack);
    glfwSetWindowCloseCallback(m_window, WindowCloseCallBack);
    glfwSetFramebufferSizeCallback(m_window, WindowSizeCallBack);

    m_input_manager = std::make_shared<InputManager>();
}

bool GlfwWindow::ShouldClose()
{
    return glfwWindowShouldClose(m_window);
}

void GlfwWindow::Close()
{
    glfwSetWindowShouldClose(m_window, true);
}

void GlfwWindow::PollEvent()
{
    glfwPollEvents();
}

void GlfwWindow::HandleMinimize()
{
    int width, height;
    glfwGetFramebufferSize(m_window, &width, &height);
    while (width == 0 || height == 0)
    {
        glfwGetFramebufferSize(m_window, &width, &height);
        glfwWaitEvents();
    }
}
