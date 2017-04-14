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

~~~~sh
gcc main.c -lprogbase
~~~~

## Check library version (since 0.1.0)

You need to change directory to cloned `libprogbase/` directory and execute command:

~~~~sh
make version
~~~~

## Library update

### Auto (since 0.1.0)

Works only if you cloned this repository with Git.

Change directory to cloned `libprogbase/` and execute command:

~~~~
sudo make update
~~~~

And that's all.

### Manual

You need to re-install library.

## Headers

### progbase.h

Sample usage to read all available data type values from terminal:

~~~~c
#include <stdio.h>
#include <stdlib.h>
#include <progbase.h>

int main(void) {
	int i = 0;
	long l = 0;
	float f = 0;
	double d = 0;
	string s = "";

	printf("Enter int: ");
	i = getInt();
	printf("Entered: %d\n", i);

	printf("Enter long: ");
	l = getLong();
	printf("Entered: %ld\n", l);

	printf("Enter float: ");
	f = getFloat();
	printf("Entered: %f\n", f);

	printf("Enter double: ");
	d = getDouble();
	printf("Entered: %lf\n", d);

	printf("Enter string: ");
	s = getString();
	printf("Entered: %s\n", s);

	freeString(s);
	return 0;
}
~~~~

Sleep milliseconds sample `sleepMillis()` (since 0.1.0):

```c
#include <stdio.h>
#include <progbase.h>

int main(void) {
	int i = 0;
	const unsigned long MILLIS = 100;

	for (i = 0; i < 100; i++) {
		if (0 == i % 10) {
			puts("");
		}
		printf("%i\t", i);
		fflush(stdout);
		sleepMillis(MILLIS);
	}
	puts("");
	return 0;
}
```

[home]: https://github.com/PublicHadyniak/libprogbase-cpp
[libprogbase]: https://github.com/PublicHadyniak/libprogbase
[travis-badge]: https://travis-ci.org/PublicHadyniak/libprogbase-cpp.svg?branch=master
[travis-builds]: https://travis-ci.org/PublicHadyniak/libprogbase-cpp/builds
