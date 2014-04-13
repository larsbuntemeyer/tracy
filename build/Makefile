# makefile for the raytracer
# from quickcf tutorial:  g++ *.cpp -lSDL -O3 

CC = g++

vpath %.cpp ../source
vpath %.h ../source
#VPATH = ../source

HEADERS = camera.h color.h light.h \
          material.h plane.h primitive.h ray.h raytracer.h \
          scene.h frame.h \
          sphere.h hyperboloid.h torus.h cylinder.h\
          vector3d.h \
          matrix.h transformation.h implicit.h

OBJECTS = camera.o color.o light.o \
          material.o plane.o primitive.o ray.o raytracer.o \
          scene.o frame.o \
          sphere.o hyperboloid.o torus.o cube.o cylinder.o\
          vector3d.o matrix.o transformation.o texture.o locator.o \
          implicit.o

#FLAGS   = #-I.. -Wall -W -ansi -pedantic -lm -Dcimg_use_vt100
       #   -L/usr/X11R6/lib -lpthread -lX11 -lXext -lXrandr \
       #   -I/usr/X11R6/include -Dcimg_use_xshm -Dcimg_use_xrandr 

CFLAGS  = -I.. -Wall -W -ansi -pedantic -Dcimg_use_vt100 -I/usr/X11R6/include -lm 

LFLAGS  = -L/usr/X11R6/lib -lpthread -lX11

main:   main.o quickcg.o $(OBJECTS) $(HEADERS)
	$(CC) main.o $(OBJECTS) -o main $(LFLAGS)

test:   raytracer_test.o $(OBJECTS)
	$(CC) raytracer_test.o $(OBJECTS) -o test

.cpp.o: 
	$(CC) -c $<

clean:
	rm $(OBJECTS) main main.o quickcg.o
