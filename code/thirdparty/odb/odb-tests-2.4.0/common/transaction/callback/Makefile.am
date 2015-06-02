# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std transaction-callback-mysql-vc8.vcproj transaction-callback-sqlite-vc8.vcproj transaction-callback-pgsql-vc8.vcproj transaction-callback-oracle-vc8.vcproj transaction-callback-mssql-vc8.vcproj transaction-callback-mysql-vc9.vcproj transaction-callback-sqlite-vc9.vcproj transaction-callback-pgsql-vc9.vcproj transaction-callback-oracle-vc9.vcproj transaction-callback-mssql-vc9.vcproj transaction-callback-mysql-vc10.vcxproj transaction-callback-sqlite-vc10.vcxproj transaction-callback-pgsql-vc10.vcxproj transaction-callback-oracle-vc10.vcxproj transaction-callback-mssql-vc10.vcxproj transaction-callback-mysql-vc10.vcxproj.filters transaction-callback-sqlite-vc10.vcxproj.filters transaction-callback-pgsql-vc10.vcxproj.filters transaction-callback-oracle-vc10.vcxproj.filters transaction-callback-mssql-vc10.vcxproj.filters transaction-callback-mysql-vc11.vcxproj transaction-callback-sqlite-vc11.vcxproj transaction-callback-pgsql-vc11.vcxproj transaction-callback-oracle-vc11.vcxproj transaction-callback-mssql-vc11.vcxproj transaction-callback-mysql-vc11.vcxproj.filters transaction-callback-sqlite-vc11.vcxproj.filters transaction-callback-pgsql-vc11.vcxproj.filters transaction-callback-oracle-vc11.vcxproj.filters transaction-callback-mssql-vc11.vcxproj.filters transaction-callback-mysql-vc12.vcxproj transaction-callback-sqlite-vc12.vcxproj transaction-callback-pgsql-vc12.vcxproj transaction-callback-oracle-vc12.vcxproj transaction-callback-mssql-vc12.vcxproj transaction-callback-mysql-vc12.vcxproj.filters transaction-callback-sqlite-vc12.vcxproj.filters transaction-callback-pgsql-vc12.vcxproj.filters transaction-callback-oracle-vc12.vcxproj.filters transaction-callback-mssql-vc12.vcxproj.filters

noinst_PROGRAMS = driver
driver_SOURCES = driver.cxx  
LDADD = $(top_builddir)/libcommon/common/libcommon.la
AM_CPPFLAGS = -I'$(top_builddir)/libcommon' -I'$(top_srcdir)/libcommon'
AM_CPPFLAGS += -I'$(builddir)' -I'$(srcdir)'

TESTS=$(top_builddir)/tester
TESTS_ENVIRONMENT=top_builddir=$(top_builddir); export top_builddir;


