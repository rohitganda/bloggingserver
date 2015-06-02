# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std callback-mysql-vc8.vcproj callback-sqlite-vc8.vcproj callback-pgsql-vc8.vcproj callback-oracle-vc8.vcproj callback-mssql-vc8.vcproj callback-mysql-vc9.vcproj callback-sqlite-vc9.vcproj callback-pgsql-vc9.vcproj callback-oracle-vc9.vcproj callback-mssql-vc9.vcproj callback-mysql-vc10.vcxproj callback-sqlite-vc10.vcxproj callback-pgsql-vc10.vcxproj callback-oracle-vc10.vcxproj callback-mssql-vc10.vcxproj callback-mysql-vc10.vcxproj.filters callback-sqlite-vc10.vcxproj.filters callback-pgsql-vc10.vcxproj.filters callback-oracle-vc10.vcxproj.filters callback-mssql-vc10.vcxproj.filters callback-mysql-vc11.vcxproj callback-sqlite-vc11.vcxproj callback-pgsql-vc11.vcxproj callback-oracle-vc11.vcxproj callback-mssql-vc11.vcxproj callback-mysql-vc11.vcxproj.filters callback-sqlite-vc11.vcxproj.filters callback-pgsql-vc11.vcxproj.filters callback-oracle-vc11.vcxproj.filters callback-mssql-vc11.vcxproj.filters callback-mysql-vc12.vcxproj callback-sqlite-vc12.vcxproj callback-pgsql-vc12.vcxproj callback-oracle-vc12.vcxproj callback-mssql-vc12.vcxproj callback-mysql-vc12.vcxproj.filters callback-sqlite-vc12.vcxproj.filters callback-pgsql-vc12.vcxproj.filters callback-oracle-vc12.vcxproj.filters callback-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix callback_ $<


