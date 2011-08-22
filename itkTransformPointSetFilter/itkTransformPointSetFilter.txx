/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile: itkTransformPointSetFilter.txx,v $
  Language:  C++
  Date:      $Date: 2009-7-14 13:11:15 $
  Version:   $Revision: 1.23 $

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkTransformPointSetFilter_txx
#define __itkTransformPointSetFilter_txx

#include "itkTransformPointSetFilter.h"
#include "itkExceptionObject.h"

namespace itk
{
  
/**
 *
 */
template <class TInputPointSet, class TOutputPointSet, class TTransform>
TransformPointSetFilter<TInputPointSet,TOutputPointSet,TTransform>
::TransformPointSetFilter()
{
  m_Transform = TransformType::New();
}

/**
 *
 */
template <class TInputPointSet, class TOutputPointSet, class TTransform>
void 
TransformPointSetFilter<TInputPointSet, TOutputPointSet, TTransform>
::SetInput(TInputPointSet *input)
{
  this->ProcessObject::SetNthInput(0, input);
}

/**
 *
 */
template <class TInputPointSet, class TOutputPointSet, class TTransform>
void 
TransformPointSetFilter<TInputPointSet,TOutputPointSet,TTransform>
::PrintSelf(std::ostream& os, Indent indent) const
{
//  Superclass::PrintSelf(os,indent);
  if (m_Transform)
    {
    os << indent << "Transform: " << m_Transform << std::endl;
    }
}


/**
 * This method causes the filter to generate its output.
 */
template <class TInputPointSet, class TOutputPointSet, class TTransform>
void 
TransformPointSetFilter<TInputPointSet,TOutputPointSet,TTransform>
::GenerateData(void) 
{
  
  typedef typename TInputPointSet::PointsContainer  InputPointsContainer;
  typedef typename TOutputPointSet::PointsContainer OutputPointsContainer;

  typedef typename TInputPointSet::PointsContainerPointer  InputPointsContainerPointer;
  typedef typename TOutputPointSet::PointsContainerPointer OutputPointsContainerPointer;

  InputPointSetPointer    inputPointSet      =  this->GetInput();
  OutputPointSetPointer   outputPointSet     =  this->GetOutput();
  
  if( !inputPointSet )
    {
    itkExceptionMacro(<<"Missing Input PointSet");
    }

  if( !outputPointSet )
    {
    itkExceptionMacro(<<"Missing Output PointSet");
    }

  outputPointSet->SetBufferedRegion( outputPointSet->GetRequestedRegion() );

  InputPointsContainerPointer  inPoints  = inputPointSet->GetPoints();
  OutputPointsContainerPointer outPoints = outputPointSet->GetPoints();

  outPoints->Reserve( inputPointSet->GetNumberOfPoints() );
  outPoints->Squeeze();  // in case the previous pointset had 
                         // allocated a larger memory

  typename InputPointsContainer::ConstIterator  inputPoint  = inPoints->Begin();
  typename OutputPointsContainer::Iterator      outputPoint = outPoints->Begin();

  while( inputPoint != inPoints->End() ) 
    {
    outputPoint.Value() = 
      m_Transform->TransformPoint( inputPoint.Value() );

    ++inputPoint;
    ++outputPoint;
    }


  // Create duplicate references to the rest of data on the pointset
  outputPointSet->SetPointData(  inputPointSet->GetPointData() );
}

} // end namespace itk

#endif
