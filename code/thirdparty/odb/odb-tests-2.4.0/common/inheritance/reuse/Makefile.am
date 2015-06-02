# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std inheritance-reuse-mysql-vc8.vcproj inheritance-reuse-sqlite-vc8.vcproj inheritance-reuse-pgsql-vc8.vcproj inheritance-reuse-oracle-vc8.vcproj inheritance-reuse-mssql-vc8.vcproj inheritance-reuse-mysql-vc9.vcproj inheritance-reuse-sqlite-vc9.vcproj inheritance-reuse-pgsql-vc9.vcproj inheritance-reuse-oracle-vc9.vcproj inheritance-reuse-mssql-vc9.vcproj inheritance-reuse-mysql-vc10.vcxproj inheritance-reuse-sqlite-vc10.vcxproj inheritance-reuse-pgsql-vc10.vcxproj inheritance-reuse-oracle-vc10.vcxproj inheritance-reuse-mssql-vc10.vcxproj inheritance-reuse-mysql-vc10.vcxproj.filters inheritance-reuse-sqlite-vc10.vcxproj.filters inheritance-reuse-pgsql-vc10.vcxproj.filters inheritance-reuse-oracle-vc10.vcxproj.filters inheritance-reuse-mssql-vc10.vcxproj.filters inheritance-reuse-mysql-vc11.vcxproj inheritance-reuse-sqlite-vc11.vcxproj inheritance-reuse-pgsql-vc11.vcxproj inheritance-reuse-oracle-vc11.vcxproj inheritance-reuse-mssql-vc11.vcxproj inheritance-reuse-mysql-vc11.vcxproj.filters inheritance-reuse-sqlite-vc11.vcxproj.filters inheritance-reuse-pgsql-vc11.vcxproj.filters inheritance-reuse-oracle-vc11.vcxproj.filters inheritance-reuse-mssql-vc11.vcxproj.filters inheritance-reuse-mysql-vc12.vcxproj inheritance-reuse-sqlite-vc12.vcxproj inheritance-reuse-pgsql-vc12.vcxproj inheritance-reuse-oracle-vc12.vcxproj inheritance-reuse-mssql-vc12.vcxproj inheritance-reuse-mysql-vc12.vcxproj.filters inheritance-reuse-sqlite-vc12.vcxproj.filters inheritance-reuse-pgsql-vc12.vcxproj.filters inheritance-reuse-oracle-vc12.vcxproj.filters inheritance-reuse-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix inhrt_r_ $<


