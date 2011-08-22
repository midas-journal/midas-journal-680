/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile: itkTransformPointSetFilter.h,v $
  Language:  C++
  Date:      $Date: 2009-7-14 13:11:15 $
  Version:   $Revision: 1.15 $

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkTransformPointSetFilter_h
#define __itkTransformPointSetFilter_h

#include "itkTransform.h"
#include "itkPointSetToPointSetFilter.h"

namespace itk
{

/** \class TransformPointSetFilter
 * \brief 
 *
 * TransformPointSetFilter applies a transform to all the points
 * of in a PointSet.
 * 
 * \ingroup PointSetFilters ???
 */
template <class TInputPointSet, class TOutputPointSet, class TTransform>
class ITK_EXPORT TransformPointSetFilter : public PointSetToPointSetFilter< TInputPointSet, TOutputPointSet >
{
public:
  /** Standard class typedefs. */
  typedef TransformPointSetFilter         Self;
  typedef PointSetToPointSetFilter<
    TInputPointSet,TOutputPointSet>       Superclass;
  typedef SmartPointer<Self>              Pointer;
  typedef SmartPointer<const Self>        ConstPointer;

  typedef TInputPointSet                       InputPointSetType;
  typedef TOutputPointSet                      OutputPointSetType;
  typedef typename InputPointSetType::Pointer  InputPointSetPointer;
  typedef typename OutputPointSetType::Pointer OutputPointSetPointer;
  
  /** Type for representing coordinates. */
  typedef typename TInputPointSet::CoordRepType  CoordRepType;

  /** Type of the transform. */
  typedef TTransform  TransformType;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Declaration of hierarchy */
  itkTypeMacro( TransformPointSetFilter, PointSetSource );

  /** Set transform. */
  itkSetObjectMacro(Transform, TransformType); 

  /** Set input. */
  void SetInput(InputPointSetType *input);

  /** Get transform. */
  itkGetObjectMacro(Transform,TransformType);


protected:
  TransformPointSetFilter();
  ~TransformPointSetFilter() {};
  void PrintSelf(std::ostream& os, Indent indent) const;
  
  /** Generate Requested Data */
  virtual void GenerateData( void );

  /** Transform to apply to all the pointset points. */
  typename TransformType::Pointer   m_Transform;

private:
  TransformPointSetFilter(const TransformPointSetFilter&); //purposely not implemented
  void operator=(const TransformPointSetFilter&); //purposely not implemented
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkTransformPointSetFilter.txx"
#endif

#endif
