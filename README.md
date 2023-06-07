# csapp_lib
wrappers in csapp

**only `csapp.c` and `csapp.h` matters**

## include header

For simple management, we can create directory `/home/[current_usr]/c_headers`, which holds all customized header files

```shell
$ cd ~
$ mkdir c_headers
# copy csapp.h to /home/[current_usr]/c_headers by commend cp
```

edit `/etc/evironment` and modify include path

```shell
C_INCLUDE_PATH="/home/[current_user]/c_headers:$C_INCLUDE_PATH"
```

> if `/etc/environment` does not contains `C_INCLUDE_PATH`, then just add one
> 
> ```shell
> C_INCLUDE_PATH="/home/[current_user]/c_headers"
> ```

Or we can just move `caspp.h` to `/usr/local/include`, which is much more easier
> never add header files in `/usr/include` !!!

## static linking

* complie `csapp.c` to get linkable object file `csapp.o`
  ```shell
  $ gcc -c -o csapp.o csapp.c
  ```
* link `csapp.o`, get executable object file, remember to include libpthread
  ```shell
  $ gcc -o test test.c csapp.o -lpthread 
  ```

  static linking is simple but not elegant: 
  * we need csapp.o placed in project directory
  * we need flag `-lpthread` to finish linking

## dynamic linking

* complie `csapp.c` with flag: `-fPIC` with means get a position-independent code
  ```shell
  $ gcc -c -fPIC -o csapp.o csapp.c
  ```
* create shared library(`libcsapp.so`) by `csapp.o`
  ```shell
  $ gcc --shared -o libcsapp.so csapp.o -lpthread
  ```
* copy .so file into `/usr/local/lib`
  ```shell
  $ cp libcsapp.so /usr/local/lib
  ```
* update linker cache
  ```shell
  $ ldconfig /usr/local/bin
  ```

## test with a demo

complie source code just by flag `-lcsapp`(without copying `libcsapp.so` into project directory!)
  ```shell
  $ gcc -o test test.c -lcsapp && cat test.txt
  this is a test messsage
  ```

there will be a message on the screen: "this is a test messsage" !!!


## makefile will handle all

```shell
$ make all
```