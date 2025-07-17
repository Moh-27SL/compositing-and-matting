#include <iostream>
#include <string>
#include "../header/matting.h"

using namespace std;

unsigned char* generateArtifact(PngImage img)
{
    if (img.channels != 3)
    {
        cerr << "Sorry dude, the image should only be RGB!\n";
        return nullptr;
    }

    long long sumR = 0;
    long long sumG = 0;
    long long sumB = 0;
    int numOfPixels = img.width * img.height;

    for (int i = 0; i < numOfPixels; ++i)
    {
        int base = i * 3;
        sumR += img.data[base];     // Red
        sumG += img.data[base + 1]; // Green
        sumB += img.data[base + 2]; // Blue
    }

    unsigned char* artifact = new unsigned char[3];
    artifact[0] = static_cast<unsigned char>(sumR / numOfPixels);
    artifact[1] = static_cast<unsigned char>(sumG / numOfPixels);
    artifact[2] = static_cast<unsigned char>(sumB / numOfPixels);

    return artifact;
}


double* alphaMap(PngImage img, const unsigned char* artifact, int tol)
{
    if (img.channels != 3)
    {
        cerr << "Sorry dude, the image should only be RGB!\n";
        return nullptr;
    }

    int numPixels = img.width * img.height;
    double* alpha = new double[numPixels];
    bool artBefore = false;

    for (int i = 0; i < numPixels; ++i)
    {
        int base = i * 3;
        unsigned char r = img.data[base];
        unsigned char g = img.data[base + 1];
        unsigned char b = img.data[base + 2];

        bool isArtifact =
            abs(r - artifact[0]) <= tol &&
            abs(g - artifact[1]) <= tol &&
            abs(b - artifact[2]) <= tol;

        if (isArtifact)
        {
            alpha[i] = 0.0;
            artBefore = true;
        }
        else if (artBefore)
        {
            alpha[i] = 0.5;
            artBefore = false;
        }
        else
        {
            alpha[i] = 1.0;
        }
    }

    return alpha;
}
