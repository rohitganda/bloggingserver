# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std threads-mysql-vc8.vcproj threads-sqlite-vc8.vcproj threads-pgsql-vc8.vcproj threads-oracle-vc8.vcproj threads-mssql-vc8.vcproj threads-mysql-vc9.vcproj threads-sqlite-vc9.vcproj threads-pgsql-vc9.vcproj threads-oracle-vc9.vcproj threads-mssql-vc9.vcproj threads-mysql-vc10.vcxproj threads-sqlite-vc10.vcxproj threads-pgsql-vc10.vcxproj threads-oracle-vc10.vcxproj threads-mssql-vc10.vcxproj threads-mysql-vc10.vcxproj.filters threads-sqlite-vc10.vcxproj.filters threads-pgsql-vc10.vcxproj.filters threads-oracle-vc10.vcxproj.filters threads-mssql-vc10.vcxproj.filters threads-mysql-vc11.vcxproj threads-sqlite-vc11.vcxproj threads-pgsql-vc11.vcxproj threads-oracle-vc11.vcxproj threads-mssql-vc11.vcxproj threads-mysql-vc11.vcxproj.filters threads-sqlite-vc11.vcxproj.filters threads-pgsql-vc11.vcxproj.filters threads-oracle-vc11.vcxproj.filters threads-mssql-vc11.vcxproj.filters threads-mysql-vc12.vcxproj threads-sqlite-vc12.vcxproj threads-pgsql-vc12.vcxproj threads-oracle-vc12.vcxproj threads-mssql-vc12.vcxproj threads-mysql-vc12.vcxproj.filters threads-sqlite-vc12.vcxproj.filters threads-pgsql-vc12.vcxproj.filters threads-oracle-vc12.vcxproj.filters threads-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix threads_ $<


