FROM ubuntu


RUN apt-get update 
RUN apt-get -y install git gcc make g++
RUN mkdir /opt/src
WORKDIR /opt/src
RUN git clone https://github.com/google/googletest.git

ENV GTEST_DIR=/opt/src/googletest/googletest/
WORKDIR $GTEST_DIR/src
COPY . .

RUN make test
RUN cp my_test.exe /
CMD ["./my_test.exe"]