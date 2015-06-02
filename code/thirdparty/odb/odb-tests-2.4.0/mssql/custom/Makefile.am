# file      : mssql/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std custom.sql custom-vc8.vcproj custom-vc9.vcproj custom-vc10.vcxproj custom-vc10.vcxproj.filters custom-vc11.vcxproj custom-vc11.vcxproj.filters custom-vc12.vcxproj custom-vc12.vcxproj.filters

noinst_PROGRAMS = driver
driver_SOURCES = driver.cxx traits.cxx traits.hxx query.hxx
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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database mssql --default-database common --generate-schema --generate-query --hxx-prologue '#include "traits.hxx"' --hxx-prologue '#include "query.hxx"' --sql-interlude ":r $(srcdir)/custom.sql" --table-prefix mssql_custom_ $<

