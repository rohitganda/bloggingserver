# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std composite-mysql-vc8.vcproj composite-sqlite-vc8.vcproj composite-pgsql-vc8.vcproj composite-oracle-vc8.vcproj composite-mssql-vc8.vcproj composite-mysql-vc9.vcproj composite-sqlite-vc9.vcproj composite-pgsql-vc9.vcproj composite-oracle-vc9.vcproj composite-mssql-vc9.vcproj composite-mysql-vc10.vcxproj composite-sqlite-vc10.vcxproj composite-pgsql-vc10.vcxproj composite-oracle-vc10.vcxproj composite-mssql-vc10.vcxproj composite-mysql-vc10.vcxproj.filters composite-sqlite-vc10.vcxproj.filters composite-pgsql-vc10.vcxproj.filters composite-oracle-vc10.vcxproj.filters composite-mssql-vc10.vcxproj.filters composite-mysql-vc11.vcxproj composite-sqlite-vc11.vcxproj composite-pgsql-vc11.vcxproj composite-oracle-vc11.vcxproj composite-mssql-vc11.vcxproj composite-mysql-vc11.vcxproj.filters composite-sqlite-vc11.vcxproj.filters composite-pgsql-vc11.vcxproj.filters composite-oracle-vc11.vcxproj.filters composite-mssql-vc11.vcxproj.filters composite-mysql-vc12.vcxproj composite-sqlite-vc12.vcxproj composite-pgsql-vc12.vcxproj composite-oracle-vc12.vcxproj composite-mssql-vc12.vcxproj composite-mysql-vc12.vcxproj.filters composite-sqlite-vc12.vcxproj.filters composite-pgsql-vc12.vcxproj.filters composite-oracle-vc12.vcxproj.filters composite-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix t_comp_ $<


