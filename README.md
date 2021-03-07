# Funcplus
Advanced C++ classes project of an interpreter of a 
simple functional programming language.


### Installing PEGTL
To build, first install the PETGL library, which is used in the project
to parse source codes:
```
wget https://github.com/taocpp/PEGTL/archive/3.2.0.tar.gz
tar -zxvf 3.2.0.tar.gz
cd PEGTL-3.2.0
mkdir build
cd build
cmake ..
make
sudo make install
```
The above will install the PEGTL library in the standard UNIX installation
directory. More information can be found on https://github.com/taocpp/PEGTL/blob/3.2.0/doc/Installing-and-Using.md

### Installing Qt

The project also needs Qt 5 to build. Download the binary
distribution or build from sources and install.
https://www.qt.io/download-open-source

## Building the app

To build, in the project's directory execute
```
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH=$QT_PATH
make
```
where the `QT_PATH` variable should point to the Qt installation
directory. If you forget to provide this path, CMake will prompt
you to do so anyway.