# file      : qt/common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std template-qt4-mysql-vc8.vcproj template-qt4-sqlite-vc8.vcproj template-qt4-pgsql-vc8.vcproj template-qt4-oracle-vc8.vcproj template-qt4-mssql-vc8.vcproj template-qt4-mysql-vc9.vcproj template-qt4-sqlite-vc9.vcproj template-qt4-pgsql-vc9.vcproj template-qt4-oracle-vc9.vcproj template-qt4-mssql-vc9.vcproj template-qt5-mysql-vc9.vcproj template-qt5-sqlite-vc9.vcproj template-qt5-pgsql-vc9.vcproj template-qt5-oracle-vc9.vcproj template-qt5-mssql-vc9.vcproj template-qt4-mysql-vc10.vcxproj template-qt4-sqlite-vc10.vcxproj template-qt4-pgsql-vc10.vcxproj template-qt4-oracle-vc10.vcxproj template-qt4-mssql-vc10.vcxproj template-qt4-mysql-vc10.vcxproj.filters template-qt4-sqlite-vc10.vcxproj.filters template-qt4-pgsql-vc10.vcxproj.filters template-qt4-oracle-vc10.vcxproj.filters template-qt4-mssql-vc10.vcxproj.filters template-qt5-mysql-vc10.vcxproj template-qt5-sqlite-vc10.vcxproj template-qt5-pgsql-vc10.vcxproj template-qt5-oracle-vc10.vcxproj template-qt5-mssql-vc10.vcxproj template-qt5-mysql-vc10.vcxproj.filters template-qt5-sqlite-vc10.vcxproj.filters template-qt5-pgsql-vc10.vcxproj.filters template-qt5-oracle-vc10.vcxproj.filters template-qt5-mssql-vc10.vcxproj.filters template-qt4-mysql-vc11.vcxproj template-qt4-sqlite-vc11.vcxproj template-qt4-pgsql-vc11.vcxproj template-qt4-oracle-vc11.vcxproj template-qt4-mssql-vc11.vcxproj template-qt4-mysql-vc11.vcxproj.filters template-qt4-sqlite-vc11.vcxproj.filters template-qt4-pgsql-vc11.vcxproj.filters template-qt4-oracle-vc11.vcxproj.filters template-qt4-mssql-vc11.vcxproj.filters template-qt5-mysql-vc11.vcxproj template-qt5-sqlite-vc11.vcxproj template-qt5-pgsql-vc11.vcxproj template-qt5-oracle-vc11.vcxproj template-qt5-mssql-vc11.vcxproj template-qt5-mysql-vc11.vcxproj.filters template-qt5-sqlite-vc11.vcxproj.filters template-qt5-pgsql-vc11.vcxproj.filters template-qt5-oracle-vc11.vcxproj.filters template-qt5-mssql-vc11.vcxproj.filters template-qt4-mysql-vc12.vcxproj template-qt4-sqlite-vc12.vcxproj template-qt4-pgsql-vc12.vcxproj template-qt4-oracle-vc12.vcxproj template-qt4-mssql-vc12.vcxproj template-qt4-mysql-vc12.vcxproj.filters template-qt4-sqlite-vc12.vcxproj.filters template-qt4-pgsql-vc12.vcxproj.filters template-qt4-oracle-vc12.vcxproj.filters template-qt4-mssql-vc12.vcxproj.filters template-qt5-mysql-vc12.vcxproj template-qt5-sqlite-vc12.vcxproj template-qt5-pgsql-vc12.vcxproj template-qt5-oracle-vc12.vcxproj template-qt5-mssql-vc12.vcxproj template-qt5-mysql-vc12.vcxproj.filters template-qt5-sqlite-vc12.vcxproj.filters template-qt5-pgsql-vc12.vcxproj.filters template-qt5-oracle-vc12.vcxproj.filters template-qt5-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --profile qt/version --table-prefix qt_template_ $<
