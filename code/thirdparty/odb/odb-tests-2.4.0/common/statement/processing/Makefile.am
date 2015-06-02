# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std statement-processing-mysql-vc8.vcproj statement-processing-sqlite-vc8.vcproj statement-processing-pgsql-vc8.vcproj statement-processing-oracle-vc8.vcproj statement-processing-mssql-vc8.vcproj statement-processing-mysql-vc9.vcproj statement-processing-sqlite-vc9.vcproj statement-processing-pgsql-vc9.vcproj statement-processing-oracle-vc9.vcproj statement-processing-mssql-vc9.vcproj statement-processing-mysql-vc10.vcxproj statement-processing-sqlite-vc10.vcxproj statement-processing-pgsql-vc10.vcxproj statement-processing-oracle-vc10.vcxproj statement-processing-mssql-vc10.vcxproj statement-processing-mysql-vc10.vcxproj.filters statement-processing-sqlite-vc10.vcxproj.filters statement-processing-pgsql-vc10.vcxproj.filters statement-processing-oracle-vc10.vcxproj.filters statement-processing-mssql-vc10.vcxproj.filters statement-processing-mysql-vc11.vcxproj statement-processing-sqlite-vc11.vcxproj statement-processing-pgsql-vc11.vcxproj statement-processing-oracle-vc11.vcxproj statement-processing-mssql-vc11.vcxproj statement-processing-mysql-vc11.vcxproj.filters statement-processing-sqlite-vc11.vcxproj.filters statement-processing-pgsql-vc11.vcxproj.filters statement-processing-oracle-vc11.vcxproj.filters statement-processing-mssql-vc11.vcxproj.filters statement-processing-mysql-vc12.vcxproj statement-processing-sqlite-vc12.vcxproj statement-processing-pgsql-vc12.vcxproj statement-processing-oracle-vc12.vcxproj statement-processing-mssql-vc12.vcxproj statement-processing-mysql-vc12.vcxproj.filters statement-processing-sqlite-vc12.vcxproj.filters statement-processing-pgsql-vc12.vcxproj.filters statement-processing-oracle-vc12.vcxproj.filters statement-processing-mssql-vc12.vcxproj.filters

noinst_PROGRAMS = driver
driver_SOURCES = driver.cxx  
LDADD = $(top_builddir)/libcommon/common/libcommon.la
AM_CPPFLAGS = -I'$(top_builddir)/libcommon' -I'$(top_srcdir)/libcommon'
AM_CPPFLAGS += -I'$(builddir)' -I'$(srcdir)'

TESTS=$(top_builddir)/tester
TESTS_ENVIRONMENT=top_builddir=$(top_builddir); export top_builddir;


