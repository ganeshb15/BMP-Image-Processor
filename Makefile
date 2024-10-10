o=out
BMP:  
	 
	g++ $(f) bmp/header.cpp bmp/pixel.cpp bmp/write.cpp  bmp/matrix/matrix.cpp -o $(o)
	chmod +x ./$(o)
	./$(o)
