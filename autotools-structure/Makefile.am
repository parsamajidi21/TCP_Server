#
#  [2019] Signet Lab - Programming for ICT
#  All Rights Reserved.
#
#  Authors Filippo Campagnaro and Michele Polese 
#

AUTOMAKE_OPTIONS = foreign

SUBDIRS = m4 \
    basic_utilities \
    second_exam 

if WITH_TEST 
  SUBDIRS +=  \
    test/basic_utilities_test \
    test/second_exam_test 
  TESTS = \
    test/basic_utilities_test/basic_utilities_test \
    test/second_exam_test/second_exam_test 
endif

ACLOCAL_AMFLAGS = -I m4
