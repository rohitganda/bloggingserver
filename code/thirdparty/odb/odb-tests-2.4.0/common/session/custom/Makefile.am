# file      : common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std session-custom-mysql-vc10.vcxproj session-custom-sqlite-vc10.vcxproj session-custom-pgsql-vc10.vcxproj session-custom-oracle-vc10.vcxproj session-custom-mssql-vc10.vcxproj session-custom-mysql-vc10.vcxproj.filters session-custom-sqlite-vc10.vcxproj.filters session-custom-pgsql-vc10.vcxproj.filters session-custom-oracle-vc10.vcxproj.filters session-custom-mssql-vc10.vcxproj.filters session-custom-mysql-vc11.vcxproj session-custom-sqlite-vc11.vcxproj session-custom-pgsql-vc11.vcxproj session-custom-oracle-vc11.vcxproj session-custom-mssql-vc11.vcxproj session-custom-mysql-vc11.vcxproj.filters session-custom-sqlite-vc11.vcxproj.filters session-custom-pgsql-vc11.vcxproj.filters session-custom-oracle-vc11.vcxproj.filters session-custom-mssql-vc11.vcxproj.filters session-custom-mysql-vc12.vcxproj session-custom-sqlite-vc12.vcxproj session-custom-pgsql-vc12.vcxproj session-custom-oracle-vc12.vcxproj session-custom-mssql-vc12.vcxproj session-custom-mysql-vc12.vcxproj.filters session-custom-sqlite-vc12.vcxproj.filters session-custom-pgsql-vc12.vcxproj.filters session-custom-oracle-vc12.vcxproj.filters session-custom-mssql-vc12.vcxproj.filters

noinst_PROGRAMS = driver
driver_SOURCES = driver.cxx session.cxx session.hxx session.txx
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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-session --session-type ::session --hxx-prologue '#include "session.hxx"' --table-prefix session_custom_ $<


