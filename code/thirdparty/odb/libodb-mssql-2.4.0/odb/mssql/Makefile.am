# file      : odb/mssql/Makefile.am
# copyright : Copyright (c) 2009-2015 Code Synthesis Tools CC
# license   : ODB NCUEL; see accompanying LICENSE file

lib_LTLIBRARIES = libodb-mssql.la
libodb_mssql_la_SOURCES = auto-handle.cxx connection.cxx connection-factory.cxx database.cxx error.cxx exceptions.cxx prepared-query.cxx query.cxx query-dynamic.cxx query-const-expr.cxx simple-object-statements.cxx statement.cxx statement-processing.cxx statements-base.cxx tracer.cxx traits.cxx transaction.cxx transaction-impl.cxx details/options.cxx

odbmssqlincludedir = $(includedir)/odb/mssql/
nobase_odbmssqlinclude_HEADERS = auto-handle.hxx binding.hxx connection-factory.hxx connection.hxx connection.ixx container-statements.hxx container-statements.txx database.hxx database.ixx details/config.hxx details/conversion.hxx details/export.hxx details/options.hxx details/options.ixx error.hxx exceptions.hxx forward.hxx mssql-fwd.hxx mssql-types.hxx mssql.hxx no-id-object-result.hxx no-id-object-result.txx no-id-object-statements.hxx no-id-object-statements.txx polymorphic-object-result.hxx polymorphic-object-result.txx polymorphic-object-statements.hxx polymorphic-object-statements.txx prepared-query.hxx query-dynamic.hxx query-dynamic.ixx query-dynamic.txx query.hxx query.ixx query.txx section-statements.hxx section-statements.txx simple-object-result.hxx simple-object-result.txx simple-object-statements.hxx simple-object-statements.ixx simple-object-statements.txx statement-cache.hxx statement-cache.txx statement.hxx statement.ixx statements-base.hxx tracer.hxx traits-calls.hxx traits.hxx traits.txx transaction-impl.hxx transaction-impl.ixx transaction.hxx transaction.ixx version.hxx view-result.hxx view-result.txx view-statements.hxx view-statements.txx
nobase_nodist_odbmssqlinclude_HEADERS = details/config.h

EXTRA_DIST = details/options.cli details/config.h.in libodb-mssql-vc8.vcproj libodb-mssql-vc9.vcproj libodb-mssql-vc10.vcxproj libodb-mssql-vc10.vcxproj.filters libodb-mssql-vc11.vcxproj libodb-mssql-vc11.vcxproj.filters libodb-mssql-vc12.vcxproj libodb-mssql-vc12.vcxproj.filters

AM_CPPFLAGS= -I'$(top_builddir)' -I'$(top_srcdir)' -DLIBODB_MSSQL_DYNAMIC_LIB
AM_LDFLAGS = -release 2.4 -no-undefined
