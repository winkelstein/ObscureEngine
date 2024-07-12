#include <iostream>
#include <ObscureEngine/WS/Window.h>

int main()
{
  ObscureEngine::WS::Window window("ObscureEngine example", 800, 600);

  while (window.isOpen())
  {
    window.pollEvent();

    window.clear(1.0, 1.0, 1.0, 1.0);
  }
}