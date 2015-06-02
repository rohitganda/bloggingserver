# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std types-mysql-vc8.vcproj types-sqlite-vc8.vcproj types-pgsql-vc8.vcproj types-oracle-vc8.vcproj types-mssql-vc8.vcproj types-mysql-vc9.vcproj types-sqlite-vc9.vcproj types-pgsql-vc9.vcproj types-oracle-vc9.vcproj types-mssql-vc9.vcproj types-mysql-vc10.vcxproj types-sqlite-vc10.vcxproj types-pgsql-vc10.vcxproj types-oracle-vc10.vcxproj types-mssql-vc10.vcxproj types-mysql-vc10.vcxproj.filters types-sqlite-vc10.vcxproj.filters types-pgsql-vc10.vcxproj.filters types-oracle-vc10.vcxproj.filters types-mssql-vc10.vcxproj.filters types-mysql-vc11.vcxproj types-sqlite-vc11.vcxproj types-pgsql-vc11.vcxproj types-oracle-vc11.vcxproj types-mssql-vc11.vcxproj types-mysql-vc11.vcxproj.filters types-sqlite-vc11.vcxproj.filters types-pgsql-vc11.vcxproj.filters types-oracle-vc11.vcxproj.filters types-mssql-vc11.vcxproj.filters types-mysql-vc12.vcxproj types-sqlite-vc12.vcxproj types-pgsql-vc12.vcxproj types-oracle-vc12.vcxproj types-mssql-vc12.vcxproj types-mysql-vc12.vcxproj.filters types-sqlite-vc12.vcxproj.filters types-pgsql-vc12.vcxproj.filters types-oracle-vc12.vcxproj.filters types-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --table-prefix types_ $<


