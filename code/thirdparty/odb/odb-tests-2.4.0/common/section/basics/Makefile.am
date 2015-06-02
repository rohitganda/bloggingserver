# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std section-basics-mysql-vc8.vcproj section-basics-sqlite-vc8.vcproj section-basics-pgsql-vc8.vcproj section-basics-oracle-vc8.vcproj section-basics-mssql-vc8.vcproj section-basics-mysql-vc9.vcproj section-basics-sqlite-vc9.vcproj section-basics-pgsql-vc9.vcproj section-basics-oracle-vc9.vcproj section-basics-mssql-vc9.vcproj section-basics-mysql-vc10.vcxproj section-basics-sqlite-vc10.vcxproj section-basics-pgsql-vc10.vcxproj section-basics-oracle-vc10.vcxproj section-basics-mssql-vc10.vcxproj section-basics-mysql-vc10.vcxproj.filters section-basics-sqlite-vc10.vcxproj.filters section-basics-pgsql-vc10.vcxproj.filters section-basics-oracle-vc10.vcxproj.filters section-basics-mssql-vc10.vcxproj.filters section-basics-mysql-vc11.vcxproj section-basics-sqlite-vc11.vcxproj section-basics-pgsql-vc11.vcxproj section-basics-oracle-vc11.vcxproj section-basics-mssql-vc11.vcxproj section-basics-mysql-vc11.vcxproj.filters section-basics-sqlite-vc11.vcxproj.filters section-basics-pgsql-vc11.vcxproj.filters section-basics-oracle-vc11.vcxproj.filters section-basics-mssql-vc11.vcxproj.filters section-basics-mysql-vc12.vcxproj section-basics-sqlite-vc12.vcxproj section-basics-pgsql-vc12.vcxproj section-basics-oracle-vc12.vcxproj section-basics-mssql-vc12.vcxproj section-basics-mysql-vc12.vcxproj.filters section-basics-sqlite-vc12.vcxproj.filters section-basics-pgsql-vc12.vcxproj.filters section-basics-oracle-vc12.vcxproj.filters section-basics-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix t_section_b_ $<


