#pragma once

extern Maple::Application* Maple::CreateApplication();

int main(int argc, char** argv)
{
    Maple::Log::Init();
    MP_CORE_WARN("Initialized Log!");

    auto app = Maple::CreateApplication();
    app->Run();
    delete app;
}