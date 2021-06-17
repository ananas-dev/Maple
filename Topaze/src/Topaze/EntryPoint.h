#pragma once

extern Topaze::Application* Topaze::CreateApplication();

int main(int argc, char** argv)
{
    Topaze::Log::Init();
    TPZ_CORE_WARN("Initialized Log!");

    auto app = Topaze::CreateApplication();
    app->Run();
    delete app;
}