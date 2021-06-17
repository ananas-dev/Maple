#include <iostream>
#include <Topaze.h>

class Sandbox : public Topaze::Application
{
public:
    Sandbox()
    {

    }

    ~Sandbox()
    {

    }
};

Topaze::Application* Topaze::CreateApplication()
{
    return new Sandbox();
}