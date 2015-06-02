# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std view-basics-mysql-vc8.vcproj view-basics-sqlite-vc8.vcproj view-basics-pgsql-vc8.vcproj view-basics-oracle-vc8.vcproj view-basics-mssql-vc8.vcproj view-basics-mysql-vc9.vcproj view-basics-sqlite-vc9.vcproj view-basics-pgsql-vc9.vcproj view-basics-oracle-vc9.vcproj view-basics-mssql-vc9.vcproj view-basics-mysql-vc10.vcxproj view-basics-sqlite-vc10.vcxproj view-basics-pgsql-vc10.vcxproj view-basics-oracle-vc10.vcxproj view-basics-mssql-vc10.vcxproj view-basics-mysql-vc10.vcxproj.filters view-basics-sqlite-vc10.vcxproj.filters view-basics-pgsql-vc10.vcxproj.filters view-basics-oracle-vc10.vcxproj.filters view-basics-mssql-vc10.vcxproj.filters view-basics-mysql-vc11.vcxproj view-basics-sqlite-vc11.vcxproj view-basics-pgsql-vc11.vcxproj view-basics-oracle-vc11.vcxproj view-basics-mssql-vc11.vcxproj view-basics-mysql-vc11.vcxproj.filters view-basics-sqlite-vc11.vcxproj.filters view-basics-pgsql-vc11.vcxproj.filters view-basics-oracle-vc11.vcxproj.filters view-basics-mssql-vc11.vcxproj.filters view-basics-mysql-vc12.vcxproj view-basics-sqlite-vc12.vcxproj view-basics-pgsql-vc12.vcxproj view-basics-oracle-vc12.vcxproj view-basics-mssql-vc12.vcxproj view-basics-mysql-vc12.vcxproj.filters view-basics-sqlite-vc12.vcxproj.filters view-basics-pgsql-vc12.vcxproj.filters view-basics-oracle-vc12.vcxproj.filters view-basics-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix t_view_b_ $<


