# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std schema-embedded-order-mysql-vc8.vcproj schema-embedded-order-sqlite-vc8.vcproj schema-embedded-order-pgsql-vc8.vcproj schema-embedded-order-oracle-vc8.vcproj schema-embedded-order-mssql-vc8.vcproj schema-embedded-order-mysql-vc9.vcproj schema-embedded-order-sqlite-vc9.vcproj schema-embedded-order-pgsql-vc9.vcproj schema-embedded-order-oracle-vc9.vcproj schema-embedded-order-mssql-vc9.vcproj schema-embedded-order-mysql-vc10.vcxproj schema-embedded-order-sqlite-vc10.vcxproj schema-embedded-order-pgsql-vc10.vcxproj schema-embedded-order-oracle-vc10.vcxproj schema-embedded-order-mssql-vc10.vcxproj schema-embedded-order-mysql-vc10.vcxproj.filters schema-embedded-order-sqlite-vc10.vcxproj.filters schema-embedded-order-pgsql-vc10.vcxproj.filters schema-embedded-order-oracle-vc10.vcxproj.filters schema-embedded-order-mssql-vc10.vcxproj.filters schema-embedded-order-mysql-vc11.vcxproj schema-embedded-order-sqlite-vc11.vcxproj schema-embedded-order-pgsql-vc11.vcxproj schema-embedded-order-oracle-vc11.vcxproj schema-embedded-order-mssql-vc11.vcxproj schema-embedded-order-mysql-vc11.vcxproj.filters schema-embedded-order-sqlite-vc11.vcxproj.filters schema-embedded-order-pgsql-vc11.vcxproj.filters schema-embedded-order-oracle-vc11.vcxproj.filters schema-embedded-order-mssql-vc11.vcxproj.filters schema-embedded-order-mysql-vc12.vcxproj schema-embedded-order-sqlite-vc12.vcxproj schema-embedded-order-pgsql-vc12.vcxproj schema-embedded-order-oracle-vc12.vcxproj schema-embedded-order-mssql-vc12.vcxproj schema-embedded-order-mysql-vc12.vcxproj.filters schema-embedded-order-sqlite-vc12.vcxproj.filters schema-embedded-order-pgsql-vc12.vcxproj.filters schema-embedded-order-oracle-vc12.vcxproj.filters schema-embedded-order-mssql-vc12.vcxproj.filters

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

driver_SOURCES += test2.hxx
nodist_driver_SOURCES += test2-odb.cxx
BUILT_SOURCES += test2-odb.hxx
CLEANFILES += test2-odb.hxx test2-odb.ixx test2-odb.cxx

test2-odb.hxx: test2.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --schema-format embedded --table-prefix schema_embd_ordr_ $<

driver_SOURCES += test1.hxx
nodist_driver_SOURCES += test1-odb.cxx
BUILT_SOURCES += test1-odb.hxx
CLEANFILES += test1-odb.hxx test1-odb.ixx test1-odb.cxx

test1-odb.hxx: test1.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --schema-format embedded --table-prefix schema_embd_ordr_ $<


