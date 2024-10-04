## A simple image compressor built using c++ and stb library

This project is a cross-platform image compression tool that uses the `stb_image` and `stb_image_write` libraries for image loading and saving

## Features

- Load images in various formats (e.g., PNG, JPEG, BMP)
- Compress images to JPEG format with a specified compression level
- Cross-platform support (Linux, macOS, Windows)

## Prerequisites

- CMake 3.10 or higher
- A C++17 compatible compiler
- Git


### Installing Prerequisites

#### macOS

```sh
brew install cmake git jpeg

```
#### Linux (Debian-based)

```sh
sudo apt-get update
sudo apt-get install cmake git libjpeg-dev
```

#### Windows
- Install CMake
- Install Git
- Install libjpeg using vcpkg

```sh
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg integrate install
.\vcpkg install libjpeg
```

### Setup

#### Clone the repository:

```sh
git clone https://github.com/yourusername/image-compression.git
cd image-compression
```

#### Create a build directory and navigate into it:

 ```sh
mkdir build
cd build
```

#### Run CMake to configure the project:

```sh
cmake ..
```
This will check if the stb library is present in submods/stb/. If not, it will create the directory and clone the stb repository into it.

#### Build the project:

on macos/linux
```sh
make
```
On Windows,use:
```sh
cmake --build .
```

## Usage

### Run the executable with the following command:

```sh
./image-compression <input-image> <output-image> <compression-level>
```

- ```<input-image>``` : Path to the input image file
- ```<output-image>``` : Path to the output compressed image file
- ```<compression-level>``` : Compression level (0-100, where 100 is the highest quality)

#### Example:

```sh
./image-compression input.png output.jpg 85
```

## Acknowledgements

### stb - Single-file public domain libraries for C/C++.
### libjpeg - A widely used C library for reading and writing JPEG image files.
