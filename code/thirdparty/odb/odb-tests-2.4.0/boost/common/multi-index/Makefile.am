# file      : boost/common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std multi-index-mysql-vc8.vcproj multi-index-sqlite-vc8.vcproj multi-index-pgsql-vc8.vcproj multi-index-oracle-vc8.vcproj multi-index-mssql-vc8.vcproj multi-index-mysql-vc9.vcproj multi-index-sqlite-vc9.vcproj multi-index-pgsql-vc9.vcproj multi-index-oracle-vc9.vcproj multi-index-mssql-vc9.vcproj multi-index-mysql-vc10.vcxproj multi-index-sqlite-vc10.vcxproj multi-index-pgsql-vc10.vcxproj multi-index-oracle-vc10.vcxproj multi-index-mssql-vc10.vcxproj multi-index-mysql-vc10.vcxproj.filters multi-index-sqlite-vc10.vcxproj.filters multi-index-pgsql-vc10.vcxproj.filters multi-index-oracle-vc10.vcxproj.filters multi-index-mssql-vc10.vcxproj.filters multi-index-mysql-vc11.vcxproj multi-index-sqlite-vc11.vcxproj multi-index-pgsql-vc11.vcxproj multi-index-oracle-vc11.vcxproj multi-index-mssql-vc11.vcxproj multi-index-mysql-vc11.vcxproj.filters multi-index-sqlite-vc11.vcxproj.filters multi-index-pgsql-vc11.vcxproj.filters multi-index-oracle-vc11.vcxproj.filters multi-index-mssql-vc11.vcxproj.filters multi-index-mysql-vc12.vcxproj multi-index-sqlite-vc12.vcxproj multi-index-pgsql-vc12.vcxproj multi-index-oracle-vc12.vcxproj multi-index-mssql-vc12.vcxproj multi-index-mysql-vc12.vcxproj.filters multi-index-sqlite-vc12.vcxproj.filters multi-index-pgsql-vc12.vcxproj.filters multi-index-oracle-vc12.vcxproj.filters multi-index-mssql-vc12.vcxproj.filters

noinst_PROGRAMS = driver
driver_SOURCES = driver.cxx  
LDADD = $(top_builddir)/libcommon/common/libcommon.la
AM_CPPFLAGS = -I'$(top_builddir)/libcommon' -I'$(top_srcdir)/libcommon'
AM_CPPFLAGS += -I'$(builddir)' -I'$(srcdir)'

TESTS=$(top_builddir)/tester
TESTS_ENVIRONMENT=top_builddir=$(top_builddir); export top_builddir;

# ODB compilation.
#
driver_SOURCES += test.hxx
nodist_driver_SOURCES = test-odb.cxx
BUILT_SOURCES = test-odb.hxx
CLEANFILES = test-odb.hxx test-odb.ixx test-odb.cxx

ODB = @ODB@
ODBFLAGS = @ODBFLAGS@
ODBCPPFLAGS = @ODBCPPFLAGS@

if HAVE_CXX11
ODBFLAGS += --std c++11
endif

test-odb.hxx: test.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --profile boost/multi-index --table-prefix boost_multi_index_ $<
