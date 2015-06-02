# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std no-id-mysql-vc8.vcproj no-id-sqlite-vc8.vcproj no-id-pgsql-vc8.vcproj no-id-oracle-vc8.vcproj no-id-mssql-vc8.vcproj no-id-mysql-vc9.vcproj no-id-sqlite-vc9.vcproj no-id-pgsql-vc9.vcproj no-id-oracle-vc9.vcproj no-id-mssql-vc9.vcproj no-id-mysql-vc10.vcxproj no-id-sqlite-vc10.vcxproj no-id-pgsql-vc10.vcxproj no-id-oracle-vc10.vcxproj no-id-mssql-vc10.vcxproj no-id-mysql-vc10.vcxproj.filters no-id-sqlite-vc10.vcxproj.filters no-id-pgsql-vc10.vcxproj.filters no-id-oracle-vc10.vcxproj.filters no-id-mssql-vc10.vcxproj.filters no-id-mysql-vc11.vcxproj no-id-sqlite-vc11.vcxproj no-id-pgsql-vc11.vcxproj no-id-oracle-vc11.vcxproj no-id-mssql-vc11.vcxproj no-id-mysql-vc11.vcxproj.filters no-id-sqlite-vc11.vcxproj.filters no-id-pgsql-vc11.vcxproj.filters no-id-oracle-vc11.vcxproj.filters no-id-mssql-vc11.vcxproj.filters no-id-mysql-vc12.vcxproj no-id-sqlite-vc12.vcxproj no-id-pgsql-vc12.vcxproj no-id-oracle-vc12.vcxproj no-id-mssql-vc12.vcxproj no-id-mysql-vc12.vcxproj.filters no-id-sqlite-vc12.vcxproj.filters no-id-pgsql-vc12.vcxproj.filters no-id-oracle-vc12.vcxproj.filters no-id-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix no_id_ $<


