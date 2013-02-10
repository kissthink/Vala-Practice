## Process this file with automake to produce Makefile.in

## Created by Anjuta


uidir = $(pkgdatadir)/ui
ui_DATA = pricecalc.ui


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(PRICECALC_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = pricecalc

pricecalc_SOURCES = \
	pricecalc.vala config.vapi discount.vala discount_factory.vala

pricecalc_VALAFLAGS =  \
	--pkg gtk+-3.0

pricecalc_LDFLAGS = \
	-Wl,--export-dynamic

pricecalc_LDADD = $(PRICECALC_LIBS)


EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(pkgdatadir)

