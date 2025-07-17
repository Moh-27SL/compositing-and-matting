#ifndef MATTING_H_INCLUDED
#define MATTING_H_INCLUDED

#include <string>
#include "../header/png.h"

unsigned char* generateArtifact(PngImage img);
double* alphaMap(PngImage img, const unsigned char* artifact, int tol);

#endif // MATTING_H_INCLUDED
