# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std object-mysql-vc8.vcproj object-sqlite-vc8.vcproj object-pgsql-vc8.vcproj object-oracle-vc8.vcproj object-mssql-vc8.vcproj object-mysql-vc9.vcproj object-sqlite-vc9.vcproj object-pgsql-vc9.vcproj object-oracle-vc9.vcproj object-mssql-vc9.vcproj object-mysql-vc10.vcxproj object-sqlite-vc10.vcxproj object-pgsql-vc10.vcxproj object-oracle-vc10.vcxproj object-mssql-vc10.vcxproj object-mysql-vc10.vcxproj.filters object-sqlite-vc10.vcxproj.filters object-pgsql-vc10.vcxproj.filters object-oracle-vc10.vcxproj.filters object-mssql-vc10.vcxproj.filters object-mysql-vc11.vcxproj object-sqlite-vc11.vcxproj object-pgsql-vc11.vcxproj object-oracle-vc11.vcxproj object-mssql-vc11.vcxproj object-mysql-vc11.vcxproj.filters object-sqlite-vc11.vcxproj.filters object-pgsql-vc11.vcxproj.filters object-oracle-vc11.vcxproj.filters object-mssql-vc11.vcxproj.filters object-mysql-vc12.vcxproj object-sqlite-vc12.vcxproj object-pgsql-vc12.vcxproj object-oracle-vc12.vcxproj object-mssql-vc12.vcxproj object-mysql-vc12.vcxproj.filters object-sqlite-vc12.vcxproj.filters object-pgsql-vc12.vcxproj.filters object-oracle-vc12.vcxproj.filters object-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --table-prefix object_ --generate-query $<


