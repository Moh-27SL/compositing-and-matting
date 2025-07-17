#ifndef COMPOSTING_H_INCLUDED
#define COMPOSTING_H_INCLUDED

#include <string>
#include "../header/png.h"

using namespace std;

class compositing
{
private:

    int tolerance;
    unsigned char* artifact;
    double* alpha;
    PngImage background;
    PngImage foreground;
    PngImage result;

public:

    ///need to reset alphaMap after setting tolerance
    void setTolerance(int tolerance) {this->tolerance = tolerance;}

    void setAlphaMap();

    bool save_result(string filepath){return save_png(filepath,result);}

    PngImage getResult(){return result;}
    double* getAlphaMap(int* width, int* height){ *width = foreground.width; *height = foreground.height; return alpha;}
    unsigned char* getArtifact(){return artifact;} /// always size 3  ->RGB

    compositing(string foreground_Path, string background_path, string artifact_path, int tolerance)
    {
        setForeground(foreground_Path);
        setBackground(background_path);
        setArtifact(artifact_path);
        setTolerance(tolerance);
        setAlphaMap();
    }

    compositing()
    {
        artifact = nullptr;
        alpha = nullptr;
        tolerance = 0;
    }

    void setArtifact(string artifact_path);

    void setBackground(string background_path)
    {
        this->background = load_png(background_path);
    }

    void setForeground(string foreground_path)
    {
        this->foreground = load_png(foreground_path);
    }

    bool compose();

    ~compositing()
    {
        if(alpha)
        {
            delete[] alpha;
            alpha = nullptr;
        }
    }
};



#endif // COMPOSTING_H_INCLUDED
