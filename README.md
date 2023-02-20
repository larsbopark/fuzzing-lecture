# Fuzz Testing Exercises
This repository is made as a supplement to the fuzz testing lectures held by Lars Bo Frydenskov,
Research Assistant on Aalborg University. 
In this repository, you find the slides used in most recently held lecture and related exercises.

## Cloning the Repository
In order to clone the repository you can type the following the command if you have `git` installed on your system. 
```shell
git clone https://github.com/larsbpf/fuzzing-lecture.git
```
Otherwise you are able to download zip, [here](https://github.com/larsbpf/fuzzing-lecture/archive/refs/heads/main.zip). 

## Running Docker
Simply be sure to have Docker installed, and then run the build script.
```bash
./build-docker.sh
```
Then a container is spawned with a bash terminal to interact with the container.
The image used is pulled from `aflplusplus/afplusplus` from Docker Hub.
For more information, take a look at [AFL++ github repository](https://github.com/AFLplusplus/AFLplusplus).
