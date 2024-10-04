
#include <iostream>
#include <filesystem>
#define STB_IMAGE_IMPLEMENTATION
#include "submods/stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "submods/stb/stb_image_write.h"
#include <stdio.h>

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input-image> <output-image> <compression-level>" << std::endl;
        return -1;
    }

    const char *inputImage = argv[1];
    const char *outputImage = argv[2];
    int compressionLevel = std::stoi(argv[3]);

    int width, height, channels;
    

    unsigned char *image = stbi_load(inputImage, &width, &height, &channels, 3);  // Force loading as RGB (3 channels)
    if (!image) {
        std::cerr << "Error loading image!" << std::endl;
        return -1;
    } else {
        std::cout << "Image loaded successfully!" << std::endl;
    }

    auto originalSize = fs::file_size(inputImage);
    std::cout << "Original image size: " << originalSize << " bytes" << std::endl;



    stbi_write_jpg(outputImage, width, height, 3, image, compressionLevel);

    auto finalSize = fs::file_size(outputImage);
    std::cout << "Final image size: " << finalSize << " bytes" << std::endl;

    stbi_image_free(image);

    return 0;
}