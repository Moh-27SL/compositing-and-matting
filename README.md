# Image Compositing and Matting

This project performs simple image compositing and artifact-based color correction using C++. It uses PNG input images to isolate and blend foreground and background regions, applying alpha matting logic for compositing.

## Example Output
*foreground*

![THATS ME!! (foreground)](result/foreground/me.png)

-->

*alpha \* foreground*

![after artifact removal](result/foreground/foreground.png)

-->

*background*

![background](result/background/nature.png)

-->

*(1-alpha) \* background*

![background after applying alphaM matte map](result/background/background.png)

-->

*(1-alpha) \* background + alpha \* foreground*

![result](result/result.png)


## Features

- Load PNG images (foreground, background, artifact)
- Apply artifact-based color correction (RGB offset)
- Generate alpha matte from artifact image with    user specified tolerance
- Composite foreground over background using the matte
- Save the final blended image

*artifact Example (the wall behind the robot)*

![artifact Example](result/artifacts/my_wall.png)

*example map of tolerance = 30, if unspesified tolerance = 0*  
![tolerance map](result/artifacts/artifact_tolerance.png)

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


*email : es-mohamed.yasser2027@alexu.edu.eg* 


