// #pragma once
// #include <memory>
// #include "IWindow.h"
// #include "GlfwWindow.h"

// enum class WindowType
// {
//     GLFW_WINDOW
// };

// class WindowsFactory
// {
// public:
//     static std::unique_ptr<IWindow> CreateWindow(const WindowType &window_type)
//     {
//         switch (window_type)
//         {
//         case WindowType::GLFW_WINDOW:
//             return std::make_unique<GlfwWindow>();
//             break;

//         default:
//             return nullptr;
//         }
//     }
// };