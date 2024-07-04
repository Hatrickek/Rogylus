# Oxylus Project Template
Github repository template for Oxylus projects. 

## Usage
Create a new repository using this template.  
Right after creation a github action will run and rename the contents and directories using the repository name and PR the changes.

## Building
Currently supported and tested compilers are only: MSVC and Clang
- Install [Vulkan SDK](https://vulkan.lunarg.com/sdk/home).
- Run the root CMake script with this command to generate for MSVC:       
`cmake -S . -B ./build/ -G "Visual Studio 17 2022" -A x64`      
For clang:  
`cmake -B ./build -G Ninja -DCMAKE_CXX_COMPILER=clang++`
- Install `directx-shader-compiler` package if required. (Only required for UNIX)
- Then run this command to build it with CMake:   
`cmake --build ./build --config Release`
