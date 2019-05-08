CC = g++
CFLAGS = -g -O2 -Wshadow -Wall -I/usr/local/include
DEPS = functions.h sortings.h
GMP = -lgmp
HEdir = /home/white_wolf/Desktop/Thesis/HElib-master/src
HElib = $(HEdir)/fhe.a

LDLIBS = -L/usr/local/lib $(HElib) -lgf2x $(NTL) -lntl $(GMP) -lm -lpthread
INCDIR = -I$(HEdir)

all: operations

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

operations: operations.o
	$(CC) $(CFLAGS) -o $@ $(INCDIR) $< $(LDLIBS)

clean:
	rm -f he_cmp *.o $(all)
