INCLUDE(${CMAKE_SOURCE_DIR}/IJMacros.txt)

#Change PROJECT_NAME to the name of your project
PROJECT(itkTransformPointSetFilterTest)

#The following lines are required to use Dart
ENABLE_TESTING()
INCLUDE(Dart)

#Declare any external dependencies that your project may have here.
#examples include: ITK, VTK, JPEG, PNG, OpenGL, ZLIB, Perl, Java
#If you're not sure what name to use, look in the Modules directory of your
#cmake install and check that a file named Find(Package).cmake exists
#
# The packages can be specified with a version number, for example:
#
# ITK 2.8.1
# ITK 3.2.0
#
# If no version is specified, the most recent release of the package
# will be used.
SET(Required_Packages
ITK
)

#this foreach loads all of the packages that you specified as required.
#It shouldn't need to be modified.
FOREACH(Package ${Required_Packages})
  LOADPACKAGE(${Package})
ENDFOREACH(Package)

SET(Libraries
ITKCommon
ITKIO
)

ADD_EXECUTABLE(itkTransformPointSetFilterTest itkTransformPointSetFilterTest.cxx) 
TARGET_LINK_LIBRARIES(itkTransformPointSetFilterTest ${Libraries})

ADD_TEST(itkTransformPointSetFilterTest itkTransformPointSetFilterTest)

