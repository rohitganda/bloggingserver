# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std relationship-query-mysql-vc8.vcproj relationship-query-sqlite-vc8.vcproj relationship-query-pgsql-vc8.vcproj relationship-query-oracle-vc8.vcproj relationship-query-mssql-vc8.vcproj relationship-query-mysql-vc9.vcproj relationship-query-sqlite-vc9.vcproj relationship-query-pgsql-vc9.vcproj relationship-query-oracle-vc9.vcproj relationship-query-mssql-vc9.vcproj relationship-query-mysql-vc10.vcxproj relationship-query-sqlite-vc10.vcxproj relationship-query-pgsql-vc10.vcxproj relationship-query-oracle-vc10.vcxproj relationship-query-mssql-vc10.vcxproj relationship-query-mysql-vc10.vcxproj.filters relationship-query-sqlite-vc10.vcxproj.filters relationship-query-pgsql-vc10.vcxproj.filters relationship-query-oracle-vc10.vcxproj.filters relationship-query-mssql-vc10.vcxproj.filters relationship-query-mysql-vc11.vcxproj relationship-query-sqlite-vc11.vcxproj relationship-query-pgsql-vc11.vcxproj relationship-query-oracle-vc11.vcxproj relationship-query-mssql-vc11.vcxproj relationship-query-mysql-vc11.vcxproj.filters relationship-query-sqlite-vc11.vcxproj.filters relationship-query-pgsql-vc11.vcxproj.filters relationship-query-oracle-vc11.vcxproj.filters relationship-query-mssql-vc11.vcxproj.filters relationship-query-mysql-vc12.vcxproj relationship-query-sqlite-vc12.vcxproj relationship-query-pgsql-vc12.vcxproj relationship-query-oracle-vc12.vcxproj relationship-query-mssql-vc12.vcxproj relationship-query-mysql-vc12.vcxproj.filters relationship-query-sqlite-vc12.vcxproj.filters relationship-query-pgsql-vc12.vcxproj.filters relationship-query-oracle-vc12.vcxproj.filters relationship-query-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-session --table-prefix t_rel_query_ $<


