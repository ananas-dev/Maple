#pragma once

#include "Maple/Core.h"

#include "Maple/Window.h"
#include "Maple/LayerStack.h"
#include "Maple/Events/Event.h"
#include "Maple/Events/ApplicationEvent.h"

namespace Maple {

    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;

        LayerStack m_LayerStack;
    };

    // To be defined in client
    Application* CreateApplication();

}