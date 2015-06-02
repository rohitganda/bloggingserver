# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std enum-mysql-vc8.vcproj enum-sqlite-vc8.vcproj enum-pgsql-vc8.vcproj enum-oracle-vc8.vcproj enum-mssql-vc8.vcproj enum-mysql-vc9.vcproj enum-sqlite-vc9.vcproj enum-pgsql-vc9.vcproj enum-oracle-vc9.vcproj enum-mssql-vc9.vcproj enum-mysql-vc10.vcxproj enum-sqlite-vc10.vcxproj enum-pgsql-vc10.vcxproj enum-oracle-vc10.vcxproj enum-mssql-vc10.vcxproj enum-mysql-vc10.vcxproj.filters enum-sqlite-vc10.vcxproj.filters enum-pgsql-vc10.vcxproj.filters enum-oracle-vc10.vcxproj.filters enum-mssql-vc10.vcxproj.filters enum-mysql-vc11.vcxproj enum-sqlite-vc11.vcxproj enum-pgsql-vc11.vcxproj enum-oracle-vc11.vcxproj enum-mssql-vc11.vcxproj enum-mysql-vc11.vcxproj.filters enum-sqlite-vc11.vcxproj.filters enum-pgsql-vc11.vcxproj.filters enum-oracle-vc11.vcxproj.filters enum-mssql-vc11.vcxproj.filters enum-mysql-vc12.vcxproj enum-sqlite-vc12.vcxproj enum-pgsql-vc12.vcxproj enum-oracle-vc12.vcxproj enum-mssql-vc12.vcxproj enum-mysql-vc12.vcxproj.filters enum-sqlite-vc12.vcxproj.filters enum-pgsql-vc12.vcxproj.filters enum-oracle-vc12.vcxproj.filters enum-mssql-vc12.vcxproj.filters

noinst_PROGRAMS = driver
driver_SOURCES = driver.cxx  
LDADD = $(top_builddir)/libcommon/common/libcommon.la
AM_CPPFLAGS = -I'$(top_builddir)/libcommon' -I'$(top_srcdir)/libcommon'
AM_CPPFLAGS += -I'$(builddir)' -I'$(srcdir)'

TESTS=$(top_builddir)/tester
TESTS_ENVIRONMENT=top_builddir=$(top_builddir); export top_builddir;

# ODB compilation.
#
ODB = @ODB@
ODBFLAGS = @ODBFLAGS@
ODBCPPFLAGS = @ODBCPPFLAGS@

if HAVE_CXX11
ODBFLAGS += --std c++11
endif

nodist_driver_SOURCES =
BUILT_SOURCES =
CLEANFILES =

driver_SOURCES += test.hxx
nodist_driver_SOURCES += test-odb.cxx
BUILT_SOURCES += test-odb.hxx
CLEANFILES += test-odb.hxx test-odb.ixx test-odb.cxx

test-odb.hxx: test.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix enum_ $<


