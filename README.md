# NE Simulator (vterm)

vterm project simulates behaviour of a real telecom network element majorily it simulates the terminal behaviour therefore the sort name vterm (virtual terminal).
It also has features like to send alarm (A Telecom thing).

Operating System Supported:
LINUX / Solaris

Compile Time pre-requistes:
  - g++ - C++ compiler.
  - pkg-config - Too to retrieve information about installed libraries in the system.
  - xerces-c - Library for parsing, generating, manipulating, and validating XML documents.
  - GTK+ 2.0 - Library to build graphical user interfaces (GUIs).

Runtime pre-requisites:
  - inetd - inetd daemon provides Internet service management for a network. (Present by default in Solaris)
  - inetd.conf path - /etc/inet/inetd.conf
  - services path - /etc/inet/services

Compilation and Package Building Steps for Solaris:
```sh
$ make -f Makefile.sol
$ make -f Makefile.sol install
```
Compilation and Package Building Steps for LINUX:
```sh
$ make
$ make install
```

Above will create package named "wans.tar" in the code base directory.

Setup Guidelines:
  - Copy the package "wans.tar" in the test server.
  - Extract the package using below command:
```sh
$ tar -xvf wans.tar
```
  - Move to the directory where package got extracted:
```sh
$ cd wans
```
  - Start Simulator using the GUI with below command:
```sh
$ ./launch_gui.sh
```
