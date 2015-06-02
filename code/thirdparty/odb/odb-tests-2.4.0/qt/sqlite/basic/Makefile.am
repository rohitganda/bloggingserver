# file      : qt/sqlite/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std basic-qt4-vc8.vcproj basic-qt4-vc9.vcproj basic-qt5-vc9.vcproj basic-qt4-vc10.vcxproj basic-qt4-vc10.vcxproj.filters basic-qt5-vc10.vcxproj basic-qt5-vc10.vcxproj.filters basic-qt4-vc11.vcxproj basic-qt4-vc11.vcxproj.filters basic-qt5-vc11.vcxproj basic-qt5-vc11.vcxproj.filters basic-qt4-vc12.vcxproj basic-qt4-vc12.vcxproj.filters basic-qt5-vc12.vcxproj basic-qt5-vc12.vcxproj.filters

noinst_PROGRAMS = driver
driver_SOURCES = driver.cxx  
LDADD = $(top_builddir)/libcommon/common/libcommon.la
AM_CPPFLAGS = -I'$(top_builddir)/libcommon' -I'$(top_srcdir)/libcommon'
AM_CPPFLAGS += -I'$(builddir)' -I'$(srcdir)'

TESTS=$(top_builddir)/tester
TESTS_ENVIRONMENT=top_builddir=$(top_builddir); export top_builddir;

# ODB compilation.
#
driver_SOURCES += test.hxx
nodist_driver_SOURCES = test-odb.cxx
BUILT_SOURCES = test-odb.hxx
CLEANFILES = test-odb.hxx test-odb.ixx test-odb.cxx

ODB = @ODB@
ODBFLAGS = @ODBFLAGS@
ODBCPPFLAGS = @ODBCPPFLAGS@

if HAVE_CXX11
ODBFLAGS += --std c++11
endif

test-odb.hxx: test.hxx
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database sqlite --profile qt/basic --generate-schema --table-prefix qt_sqlite_basic_ $<

