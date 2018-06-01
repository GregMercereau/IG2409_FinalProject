#Creation du fichier executable avec les fichiers objet

Main : main.o blur_video.o brightness.o brightness_video.o CED.o erosion.o gaussian_video.o panorama.o resize.o rotate_video.o CED_video.o
	g++ -o Main main.o blur_video.o brightness.o brightness_video.o CED.o erosion.o gaussian_video.o panorama.o resize.o rotate_video.o CED_video.o `pkg-config opencv --cflags --libs`

#Creation des fichiers objet 

main.o : main.cpp
	g++ -c -Wall main.cpp

blur_video.o : blur_video.cpp 
	g++ -c -Wall blur_video.cpp
	
brightness.o : brightness.cpp
	g++ -c -Wall brightness.cpp
 
brightness_video.o : brightness_video.cpp
	g++ -c -Wall brightness_video.cpp
 
CED.o : CED.cpp
	g++ -c -Wall CED.cpp
 
erosion.o : erosion.cpp
	g++ -c -Wall erosion.cpp

gaussian_video.o : gaussian_video.cpp
	g++ -c -Wall gaussian_video.cpp
 
panorama.o : panorama.cpp
	g++ -c -Wall panorama.cpp
 
resize.o : resize.cpp 
	g++ -c -Wall resize.cpp

rotate_video.o : rotate_video.cpp 
	g++ -c -Wall rotate_video.cpp

CED_video.o : CED_video.cpp 
	g++ -c -Wall CED_video.cpp
