# Test driven develpment

This is a basic sample showing how the bases for using googletest in a project with:
- a `main.cpp` file
- a `library.cpp` / `library.h` with the functions you wants to test
- a separate executable for the program you're creating and one for running the tests.

How to get it to work:

- Create a new project (`main.cpp`, `CMakeLists.txt`);
- Download gtest/gmock zipped archive from https://github.com/google/googletest
- Place it in your code directory and unzip it; rename the directory as `googletest`.
- Compile googletest:

  ~~~.sh
  cd googletest/
  mkdir build
  cd build
  cmake -Dgtest_build_tests=ON ..
  make -j2
  make test
  ~~~
- Add googletest to the project's `CMakeLists.txt` file, create and run the test in `main.cpp` (see the files in this directory).

  ~~~.sh
  cd ..
  mkdir build
  cd build
  cmake ..
  make
  make test
  ~~~


## Resources

- [Build and install Google Test](https://gist.github.com/massenz/41bb2c8375294f4d9927)
- a too complicated CMakeLists.txt:
  https://github.com/dmonopoly/gtest-cmake-example/blob/master/CMakeLists.txt
