#!/bin/bash
docker rm -f aflplusplus-excercise
docker build -t aflplusplus-excercise .
docker run --rm --name=aflplusplus-excercise -it aflplusplus-excercise