# file      : libcommon/common/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

noinst_LTLIBRARIES = libcommon.la
libcommon_la_SOURCES = common.cxx concrete.hxx common.hxx common.txx buffer.hxx export.hxx config.hxx

EXTRA_DIST = config.h.in config-vc.h libcommon-mysql-vc8.vcproj libcommon-sqlite-vc8.vcproj libcommon-pgsql-vc8.vcproj libcommon-oracle-vc8.vcproj libcommon-mssql-vc8.vcproj libcommon-mysql-vc9.vcproj libcommon-sqlite-vc9.vcproj libcommon-pgsql-vc9.vcproj libcommon-oracle-vc9.vcproj libcommon-mssql-vc9.vcproj libcommon-mysql-vc10.vcxproj libcommon-sqlite-vc10.vcxproj libcommon-pgsql-vc10.vcxproj libcommon-oracle-vc10.vcxproj libcommon-mssql-vc10.vcxproj libcommon-mysql-vc10.vcxproj.filters libcommon-sqlite-vc10.vcxproj.filters libcommon-pgsql-vc10.vcxproj.filters libcommon-oracle-vc10.vcxproj.filters libcommon-mssql-vc10.vcxproj.filters libcommon-mysql-vc11.vcxproj libcommon-sqlite-vc11.vcxproj libcommon-pgsql-vc11.vcxproj libcommon-oracle-vc11.vcxproj libcommon-mssql-vc11.vcxproj libcommon-mysql-vc11.vcxproj.filters libcommon-sqlite-vc11.vcxproj.filters libcommon-pgsql-vc11.vcxproj.filters libcommon-oracle-vc11.vcxproj.filters libcommon-mssql-vc11.vcxproj.filters libcommon-mysql-vc12.vcxproj libcommon-sqlite-vc12.vcxproj libcommon-pgsql-vc12.vcxproj libcommon-oracle-vc12.vcxproj libcommon-mssql-vc12.vcxproj libcommon-mysql-vc12.vcxproj.filters libcommon-sqlite-vc12.vcxproj.filters libcommon-pgsql-vc12.vcxproj.filters libcommon-oracle-vc12.vcxproj.filters libcommon-mssql-vc12.vcxproj.filters

AM_CPPFLAGS = -I'$(top_builddir)/libcommon' -I'$(top_srcdir)/libcommon'
AM_CPPFLAGS += -DLIBCOMMON_DYNAMIC_LIB
AM_LDFLAGS = -no-undefined -rpath '$(libdir)'
