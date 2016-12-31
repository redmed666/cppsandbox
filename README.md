Just a test of an application with QT and Mongo

So the idea is to extract everything from a database and let the user selects which 
recipe he/she wants.

Building infos
--------------

mkdir build && cd build
conan install .. --build missing
cmake ..; cmake --build; make doc