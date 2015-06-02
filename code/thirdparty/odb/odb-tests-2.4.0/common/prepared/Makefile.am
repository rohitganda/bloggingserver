# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std prepared-mysql-vc8.vcproj prepared-sqlite-vc8.vcproj prepared-pgsql-vc8.vcproj prepared-oracle-vc8.vcproj prepared-mssql-vc8.vcproj prepared-mysql-vc9.vcproj prepared-sqlite-vc9.vcproj prepared-pgsql-vc9.vcproj prepared-oracle-vc9.vcproj prepared-mssql-vc9.vcproj prepared-mysql-vc10.vcxproj prepared-sqlite-vc10.vcxproj prepared-pgsql-vc10.vcxproj prepared-oracle-vc10.vcxproj prepared-mssql-vc10.vcxproj prepared-mysql-vc10.vcxproj.filters prepared-sqlite-vc10.vcxproj.filters prepared-pgsql-vc10.vcxproj.filters prepared-oracle-vc10.vcxproj.filters prepared-mssql-vc10.vcxproj.filters prepared-mysql-vc11.vcxproj prepared-sqlite-vc11.vcxproj prepared-pgsql-vc11.vcxproj prepared-oracle-vc11.vcxproj prepared-mssql-vc11.vcxproj prepared-mysql-vc11.vcxproj.filters prepared-sqlite-vc11.vcxproj.filters prepared-pgsql-vc11.vcxproj.filters prepared-oracle-vc11.vcxproj.filters prepared-mssql-vc11.vcxproj.filters prepared-mysql-vc12.vcxproj prepared-sqlite-vc12.vcxproj prepared-pgsql-vc12.vcxproj prepared-oracle-vc12.vcxproj prepared-mssql-vc12.vcxproj prepared-mysql-vc12.vcxproj.filters prepared-sqlite-vc12.vcxproj.filters prepared-pgsql-vc12.vcxproj.filters prepared-oracle-vc12.vcxproj.filters prepared-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --omit-unprepared --table-prefix prepared_ $<


