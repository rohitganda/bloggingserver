# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std query-array-mysql-vc8.vcproj query-array-sqlite-vc8.vcproj query-array-pgsql-vc8.vcproj query-array-oracle-vc8.vcproj query-array-mssql-vc8.vcproj query-array-mysql-vc9.vcproj query-array-sqlite-vc9.vcproj query-array-pgsql-vc9.vcproj query-array-oracle-vc9.vcproj query-array-mssql-vc9.vcproj query-array-mysql-vc10.vcxproj query-array-sqlite-vc10.vcxproj query-array-pgsql-vc10.vcxproj query-array-oracle-vc10.vcxproj query-array-mssql-vc10.vcxproj query-array-mysql-vc10.vcxproj.filters query-array-sqlite-vc10.vcxproj.filters query-array-pgsql-vc10.vcxproj.filters query-array-oracle-vc10.vcxproj.filters query-array-mssql-vc10.vcxproj.filters query-array-mysql-vc11.vcxproj query-array-sqlite-vc11.vcxproj query-array-pgsql-vc11.vcxproj query-array-oracle-vc11.vcxproj query-array-mssql-vc11.vcxproj query-array-mysql-vc11.vcxproj.filters query-array-sqlite-vc11.vcxproj.filters query-array-pgsql-vc11.vcxproj.filters query-array-oracle-vc11.vcxproj.filters query-array-mssql-vc11.vcxproj.filters query-array-mysql-vc12.vcxproj query-array-sqlite-vc12.vcxproj query-array-pgsql-vc12.vcxproj query-array-oracle-vc12.vcxproj query-array-mssql-vc12.vcxproj query-array-mysql-vc12.vcxproj.filters query-array-sqlite-vc12.vcxproj.filters query-array-pgsql-vc12.vcxproj.filters query-array-oracle-vc12.vcxproj.filters query-array-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --sql-name-case oracle:upper --table-prefix t_query_array_ $<


