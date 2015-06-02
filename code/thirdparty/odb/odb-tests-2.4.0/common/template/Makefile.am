# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std template-mysql-vc8.vcproj template-sqlite-vc8.vcproj template-pgsql-vc8.vcproj template-oracle-vc8.vcproj template-mssql-vc8.vcproj template-mysql-vc9.vcproj template-sqlite-vc9.vcproj template-pgsql-vc9.vcproj template-oracle-vc9.vcproj template-mssql-vc9.vcproj template-mysql-vc10.vcxproj template-sqlite-vc10.vcxproj template-pgsql-vc10.vcxproj template-oracle-vc10.vcxproj template-mssql-vc10.vcxproj template-mysql-vc10.vcxproj.filters template-sqlite-vc10.vcxproj.filters template-pgsql-vc10.vcxproj.filters template-oracle-vc10.vcxproj.filters template-mssql-vc10.vcxproj.filters template-mysql-vc11.vcxproj template-sqlite-vc11.vcxproj template-pgsql-vc11.vcxproj template-oracle-vc11.vcxproj template-mssql-vc11.vcxproj template-mysql-vc11.vcxproj.filters template-sqlite-vc11.vcxproj.filters template-pgsql-vc11.vcxproj.filters template-oracle-vc11.vcxproj.filters template-mssql-vc11.vcxproj.filters template-mysql-vc12.vcxproj template-sqlite-vc12.vcxproj template-pgsql-vc12.vcxproj template-oracle-vc12.vcxproj template-mssql-vc12.vcxproj template-mysql-vc12.vcxproj.filters template-sqlite-vc12.vcxproj.filters template-pgsql-vc12.vcxproj.filters template-oracle-vc12.vcxproj.filters template-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --table-prefix template_ $<


