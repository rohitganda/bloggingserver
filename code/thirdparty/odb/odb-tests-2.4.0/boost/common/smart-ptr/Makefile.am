# file      : boost/common/template/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : GNU GPL v2; see accompanying LICENSE file

EXTRA_DIST = test.std smart-ptr-mysql-vc8.vcproj smart-ptr-sqlite-vc8.vcproj smart-ptr-pgsql-vc8.vcproj smart-ptr-oracle-vc8.vcproj smart-ptr-mssql-vc8.vcproj smart-ptr-mysql-vc9.vcproj smart-ptr-sqlite-vc9.vcproj smart-ptr-pgsql-vc9.vcproj smart-ptr-oracle-vc9.vcproj smart-ptr-mssql-vc9.vcproj smart-ptr-mysql-vc10.vcxproj smart-ptr-sqlite-vc10.vcxproj smart-ptr-pgsql-vc10.vcxproj smart-ptr-oracle-vc10.vcxproj smart-ptr-mssql-vc10.vcxproj smart-ptr-mysql-vc10.vcxproj.filters smart-ptr-sqlite-vc10.vcxproj.filters smart-ptr-pgsql-vc10.vcxproj.filters smart-ptr-oracle-vc10.vcxproj.filters smart-ptr-mssql-vc10.vcxproj.filters smart-ptr-mysql-vc11.vcxproj smart-ptr-sqlite-vc11.vcxproj smart-ptr-pgsql-vc11.vcxproj smart-ptr-oracle-vc11.vcxproj smart-ptr-mssql-vc11.vcxproj smart-ptr-mysql-vc11.vcxproj.filters smart-ptr-sqlite-vc11.vcxproj.filters smart-ptr-pgsql-vc11.vcxproj.filters smart-ptr-oracle-vc11.vcxproj.filters smart-ptr-mssql-vc11.vcxproj.filters smart-ptr-mysql-vc12.vcxproj smart-ptr-sqlite-vc12.vcxproj smart-ptr-pgsql-vc12.vcxproj smart-ptr-oracle-vc12.vcxproj smart-ptr-mssql-vc12.vcxproj smart-ptr-mysql-vc12.vcxproj.filters smart-ptr-sqlite-vc12.vcxproj.filters smart-ptr-pgsql-vc12.vcxproj.filters smart-ptr-oracle-vc12.vcxproj.filters smart-ptr-mssql-vc12.vcxproj.filters

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
	$(ODB) $(AM_CPPFLAGS) $(ODBCPPFLAGS) $(CPPFLAGS) $(ODBFLAGS) --database @database@ --generate-schema --generate-session --profile boost/smart-ptr --table-prefix boost_smart_ptr_ $<
