# CM2-Reference

### Reverse engineered headers of the Faktum and CM2 libraries from the 2007 PC game Crazy Machines 2

## Building

### Requirements

- `cm2.dll` 1.05.0385[^1]
- `faktum.dll` 1.3.0296[^1]
- [openssl 0.9.8e](https://ftp.openssl.org/source/old/0.9.x/) headers
- [zlib 1.2.3](https://github.com/madler/zlib/tree/v1.2.3) headers
- MSVC (latest, amd64_x86 target)

[^1]: The version of both libraries can be checked through the `cm2.log` file written upon game launch

### Preparation

Copy both the zlib and openssl include folders into `lib/<LIBRARY>/include` (this path is to be consistent with the other libraries).

Copy both the game's DLLs from the game's root into the corresponding folder at `lib/<LIBRARY>/x86`.

Verify the hashes of your DLLs with the `.sha256` files located in the same folders to make sure they are compatible with the headers.

Convert the DLLs into `.lib` files by following the [guide on stackoverflow](https://stackoverflow.com/a/16127548).

### Compiling

Add all the libraries' include folders (`lib/<LIBRARY>/include`) to the include path, link against both libraries (now located at `lib/cm2/x86/cm2.lib` and `lib/faktum/x86/faktum.lib`) and compile with the MSVC compiler on amd64_x86 target.

Make sure to compile with the standard set to C++20 to avoid any issues, a CMake project is recommended.

## But why

- Building [Anfora](https://github.com/ItzTacosOfficial/Anfora) mods (and the modloader itself as well)
- Replacing the game's main executable `cm2.exe` (which is how Anfora works)
- Hopefully writing useful modding tools (for the `.fst` format)

## Contributing

Commit messages should follow the formatting `<FAK/CM2>: <MESSAGE>`
