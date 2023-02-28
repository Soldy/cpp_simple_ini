# Simple ini


It's a simple ini file reader without section support. 
The reader's function comes back with a map of two strings.
Sometimes you don't need more.

# Simple function:

```C++

std::map<std::sting, std::string> cpp_simple_ini::read(std::string file_name);

```


# Before you use it:

That is a working-in-progress code, not a release, made for my microsystems.

Other well-tested solutions already exist on your system:

   1. The windows API already provides an easy solution.
   1. On a Linux desktop, glib is probably the easiest. 
   1. On a server have multiple options like: libconfini, iniparser, inih, inipp


A good choice for Arduino. 
