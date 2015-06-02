# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std inheritance-transient-mysql-vc8.vcproj inheritance-transient-sqlite-vc8.vcproj inheritance-transient-pgsql-vc8.vcproj inheritance-transient-oracle-vc8.vcproj inheritance-transient-mssql-vc8.vcproj inheritance-transient-mysql-vc9.vcproj inheritance-transient-sqlite-vc9.vcproj inheritance-transient-pgsql-vc9.vcproj inheritance-transient-oracle-vc9.vcproj inheritance-transient-mssql-vc9.vcproj inheritance-transient-mysql-vc10.vcxproj inheritance-transient-sqlite-vc10.vcxproj inheritance-transient-pgsql-vc10.vcxproj inheritance-transient-oracle-vc10.vcxproj inheritance-transient-mssql-vc10.vcxproj inheritance-transient-mysql-vc10.vcxproj.filters inheritance-transient-sqlite-vc10.vcxproj.filters inheritance-transient-pgsql-vc10.vcxproj.filters inheritance-transient-oracle-vc10.vcxproj.filters inheritance-transient-mssql-vc10.vcxproj.filters inheritance-transient-mysql-vc11.vcxproj inheritance-transient-sqlite-vc11.vcxproj inheritance-transient-pgsql-vc11.vcxproj inheritance-transient-oracle-vc11.vcxproj inheritance-transient-mssql-vc11.vcxproj inheritance-transient-mysql-vc11.vcxproj.filters inheritance-transient-sqlite-vc11.vcxproj.filters inheritance-transient-pgsql-vc11.vcxproj.filters inheritance-transient-oracle-vc11.vcxproj.filters inheritance-transient-mssql-vc11.vcxproj.filters inheritance-transient-mysql-vc12.vcxproj inheritance-transient-sqlite-vc12.vcxproj inheritance-transient-pgsql-vc12.vcxproj inheritance-transient-oracle-vc12.vcxproj inheritance-transient-mssql-vc12.vcxproj inheritance-transient-mysql-vc12.vcxproj.filters inheritance-transient-sqlite-vc12.vcxproj.filters inheritance-transient-pgsql-vc12.vcxproj.filters inheritance-transient-oracle-vc12.vcxproj.filters inheritance-transient-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix inhrt_t_ $<


