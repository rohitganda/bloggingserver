# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std circular-multiple-mysql-vc8.vcproj circular-multiple-sqlite-vc8.vcproj circular-multiple-pgsql-vc8.vcproj circular-multiple-oracle-vc8.vcproj circular-multiple-mssql-vc8.vcproj circular-multiple-mysql-vc9.vcproj circular-multiple-sqlite-vc9.vcproj circular-multiple-pgsql-vc9.vcproj circular-multiple-oracle-vc9.vcproj circular-multiple-mssql-vc9.vcproj circular-multiple-mysql-vc10.vcxproj circular-multiple-sqlite-vc10.vcxproj circular-multiple-pgsql-vc10.vcxproj circular-multiple-oracle-vc10.vcxproj circular-multiple-mssql-vc10.vcxproj circular-multiple-mysql-vc10.vcxproj.filters circular-multiple-sqlite-vc10.vcxproj.filters circular-multiple-pgsql-vc10.vcxproj.filters circular-multiple-oracle-vc10.vcxproj.filters circular-multiple-mssql-vc10.vcxproj.filters circular-multiple-mysql-vc11.vcxproj circular-multiple-sqlite-vc11.vcxproj circular-multiple-pgsql-vc11.vcxproj circular-multiple-oracle-vc11.vcxproj circular-multiple-mssql-vc11.vcxproj circular-multiple-mysql-vc11.vcxproj.filters circular-multiple-sqlite-vc11.vcxproj.filters circular-multiple-pgsql-vc11.vcxproj.filters circular-multiple-oracle-vc11.vcxproj.filters circular-multiple-mssql-vc11.vcxproj.filters circular-multiple-mysql-vc12.vcxproj circular-multiple-sqlite-vc12.vcxproj circular-multiple-pgsql-vc12.vcxproj circular-multiple-oracle-vc12.vcxproj circular-multiple-mssql-vc12.vcxproj circular-multiple-mysql-vc12.vcxproj.filters circular-multiple-sqlite-vc12.vcxproj.filters circular-multiple-pgsql-vc12.vcxproj.filters circular-multiple-oracle-vc12.vcxproj.filters circular-multiple-mssql-vc12.vcxproj.filters

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

driver_SOURCES += test1.hxx
nodist_driver_SOURCES += test1-odb.cxx
BUILT_SOURCES += test1-odb.hxx
CLEANFILES += test1-odb.hxx test1-odb.ixx test1-odb.cxx

test1-odb.hxx: test1.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --schema-format embedded --table-prefix circular_m_ $<

driver_SOURCES += test2.hxx
nodist_driver_SOURCES += test2-odb.cxx
BUILT_SOURCES += test2-odb.hxx
CLEANFILES += test2-odb.hxx test2-odb.ixx test2-odb.cxx

test2-odb.hxx: test2.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --schema-format embedded --table-prefix circular_m_ $<


