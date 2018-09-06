# dodbm

[![Build Status](https://travis-ci.com/WopsS/dodbm.svg?branch=master)](https://travis-ci.com/WopsS/dodbm)
[![Build status](https://ci.appveyor.com/api/projects/status/mjghq67lhk84v8iq?svg=true)](https://ci.appveyor.com/project/WopsS/dodbm)

A database migration library for C++ applications.

## Build instructions

### Requirements

* **[CMake](https://cmake.org/)**.
* **[MariaDB Connector/C](https://downloads.mariadb.org/connector-c/+releases/)** or [MySQL Connector/C](https://dev.mysql.com/downloads/connector/c/).

### Windows

1. Download and install **[Visual Studio 2017 Community Edition](https://www.visualstudio.com/)** or a higher version.
2. Download and install the **[Requirements](#requirements)**.
3. Clone this repository.
4. Create a directory named `build` and run **[CMake](https://cmake.org/)** in it.
5. Open the solution (**dodbm.sln**) located in **build** directory.
6. Build the projects.

### Linux

1. Download and install a **C++ compiler**.
2. Download and install the **[Requirements](#requirements)**.
3. Clone this repository.
4. Create a directory named `build` and run **[CMake](https://cmake.org/)** in it.
5. Build the projects.

## How to use it

The documentation is available at [docs](/docs), but the most important parts are:

* [Getting started](/docs/tutorial.md)
* [Writing a provider](/docs/writing-a-provider.md)