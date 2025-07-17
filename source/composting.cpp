#include <iostream>
#include <string>
#include "../header/matting.h"
#include "../header/composting.h"

using namespace std;

void compositing::setArtifact(string artifact_path)
{
    PngImage img = load_png(artifact_path);
    artifact = generateArtifact(img);
}

void compositing::setAlphaMap()
{
    if(foreground.data != nullptr && artifact != nullptr)
        this->alpha = alphaMap(foreground,artifact,tolerance);
}

bool compositing::compose()
{
    if(foreground.data != nullptr && background.data != nullptr && alpha != nullptr)

        ///will implement resizing later, for now assume both are the same size
        if(foreground.height == background.height &&
            foreground.width == background.width)
        {
            int numPixels = foreground.width * foreground.height;
            if(result.data == nullptr)
            {
                result.data = new unsigned char[numPixels * 3];
                result.height = foreground.height;
                result.width = foreground.width;
                result.channels = 3;
            }
            else
            {
                delete[] result.data;

                result.data = new unsigned char[numPixels * 3];
                result.height = foreground.height;
                result.width = foreground.width;
            }

            for (int i = 0; i < numPixels; ++i)
            {
                int base = i * 3;

                result.data[base]     = static_cast<unsigned char>(background.data[base] * (1-alpha[i]))
                                        + static_cast<unsigned char>(foreground.data[base] * (alpha[i])); // R

                result.data[base + 1] = static_cast<unsigned char>(background.data[base + 1] * (1-alpha[i]))
                                        + static_cast<unsigned char>(foreground.data[base + 1] * (alpha[i])); // G

                result.data[base + 2] = static_cast<unsigned char>(background.data[base + 2] * (1-alpha[i]))
                                        + static_cast<unsigned char>(foreground.data[base + 2] * (alpha[i])); // B
            }
            return true;
        }

    return false;
}
