# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std index-mysql-vc8.vcproj index-sqlite-vc8.vcproj index-pgsql-vc8.vcproj index-oracle-vc8.vcproj index-mssql-vc8.vcproj index-mysql-vc9.vcproj index-sqlite-vc9.vcproj index-pgsql-vc9.vcproj index-oracle-vc9.vcproj index-mssql-vc9.vcproj index-mysql-vc10.vcxproj index-sqlite-vc10.vcxproj index-pgsql-vc10.vcxproj index-oracle-vc10.vcxproj index-mssql-vc10.vcxproj index-mysql-vc10.vcxproj.filters index-sqlite-vc10.vcxproj.filters index-pgsql-vc10.vcxproj.filters index-oracle-vc10.vcxproj.filters index-mssql-vc10.vcxproj.filters index-mysql-vc11.vcxproj index-sqlite-vc11.vcxproj index-pgsql-vc11.vcxproj index-oracle-vc11.vcxproj index-mssql-vc11.vcxproj index-mysql-vc11.vcxproj.filters index-sqlite-vc11.vcxproj.filters index-pgsql-vc11.vcxproj.filters index-oracle-vc11.vcxproj.filters index-mssql-vc11.vcxproj.filters index-mysql-vc12.vcxproj index-sqlite-vc12.vcxproj index-pgsql-vc12.vcxproj index-oracle-vc12.vcxproj index-mssql-vc12.vcxproj index-mysql-vc12.vcxproj.filters index-sqlite-vc12.vcxproj.filters index-pgsql-vc12.vcxproj.filters index-oracle-vc12.vcxproj.filters index-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --table-prefix index_ $<


