#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/Event.h"

namespace Maple {

    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // To be defined in client
    Application* CreateApplication();

}