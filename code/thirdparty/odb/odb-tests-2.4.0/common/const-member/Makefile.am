# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std const-member-mysql-vc8.vcproj const-member-sqlite-vc8.vcproj const-member-pgsql-vc8.vcproj const-member-oracle-vc8.vcproj const-member-mssql-vc8.vcproj const-member-mysql-vc9.vcproj const-member-sqlite-vc9.vcproj const-member-pgsql-vc9.vcproj const-member-oracle-vc9.vcproj const-member-mssql-vc9.vcproj const-member-mysql-vc10.vcxproj const-member-sqlite-vc10.vcxproj const-member-pgsql-vc10.vcxproj const-member-oracle-vc10.vcxproj const-member-mssql-vc10.vcxproj const-member-mysql-vc10.vcxproj.filters const-member-sqlite-vc10.vcxproj.filters const-member-pgsql-vc10.vcxproj.filters const-member-oracle-vc10.vcxproj.filters const-member-mssql-vc10.vcxproj.filters const-member-mysql-vc11.vcxproj const-member-sqlite-vc11.vcxproj const-member-pgsql-vc11.vcxproj const-member-oracle-vc11.vcxproj const-member-mssql-vc11.vcxproj const-member-mysql-vc11.vcxproj.filters const-member-sqlite-vc11.vcxproj.filters const-member-pgsql-vc11.vcxproj.filters const-member-oracle-vc11.vcxproj.filters const-member-mssql-vc11.vcxproj.filters const-member-mysql-vc12.vcxproj const-member-sqlite-vc12.vcxproj const-member-pgsql-vc12.vcxproj const-member-oracle-vc12.vcxproj const-member-mssql-vc12.vcxproj const-member-mysql-vc12.vcxproj.filters const-member-sqlite-vc12.vcxproj.filters const-member-pgsql-vc12.vcxproj.filters const-member-oracle-vc12.vcxproj.filters const-member-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --table-prefix constm_ $<


