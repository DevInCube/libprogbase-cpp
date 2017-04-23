# libprogbase-cpp v0.2.1

[![Travis-CI][travis-badge]][travis-builds]

[Repository home][home]

A simple C++ wrapper library for [libprogbase][libprogbase].

## Releases

Now all releases and corresponding release notes will be published in [Releases][releases] section

### New in v0.2.1

* An update for `libprogbase` __v0.3.4__ SSL security features.

### New in v0.2.0

* New module `console` wrapper (for new interface version).

### New in v0.1.1

* `NetMessage` class now inherits from `std::runtime_error`.
* `NetMessage` method `message()` marked as deprecated. Use method `what()` instead.

### Version v0.1.0

* Wrapper module `progbase/net` for networking.

## Installation and linkage

Install __cmake__.

Install the latest version of [libprogbase][libprogbase] library.

Clone this repository with command:

```sh
git clone https://github.com/PublicHadyniak/libprogbase-cpp.git
```

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
-lprogbase-cpp -lprogbase
```

__Note__ that it is important to link `libprogbase-cpp` before `libprogbase`!

## Library update

You need to reinstall library.

[home]: https://github.com/PublicHadyniak/libprogbase-cpp
[releases]: https://github.com/PublicHadyniak/libprogbase-cpp/releases
[libprogbase]: https://github.com/PublicHadyniak/libprogbase
[travis-badge]: https://travis-ci.org/PublicHadyniak/libprogbase-cpp.svg?branch=master
[travis-builds]: https://travis-ci.org/PublicHadyniak/libprogbase-cpp/builds
