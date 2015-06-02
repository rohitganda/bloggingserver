# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std blob-mysql-vc8.vcproj blob-sqlite-vc8.vcproj blob-pgsql-vc8.vcproj blob-oracle-vc8.vcproj blob-mssql-vc8.vcproj blob-mysql-vc9.vcproj blob-sqlite-vc9.vcproj blob-pgsql-vc9.vcproj blob-oracle-vc9.vcproj blob-mssql-vc9.vcproj blob-mysql-vc10.vcxproj blob-sqlite-vc10.vcxproj blob-pgsql-vc10.vcxproj blob-oracle-vc10.vcxproj blob-mssql-vc10.vcxproj blob-mysql-vc10.vcxproj.filters blob-sqlite-vc10.vcxproj.filters blob-pgsql-vc10.vcxproj.filters blob-oracle-vc10.vcxproj.filters blob-mssql-vc10.vcxproj.filters blob-mysql-vc11.vcxproj blob-sqlite-vc11.vcxproj blob-pgsql-vc11.vcxproj blob-oracle-vc11.vcxproj blob-mssql-vc11.vcxproj blob-mysql-vc11.vcxproj.filters blob-sqlite-vc11.vcxproj.filters blob-pgsql-vc11.vcxproj.filters blob-oracle-vc11.vcxproj.filters blob-mssql-vc11.vcxproj.filters blob-mysql-vc12.vcxproj blob-sqlite-vc12.vcxproj blob-pgsql-vc12.vcxproj blob-oracle-vc12.vcxproj blob-mssql-vc12.vcxproj blob-mysql-vc12.vcxproj.filters blob-sqlite-vc12.vcxproj.filters blob-pgsql-vc12.vcxproj.filters blob-oracle-vc12.vcxproj.filters blob-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --table-prefix blob_ $<


