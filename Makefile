main:=tests/sculptor_test.cc
all: CutVoxel.o CutBox.o CutSphere.o CutEllipsoid.o PutVoxel.o PutBox.o PutSphere.o PutEllipsoid.o GeometricFigure.o Sculptor.o
	g++ -o run CutVoxel.o CutBox.o CutSphere.o CutEllipsoid.o PutVoxel.o PutBox.o PutSphere.o PutEllipsoid.o GeometricFigure.o Sculptor.o $(main)

CutVoxel.o: include/CutVoxel.h
	g++ -c src/CutVoxel.cc

CutBox.o: include/CutBox.h
	g++ -c src/CutBox.cc

CutSphere.o: include/CutSphere.h
	g++ -c src/CutSphere.cc

CutEllipsoid.o: include/CutEllipsoid.h
	g++ -c src/CutEllipsoid.cc

PutVoxel.o: include/PutVoxel.h
	g++ -c src/PutVoxel.cc

PutBox.o: include/PutBox.h
	g++ -c src/PutBox.cc

PutSphere.o: include/PutSphere.h
	g++ -c src/PutSphere.cc

PutEllipsoid.o: include/PutEllipsoid.h
	g++ -c src/PutEllipsoid.cc

Sculptor.o: include/Sculptor.h
	g++ -c src/Sculptor.cc

GeometricFigure.o: include/GeometricFigure.h
	g++ -c src/GeometricFigure.cc

clean:
	rm -rf *.o *.off run

cleano:
	rm -rf *.o

cleanoff:
	rm -rf *.off