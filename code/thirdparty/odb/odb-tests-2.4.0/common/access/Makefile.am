# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std access-mysql-vc8.vcproj access-sqlite-vc8.vcproj access-pgsql-vc8.vcproj access-oracle-vc8.vcproj access-mssql-vc8.vcproj access-mysql-vc9.vcproj access-sqlite-vc9.vcproj access-pgsql-vc9.vcproj access-oracle-vc9.vcproj access-mssql-vc9.vcproj access-mysql-vc10.vcxproj access-sqlite-vc10.vcxproj access-pgsql-vc10.vcxproj access-oracle-vc10.vcxproj access-mssql-vc10.vcxproj access-mysql-vc10.vcxproj.filters access-sqlite-vc10.vcxproj.filters access-pgsql-vc10.vcxproj.filters access-oracle-vc10.vcxproj.filters access-mssql-vc10.vcxproj.filters access-mysql-vc11.vcxproj access-sqlite-vc11.vcxproj access-pgsql-vc11.vcxproj access-oracle-vc11.vcxproj access-mssql-vc11.vcxproj access-mysql-vc11.vcxproj.filters access-sqlite-vc11.vcxproj.filters access-pgsql-vc11.vcxproj.filters access-oracle-vc11.vcxproj.filters access-mssql-vc11.vcxproj.filters access-mysql-vc12.vcxproj access-sqlite-vc12.vcxproj access-pgsql-vc12.vcxproj access-oracle-vc12.vcxproj access-mssql-vc12.vcxproj access-mysql-vc12.vcxproj.filters access-sqlite-vc12.vcxproj.filters access-pgsql-vc12.vcxproj.filters access-oracle-vc12.vcxproj.filters access-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --table-prefix access_ --accessor-regex "#(.+)#Get\u\1#" --modifier-regex "#(.+)#Set\u\1#" $<


