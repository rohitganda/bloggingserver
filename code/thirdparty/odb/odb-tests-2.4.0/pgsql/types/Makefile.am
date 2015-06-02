# file      : pgsql/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std types-vc8.vcproj types-vc9.vcproj types-vc10.vcxproj types-vc10.vcxproj.filters types-vc11.vcxproj types-vc11.vcxproj.filters types-vc12.vcxproj types-vc12.vcxproj.filters

noinst_PROGRAMS = driver
driver_SOURCES = driver.cxx  traits.hxx
LDADD = $(top_builddir)/libcommon/common/libcommon.la
AM_CPPFLAGS = -I'$(top_builddir)/libcommon' -I'$(top_srcdir)/libcommon'
AM_CPPFLAGS += -I'$(builddir)' -I'$(srcdir)'

TESTS=$(top_builddir)/tester
TESTS_ENVIRONMENT=top_builddir=$(top_builddir); export top_builddir;

# ODB compilation.
#
driver_SOURCES += test.hxx
nodist_driver_SOURCES = test-odb.cxx
BUILT_SOURCES = test-odb.hxx
CLEANFILES = test-odb.hxx test-odb.ixx test-odb.cxx

ODB = @ODB@
ODBFLAGS = @ODBFLAGS@
ODBCPPFLAGS = @ODBCPPFLAGS@

if HAVE_CXX11
ODBFLAGS += --std c++11
endif

test-odb.hxx: test.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database pgsql --default-database common --generate-schema --generate-query --cxx-prologue '#include "traits.hxx"' --table-prefix pgsql_types_ $<

