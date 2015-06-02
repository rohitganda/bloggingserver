# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std wrapper-mysql-vc8.vcproj wrapper-sqlite-vc8.vcproj wrapper-pgsql-vc8.vcproj wrapper-oracle-vc8.vcproj wrapper-mssql-vc8.vcproj wrapper-mysql-vc9.vcproj wrapper-sqlite-vc9.vcproj wrapper-pgsql-vc9.vcproj wrapper-oracle-vc9.vcproj wrapper-mssql-vc9.vcproj wrapper-mysql-vc10.vcxproj wrapper-sqlite-vc10.vcxproj wrapper-pgsql-vc10.vcxproj wrapper-oracle-vc10.vcxproj wrapper-mssql-vc10.vcxproj wrapper-mysql-vc10.vcxproj.filters wrapper-sqlite-vc10.vcxproj.filters wrapper-pgsql-vc10.vcxproj.filters wrapper-oracle-vc10.vcxproj.filters wrapper-mssql-vc10.vcxproj.filters wrapper-mysql-vc11.vcxproj wrapper-sqlite-vc11.vcxproj wrapper-pgsql-vc11.vcxproj wrapper-oracle-vc11.vcxproj wrapper-mssql-vc11.vcxproj wrapper-mysql-vc11.vcxproj.filters wrapper-sqlite-vc11.vcxproj.filters wrapper-pgsql-vc11.vcxproj.filters wrapper-oracle-vc11.vcxproj.filters wrapper-mssql-vc11.vcxproj.filters wrapper-mysql-vc12.vcxproj wrapper-sqlite-vc12.vcxproj wrapper-pgsql-vc12.vcxproj wrapper-oracle-vc12.vcxproj wrapper-mssql-vc12.vcxproj wrapper-mysql-vc12.vcxproj.filters wrapper-sqlite-vc12.vcxproj.filters wrapper-pgsql-vc12.vcxproj.filters wrapper-oracle-vc12.vcxproj.filters wrapper-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --table-prefix wrapper_ $<


