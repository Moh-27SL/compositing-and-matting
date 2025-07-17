#include <iostream>
#include "../header/composting.h"

using namespace std;

int main()
{
    compositing composer;

    composer.setArtifact("result/artifacts/my_wall.png");
    composer.setForeground("result/foreground/me.png");
    composer.setBackground("result/background/nature.png");

    composer.setTolerance(30);
    composer.setAlphaMap();
    composer.compose();

    composer.save_result("result/result.png");

    return 0;
}
