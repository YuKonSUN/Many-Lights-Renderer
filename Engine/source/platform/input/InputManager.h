#pragma once
#include <memory>
#include <vector>
#include <functional>

class InputManager
{
public:
    typedef std::function<void(int, int, int, int)> OnKeyFunc;
    typedef std::function<void(int, int, int)> OnMouseButtonFunc;
    typedef std::function<void(double, double)> OnCursorPosFunc;

    void RegisterKeyInputListener(OnKeyFunc func) { m_keyinput_listeners.push_back(func); };
    void RegisterMouseButtonListener(OnMouseButtonFunc func) { m_mousebutton_listeners.push_back(func); };
    void RegisterCursorPosListener(OnCursorPosFunc func) { m_cursorpos_listeners.push_back(func); };

    // protected:
    void DispathKeybordEvent(int key, int scancode, int action, int mods)
    {
        for (auto &func : m_keyinput_listeners)
        {
            func(key, scancode, action, mods);
        }
    }
    void DispathMouseButtonEvent(int button, int action, int mods)
    {
        for (auto &func : m_mousebutton_listeners)
        {
            func(button, action, mods);
        }
    }
    void DispathMouseMoveEvent(double xpos, double ypos)
    {
        for (auto &func : m_cursorpos_listeners)
        {
            func(xpos, ypos);
        }
    }

private:
    std::vector<OnKeyFunc> m_keyinput_listeners;
    std::vector<OnMouseButtonFunc> m_mousebutton_listeners;
    std::vector<OnCursorPosFunc> m_cursorpos_listeners;
};