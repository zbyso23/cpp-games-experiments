# cpp-games-experiments
C++ games experiments with SFML library and others


# Libraries used
- RayLib [raylib.com](https://www.raylib.com/)
- SFML [sfml-dev.org](https://www.sfml-dev.org/)

# Setup (Ubuntu)

## SFML

```
sudo apt update
sudo apt install libsfml-dev
```

## RayLib (package)

```
sudo apt-get update
sudo apt-get install build-essential libgl1-mesa-dev libraylib-dev
```

## RayLib (from source)

```
sudo apt-get update
sudo apt-get install build-essential cmake libgl1-mesa-dev libopenal-dev
```

```
git clone https://github.com/raysan5/raylib.git
cd raylib
```

```
mkdir build
cd build
cmake ..
make
```

```
sudo make install
sudo ldconfig
```