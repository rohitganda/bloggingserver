# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std definition-mysql-vc8.vcproj definition-sqlite-vc8.vcproj definition-pgsql-vc8.vcproj definition-oracle-vc8.vcproj definition-mssql-vc8.vcproj definition-mysql-vc9.vcproj definition-sqlite-vc9.vcproj definition-pgsql-vc9.vcproj definition-oracle-vc9.vcproj definition-mssql-vc9.vcproj definition-mysql-vc10.vcxproj definition-sqlite-vc10.vcxproj definition-pgsql-vc10.vcxproj definition-oracle-vc10.vcxproj definition-mssql-vc10.vcxproj definition-mysql-vc10.vcxproj.filters definition-sqlite-vc10.vcxproj.filters definition-pgsql-vc10.vcxproj.filters definition-oracle-vc10.vcxproj.filters definition-mssql-vc10.vcxproj.filters definition-mysql-vc11.vcxproj definition-sqlite-vc11.vcxproj definition-pgsql-vc11.vcxproj definition-oracle-vc11.vcxproj definition-mssql-vc11.vcxproj definition-mysql-vc11.vcxproj.filters definition-sqlite-vc11.vcxproj.filters definition-pgsql-vc11.vcxproj.filters definition-oracle-vc11.vcxproj.filters definition-mssql-vc11.vcxproj.filters definition-mysql-vc12.vcxproj definition-sqlite-vc12.vcxproj definition-pgsql-vc12.vcxproj definition-oracle-vc12.vcxproj definition-mssql-vc12.vcxproj definition-mysql-vc12.vcxproj.filters definition-sqlite-vc12.vcxproj.filters definition-pgsql-vc12.vcxproj.filters definition-oracle-vc12.vcxproj.filters definition-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --table-prefix definition_ $<

driver_SOURCES += time-mapping.hxx
nodist_driver_SOURCES += time-mapping-odb.cxx
BUILT_SOURCES += time-mapping-odb.hxx
CLEANFILES += time-mapping-odb.hxx time-mapping-odb.ixx time-mapping-odb.cxx

time-mapping-odb.hxx: time-mapping.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --table-prefix definition_ $<


