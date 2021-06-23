#include <Maple.h>

class ExampleLayer : public Maple::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        MP_INFO("ExampleLayer::Update");
    }

    void OnEvent(Maple::Event& event) override
    {
        MP_TRACE("{0}", event);
    }
};

class Sandbox : public Maple::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox() override
    = default;
};

Maple::Application* Maple::CreateApplication()
{
    return new Sandbox();
}