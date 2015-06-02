# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std lifecycle-mysql-vc8.vcproj lifecycle-sqlite-vc8.vcproj lifecycle-pgsql-vc8.vcproj lifecycle-oracle-vc8.vcproj lifecycle-mssql-vc8.vcproj lifecycle-mysql-vc9.vcproj lifecycle-sqlite-vc9.vcproj lifecycle-pgsql-vc9.vcproj lifecycle-oracle-vc9.vcproj lifecycle-mssql-vc9.vcproj lifecycle-mysql-vc10.vcxproj lifecycle-sqlite-vc10.vcxproj lifecycle-pgsql-vc10.vcxproj lifecycle-oracle-vc10.vcxproj lifecycle-mssql-vc10.vcxproj lifecycle-mysql-vc10.vcxproj.filters lifecycle-sqlite-vc10.vcxproj.filters lifecycle-pgsql-vc10.vcxproj.filters lifecycle-oracle-vc10.vcxproj.filters lifecycle-mssql-vc10.vcxproj.filters lifecycle-mysql-vc11.vcxproj lifecycle-sqlite-vc11.vcxproj lifecycle-pgsql-vc11.vcxproj lifecycle-oracle-vc11.vcxproj lifecycle-mssql-vc11.vcxproj lifecycle-mysql-vc11.vcxproj.filters lifecycle-sqlite-vc11.vcxproj.filters lifecycle-pgsql-vc11.vcxproj.filters lifecycle-oracle-vc11.vcxproj.filters lifecycle-mssql-vc11.vcxproj.filters lifecycle-mysql-vc12.vcxproj lifecycle-sqlite-vc12.vcxproj lifecycle-pgsql-vc12.vcxproj lifecycle-oracle-vc12.vcxproj lifecycle-mssql-vc12.vcxproj lifecycle-mysql-vc12.vcxproj.filters lifecycle-sqlite-vc12.vcxproj.filters lifecycle-pgsql-vc12.vcxproj.filters lifecycle-oracle-vc12.vcxproj.filters lifecycle-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --table-prefix lifecycle_ $<


