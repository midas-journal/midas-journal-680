/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile: itkTransformPointSetFilterTest.cxx,v $
  Language:  C++
  Date:      $Date: 2009-07-14 13:34:02 $
  Version:   $Revision: 1.10 $

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

//#include <itkTransformPointSetFilter.h>
#include "itkTransformPointSetFilter.h"
#include <itkPointSet.h>
#include <itkAffineTransform.h>

//int itkTransformPointSetFilterTest(int, char* [] )
int main(int, char* [] )  
{
  // Declare the pointset pixel type.
  typedef itk::PointSet<double, 3 > PointSetType;

  // Declare the type for PointsContainer
  typedef PointSetType::PointsContainer     PointsContainerType;

  // Declare the type for PointsContainerPointer
  typedef PointSetType::PointsContainerPointer     
                                        PointsContainerPointer;
  // Declare the type for Points
  typedef PointSetType::PointType PointType;

  // Create an input PointSet
  PointSetType::Pointer inputPointSet = PointSetType::New();

  // Insert data in the PointSet
  PointsContainerPointer  points = inputPointSet->GetPoints();

  //create three points and add them to the point set
  PointType p0;
  p0[0] = 0.0;
  p0[1] = 0.0;
  p0[2] = 0.0;
  points->InsertElement( 0, p0 );

  PointType p1;
  p1[0] = 1.0;
  p1[1] = 1.0;
  p1[2] = 1.0;
  points->InsertElement( 1, p1 );

  PointType p2;
  p2[0] = 1.0;
  p2[1] = 0.0;
  p2[2] = 0.0;
  points->InsertElement( 2, p2 );
  
  std::cout << "Input PointSet has " << inputPointSet->GetNumberOfPoints();
  std::cout << "   points " << std::endl;

  
  // Declare the transform type
  typedef itk::AffineTransform<float,3> TransformType;
  

  // Declare the type for the filter
  typedef itk::TransformPointSetFilter<
                                PointSetType,
                                PointSetType,
                                TransformType  >       FilterType;
            

  // Create a Filter                                
  FilterType::Pointer filter = FilterType::New();



  // Create an  Transform 
  // (it doesn't use smart pointers)
//create a simple translation transform so that we immediately know what
//the result should be
  TransformType::Pointer   affineTransform = TransformType::New();
//  affineTransform->Scale( 3.5 ); //this can be uncommented to test 
//a more complicated transform
  TransformType::OffsetType::ValueType tInit[3] = {100,200,300};
  TransformType::OffsetType   translation = tInit;
  affineTransform->Translate( translation );


  // Connect the inputs
  filter->SetInput( inputPointSet ); 
  filter->SetTransform( affineTransform ); 

  // Execute the filter
  filter->Update();
  std::cout << "Filter: " << filter;

  // Get the Smart Pointer to the Filter Output 
  PointSetType::Pointer outputPointSet = filter->GetOutput();

  std::cout << "Output PointSet has " << outputPointSet->GetNumberOfPoints();
  std::cout << "   points " << std::endl;

  // Get the the point container
  PointSetType::PointsContainerPointer  
                  transformedPoints = outputPointSet->GetPoints();


  PointsContainerType::ConstIterator it = transformedPoints->Begin();
  while( it != transformedPoints->End() )
    {
    PointType p = it.Value();
    std::cout.width( 5 ); std::cout << p[0] << ", ";
    std::cout.width( 5 ); std::cout << p[1] << ", ";
    std::cout.width( 5 ); std::cout << p[2] << std::endl;
    ++it;
    }

// We know the transformed points should be:
  PointType correct_tp0;
  correct_tp0[0] = 100.0;
  correct_tp0[1] = 200.0;
  correct_tp0[2] = 300.0;

  PointType correct_tp1;
  correct_tp1[0] = 101.0;
  correct_tp1[1] = 201.0;
  correct_tp1[2] = 301.0;

  PointType correct_tp2;
  correct_tp2[0] = 101.0;
  correct_tp2[1] = 200.0;
  correct_tp2[2] = 300.0;

// Get the transformed values
  it = transformedPoints->Begin();
  PointType tp0 = it.Value();
  ++it;
  PointType tp1 = it.Value();
  ++it;
  PointType tp2 = it.Value();

  if((tp0 == correct_tp0) && (tp1 == correct_tp1) && (tp2 == correct_tp2))
  {
    std::cout << "Pass!" << std::endl;
    return EXIT_SUCCESS;
    // All objects should be automatically destroyed at this point
  }
  else
  {
    std::cout << "Fail!" << std::endl;
    return EXIT_FAILURE;
  }


}
