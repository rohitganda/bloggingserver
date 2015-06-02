# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std query-one-mysql-vc8.vcproj query-one-sqlite-vc8.vcproj query-one-pgsql-vc8.vcproj query-one-oracle-vc8.vcproj query-one-mssql-vc8.vcproj query-one-mysql-vc9.vcproj query-one-sqlite-vc9.vcproj query-one-pgsql-vc9.vcproj query-one-oracle-vc9.vcproj query-one-mssql-vc9.vcproj query-one-mysql-vc10.vcxproj query-one-sqlite-vc10.vcxproj query-one-pgsql-vc10.vcxproj query-one-oracle-vc10.vcxproj query-one-mssql-vc10.vcxproj query-one-mysql-vc10.vcxproj.filters query-one-sqlite-vc10.vcxproj.filters query-one-pgsql-vc10.vcxproj.filters query-one-oracle-vc10.vcxproj.filters query-one-mssql-vc10.vcxproj.filters query-one-mysql-vc11.vcxproj query-one-sqlite-vc11.vcxproj query-one-pgsql-vc11.vcxproj query-one-oracle-vc11.vcxproj query-one-mssql-vc11.vcxproj query-one-mysql-vc11.vcxproj.filters query-one-sqlite-vc11.vcxproj.filters query-one-pgsql-vc11.vcxproj.filters query-one-oracle-vc11.vcxproj.filters query-one-mssql-vc11.vcxproj.filters query-one-mysql-vc12.vcxproj query-one-sqlite-vc12.vcxproj query-one-pgsql-vc12.vcxproj query-one-oracle-vc12.vcxproj query-one-mssql-vc12.vcxproj query-one-mysql-vc12.vcxproj.filters query-one-sqlite-vc12.vcxproj.filters query-one-pgsql-vc12.vcxproj.filters query-one-oracle-vc12.vcxproj.filters query-one-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix t_query_one_ $<


