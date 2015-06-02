# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std composite-id-mysql-vc8.vcproj composite-id-sqlite-vc8.vcproj composite-id-pgsql-vc8.vcproj composite-id-oracle-vc8.vcproj composite-id-mssql-vc8.vcproj composite-id-mysql-vc9.vcproj composite-id-sqlite-vc9.vcproj composite-id-pgsql-vc9.vcproj composite-id-oracle-vc9.vcproj composite-id-mssql-vc9.vcproj composite-id-mysql-vc10.vcxproj composite-id-sqlite-vc10.vcxproj composite-id-pgsql-vc10.vcxproj composite-id-oracle-vc10.vcxproj composite-id-mssql-vc10.vcxproj composite-id-mysql-vc10.vcxproj.filters composite-id-sqlite-vc10.vcxproj.filters composite-id-pgsql-vc10.vcxproj.filters composite-id-oracle-vc10.vcxproj.filters composite-id-mssql-vc10.vcxproj.filters composite-id-mysql-vc11.vcxproj composite-id-sqlite-vc11.vcxproj composite-id-pgsql-vc11.vcxproj composite-id-oracle-vc11.vcxproj composite-id-mssql-vc11.vcxproj composite-id-mysql-vc11.vcxproj.filters composite-id-sqlite-vc11.vcxproj.filters composite-id-pgsql-vc11.vcxproj.filters composite-id-oracle-vc11.vcxproj.filters composite-id-mssql-vc11.vcxproj.filters composite-id-mysql-vc12.vcxproj composite-id-sqlite-vc12.vcxproj composite-id-pgsql-vc12.vcxproj composite-id-oracle-vc12.vcxproj composite-id-mssql-vc12.vcxproj composite-id-mysql-vc12.vcxproj.filters composite-id-sqlite-vc12.vcxproj.filters composite-id-pgsql-vc12.vcxproj.filters composite-id-oracle-vc12.vcxproj.filters composite-id-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-session --table-prefix t_comp_id_ $<


