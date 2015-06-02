# file      : boost/common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std unordered-mysql-vc8.vcproj unordered-sqlite-vc8.vcproj unordered-pgsql-vc8.vcproj unordered-oracle-vc8.vcproj unordered-mssql-vc8.vcproj unordered-mysql-vc9.vcproj unordered-sqlite-vc9.vcproj unordered-pgsql-vc9.vcproj unordered-oracle-vc9.vcproj unordered-mssql-vc9.vcproj unordered-mysql-vc10.vcxproj unordered-sqlite-vc10.vcxproj unordered-pgsql-vc10.vcxproj unordered-oracle-vc10.vcxproj unordered-mssql-vc10.vcxproj unordered-mysql-vc10.vcxproj.filters unordered-sqlite-vc10.vcxproj.filters unordered-pgsql-vc10.vcxproj.filters unordered-oracle-vc10.vcxproj.filters unordered-mssql-vc10.vcxproj.filters unordered-mysql-vc11.vcxproj unordered-sqlite-vc11.vcxproj unordered-pgsql-vc11.vcxproj unordered-oracle-vc11.vcxproj unordered-mssql-vc11.vcxproj unordered-mysql-vc11.vcxproj.filters unordered-sqlite-vc11.vcxproj.filters unordered-pgsql-vc11.vcxproj.filters unordered-oracle-vc11.vcxproj.filters unordered-mssql-vc11.vcxproj.filters unordered-mysql-vc12.vcxproj unordered-sqlite-vc12.vcxproj unordered-pgsql-vc12.vcxproj unordered-oracle-vc12.vcxproj unordered-mssql-vc12.vcxproj unordered-mysql-vc12.vcxproj.filters unordered-sqlite-vc12.vcxproj.filters unordered-pgsql-vc12.vcxproj.filters unordered-oracle-vc12.vcxproj.filters unordered-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --profile boost/unordered --table-prefix boost_unordered_ $<
