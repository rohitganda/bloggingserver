# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std inverse-mysql-vc8.vcproj inverse-sqlite-vc8.vcproj inverse-pgsql-vc8.vcproj inverse-oracle-vc8.vcproj inverse-mssql-vc8.vcproj inverse-mysql-vc9.vcproj inverse-sqlite-vc9.vcproj inverse-pgsql-vc9.vcproj inverse-oracle-vc9.vcproj inverse-mssql-vc9.vcproj inverse-mysql-vc10.vcxproj inverse-sqlite-vc10.vcxproj inverse-pgsql-vc10.vcxproj inverse-oracle-vc10.vcxproj inverse-mssql-vc10.vcxproj inverse-mysql-vc10.vcxproj.filters inverse-sqlite-vc10.vcxproj.filters inverse-pgsql-vc10.vcxproj.filters inverse-oracle-vc10.vcxproj.filters inverse-mssql-vc10.vcxproj.filters inverse-mysql-vc11.vcxproj inverse-sqlite-vc11.vcxproj inverse-pgsql-vc11.vcxproj inverse-oracle-vc11.vcxproj inverse-mssql-vc11.vcxproj inverse-mysql-vc11.vcxproj.filters inverse-sqlite-vc11.vcxproj.filters inverse-pgsql-vc11.vcxproj.filters inverse-oracle-vc11.vcxproj.filters inverse-mssql-vc11.vcxproj.filters inverse-mysql-vc12.vcxproj inverse-sqlite-vc12.vcxproj inverse-pgsql-vc12.vcxproj inverse-oracle-vc12.vcxproj inverse-mssql-vc12.vcxproj inverse-mysql-vc12.vcxproj.filters inverse-sqlite-vc12.vcxproj.filters inverse-pgsql-vc12.vcxproj.filters inverse-oracle-vc12.vcxproj.filters inverse-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-session --table-prefix t_inverse_ $<


