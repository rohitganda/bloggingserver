# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std readonly-mysql-vc8.vcproj readonly-sqlite-vc8.vcproj readonly-pgsql-vc8.vcproj readonly-oracle-vc8.vcproj readonly-mssql-vc8.vcproj readonly-mysql-vc9.vcproj readonly-sqlite-vc9.vcproj readonly-pgsql-vc9.vcproj readonly-oracle-vc9.vcproj readonly-mssql-vc9.vcproj readonly-mysql-vc10.vcxproj readonly-sqlite-vc10.vcxproj readonly-pgsql-vc10.vcxproj readonly-oracle-vc10.vcxproj readonly-mssql-vc10.vcxproj readonly-mysql-vc10.vcxproj.filters readonly-sqlite-vc10.vcxproj.filters readonly-pgsql-vc10.vcxproj.filters readonly-oracle-vc10.vcxproj.filters readonly-mssql-vc10.vcxproj.filters readonly-mysql-vc11.vcxproj readonly-sqlite-vc11.vcxproj readonly-pgsql-vc11.vcxproj readonly-oracle-vc11.vcxproj readonly-mssql-vc11.vcxproj readonly-mysql-vc11.vcxproj.filters readonly-sqlite-vc11.vcxproj.filters readonly-pgsql-vc11.vcxproj.filters readonly-oracle-vc11.vcxproj.filters readonly-mssql-vc11.vcxproj.filters readonly-mysql-vc12.vcxproj readonly-sqlite-vc12.vcxproj readonly-pgsql-vc12.vcxproj readonly-oracle-vc12.vcxproj readonly-mssql-vc12.vcxproj readonly-mysql-vc12.vcxproj.filters readonly-sqlite-vc12.vcxproj.filters readonly-pgsql-vc12.vcxproj.filters readonly-oracle-vc12.vcxproj.filters readonly-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --table-prefix readonly_ $<


