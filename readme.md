## profiling

```bash
$ g++ --std=c++14 -gp main.cpp
$ ./a.out
$ gprof a.out gmon.out | less
```

## build

```bash
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
$ ./Main
```

