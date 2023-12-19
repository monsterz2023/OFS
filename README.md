# OpenFunscripter
Can be used to create `.funscript` files. (NSFW)  
The project is based on OpenGL, SDL2, ImGui, libmpv, & all these other great [libraries](https://github.com/OpenFunscripter/OpenFunscripter/tree/master/lib).

![OpenFunscripter Screenshot](https://github.com/OpenFunscripter/OpenFunscripter/blob/1b4f096be8c2f6c75ceed7787a300a86a13fb167/OpenFunscripter.jpg)

### How to build ( for people who want to contribute or fork )
```
cd OFS
git submodule update --init
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DOFS_SNAP_IMAGE=1 ..
make
sudo make install
```

Known linux dependencies to just compile are `build-essential libmpv-dev libglvnd-dev`.  

### Windows libmpv binaries used
Currently using: [mpv-dev-x86_64-v3-20220925-git-56e24d5.7z (it's part of the repository)](https://sourceforge.net/projects/mpv-player-windows/files/libmpv/)

### Platforms
I'm providing windows binaries and a linux AppImage.
In theory OSX should work as well but I lack the hardware to set any of that up.
