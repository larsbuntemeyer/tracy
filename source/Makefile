# makefile for the raytracer
# from quickcf tutorial:  g++ *.cpp -lSDL -O3 

CC = g++ 

HEADERS = camera.h color.h light.h \
          material.h plane.h primitive.h ray.h raytracer.h \
          scene.h frame.h sphere.h vector3d.h hyperboloid.h \
          matrix.h transformation.h

OBJECTS = camera.o color.o light.o \
          material.o plane.o primitive.o ray.o raytracer.o \
          scene.o frame.o sphere.o vector3d.o hyperboloid.o \
          matrix.o transformation.o texture.o cube.o locator.o \

FLAGS   = -I.. -Wall -W -ansi -pedantic -lm -Dcimg_use_vt100 \
          -I/usr/X11R6/include -Dcimg_use_xshm -Dcimg_use_xrandr \
          -L/usr/X11R6/lib -lpthread -lX11 -lXext -lXrandr

main:   main.o quickcg.o $(OBJECTS) $(HEADERS)
	$(CC) main.o quickcg.o $(OBJECTS) -lSDL -o main $(FLAGS)

test:   raytracer_test.o $(OBJECTS)
	$(CC) raytracer_test.o $(OBJECTS) -o test

.cpp.o: 
	$(CC) -c $<
