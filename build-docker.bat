@echo off
docker rm -f aflplusplus-exercise
docker build -t aflplusplus-exercise .
docker run --rm --name=aflplusplus-exercise -it aflplusplus-exercise
