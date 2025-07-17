# Image Compositing and Matting

This project performs simple image compositing and artifact-based color correction using C++. It uses PNG input images to isolate and blend foreground and background regions, applying alpha matting logic for compositing.

## Example Output
![THATS ME!! (foreground)](result/foreground/me.png)
*foreground*\
-->
![after artifact removal](result/foreground/foreground.png)
*alpha \* foreground*\
-->
![background](result/background/nature.png)
*background*\
-->
![background after applying alphaM matte map](result/background/background.png)
*(1-alpha) \* background*\
-->
![result](result/result.png)
*(1-alpha) \* background + alpha \* foreground*

## Features

- Load PNG images (foreground, background, artifact)
![artifact Example](result/artifacts/my_wall.png)
*artifact Example*
- Apply artifact-based color correction (RGB offset)
- Generate alpha matte from artifact image with    user specified tolerance 
![tolerance map](result/foreground/me.png)
*example map of tolerance = 30, if unspesified tolerance = 0*  
- Composite foreground over background using the matte
- Save the final blended image

## Dependencies

- [stb_image.h](https://github.com/nothings/stb) and [stb_image_write.h](https://github.com/nothings/stb) for PNG loading/saving

## Project Structure

- `PngImage`: Struct to hold image data with width, height, channels, and raw pixel data
- `Compositing`: Main class that handles image loading, matting, color correction, and saving

## How to Use

1. Provide PNG images: artifact, foreground, and background.
2. Compile and run the program — it will generate a result image using the compositing process where you can save the image to enjoy it.

---

*Developed by Mohammed Yasser Mohammed*  


