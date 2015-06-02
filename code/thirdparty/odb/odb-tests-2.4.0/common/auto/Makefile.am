# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std auto-mysql-vc8.vcproj auto-sqlite-vc8.vcproj auto-pgsql-vc8.vcproj auto-oracle-vc8.vcproj auto-mssql-vc8.vcproj auto-mysql-vc9.vcproj auto-sqlite-vc9.vcproj auto-pgsql-vc9.vcproj auto-oracle-vc9.vcproj auto-mssql-vc9.vcproj auto-mysql-vc10.vcxproj auto-sqlite-vc10.vcxproj auto-pgsql-vc10.vcxproj auto-oracle-vc10.vcxproj auto-mssql-vc10.vcxproj auto-mysql-vc10.vcxproj.filters auto-sqlite-vc10.vcxproj.filters auto-pgsql-vc10.vcxproj.filters auto-oracle-vc10.vcxproj.filters auto-mssql-vc10.vcxproj.filters auto-mysql-vc11.vcxproj auto-sqlite-vc11.vcxproj auto-pgsql-vc11.vcxproj auto-oracle-vc11.vcxproj auto-mssql-vc11.vcxproj auto-mysql-vc11.vcxproj.filters auto-sqlite-vc11.vcxproj.filters auto-pgsql-vc11.vcxproj.filters auto-oracle-vc11.vcxproj.filters auto-mssql-vc11.vcxproj.filters auto-mysql-vc12.vcxproj auto-sqlite-vc12.vcxproj auto-pgsql-vc12.vcxproj auto-oracle-vc12.vcxproj auto-mssql-vc12.vcxproj auto-mysql-vc12.vcxproj.filters auto-sqlite-vc12.vcxproj.filters auto-pgsql-vc12.vcxproj.filters auto-oracle-vc12.vcxproj.filters auto-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --table-prefix auto_ $<


