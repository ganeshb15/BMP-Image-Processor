
# BMP Image Processing Documentation

## Key Functionalities

1. **File Handling:**
   - The code provides functionalities for opening, reading, and writing BMP image files. It handles file operations such as opening a BMP file, reading its header, manipulating pixel data, and writing the new data into an output BMP file.

2. **Header Processing:**
   - It reads the BMP header to extract important metadata such as image width, height, bit count (color depth), and offset to pixel data. The header data is then used to correctly interpret and write image information.

3. **Padding Management:**
   - For BMP images, each row's width must be aligned to 4-byte boundaries. The code computes the necessary padding (`w`) based on the width of the image and the bit depth (8-bit or 24-bit), ensuring BMP format compliance.

4. **Pixel Manipulation:**
   - It allows for manipulation of pixel values, including threshold-based operations where pixels are set to either black or white depending on their RGB values. This is particularly useful for tasks like binary image thresholding.

5. **Grey-scale Image Processing:**
   - The code provides a function to convert 24-bit BMP images to grey-scale by replacing the color pixel data with intensity values, suitable for 8-bit BMP files.

6. **Makefile Usage:**
   - You can compile and run the program using a makefile with the command: `make f=sample.cpp o=out2`. This will compile the given source file `sample.cpp` and produce an executable named `out2`.

## Possible Logs (Summary of Operations)

1. **File Opened:**
   - `"BMP file 'image.bmp' opened successfully."`
   - Logs whenever a BMP file is successfully opened for reading or writing.

2. **Header Data Read:**
   - `"Header read: width=1024, height=768, bitcount=24."`
   - After reading the BMP header, it logs the image properties such as width, height, and bit depth (bitcount).

3. **Image Data Processed:**
   - `"Processing pixel data: row 10 of 768 completed."`
   - Logs progress during the pixel manipulation or writing process. It helps in debugging by indicating how much of the image has been processed.

4. **Grey-scale Conversion:**
   - `"Converting image to grey-scale."`
   - Logs when the image is being converted to grey-scale before writing the modified data.

5. **File Written:**
   - `"Image data written to 'out.bmp'."`
   - Indicates that the image data has been successfully written to a new BMP file.

## How to Use in Code (Markdown/Markup Language)

```cpp
#include "BMP.h"

int main()
{
    // Initialize and read BMP file header
    header("image.bmp");

    // Create a 3D matrix for image data manipulation
    int ***arr1 = MATRIX3D(width, height, 3);

    // Get the pixel data
    int ***e = pixel();

    // Thresholding pixel manipulation
    for(int l = 1; l < height - 1; l = l + 2)
    {
        for(int k = 1; k < width - 1; k = k + 2)
        {
            if (e[k][l][0] > 150 && e[k][l][1] > 150 && e[k][l][2] > 150)
            {
                arr1[k][l][0] = 255;
                arr1[k][l][1] = 255;
                arr1[k][l][2] = 255;
                printf("00");
            }
            else
            {
                arr1[k][l][0] = 0;
                arr1[k][l][1] = 0;
                arr1[k][l][2] = 0;
                printf("11");
            }
        }
        printf("
");
    }

    // Write the manipulated pixel data to output file
    write(arr1);

    return 0;
}
```

## Makefile Example

```Makefile
# Makefile to compile and link BMP processing program

CC = g++
CFLAGS = -Wall
OBJ = $(f:.cpp=.o)

# Default target
all: $(o)

# Build target
$(o): $(OBJ)
	$(CC) $(CFLAGS) -o $(o) $(OBJ)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean command to remove compiled files
clean:
	rm -f *.o $(o)

# Usage:
# make f=sample.cpp o=out2
# This command will compile sample.cpp and output executable as out2.
```

## Steps to Use:

1. **Save your source files:**  
   - Save your `sample.cpp` (main code file), `BMP.h`, and your image processing logic into separate files.

2. **Prepare the makefile:**  
   - Create a file named `Makefile` and insert the provided makefile content into it.

3. **Compile using make:**  
   - Run the following command to compile your code:
     ```bash
     make f=sample.cpp o=out2
     ```
   - This will compile `sample.cpp` and generate an executable named `out2`.

4. **Run the program:**  
   - After compiling, run the program using:
     ```bash
     ./out2
     ```

This will process the BMP file and apply the thresholding logic you implemented, writing the resulting image to `out.bmp`.
