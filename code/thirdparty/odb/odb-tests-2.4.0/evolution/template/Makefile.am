# file      : evolution/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = template-mysql-vc8.vcproj template-sqlite-vc8.vcproj template-pgsql-vc8.vcproj template-oracle-vc8.vcproj template-mssql-vc8.vcproj template-mysql-vc9.vcproj template-sqlite-vc9.vcproj template-pgsql-vc9.vcproj template-oracle-vc9.vcproj template-mssql-vc9.vcproj template-mysql-vc10.vcxproj template-sqlite-vc10.vcxproj template-pgsql-vc10.vcxproj template-oracle-vc10.vcxproj template-mssql-vc10.vcxproj template-mysql-vc10.vcxproj.filters template-sqlite-vc10.vcxproj.filters template-pgsql-vc10.vcxproj.filters template-oracle-vc10.vcxproj.filters template-mssql-vc10.vcxproj.filters template-mysql-vc11.vcxproj template-sqlite-vc11.vcxproj template-pgsql-vc11.vcxproj template-oracle-vc11.vcxproj template-mssql-vc11.vcxproj template-mysql-vc11.vcxproj.filters template-sqlite-vc11.vcxproj.filters template-pgsql-vc11.vcxproj.filters template-oracle-vc11.vcxproj.filters template-mssql-vc11.vcxproj.filters template-mysql-vc12.vcxproj template-sqlite-vc12.vcxproj template-pgsql-vc12.vcxproj template-oracle-vc12.vcxproj template-mssql-vc12.vcxproj template-mysql-vc12.vcxproj.filters template-sqlite-vc12.vcxproj.filters template-pgsql-vc12.vcxproj.filters template-oracle-vc12.vcxproj.filters template-mssql-vc12.vcxproj.filters

noinst_PROGRAMS = driver
driver_SOURCES = driver.cxx  model.hxx
LDADD = $(top_builddir)/libcommon/common/libcommon.la
AM_CPPFLAGS = -I'$(top_builddir)/libcommon' -I'$(top_srcdir)/libcommon'
AM_CPPFLAGS += -I'$(builddir)' -I'$(srcdir)'

TESTS=$(top_builddir)/evolution/tester
TESTS_ENVIRONMENT=top_builddir=$(top_builddir); export top_builddir;

ODB = @ODB@
ODBFLAGS = @ODBFLAGS@
ODBCPPFLAGS = @ODBCPPFLAGS@

if HAVE_CXX11
ODBFLAGS += --std c++11
endif

# test1.hxx
#
driver_SOURCES += test1.hxx
nodist_driver_SOURCES = test1-odb.cxx
BUILT_SOURCES = test1-odb.hxx
CLEANFILES = test1-odb.hxx test1-odb.ixx test1-odb.cxx test1.sql model.xml

test1-odb.hxx: test1.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-query --generate-schema --at-once --table-prefix evo_template_ --init-changelog --changelog model.xml $<

# test2.hxx
#
driver_SOURCES += test2.hxx
nodist_driver_SOURCES += test2-odb.cxx
BUILT_SOURCES += test2-odb.hxx
CLEANFILES += test2-odb.hxx test2-odb.ixx test2-odb.cxx test2.sql

test2-odb.hxx: test2.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-query --generate-schema --at-once --table-prefix evo_template_ --omit-create --suppress-migration --changelog model.xml $<

# test3.hxx
#
driver_SOURCES += test3.hxx
nodist_driver_SOURCES += test3-odb.cxx
BUILT_SOURCES += test3-odb.hxx
CLEANFILES += test3-odb.hxx test3-odb.ixx test3-odb.cxx test3.sql \
test3-002-pre.sql test3-002-post.sql test3-003-pre.sql test3-003-post.sql

test3-odb.hxx: test3.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-query --generate-schema --at-once --table-prefix evo_template_ --omit-create --changelog model.xml $<

# Make sure testN.hxx are compiled serially since they share the
# changelog. Also add dependency on model.hxx
#
test2-odb.hxx: test1-odb.hxx
test3-odb.hxx: test2-odb.hxx
test1-odb.hxx test2-odb.hxx test3-odb.hxx: model.hxx
