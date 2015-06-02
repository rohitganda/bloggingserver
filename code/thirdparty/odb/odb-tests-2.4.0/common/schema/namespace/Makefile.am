# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std schema-namespace-mysql-vc8.vcproj schema-namespace-sqlite-vc8.vcproj schema-namespace-pgsql-vc8.vcproj schema-namespace-oracle-vc8.vcproj schema-namespace-mssql-vc8.vcproj schema-namespace-mysql-vc9.vcproj schema-namespace-sqlite-vc9.vcproj schema-namespace-pgsql-vc9.vcproj schema-namespace-oracle-vc9.vcproj schema-namespace-mssql-vc9.vcproj schema-namespace-mysql-vc10.vcxproj schema-namespace-sqlite-vc10.vcxproj schema-namespace-pgsql-vc10.vcxproj schema-namespace-oracle-vc10.vcxproj schema-namespace-mssql-vc10.vcxproj schema-namespace-mysql-vc10.vcxproj.filters schema-namespace-sqlite-vc10.vcxproj.filters schema-namespace-pgsql-vc10.vcxproj.filters schema-namespace-oracle-vc10.vcxproj.filters schema-namespace-mssql-vc10.vcxproj.filters schema-namespace-mysql-vc11.vcxproj schema-namespace-sqlite-vc11.vcxproj schema-namespace-pgsql-vc11.vcxproj schema-namespace-oracle-vc11.vcxproj schema-namespace-mssql-vc11.vcxproj schema-namespace-mysql-vc11.vcxproj.filters schema-namespace-sqlite-vc11.vcxproj.filters schema-namespace-pgsql-vc11.vcxproj.filters schema-namespace-oracle-vc11.vcxproj.filters schema-namespace-mssql-vc11.vcxproj.filters schema-namespace-mysql-vc12.vcxproj schema-namespace-sqlite-vc12.vcxproj schema-namespace-pgsql-vc12.vcxproj schema-namespace-oracle-vc12.vcxproj schema-namespace-mssql-vc12.vcxproj schema-namespace-mysql-vc12.vcxproj.filters schema-namespace-sqlite-vc12.vcxproj.filters schema-namespace-pgsql-vc12.vcxproj.filters schema-namespace-oracle-vc12.vcxproj.filters schema-namespace-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix schema_ns_ $<


