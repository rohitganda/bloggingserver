# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std view-olv-mysql-vc10.vcxproj view-olv-sqlite-vc10.vcxproj view-olv-pgsql-vc10.vcxproj view-olv-oracle-vc10.vcxproj view-olv-mssql-vc10.vcxproj view-olv-mysql-vc10.vcxproj.filters view-olv-sqlite-vc10.vcxproj.filters view-olv-pgsql-vc10.vcxproj.filters view-olv-oracle-vc10.vcxproj.filters view-olv-mssql-vc10.vcxproj.filters view-olv-mysql-vc11.vcxproj view-olv-sqlite-vc11.vcxproj view-olv-pgsql-vc11.vcxproj view-olv-oracle-vc11.vcxproj view-olv-mssql-vc11.vcxproj view-olv-mysql-vc11.vcxproj.filters view-olv-sqlite-vc11.vcxproj.filters view-olv-pgsql-vc11.vcxproj.filters view-olv-oracle-vc11.vcxproj.filters view-olv-mssql-vc11.vcxproj.filters view-olv-mysql-vc12.vcxproj view-olv-sqlite-vc12.vcxproj view-olv-pgsql-vc12.vcxproj view-olv-oracle-vc12.vcxproj view-olv-mssql-vc12.vcxproj view-olv-mysql-vc12.vcxproj.filters view-olv-sqlite-vc12.vcxproj.filters view-olv-pgsql-vc12.vcxproj.filters view-olv-oracle-vc12.vcxproj.filters view-olv-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix t_view_olv_ $<

driver_SOURCES += test2.hxx
nodist_driver_SOURCES += test2-odb.cxx
BUILT_SOURCES += test2-odb.hxx
CLEANFILES += test2-odb.hxx test2-odb.ixx test2-odb.cxx

test2-odb.hxx: test2.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix t_view_olv_ $<

driver_SOURCES += test3.hxx
nodist_driver_SOURCES += test3-odb.cxx
BUILT_SOURCES += test3-odb.hxx
CLEANFILES += test3-odb.hxx test3-odb.ixx test3-odb.cxx

test3-odb.hxx: test3.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix t_view_olv_ $<

driver_SOURCES += test4.hxx
nodist_driver_SOURCES += test4-odb.cxx
BUILT_SOURCES += test4-odb.hxx
CLEANFILES += test4-odb.hxx test4-odb.ixx test4-odb.cxx

test4-odb.hxx: test4.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix t_view_olv_ $<

driver_SOURCES += test5.hxx
nodist_driver_SOURCES += test5-odb.cxx
BUILT_SOURCES += test5-odb.hxx
CLEANFILES += test5-odb.hxx test5-odb.ixx test5-odb.cxx

test5-odb.hxx: test5.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix t_view_olv_ $<

driver_SOURCES += test6.hxx
nodist_driver_SOURCES += test6-odb.cxx
BUILT_SOURCES += test6-odb.hxx
CLEANFILES += test6-odb.hxx test6-odb.ixx test6-odb.cxx

test6-odb.hxx: test6.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix t_view_olv_ $<

driver_SOURCES += test7.hxx
nodist_driver_SOURCES += test7-odb.cxx
BUILT_SOURCES += test7-odb.hxx
CLEANFILES += test7-odb.hxx test7-odb.ixx test7-odb.cxx

test7-odb.hxx: test7.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix t_view_olv_ $<

driver_SOURCES += test8.hxx
nodist_driver_SOURCES += test8-odb.cxx
BUILT_SOURCES += test8-odb.hxx
CLEANFILES += test8-odb.hxx test8-odb.ixx test8-odb.cxx

test8-odb.hxx: test8.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix t_view_olv_ $<

driver_SOURCES += test9.hxx
nodist_driver_SOURCES += test9-odb.cxx
BUILT_SOURCES += test9-odb.hxx
CLEANFILES += test9-odb.hxx test9-odb.ixx test9-odb.cxx

test9-odb.hxx: test9.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --table-prefix t_view_olv_ $<


