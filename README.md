# dodbm

[![Build Status](https://travis-ci.com/WopsS/dodbm.svg?branch=master)](https://travis-ci.com/WopsS/dodbm)
[![Build status](https://ci.appveyor.com/api/projects/status/mjghq67lhk84v8iq?svg=true)](https://ci.appveyor.com/project/WopsS/dodbm)

A database migration library for C++ applications.

## Build instructions

### Requirements

* **[PREMAKE 5](https://github.com/premake/premake-core/releases)**.

### Windows

1. Download and install **[Visual Studio 2017 Community Edition](https://www.visualstudio.com/)** or a higher version.
2. Clone this repository.
3. Extract the content of **[PREMAKE 5](https://github.com/premake/premake-core/releases)** into **premake** directory.
11. Go to the **premake** directory and run **generate_vs_projects.bat**.
12. Open the solution (**dodbm.sln**) located in **premake/projects** directory.
13. Build the projects.

### Linux

1. Download and install a **C++ compiler**.
2. Clone this repository.
3. Extract the content of **[PREMAKE 5](https://github.com/premake/premake-core/releases)** into **premake** directory.
4. Go to the **premake** directory and run **generate_gmake_projects.sh**.
5. Build the projects by running the `make` command into **premake/projects** directory.