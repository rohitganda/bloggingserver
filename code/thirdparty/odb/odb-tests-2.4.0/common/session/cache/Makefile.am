# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std session-cache-mysql-vc8.vcproj session-cache-sqlite-vc8.vcproj session-cache-pgsql-vc8.vcproj session-cache-oracle-vc8.vcproj session-cache-mssql-vc8.vcproj session-cache-mysql-vc9.vcproj session-cache-sqlite-vc9.vcproj session-cache-pgsql-vc9.vcproj session-cache-oracle-vc9.vcproj session-cache-mssql-vc9.vcproj session-cache-mysql-vc10.vcxproj session-cache-sqlite-vc10.vcxproj session-cache-pgsql-vc10.vcxproj session-cache-oracle-vc10.vcxproj session-cache-mssql-vc10.vcxproj session-cache-mysql-vc10.vcxproj.filters session-cache-sqlite-vc10.vcxproj.filters session-cache-pgsql-vc10.vcxproj.filters session-cache-oracle-vc10.vcxproj.filters session-cache-mssql-vc10.vcxproj.filters session-cache-mysql-vc11.vcxproj session-cache-sqlite-vc11.vcxproj session-cache-pgsql-vc11.vcxproj session-cache-oracle-vc11.vcxproj session-cache-mssql-vc11.vcxproj session-cache-mysql-vc11.vcxproj.filters session-cache-sqlite-vc11.vcxproj.filters session-cache-pgsql-vc11.vcxproj.filters session-cache-oracle-vc11.vcxproj.filters session-cache-mssql-vc11.vcxproj.filters session-cache-mysql-vc12.vcxproj session-cache-sqlite-vc12.vcxproj session-cache-pgsql-vc12.vcxproj session-cache-oracle-vc12.vcxproj session-cache-mssql-vc12.vcxproj session-cache-mysql-vc12.vcxproj.filters session-cache-sqlite-vc12.vcxproj.filters session-cache-pgsql-vc12.vcxproj.filters session-cache-oracle-vc12.vcxproj.filters session-cache-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-session --table-prefix session_cache_ $<


