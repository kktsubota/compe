# MEMO
## profiling
http://minus9d.hatenablog.com/entry/20140112/1389502918

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

