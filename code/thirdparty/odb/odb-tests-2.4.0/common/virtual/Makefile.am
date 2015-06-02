# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std virtual-mysql-vc8.vcproj virtual-sqlite-vc8.vcproj virtual-pgsql-vc8.vcproj virtual-oracle-vc8.vcproj virtual-mssql-vc8.vcproj virtual-mysql-vc9.vcproj virtual-sqlite-vc9.vcproj virtual-pgsql-vc9.vcproj virtual-oracle-vc9.vcproj virtual-mssql-vc9.vcproj virtual-mysql-vc10.vcxproj virtual-sqlite-vc10.vcxproj virtual-pgsql-vc10.vcxproj virtual-oracle-vc10.vcxproj virtual-mssql-vc10.vcxproj virtual-mysql-vc10.vcxproj.filters virtual-sqlite-vc10.vcxproj.filters virtual-pgsql-vc10.vcxproj.filters virtual-oracle-vc10.vcxproj.filters virtual-mssql-vc10.vcxproj.filters virtual-mysql-vc11.vcxproj virtual-sqlite-vc11.vcxproj virtual-pgsql-vc11.vcxproj virtual-oracle-vc11.vcxproj virtual-mssql-vc11.vcxproj virtual-mysql-vc11.vcxproj.filters virtual-sqlite-vc11.vcxproj.filters virtual-pgsql-vc11.vcxproj.filters virtual-oracle-vc11.vcxproj.filters virtual-mssql-vc11.vcxproj.filters virtual-mysql-vc12.vcxproj virtual-sqlite-vc12.vcxproj virtual-pgsql-vc12.vcxproj virtual-oracle-vc12.vcxproj virtual-mssql-vc12.vcxproj virtual-mysql-vc12.vcxproj.filters virtual-sqlite-vc12.vcxproj.filters virtual-pgsql-vc12.vcxproj.filters virtual-oracle-vc12.vcxproj.filters virtual-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-session --table-prefix virtual_ $<


