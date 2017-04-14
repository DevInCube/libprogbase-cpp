# libprogbase-cpp v0.1.0

[![Travis-CI][travis-badge]][travis-builds]

[Repository home][home]

A simple C++ wrapper library for [libprogbase][libprogbase].

## Version v0.1.0

* Wrapper module `progbase/net` for networking.

## Installation and linkage

Install __cmake__.

Install the latest version of [libprogbase][libprogbase] library.

Clone this repository with command:

~~~~
git clone https://github.com/PublicHadyniak/libprogbase-cpp.git
~~~~

Change directory (cd) to newly created `libprogbase-cpp/` directory and execute:

```sh
mkdir build
cd build
cmake ..
make .
sudo make install
```

Include header files from `include/` directory and compile your code with linker options:

```sh
-lprogbase -lprogbase-cpp
```

## Library update

### Manual

You need to re-install library.

[home]: https://github.com/PublicHadyniak/libprogbase-cpp
[libprogbase]: https://github.com/PublicHadyniak/libprogbase
[travis-badge]: https://travis-ci.org/PublicHadyniak/libprogbase-cpp.svg?branch=master
[travis-builds]: https://travis-ci.org/PublicHadyniak/libprogbase-cpp/builds
