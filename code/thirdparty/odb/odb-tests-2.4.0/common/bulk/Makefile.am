# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test-mysql.std test-sqlite.std test-pgsql.std test-oracle.std test-mssql.std bulk-mysql-vc8.vcproj bulk-sqlite-vc8.vcproj bulk-pgsql-vc8.vcproj bulk-oracle-vc8.vcproj bulk-mssql-vc8.vcproj bulk-mysql-vc9.vcproj bulk-sqlite-vc9.vcproj bulk-pgsql-vc9.vcproj bulk-oracle-vc9.vcproj bulk-mssql-vc9.vcproj bulk-mysql-vc10.vcxproj bulk-sqlite-vc10.vcxproj bulk-pgsql-vc10.vcxproj bulk-oracle-vc10.vcxproj bulk-mssql-vc10.vcxproj bulk-mysql-vc10.vcxproj.filters bulk-sqlite-vc10.vcxproj.filters bulk-pgsql-vc10.vcxproj.filters bulk-oracle-vc10.vcxproj.filters bulk-mssql-vc10.vcxproj.filters bulk-mysql-vc11.vcxproj bulk-sqlite-vc11.vcxproj bulk-pgsql-vc11.vcxproj bulk-oracle-vc11.vcxproj bulk-mssql-vc11.vcxproj bulk-mysql-vc11.vcxproj.filters bulk-sqlite-vc11.vcxproj.filters bulk-pgsql-vc11.vcxproj.filters bulk-oracle-vc11.vcxproj.filters bulk-mssql-vc11.vcxproj.filters bulk-mysql-vc12.vcxproj bulk-sqlite-vc12.vcxproj bulk-pgsql-vc12.vcxproj bulk-oracle-vc12.vcxproj bulk-mssql-vc12.vcxproj bulk-mysql-vc12.vcxproj.filters bulk-sqlite-vc12.vcxproj.filters bulk-pgsql-vc12.vcxproj.filters bulk-oracle-vc12.vcxproj.filters bulk-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix bulk_ $<


