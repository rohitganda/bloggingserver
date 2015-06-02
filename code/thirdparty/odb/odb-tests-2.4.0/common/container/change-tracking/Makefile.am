# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std container-change-tracking-mysql-vc8.vcproj container-change-tracking-sqlite-vc8.vcproj container-change-tracking-pgsql-vc8.vcproj container-change-tracking-oracle-vc8.vcproj container-change-tracking-mssql-vc8.vcproj container-change-tracking-mysql-vc9.vcproj container-change-tracking-sqlite-vc9.vcproj container-change-tracking-pgsql-vc9.vcproj container-change-tracking-oracle-vc9.vcproj container-change-tracking-mssql-vc9.vcproj container-change-tracking-mysql-vc10.vcxproj container-change-tracking-sqlite-vc10.vcxproj container-change-tracking-pgsql-vc10.vcxproj container-change-tracking-oracle-vc10.vcxproj container-change-tracking-mssql-vc10.vcxproj container-change-tracking-mysql-vc10.vcxproj.filters container-change-tracking-sqlite-vc10.vcxproj.filters container-change-tracking-pgsql-vc10.vcxproj.filters container-change-tracking-oracle-vc10.vcxproj.filters container-change-tracking-mssql-vc10.vcxproj.filters container-change-tracking-mysql-vc11.vcxproj container-change-tracking-sqlite-vc11.vcxproj container-change-tracking-pgsql-vc11.vcxproj container-change-tracking-oracle-vc11.vcxproj container-change-tracking-mssql-vc11.vcxproj container-change-tracking-mysql-vc11.vcxproj.filters container-change-tracking-sqlite-vc11.vcxproj.filters container-change-tracking-pgsql-vc11.vcxproj.filters container-change-tracking-oracle-vc11.vcxproj.filters container-change-tracking-mssql-vc11.vcxproj.filters container-change-tracking-mysql-vc12.vcxproj container-change-tracking-sqlite-vc12.vcxproj container-change-tracking-pgsql-vc12.vcxproj container-change-tracking-oracle-vc12.vcxproj container-change-tracking-mssql-vc12.vcxproj container-change-tracking-mysql-vc12.vcxproj.filters container-change-tracking-sqlite-vc12.vcxproj.filters container-change-tracking-pgsql-vc12.vcxproj.filters container-change-tracking-oracle-vc12.vcxproj.filters container-change-tracking-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --table-prefix t_cont_changet_ $<


