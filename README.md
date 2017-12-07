# 16-782-Planning-Project

The code is an implementation of [planner ensemble](https://www.ri.cmu.edu/pub_files/2014/5/The_Planner%20Ensemble_and_Trajectory_Executive_small.pdf) for a simple 2D navigation for differential drive robot. 

In this code we have 3 planners.
1) [CHOMP](https://www.ri.cmu.edu/pub_files/2009/5/icra09-chomp.pdf)
2) [ADA\*](http://www.cs.cmu.edu/~ggordon/likhachev-etal.anytime-dstar.pdf)
3) [RRT\*](http://www.roboticsproceedings.org/rss06/p34.pdf)

# Implementation
All planners are implemented in C++ and the visualizations are in MATLAB. The ADA\* implementation is a modified version of the one found in [SBPL](https://github.com/sbpl/sbpl).

# Requirements
## CHOMP
1) [Armadillo-8.300.1](http://arma.sourceforge.net/download.html)\*
2) [LAPACK-3.8](http://www.netlib.org/lapack/#_lapack_version_3_8_0_2)\*

*provided in the repository.

## ADA*
1) [SBPL](https://github.com/sbpl/sbpl) \*

*provided in the repository.

## RRT*
1) Self contained

# Compiling requirements
## CHOMP
### Armadillo
In the Armadillo directory

```
mkdir build && cd build

cmake ..

make -j

sudo make install
```

### Lapack
In the Lapack directory

`mkdir build && cd build

ccmake ..`

In the ccmake configuration, set CBLAS, LAPACKE, USE_OPTIMIZED_LAPACK and USE_OPTIMIZED_BLAS to ON

`make -j

sudo make install`

Add the following lines to your .bashrc or .envrc (if you are using direnv) file

`export LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libstdc++.so.6:/usr/lib/x86_64-linux-gnu/libprotobuf.so.9

export BLAS_VERSION="/usr/lib/libblas.so"

export LAPACK_VERSION="/usr/lib/liblapack.so"`
