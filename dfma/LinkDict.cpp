// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME LinkDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "tree.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *dssd_Dictionary();
   static void dssd_TClassManip(TClass*);
   static void *new_dssd(void *p = 0);
   static void *newArray_dssd(Long_t size, void *p);
   static void delete_dssd(void *p);
   static void deleteArray_dssd(void *p);
   static void destruct_dssd(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::dssd*)
   {
      ::dssd *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::dssd));
      static ::ROOT::TGenericClassInfo 
         instance("dssd", "tree.h", 10,
                  typeid(::dssd), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &dssd_Dictionary, isa_proxy, 4,
                  sizeof(::dssd) );
      instance.SetNew(&new_dssd);
      instance.SetNewArray(&newArray_dssd);
      instance.SetDelete(&delete_dssd);
      instance.SetDeleteArray(&deleteArray_dssd);
      instance.SetDestructor(&destruct_dssd);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::dssd*)
   {
      return GenerateInitInstanceLocal((::dssd*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::dssd*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *dssd_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::dssd*)0x0)->GetClass();
      dssd_TClassManip(theClass);
   return theClass;
   }

   static void dssd_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DFMAEVENT_Dictionary();
   static void DFMAEVENT_TClassManip(TClass*);
   static void *new_DFMAEVENT(void *p = 0);
   static void *newArray_DFMAEVENT(Long_t size, void *p);
   static void delete_DFMAEVENT(void *p);
   static void deleteArray_DFMAEVENT(void *p);
   static void destruct_DFMAEVENT(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DFMAEVENT*)
   {
      ::DFMAEVENT *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DFMAEVENT));
      static ::ROOT::TGenericClassInfo 
         instance("DFMAEVENT", "tree.h", 17,
                  typeid(::DFMAEVENT), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DFMAEVENT_Dictionary, isa_proxy, 4,
                  sizeof(::DFMAEVENT) );
      instance.SetNew(&new_DFMAEVENT);
      instance.SetNewArray(&newArray_DFMAEVENT);
      instance.SetDelete(&delete_DFMAEVENT);
      instance.SetDeleteArray(&deleteArray_DFMAEVENT);
      instance.SetDestructor(&destruct_DFMAEVENT);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DFMAEVENT*)
   {
      return GenerateInitInstanceLocal((::DFMAEVENT*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DFMAEVENT*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DFMAEVENT_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DFMAEVENT*)0x0)->GetClass();
      DFMAEVENT_TClassManip(theClass);
   return theClass;
   }

   static void DFMAEVENT_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DGSEVENT_Dictionary();
   static void DGSEVENT_TClassManip(TClass*);
   static void *new_DGSEVENT(void *p = 0);
   static void *newArray_DGSEVENT(Long_t size, void *p);
   static void delete_DGSEVENT(void *p);
   static void deleteArray_DGSEVENT(void *p);
   static void destruct_DGSEVENT(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DGSEVENT*)
   {
      ::DGSEVENT *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DGSEVENT));
      static ::ROOT::TGenericClassInfo 
         instance("DGSEVENT", "tree.h", 34,
                  typeid(::DGSEVENT), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DGSEVENT_Dictionary, isa_proxy, 4,
                  sizeof(::DGSEVENT) );
      instance.SetNew(&new_DGSEVENT);
      instance.SetNewArray(&newArray_DGSEVENT);
      instance.SetDelete(&delete_DGSEVENT);
      instance.SetDeleteArray(&deleteArray_DGSEVENT);
      instance.SetDestructor(&destruct_DGSEVENT);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DGSEVENT*)
   {
      return GenerateInitInstanceLocal((::DGSEVENT*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DGSEVENT*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DGSEVENT_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DGSEVENT*)0x0)->GetClass();
      DGSEVENT_TClassManip(theClass);
   return theClass;
   }

   static void DGSEVENT_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_dssd(void *p) {
      return  p ? new(p) ::dssd : new ::dssd;
   }
   static void *newArray_dssd(Long_t nElements, void *p) {
      return p ? new(p) ::dssd[nElements] : new ::dssd[nElements];
   }
   // Wrapper around operator delete
   static void delete_dssd(void *p) {
      delete ((::dssd*)p);
   }
   static void deleteArray_dssd(void *p) {
      delete [] ((::dssd*)p);
   }
   static void destruct_dssd(void *p) {
      typedef ::dssd current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::dssd

namespace ROOT {
   // Wrappers around operator new
   static void *new_DFMAEVENT(void *p) {
      return  p ? new(p) ::DFMAEVENT : new ::DFMAEVENT;
   }
   static void *newArray_DFMAEVENT(Long_t nElements, void *p) {
      return p ? new(p) ::DFMAEVENT[nElements] : new ::DFMAEVENT[nElements];
   }
   // Wrapper around operator delete
   static void delete_DFMAEVENT(void *p) {
      delete ((::DFMAEVENT*)p);
   }
   static void deleteArray_DFMAEVENT(void *p) {
      delete [] ((::DFMAEVENT*)p);
   }
   static void destruct_DFMAEVENT(void *p) {
      typedef ::DFMAEVENT current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DFMAEVENT

namespace ROOT {
   // Wrappers around operator new
   static void *new_DGSEVENT(void *p) {
      return  p ? new(p) ::DGSEVENT : new ::DGSEVENT;
   }
   static void *newArray_DGSEVENT(Long_t nElements, void *p) {
      return p ? new(p) ::DGSEVENT[nElements] : new ::DGSEVENT[nElements];
   }
   // Wrapper around operator delete
   static void delete_DGSEVENT(void *p) {
      delete ((::DGSEVENT*)p);
   }
   static void deleteArray_DGSEVENT(void *p) {
      delete [] ((::DGSEVENT*)p);
   }
   static void destruct_DGSEVENT(void *p) {
      typedef ::DGSEVENT current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DGSEVENT

namespace ROOT {
   static TClass *vectorlEdssdgR_Dictionary();
   static void vectorlEdssdgR_TClassManip(TClass*);
   static void *new_vectorlEdssdgR(void *p = 0);
   static void *newArray_vectorlEdssdgR(Long_t size, void *p);
   static void delete_vectorlEdssdgR(void *p);
   static void deleteArray_vectorlEdssdgR(void *p);
   static void destruct_vectorlEdssdgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<dssd>*)
   {
      vector<dssd> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<dssd>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<dssd>", -2, "vector", 214,
                  typeid(vector<dssd>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdssdgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<dssd>) );
      instance.SetNew(&new_vectorlEdssdgR);
      instance.SetNewArray(&newArray_vectorlEdssdgR);
      instance.SetDelete(&delete_vectorlEdssdgR);
      instance.SetDeleteArray(&deleteArray_vectorlEdssdgR);
      instance.SetDestructor(&destruct_vectorlEdssdgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<dssd> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<dssd>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdssdgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<dssd>*)0x0)->GetClass();
      vectorlEdssdgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdssdgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdssdgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<dssd> : new vector<dssd>;
   }
   static void *newArray_vectorlEdssdgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<dssd>[nElements] : new vector<dssd>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdssdgR(void *p) {
      delete ((vector<dssd>*)p);
   }
   static void deleteArray_vectorlEdssdgR(void *p) {
      delete [] ((vector<dssd>*)p);
   }
   static void destruct_vectorlEdssdgR(void *p) {
      typedef vector<dssd> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<dssd>

namespace ROOT {
   static TClass *vectorlEDGSEVENTgR_Dictionary();
   static void vectorlEDGSEVENTgR_TClassManip(TClass*);
   static void *new_vectorlEDGSEVENTgR(void *p = 0);
   static void *newArray_vectorlEDGSEVENTgR(Long_t size, void *p);
   static void delete_vectorlEDGSEVENTgR(void *p);
   static void deleteArray_vectorlEDGSEVENTgR(void *p);
   static void destruct_vectorlEDGSEVENTgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<DGSEVENT>*)
   {
      vector<DGSEVENT> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<DGSEVENT>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<DGSEVENT>", -2, "vector", 214,
                  typeid(vector<DGSEVENT>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEDGSEVENTgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<DGSEVENT>) );
      instance.SetNew(&new_vectorlEDGSEVENTgR);
      instance.SetNewArray(&newArray_vectorlEDGSEVENTgR);
      instance.SetDelete(&delete_vectorlEDGSEVENTgR);
      instance.SetDeleteArray(&deleteArray_vectorlEDGSEVENTgR);
      instance.SetDestructor(&destruct_vectorlEDGSEVENTgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<DGSEVENT> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<DGSEVENT>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEDGSEVENTgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<DGSEVENT>*)0x0)->GetClass();
      vectorlEDGSEVENTgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEDGSEVENTgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEDGSEVENTgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<DGSEVENT> : new vector<DGSEVENT>;
   }
   static void *newArray_vectorlEDGSEVENTgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<DGSEVENT>[nElements] : new vector<DGSEVENT>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEDGSEVENTgR(void *p) {
      delete ((vector<DGSEVENT>*)p);
   }
   static void deleteArray_vectorlEDGSEVENTgR(void *p) {
      delete [] ((vector<DGSEVENT>*)p);
   }
   static void destruct_vectorlEDGSEVENTgR(void *p) {
      typedef vector<DGSEVENT> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<DGSEVENT>

namespace ROOT {
   static TClass *vectorlEDFMAEVENTgR_Dictionary();
   static void vectorlEDFMAEVENTgR_TClassManip(TClass*);
   static void *new_vectorlEDFMAEVENTgR(void *p = 0);
   static void *newArray_vectorlEDFMAEVENTgR(Long_t size, void *p);
   static void delete_vectorlEDFMAEVENTgR(void *p);
   static void deleteArray_vectorlEDFMAEVENTgR(void *p);
   static void destruct_vectorlEDFMAEVENTgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<DFMAEVENT>*)
   {
      vector<DFMAEVENT> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<DFMAEVENT>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<DFMAEVENT>", -2, "vector", 214,
                  typeid(vector<DFMAEVENT>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEDFMAEVENTgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<DFMAEVENT>) );
      instance.SetNew(&new_vectorlEDFMAEVENTgR);
      instance.SetNewArray(&newArray_vectorlEDFMAEVENTgR);
      instance.SetDelete(&delete_vectorlEDFMAEVENTgR);
      instance.SetDeleteArray(&deleteArray_vectorlEDFMAEVENTgR);
      instance.SetDestructor(&destruct_vectorlEDFMAEVENTgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<DFMAEVENT> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<DFMAEVENT>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEDFMAEVENTgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<DFMAEVENT>*)0x0)->GetClass();
      vectorlEDFMAEVENTgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEDFMAEVENTgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEDFMAEVENTgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<DFMAEVENT> : new vector<DFMAEVENT>;
   }
   static void *newArray_vectorlEDFMAEVENTgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<DFMAEVENT>[nElements] : new vector<DFMAEVENT>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEDFMAEVENTgR(void *p) {
      delete ((vector<DFMAEVENT>*)p);
   }
   static void deleteArray_vectorlEDFMAEVENTgR(void *p) {
      delete [] ((vector<DFMAEVENT>*)p);
   }
   static void destruct_vectorlEDFMAEVENTgR(void *p) {
      typedef vector<DFMAEVENT> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<DFMAEVENT>

namespace {
  void TriggerDictionaryInitialization_LinkDict_Impl() {
    static const char* headers[] = {
"tree.h",
0
    };
    static const char* includePaths[] = {
"/opt/ROOT/root61600/include",
"/home/zhli/agafa/gsort/dssd/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "LinkDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
struct __attribute__((annotate("$clingAutoload$tree.h")))  DFMAEVENT;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
struct __attribute__((annotate("$clingAutoload$tree.h")))  DGSEVENT;
struct __attribute__((annotate("$clingAutoload$tree.h")))  dssd;
typedef struct dssd dssd __attribute__((annotate("$clingAutoload$tree.h"))) ;
typedef struct DFMAEVENT DFMAEVENT __attribute__((annotate("$clingAutoload$tree.h"))) ;
typedef struct DGSEVENT DGSEVENT __attribute__((annotate("$clingAutoload$tree.h"))) ;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "LinkDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "tree.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"DFMAEVENT", payloadCode, "@",
"DGSEVENT", payloadCode, "@",
"dssd", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("LinkDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_LinkDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_LinkDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_LinkDict() {
  TriggerDictionaryInitialization_LinkDict_Impl();
}
