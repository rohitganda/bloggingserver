# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std relationship-on-delete-mysql-vc8.vcproj relationship-on-delete-sqlite-vc8.vcproj relationship-on-delete-pgsql-vc8.vcproj relationship-on-delete-oracle-vc8.vcproj relationship-on-delete-mssql-vc8.vcproj relationship-on-delete-mysql-vc9.vcproj relationship-on-delete-sqlite-vc9.vcproj relationship-on-delete-pgsql-vc9.vcproj relationship-on-delete-oracle-vc9.vcproj relationship-on-delete-mssql-vc9.vcproj relationship-on-delete-mysql-vc10.vcxproj relationship-on-delete-sqlite-vc10.vcxproj relationship-on-delete-pgsql-vc10.vcxproj relationship-on-delete-oracle-vc10.vcxproj relationship-on-delete-mssql-vc10.vcxproj relationship-on-delete-mysql-vc10.vcxproj.filters relationship-on-delete-sqlite-vc10.vcxproj.filters relationship-on-delete-pgsql-vc10.vcxproj.filters relationship-on-delete-oracle-vc10.vcxproj.filters relationship-on-delete-mssql-vc10.vcxproj.filters relationship-on-delete-mysql-vc11.vcxproj relationship-on-delete-sqlite-vc11.vcxproj relationship-on-delete-pgsql-vc11.vcxproj relationship-on-delete-oracle-vc11.vcxproj relationship-on-delete-mssql-vc11.vcxproj relationship-on-delete-mysql-vc11.vcxproj.filters relationship-on-delete-sqlite-vc11.vcxproj.filters relationship-on-delete-pgsql-vc11.vcxproj.filters relationship-on-delete-oracle-vc11.vcxproj.filters relationship-on-delete-mssql-vc11.vcxproj.filters relationship-on-delete-mysql-vc12.vcxproj relationship-on-delete-sqlite-vc12.vcxproj relationship-on-delete-pgsql-vc12.vcxproj relationship-on-delete-oracle-vc12.vcxproj relationship-on-delete-mssql-vc12.vcxproj relationship-on-delete-mysql-vc12.vcxproj.filters relationship-on-delete-sqlite-vc12.vcxproj.filters relationship-on-delete-pgsql-vc12.vcxproj.filters relationship-on-delete-oracle-vc12.vcxproj.filters relationship-on-delete-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --fkeys-deferrable-mode mysql:not_deferrable --fkeys-deferrable-mode mssql:not_deferrable --table-prefix t_rel_on_d_ $<


