#include "Core/Application.hpp"

int main(int argc, char const **argv)
{
    auto app = Application{};
    app.run();

    return EXIT_SUCCESS;
}
