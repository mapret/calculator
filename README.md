# Calculator

A commandline calculator which can evaluate mathematical expressions of any length.
It uses [flex](https://github.com/westes/flex) for lexing and [Bison](https://www.gnu.org/software/bison/bison.html) for parsing of the expression.

## Building

This project is built using [CMake](https://cmake.org/).

### Requirements

* cmake >= 3.0.2
* A C++ compiler with support for the C++17 standard

### Example

To build the project with the default CMake generator, use the following commands:
```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

## Tests

The tests can executed by running
```
build/test/Calculator-test
```
from the repository root directory.

## Running

The program can be run by executing
```
build/src/Calculator
```
, which starts the calculator in interactive mode, allowing calculations to be entered and evaluated within the commandline.

### Example

```
$ build/src/Calculator
2+2*2
6
(2+2)*2
8
sin(0.5)^2+cos(0.5)^2
1
```

## License

This project uses the [**BSD 3-Clause License**](LICENSE.txt).
