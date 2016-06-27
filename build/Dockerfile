FROM ubuntu:16.04

RUN apt update &&  apt-get install -y freeglut3

VOLUME  /tmp/.X11-unix:/tmp/.X11-unix 

ADD /snake.run /root

CMD DISPLAY=:0 /root/snake.run

