# CM2-Reference
### Reverse engineered headers of the Faktum and CM2 libraries from the 2007 PC game Crazy Machines 2

## Requirements
- `cm2.dll` 1.05.0385[^1]
- `faktum.dll` 1.3.0296[^1]
- [zlib 1.2.3](https://github.com/madler/zlib/tree/v1.2.3) headers
- MSVC Compiler (latest)

## Usage
Copy the zlib headers into `lib/zlib/include` (this path is to be consistent with the other libraries).

Copy both the game's DLLs from the game's root into the corresponding folder at `lib/<LIBRARY>/x86`.

Verify the hashes of your DLLs with the `.sha256` files located in the same folders to make sure they are compatible with the headers.

Convert the DLLs into `.lib` files by following the [guide on stackoverflow](https://stackoverflow.com/a/16127548).

Add all the libraries' include folders (`lib/<LIBRARY>/include`) to the include path, link against both libraries (now located at `lib/cm2/x86/cm2.lib` and `lib/faktum/x86/faktum.lib`) and compile with the MSVC compiler on amd64_x86 target.

Make sure to compile with the standard set to C++20 to avoid any issues.

As an alternative to including each header individually, the ones named after the library will include everything at once.

## But why
Writing an application with both libraries isn't really that useful, *unless one really wants to create a custom game executable (replacing `cm2.exe`)*.

However, I guess that using only the faktum library without cm2 can be really useful to create modding tools (specially dealing with the `.fst` format) or to just play around with it to understand how it works.

[^1]: The version of both libraries can be checked through the `cm2.log` file written upon game launch
