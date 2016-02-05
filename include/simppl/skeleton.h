#ifndef SIMPPL_SKELETON_H
#define SIMPPL_SKELETON_H


#include <typeinfo>
#include <cxxabi.h>

#include "simppl/skeletonbase.h"
#include "simppl/dispatcher.h"
#include "simppl/serverside.h"


namespace simppl
{
   
namespace ipc
{

template<template<template<typename...> class, 
                  template<typename...> class,
                  template<typename...> class,
                  template<typename,typename> class> class IfaceT>
struct Skeleton : SkeletonBase, IfaceT<ServerRequest, ServerResponse, ServerSignal, ServerAttribute>
{
   friend struct Dispatcher;
   
   typedef IfaceT<ServerRequest, ServerResponse, ServerSignal, ServerAttribute> interface_type;
   
   inline
   Skeleton(const char* role)
    : SkeletonBase(abi::__cxa_demangle(typeid(interface_type).name(), 0, 0, 0), role)
   {
      // NOOP
   }
   
   
protected:
   
   ServerRequestDescriptor current_request_;
};

}   // namespace ipc

}   // namespace simppl


#endif   // SIMPPL_SKELETON_H
