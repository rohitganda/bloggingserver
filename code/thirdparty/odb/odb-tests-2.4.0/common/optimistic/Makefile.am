# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std optimistic-mysql-vc8.vcproj optimistic-sqlite-vc8.vcproj optimistic-pgsql-vc8.vcproj optimistic-oracle-vc8.vcproj optimistic-mssql-vc8.vcproj optimistic-mysql-vc9.vcproj optimistic-sqlite-vc9.vcproj optimistic-pgsql-vc9.vcproj optimistic-oracle-vc9.vcproj optimistic-mssql-vc9.vcproj optimistic-mysql-vc10.vcxproj optimistic-sqlite-vc10.vcxproj optimistic-pgsql-vc10.vcxproj optimistic-oracle-vc10.vcxproj optimistic-mssql-vc10.vcxproj optimistic-mysql-vc10.vcxproj.filters optimistic-sqlite-vc10.vcxproj.filters optimistic-pgsql-vc10.vcxproj.filters optimistic-oracle-vc10.vcxproj.filters optimistic-mssql-vc10.vcxproj.filters optimistic-mysql-vc11.vcxproj optimistic-sqlite-vc11.vcxproj optimistic-pgsql-vc11.vcxproj optimistic-oracle-vc11.vcxproj optimistic-mssql-vc11.vcxproj optimistic-mysql-vc11.vcxproj.filters optimistic-sqlite-vc11.vcxproj.filters optimistic-pgsql-vc11.vcxproj.filters optimistic-oracle-vc11.vcxproj.filters optimistic-mssql-vc11.vcxproj.filters optimistic-mysql-vc12.vcxproj optimistic-sqlite-vc12.vcxproj optimistic-pgsql-vc12.vcxproj optimistic-oracle-vc12.vcxproj optimistic-mssql-vc12.vcxproj optimistic-mysql-vc12.vcxproj.filters optimistic-sqlite-vc12.vcxproj.filters optimistic-pgsql-vc12.vcxproj.filters optimistic-oracle-vc12.vcxproj.filters optimistic-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix t_optimistic_ $<


