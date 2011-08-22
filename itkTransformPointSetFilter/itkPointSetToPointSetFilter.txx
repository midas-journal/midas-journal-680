/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile: itkPointSetToPointSetFilter.txx,v $
  Language:  C++
  Date:      $Date: 2009-02-05 22:04:14 $
  Version:   $Revision: 1.20 $

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

  Portions of this code are covered under the VTK copyright.
  See VTKCopyright.txt or http://www.kitware.com/VTKCopyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkPointSetToPointSetFilter_txx
#define __itkPointSetToPointSetFilter_txx

#include "itkPointSetToPointSetFilter.h"


namespace itk
{
  
/**
 *
 */
template <class TInputPointSet, class TOutputPointSet>
PointSetToPointSetFilter<TInputPointSet,TOutputPointSet>
::PointSetToPointSetFilter()
{
  // Modify superclass default values, can be overridden by subclasses
  this->SetNumberOfRequiredInputs(1);

}


/**
 *
 */
template <class TInputPointSet, class TOutputPointSet>
void 
PointSetToPointSetFilter<TInputPointSet,TOutputPointSet>
::SetInput(TInputPointSet *input)
{
  this->ProcessObject::SetNthInput(0, input);
}


/**
 *
 */
template <class TInputPointSet, class TOutputPointSet>
typename PointSetToPointSetFilter<TInputPointSet,TOutputPointSet>::InputPointSetType *
PointSetToPointSetFilter<TInputPointSet,TOutputPointSet>
::GetInput()
{
  if (this->GetNumberOfInputs() < 1)
    {
    return 0;
    }
  
  return static_cast<TInputPointSet*>(this->ProcessObject::GetInput(0));
}

  
/**
 *
 */
template <class TInputPointSet, class TOutputPointSet>
typename PointSetToPointSetFilter<TInputPointSet,TOutputPointSet>::InputPointSetType *
PointSetToPointSetFilter<TInputPointSet,TOutputPointSet>
::GetInput(unsigned int idx)
{
  return static_cast<TInputPointSet*>(this->ProcessObject::GetInput(idx));
}


/**
 *
 */
template <class TInputPointSet, class TOutputPointSet>
const typename PointSetToPointSetFilter<TInputPointSet,TOutputPointSet>::InputPointSetType *
PointSetToPointSetFilter<TInputPointSet,TOutputPointSet>
::GetInput() const
{
  if (this->GetNumberOfInputs() < 1)
    {
    return 0;
    }
  
  return static_cast<TInputPointSet*>(this->ProcessObject::GetInput(0));
}

  
/**
 *
 */
template <class TInputPointSet, class TOutputPointSet>
const typename PointSetToPointSetFilter<TInputPointSet,TOutputPointSet>::InputPointSetType *
PointSetToPointSetFilter<TInputPointSet,TOutputPointSet>
::GetInput(unsigned int idx) const
{
  return static_cast<TInputPointSet*>(this->ProcessObject::GetInput(idx));
}


} // end namespace itk

#endif
