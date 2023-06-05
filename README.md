# Readme

## Scope

This small project tries to give an overview of templates in C++ and how they
can be used. The following topics are introduced:

- Preprocessor (see 00_preprocessor)
- Templated classes (see 01_basics)
- Template parameter packs (see 01_basics)
- Non-type template parameters (see 01_basics)
- Template metaprogramming (see 02_metaprogramming)

### TODOs

The following is currently missing:

- Examples for constrains and concepts
- Documentation of each sub project with a small explanation

## Usage

The project uses cmake[^1] to setup the build process. The different programs are
added as executables, so the following steps can be used to build all
executables:

```bash
# Create build folder
mkdir .build

# Step into newly created folder
cd .build

# Configure cmake
cmake ..

# Build using make
make
```

The commands are executed within the project folder.

To run the programs the executables can be found in their respective subfolder
in `.build` or by running `make test`.

[^1]: https://cmake.org/