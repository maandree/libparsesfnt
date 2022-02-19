.POSIX:

CONFIGFILE = config.mk
include $(CONFIGFILE)

OS = linux
# Linux:   linux
# Mac OS:  macos
# Windows: windows
include mk/$(OS).mk


LIB_MAJOR = 0
LIB_MINOR = 1
LIB_VERSION = $(LIB_MAJOR).$(LIB_MINOR)


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
	meta\
	hdmx\
	post\
	cmap\
	bdat\
	bloc\
	sbix\
	ebsc

OBJ =\
	libparsesfnt_parse___.o\
	libparsesfnt_parse_fontdir.o\
	libparsesfnt_parse_tabdir.o\
	$(MODULES:=.o)

HDR =\
	libparsesfnt.h\
	common.h

LOBJ = $(OBJ:.o=.lo)


AR_OBJ = $(OBJ)
# Using "AR_OBJ=libparsesfnt-all.o" can reduce the size of the
# library, however this may affect the size of applications that
# don't use most of the functions. If you are compiling for your
# application specification you can combine this with setting
# MODULES to the parts your application will use; note however
# that 'fpgm' covers both 'fpgm' and 'prep'.

SO_LOBJ = $(LOBJ)
# You may use "SO_LOBJ=libparsesfnt-all.lo".


all: libparsesfnt.a libparsesfnt.$(LIBEXT)
$(OBJ): $(@:.o=.c) $(HDR)
$(LOBJ): $(@:.o=.c) $(HDR)
libparsesfnt-all.o: libparsesfnt-all.c $(HDR)
libparsesfnt-all.lo: libparsesfnt-all.c $(HDR)

libparsesfnt-all.c: $(OBJ:.o=.c)
	cat $(OBJ:.o=.c) > $@

.c.o:
	$(CC) -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

.c.lo:
	$(CC) -fPIC -c -o $@ $< $(CFLAGS) $(CPPFLAGS)

libparsesfnt.$(LIBEXT): $(SO_LOBJ)
	$(CC) $(LIBFLAGS) -o $@ $(SO_LOBJ) $(LDFLAGS)

libparsesfnt.a: $(AR_OBJ)
	@rm -f -- $@
	$(AR) rc $@ $(AR_OBJ)

install: libparsesfnt.a libparsesfnt.$(LIBEXT)
	mkdir -p -- "$(DESTDIR)$(PREFIX)/lib"
	mkdir -p -- "$(DESTDIR)$(PREFIX)/include"
	cp -- libparsesfnt.a "$(DESTDIR)$(PREFIX)/lib/"
	cp -- libparsesfnt.$(LIBEXT) "$(DESTDIR)$(PREFIX)/lib/libparsesfnt.$(LIBMINOREXT)"
	$(FIX_INSTALL_NAME) "$(DESTDIR)$(PREFIX)/lib/libparsesfnt.$(LIBMINOREXT)"
	ln -sf -- "libparsesfnt.$(LIBMINOREXT)" "$(DESTDIR)$(PREFIX)/lib/libparsesfnt.$(LIBMAJOREXT)"
	ln -sf -- "libparsesfnt.$(LIBMAJOREXT)" "$(DESTDIR)$(PREFIX)/lib/libparsesfnt.$(LIBEXT)"
	cp -- libparsesfnt.h "$(DESTDIR)$(PREFIX)/include/"

uninstall:
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libparsesfnt.a"
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libparsesfnt.$(LIBEXT)"
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libparsesfnt.$(LIBMAJOREXT)"
	-rm -f -- "$(DESTDIR)$(PREFIX)/lib/libparsesfnt.$(LIBMINOREXT)"
	-rm -f -- "$(DESTDIR)$(PREFIX)/include/libparsesfnt.h"

clean:
	-rm -f -- *.o *.a *.lo *.su *.so *.so.* *.gch *.gcov *.gcno *.gcda
	-rm -f -- libparsesfnt-all.c

.SUFFIXES:
.SUFFIXES: .lo .o .c

.PHONY: all install uninstall clean
