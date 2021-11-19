all: pngremoto pnglocal textoremoto textolocal

clean: 
	rm -f *.o *.a pngremoto pnglocal textoremoto textolocal

# Arquivos objetos:
leituraremota.o : leituraremota.c ../include/libinput.h
	gcc -L. -c -fPIC leituraremota.c -I../include

leituralocal.o : leituralocal.c ../include/libinput.h
	gcc -L. -c -fPIC leituralocal.c -I../include 

plotagraficopng.o : plotagraficopng.c ../include/libplot.h
	gcc -L. -c plotagraficopng.c -I../include

plotagraficotexto.o: plotagraficotexto.c ../include/libplot.h
	gcc -L. -c plotagraficotexto.c -I../include

pngremoto.o : ../prog/wrapper.c ../include/libinput.h ../include/libplot.h
	gcc -L. -c ../prog/wrapper.c -o pngremoto.o -I../include

pnglocal.o : ../prog/wrapper.c ../include/libinput.h ../include/libplot.h
	gcc -L. -c ../prog/wrapper.c -o pnglocal.o -I../include
	
textoremoto.o : ../prog/wrapper.c ../include/libinput.h ../include/libplot.h
	gcc -L. -c ../prog/wrapper.c -o textoremoto.o -I../include

textolocal.o : ../prog/wrapper.c ../include/libinput.h ../include/libplot.h
	gcc -L. -c ../prog/wrapper.c -o textolocal.o -I../include

# Bibliotecas

# dinâmicas:
libleituraremota.so : leituraremota.o
	gcc -o libleituraremota.so -shared leituraremota.o

libleituralocal.so : leituralocal.o
	gcc -o libleituralocal.so -shared leituralocal.o

# estáticas:
libplotagraficotexto.a : plotagraficotexto.o
	ar rcv libplotagraficotexto.a plotagraficotexto.o

libplotagraficopng.a : plotagraficopng.o
	ar rcv libplotagraficopng.a plotagraficopng.o

# Executáveis:
pngremoto : pngremoto.o ../include/libinput.h ../include/libplot.h libleituraremota.so libplotagraficopng.a
	gcc -L. -o pngremoto pngremoto.o -I../include -lleituraremota -lplotagraficopng -lcurl
	
pnglocal : pnglocal.o ../include/libinput.h ../include/libplot.h libleituralocal.so libplotagraficopng.a
	gcc -L. -o pnglocal pnglocal.o -I../include -lleituralocal -lplotagraficopng -lcurl

textoremoto : textoremoto.o ../include/libinput.h ../include/libplot.h libleituraremota.so libplotagraficotexto.a
	gcc -L. -o textoremoto textoremoto.o -I../include -lleituraremota -lplotagraficotexto -lcurl

textolocal : textolocal.o ../include/libinput.h ../include/libplot.h libleituralocal.so libplotagraficotexto.a
	gcc -L. -o textolocal textolocal.o -I../include -lleituralocal -lplotagraficotexto -lcurl 