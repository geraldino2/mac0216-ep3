all: remotepng localpng remotetext localtext

clean: 
	rm -f *.o *.a remotepng localpng remotetext localtext

# Arquivos objetos:
remoteread.o : remoteread.c ../include/libinput.h
	gcc -L. -c -fPIC remoteread.c -I../include

localread.o : localread.c ../include/libinput.h
	gcc -L. -c -fPIC localread.c -I../include 

pngplot.o : pngplot.c ../include/libplot.h
	gcc -L. -c pngplot.c -I../include

textplot.o: textplot.c ../include/libplot.h
	gcc -L. -c textplot.c -I../include

remotepng.o : ../prog/wrapper.c ../include/libinput.h ../include/libplot.h
	gcc -L. -c ../prog/wrapper.c -o remotepng.o -I../include

localpng.o : ../prog/wrapper.c ../include/libinput.h ../include/libplot.h
	gcc -L. -c ../prog/wrapper.c -o localpng.o -I../include
	
remotetext.o : ../prog/wrapper.c ../include/libinput.h ../include/libplot.h
	gcc -L. -c ../prog/wrapper.c -o remotetext.o -I../include

localtext.o : ../prog/wrapper.c ../include/libinput.h ../include/libplot.h
	gcc -L. -c ../prog/wrapper.c -o localtext.o -I../include

# Bibliotecas

# dinâmicas:
libremoteread.so : remoteread.o
	gcc -o libremoteread.so -shared remoteread.o

liblocalread.so : localread.o
	gcc -o liblocalread.so -shared localread.o

# estáticas:
libtextplot.a : textplot.o
	ar rcv libtextplot.a textplot.o

libpngplot.a : pngplot.o
	ar rcv libpngplot.a pngplot.o

# Executáveis:
remotepng : remotepng.o ../include/libinput.h ../include/libplot.h libremoteread.so libpngplot.a
	gcc -o remotepng remotepng.o -I../include -lremoteread -lpngplot -lcurl
	
localpng : localpng.o ../include/libinput.h ../include/libplot.h liblocalread.so libpngplot.a
	gcc -o localpng localpng.o -I../include -llocalread -lpngplot -lcurl

remotetext : remotetext.o ../include/libinput.h ../include/libplot.h libremoteread.so libtextplot.a
	gcc -o remotetext remotetext.o -I../include -lremoteread -ltextplot -lcurl

localtext : localtext.o ../include/libinput.h ../include/libplot.h liblocalread.so libtextplot.a
	gcc -o localtext localtext.o -I../include -llocalread -ltextplot -lcurl 