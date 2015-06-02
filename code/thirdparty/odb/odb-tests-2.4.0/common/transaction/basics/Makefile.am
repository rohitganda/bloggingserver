# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std transaction-basics-mysql-vc8.vcproj transaction-basics-sqlite-vc8.vcproj transaction-basics-pgsql-vc8.vcproj transaction-basics-oracle-vc8.vcproj transaction-basics-mssql-vc8.vcproj transaction-basics-mysql-vc9.vcproj transaction-basics-sqlite-vc9.vcproj transaction-basics-pgsql-vc9.vcproj transaction-basics-oracle-vc9.vcproj transaction-basics-mssql-vc9.vcproj transaction-basics-mysql-vc10.vcxproj transaction-basics-sqlite-vc10.vcxproj transaction-basics-pgsql-vc10.vcxproj transaction-basics-oracle-vc10.vcxproj transaction-basics-mssql-vc10.vcxproj transaction-basics-mysql-vc10.vcxproj.filters transaction-basics-sqlite-vc10.vcxproj.filters transaction-basics-pgsql-vc10.vcxproj.filters transaction-basics-oracle-vc10.vcxproj.filters transaction-basics-mssql-vc10.vcxproj.filters transaction-basics-mysql-vc11.vcxproj transaction-basics-sqlite-vc11.vcxproj transaction-basics-pgsql-vc11.vcxproj transaction-basics-oracle-vc11.vcxproj transaction-basics-mssql-vc11.vcxproj transaction-basics-mysql-vc11.vcxproj.filters transaction-basics-sqlite-vc11.vcxproj.filters transaction-basics-pgsql-vc11.vcxproj.filters transaction-basics-oracle-vc11.vcxproj.filters transaction-basics-mssql-vc11.vcxproj.filters transaction-basics-mysql-vc12.vcxproj transaction-basics-sqlite-vc12.vcxproj transaction-basics-pgsql-vc12.vcxproj transaction-basics-oracle-vc12.vcxproj transaction-basics-mssql-vc12.vcxproj transaction-basics-mysql-vc12.vcxproj.filters transaction-basics-sqlite-vc12.vcxproj.filters transaction-basics-pgsql-vc12.vcxproj.filters transaction-basics-oracle-vc12.vcxproj.filters transaction-basics-mssql-vc12.vcxproj.filters

noinst_PROGRAMS = driver
driver_SOURCES = driver.cxx  
LDADD = $(top_builddir)/libcommon/common/libcommon.la
AM_CPPFLAGS = -I'$(top_builddir)/libcommon' -I'$(top_srcdir)/libcommon'
AM_CPPFLAGS += -I'$(builddir)' -I'$(srcdir)'

TESTS=$(top_builddir)/tester
TESTS_ENVIRONMENT=top_builddir=$(top_builddir); export top_builddir;


