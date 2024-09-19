# CM2 Reference

### Reverse engineered headers of the Faktum and CM2 libraries from the 2007 PC game Crazy Machines 2

> [!IMPORTANT]
> This is a hobby project and will not be maintained forever/full time.
> The project is far from finished, but due to the nature of the game this still opens some possibilities.
> Actual documentation of the libraries is most likely not happening any time soon.

## Usage

### Requirements

- MSVC VS 2022 (latest)
- CMake
- `cm2.dll`[^1]
- `faktum.dll`[^1]

[^1]: The DLLs are located in the root of the game files

> [!NOTE]
> This project is meant to work **exclusively** with the Steam build of Crazy Machines 2.
> That is to provide support for the only non-physical up-to-date version of the game.

### Preparation

Copy both the game's DLLs from the game's root into `bin/<Library>/`.

Verify compatibility by checking the hashes of your DLLs against the `.sha256` files located in the same directories.

### Building

In your project's `CMakeLists.txt`, add the `cmake` folder of the repository as a subdirectory:

```cmake
add_subdirectory("<Repository>/cmake")
```

> [!TIP]
> Cloning the repository in a separate directory then assigning its directory to an enviroment variable is recommended.
> This allows for multiple separate projects to add the reference via `"$ENV{Variable}/cmake"`

Now that the reference has been added, you can link application against the `faktum` and `cm2` targets:

```cmake
target_link_libraries(<Application> faktum cm2)
```

Upon building, the library files required for linking are going to get generated automatically.

To exclusively generate the files, the two targets `faktum.lib` and `cm2.lib` are provided.

Make sure to compile your project with the C++ standard set to 20 or above.[^2]

[^2]: A modern C++ standard is required due to possible library extensions.

## But why?

- Building [Anfora](https://github.com/ItzTacosOfficial/Anfora) and its mods
- Replacing the game's main executable `cm2.exe` (which is how Anfora works)
- Hopefully writing useful modding tools (for the `.fst` format)

## Contributing

Commit messages should follow the formatting `<FAK/CM2>: <MESSAGE>` (e.g. `FAK: Updated FObject`)
