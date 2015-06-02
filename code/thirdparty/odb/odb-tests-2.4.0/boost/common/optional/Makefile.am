# file      : boost/common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std optional-mysql-vc8.vcproj optional-sqlite-vc8.vcproj optional-pgsql-vc8.vcproj optional-oracle-vc8.vcproj optional-mssql-vc8.vcproj optional-mysql-vc9.vcproj optional-sqlite-vc9.vcproj optional-pgsql-vc9.vcproj optional-oracle-vc9.vcproj optional-mssql-vc9.vcproj optional-mysql-vc10.vcxproj optional-sqlite-vc10.vcxproj optional-pgsql-vc10.vcxproj optional-oracle-vc10.vcxproj optional-mssql-vc10.vcxproj optional-mysql-vc10.vcxproj.filters optional-sqlite-vc10.vcxproj.filters optional-pgsql-vc10.vcxproj.filters optional-oracle-vc10.vcxproj.filters optional-mssql-vc10.vcxproj.filters optional-mysql-vc11.vcxproj optional-sqlite-vc11.vcxproj optional-pgsql-vc11.vcxproj optional-oracle-vc11.vcxproj optional-mssql-vc11.vcxproj optional-mysql-vc11.vcxproj.filters optional-sqlite-vc11.vcxproj.filters optional-pgsql-vc11.vcxproj.filters optional-oracle-vc11.vcxproj.filters optional-mssql-vc11.vcxproj.filters optional-mysql-vc12.vcxproj optional-sqlite-vc12.vcxproj optional-pgsql-vc12.vcxproj optional-oracle-vc12.vcxproj optional-mssql-vc12.vcxproj optional-mysql-vc12.vcxproj.filters optional-sqlite-vc12.vcxproj.filters optional-pgsql-vc12.vcxproj.filters optional-oracle-vc12.vcxproj.filters optional-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --profile boost/optional --table-prefix boost_optional_ $<
