FROM aflplusplus/aflplusplus
WORKDIR /excercise
RUN cd /AFlplusplus; make source-only; cd -