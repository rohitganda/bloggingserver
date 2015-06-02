# file      : boost/common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std uuid-mysql-vc8.vcproj uuid-sqlite-vc8.vcproj uuid-pgsql-vc8.vcproj uuid-oracle-vc8.vcproj uuid-mssql-vc8.vcproj uuid-mysql-vc9.vcproj uuid-sqlite-vc9.vcproj uuid-pgsql-vc9.vcproj uuid-oracle-vc9.vcproj uuid-mssql-vc9.vcproj uuid-mysql-vc10.vcxproj uuid-sqlite-vc10.vcxproj uuid-pgsql-vc10.vcxproj uuid-oracle-vc10.vcxproj uuid-mssql-vc10.vcxproj uuid-mysql-vc10.vcxproj.filters uuid-sqlite-vc10.vcxproj.filters uuid-pgsql-vc10.vcxproj.filters uuid-oracle-vc10.vcxproj.filters uuid-mssql-vc10.vcxproj.filters uuid-mysql-vc11.vcxproj uuid-sqlite-vc11.vcxproj uuid-pgsql-vc11.vcxproj uuid-oracle-vc11.vcxproj uuid-mssql-vc11.vcxproj uuid-mysql-vc11.vcxproj.filters uuid-sqlite-vc11.vcxproj.filters uuid-pgsql-vc11.vcxproj.filters uuid-oracle-vc11.vcxproj.filters uuid-mssql-vc11.vcxproj.filters uuid-mysql-vc12.vcxproj uuid-sqlite-vc12.vcxproj uuid-pgsql-vc12.vcxproj uuid-oracle-vc12.vcxproj uuid-mssql-vc12.vcxproj uuid-mysql-vc12.vcxproj.filters uuid-sqlite-vc12.vcxproj.filters uuid-pgsql-vc12.vcxproj.filters uuid-oracle-vc12.vcxproj.filters uuid-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --profile boost/uuid --table-prefix boost_uuid_ $<
