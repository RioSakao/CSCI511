driver: periodical.o  video.o book.o driver.o media.o search_engine.o film.o
	g++ -g  periodical.o video.o book.o driver.o media.o search_engine.o film.o -o driver

driver.o: driver.cpp search_engine.h
	g++  -g -fno-elide-constructors -c driver.cpp

search_engine.o: search_engine.cpp search_engine.h
	g++  -g -fno-elide-constructors -c search_engine.cpp

media.o: media.cpp media.h
	g++  -g -fno-elide-constructors -c media.cpp

book.o: book.cpp book.h 
	g++  -g -fno-elide-constructors -c book.cpp

video.o: video.cpp video.h
	g++  -g -fno-elide-constructors -c video.cpp

periodical.o: periodical.cpp periodical.h
	g++  -g -fno-elide-constructors -c periodical.cpp

film.o: film.cpp film.h
	g++ -g -fno-elide-constructors -c film.cpp

clean: 
	rm -f *.o driver
