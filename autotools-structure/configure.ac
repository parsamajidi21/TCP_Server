#
#  [2019] Signet Lab - Programming for ICT
#  All Rights Reserved.
#
#  Authors Filippo Campagnaro and Michele Polese 
#

AC_INIT(PFICT,1.0)
AM_INIT_AUTOMAKE 
AC_LANG(C++)
AC_PROG_CXX
AM_PROG_AR
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL
LT_INIT
AC_CONFIG_MACRO_DIR([m4])
AC_DISABLE_STATIC
AC_LIBTOOL_WIN32_DLL





#######################################################################

AC_DEFINE(CPP_NAMESPACE,std) 

AC_CHECK_LIB(pthread, pthread_create, [LIBS="$LIBS -lpthread"]) 

AC_ARG_WITH([test],
  AC_HELP_STRING([--with-test=VAL],
    [Test library enable]),
  [with_test="$withval"],
  [with_test=""])

PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/basic_utilities'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/second_exam'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/types_declarations_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/pointers_arrays_references_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/structs_enums_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/headers_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/statements_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/functions_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/namespaces_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/classes_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/socket_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/smartpointers_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/constructors_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/subclassing_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/person_class_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/memory_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/operator_overloading_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/rtti_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/templates_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/stdlib_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/threads_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/examples/threads_sync_example'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/test/basic_utilities'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'-I$(top_srcdir)/test/second_exam_test'
PFICT_CPPFLAGS="$PFICT_CPPFLAGS "'$(GCC6_FLAG)'

PFICT_CXXFLAGS="$PFICT_CXXFLAGS "'-Wall'
PFICT_CXXFLAGS="$PFICT_CXXFLAGS "'-ggdb3'
PFICT_CXXFLAGS="$PFICT_CXXFLAGS "'-std=c++11'

PFICT_LDFLAGS="$PFICT_LDFLAGS "'-L$(top_srcdir)/basic_utilities'
PFICT_LDFLAGS="$PFICT_LDFLAGS "'-L$(top_srcdir)/second_exam'

PFICT_LIBADD="$PFICT_LIBADD"

BUTILS_LDADD="$BUTILS_LDADD "'-lbasic_utilities'
SECOND_EXAM_LDADD="$SECOND_EXAM_LDADD "'-lsecond_exam'

PFICT_LDADD="$PFICT_LDADD $BUTILS_LDADD $SECOND_EXAM_LDADD"

AM_CONDITIONAL(WITH_TEST, test "x${with_test}" != "x")

if test "x${with_test}" != "x"; then  
  AC_ARG_WITH_TEST
fi

AC_SUBST(PFICT_CPPFLAGS) 
AC_SUBST(PFICT_CXXFLAGS)
AC_SUBST(PFICT_LDFLAGS)
AC_SUBST(PFICT_LIBADD)
AC_SUBST(PFICT_LDADD)
AC_SUBST(BUTILS_LDADD)
AC_SUBST(SECOND_EXAM_LDADD)
AC_SUBST(top_srcdir)
AC_SUBST(with_test)

AC_CONFIG_FILES([
  Makefile
  m4/Makefile
  basic_utilities/Makefile
  second_exam/Makefile
  test/basic_utilities_test/Makefile
  test/second_exam_test/Makefile
  ])

AC_OUTPUT
