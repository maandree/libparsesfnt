.POSIX:

CONFIGFILE = config.mk
include $(CONFIGFILE)

MODULES =\
	head\
	bhed\
	hhea\
	hmtx\
	vhea\
	vmtx\
	maxp\
	loca\
	name\
	fmtx\
	ltag\
	xref\
	trak\
	gcid\
	fpgm\
	fdsc\
	gasp\
	avar\
	meta

OBJ =\
	libparsesfnt_parse___.o\
	libparsesfnt_parse_fontdir.o\
	libparsesfnt_parse_tabdir.o\
	$(MODULES:=.o)

HDR =\
	libparsesfnt.h\
	common.h

AR_OBJ = $(OBJ)
# Using "AR_OBJ=libparsesfnt-all.o" can reduce the size of the
# library, however this may affect the size of applications that
# don't use most of the functions. If you are compiling for your
# application specification you can combine this with setting
# MODULES to the parts your application will use; note however
# that 'fpgm' covers both 'fpgm' and 'prep'.

all: libparsesfnt.a
$(OBJ): $(@:.o=.c) $(HDR)
libparsesfnt-all.o: libparsesfnt-all.c $(HDR)

libparsesfnt-all.c: $(OBJ:.o=.c)
	cat $(OBJ:.o=.c) > $@

.c.o:
	$(CC) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

.c.lo:
	$(CC) -fPIC -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

libparsesfnt.a: $(AR_OBJ)
	@rm -f -- $@
	$(AR) rc $@ $(AR_OBJ)

install: libparsesfnt.a
	mkdir -p -- "$(DESTDIR)$(PREFIX)/lib"
	mkdir -p -- "$(DESTDIR)$(PREFIX)/include"
	cp -- libparsesfnt.a "$(DESTDIR)$(PREFIX)/lib/"
	cp -- libparsesfnt.h "$(DESTDIR)$(PREFIX)/include/"

uninstall:
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libparsesfnt.a"
	-rm -f -- "$(DESTDIR)$(PREFIX)/include/libparsesfnt.h"

clean:
	-rm -f -- *.o *.a *.lo *.su *.so *.so.* *.gch *.gcov *.gcno *.gcda
	-rm -f -- libparsesfnt-all.c

.SUFFIXES:
.SUFFIXES: .lo .o .c

.PHONY: all install uninstall clean
