# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std inheritance-polymorphism-mysql-vc8.vcproj inheritance-polymorphism-sqlite-vc8.vcproj inheritance-polymorphism-pgsql-vc8.vcproj inheritance-polymorphism-oracle-vc8.vcproj inheritance-polymorphism-mssql-vc8.vcproj inheritance-polymorphism-mysql-vc9.vcproj inheritance-polymorphism-sqlite-vc9.vcproj inheritance-polymorphism-pgsql-vc9.vcproj inheritance-polymorphism-oracle-vc9.vcproj inheritance-polymorphism-mssql-vc9.vcproj inheritance-polymorphism-mysql-vc10.vcxproj inheritance-polymorphism-sqlite-vc10.vcxproj inheritance-polymorphism-pgsql-vc10.vcxproj inheritance-polymorphism-oracle-vc10.vcxproj inheritance-polymorphism-mssql-vc10.vcxproj inheritance-polymorphism-mysql-vc10.vcxproj.filters inheritance-polymorphism-sqlite-vc10.vcxproj.filters inheritance-polymorphism-pgsql-vc10.vcxproj.filters inheritance-polymorphism-oracle-vc10.vcxproj.filters inheritance-polymorphism-mssql-vc10.vcxproj.filters inheritance-polymorphism-mysql-vc11.vcxproj inheritance-polymorphism-sqlite-vc11.vcxproj inheritance-polymorphism-pgsql-vc11.vcxproj inheritance-polymorphism-oracle-vc11.vcxproj inheritance-polymorphism-mssql-vc11.vcxproj inheritance-polymorphism-mysql-vc11.vcxproj.filters inheritance-polymorphism-sqlite-vc11.vcxproj.filters inheritance-polymorphism-pgsql-vc11.vcxproj.filters inheritance-polymorphism-oracle-vc11.vcxproj.filters inheritance-polymorphism-mssql-vc11.vcxproj.filters inheritance-polymorphism-mysql-vc12.vcxproj inheritance-polymorphism-sqlite-vc12.vcxproj inheritance-polymorphism-pgsql-vc12.vcxproj inheritance-polymorphism-oracle-vc12.vcxproj inheritance-polymorphism-mssql-vc12.vcxproj inheritance-polymorphism-mysql-vc12.vcxproj.filters inheritance-polymorphism-sqlite-vc12.vcxproj.filters inheritance-polymorphism-pgsql-vc12.vcxproj.filters inheritance-polymorphism-oracle-vc12.vcxproj.filters inheritance-polymorphism-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<

driver_SOURCES += test2.hxx
nodist_driver_SOURCES += test2-odb.cxx
BUILT_SOURCES += test2-odb.hxx
CLEANFILES += test2-odb.hxx test2-odb.ixx test2-odb.cxx

test2-odb.hxx: test2.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<

driver_SOURCES += test3.hxx
nodist_driver_SOURCES += test3-odb.cxx
BUILT_SOURCES += test3-odb.hxx
CLEANFILES += test3-odb.hxx test3-odb.ixx test3-odb.cxx

test3-odb.hxx: test3.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<

driver_SOURCES += test4.hxx
nodist_driver_SOURCES += test4-odb.cxx
BUILT_SOURCES += test4-odb.hxx
CLEANFILES += test4-odb.hxx test4-odb.ixx test4-odb.cxx

test4-odb.hxx: test4.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<

driver_SOURCES += test5.hxx
nodist_driver_SOURCES += test5-odb.cxx
BUILT_SOURCES += test5-odb.hxx
CLEANFILES += test5-odb.hxx test5-odb.ixx test5-odb.cxx

test5-odb.hxx: test5.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<

driver_SOURCES += test6.hxx
nodist_driver_SOURCES += test6-odb.cxx
BUILT_SOURCES += test6-odb.hxx
CLEANFILES += test6-odb.hxx test6-odb.ixx test6-odb.cxx

test6-odb.hxx: test6.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<

driver_SOURCES += test7.hxx
nodist_driver_SOURCES += test7-odb.cxx
BUILT_SOURCES += test7-odb.hxx
CLEANFILES += test7-odb.hxx test7-odb.ixx test7-odb.cxx

test7-odb.hxx: test7.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<

driver_SOURCES += test8.hxx
nodist_driver_SOURCES += test8-odb.cxx
BUILT_SOURCES += test8-odb.hxx
CLEANFILES += test8-odb.hxx test8-odb.ixx test8-odb.cxx

test8-odb.hxx: test8.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<

driver_SOURCES += test9.hxx
nodist_driver_SOURCES += test9-odb.cxx
BUILT_SOURCES += test9-odb.hxx
CLEANFILES += test9-odb.hxx test9-odb.ixx test9-odb.cxx

test9-odb.hxx: test9.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<

driver_SOURCES += test10.hxx
nodist_driver_SOURCES += test10-odb.cxx
BUILT_SOURCES += test10-odb.hxx
CLEANFILES += test10-odb.hxx test10-odb.ixx test10-odb.cxx

test10-odb.hxx: test10.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<

driver_SOURCES += test11.hxx
nodist_driver_SOURCES += test11-odb.cxx
BUILT_SOURCES += test11-odb.hxx
CLEANFILES += test11-odb.hxx test11-odb.ixx test11-odb.cxx

test11-odb.hxx: test11.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<

driver_SOURCES += test12.hxx
nodist_driver_SOURCES += test12-odb.cxx
BUILT_SOURCES += test12-odb.hxx
CLEANFILES += test12-odb.hxx test12-odb.ixx test12-odb.cxx

test12-odb.hxx: test12.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<

driver_SOURCES += test13.hxx
nodist_driver_SOURCES += test13-odb.cxx
BUILT_SOURCES += test13-odb.hxx
CLEANFILES += test13-odb.hxx test13-odb.ixx test13-odb.cxx

test13-odb.hxx: test13.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<

driver_SOURCES += test14.hxx
nodist_driver_SOURCES += test14-odb.cxx
BUILT_SOURCES += test14-odb.hxx
CLEANFILES += test14-odb.hxx test14-odb.ixx test14-odb.cxx

test14-odb.hxx: test14.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<

driver_SOURCES += test15.hxx
nodist_driver_SOURCES += test15-odb.cxx
BUILT_SOURCES += test15-odb.hxx
CLEANFILES += test15-odb.hxx test15-odb.ixx test15-odb.cxx

test15-odb.hxx: test15.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-query --generate-prepared --table-prefix inhrt_p_ $<


