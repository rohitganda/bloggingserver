# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std ctor-mysql-vc8.vcproj ctor-sqlite-vc8.vcproj ctor-pgsql-vc8.vcproj ctor-oracle-vc8.vcproj ctor-mssql-vc8.vcproj ctor-mysql-vc9.vcproj ctor-sqlite-vc9.vcproj ctor-pgsql-vc9.vcproj ctor-oracle-vc9.vcproj ctor-mssql-vc9.vcproj ctor-mysql-vc10.vcxproj ctor-sqlite-vc10.vcxproj ctor-pgsql-vc10.vcxproj ctor-oracle-vc10.vcxproj ctor-mssql-vc10.vcxproj ctor-mysql-vc10.vcxproj.filters ctor-sqlite-vc10.vcxproj.filters ctor-pgsql-vc10.vcxproj.filters ctor-oracle-vc10.vcxproj.filters ctor-mssql-vc10.vcxproj.filters ctor-mysql-vc11.vcxproj ctor-sqlite-vc11.vcxproj ctor-pgsql-vc11.vcxproj ctor-oracle-vc11.vcxproj ctor-mssql-vc11.vcxproj ctor-mysql-vc11.vcxproj.filters ctor-sqlite-vc11.vcxproj.filters ctor-pgsql-vc11.vcxproj.filters ctor-oracle-vc11.vcxproj.filters ctor-mssql-vc11.vcxproj.filters ctor-mysql-vc12.vcxproj ctor-sqlite-vc12.vcxproj ctor-pgsql-vc12.vcxproj ctor-oracle-vc12.vcxproj ctor-mssql-vc12.vcxproj ctor-mysql-vc12.vcxproj.filters ctor-sqlite-vc12.vcxproj.filters ctor-pgsql-vc12.vcxproj.filters ctor-oracle-vc12.vcxproj.filters ctor-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix ctor_ $<


