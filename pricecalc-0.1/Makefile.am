## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src 

pricecalcdocdir = ${prefix}/doc/pricecalc
pricecalcdoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


EXTRA_DIST = $(pricecalcdoc_DATA)


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(pricecalcdocdir)
