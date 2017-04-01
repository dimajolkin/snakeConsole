FROM ubuntu:16.04

RUN apt update
RUN apt install -y g++ make freeglut3 freeglut3-dev

VOLUME  /tmp/.X11-unix:/tmp/.X11-unix 

ADD . /app

CMD  cd /app && make && DISPLAY=:0 /tmp/snake.run

