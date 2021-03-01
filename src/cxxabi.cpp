#include <cxxabi.h>
#include <cstdint>
#include <cstdio> // DEBUGGING
#include <cstdlib>

extern "C" void __cxa_begin_catch() {
    printf("__cxa_begin_catch is a stub\n");
}

extern "C" int __cxa_guard_acquire(int64_t *guard_object) {
   return reinterpret_cast<int8_t*>(guard_object)[0] != 0;
}

extern "C" void __cxa_pure_virtual() { while(1); }

extern "C" void __cxa_throw_bad_array_new_length() {
    fprintf(stderr, "Bad array new length\n");
    exit(1);
}

void *__gxx_personality_v0 = NULL;

extern "C" void *__dynamic_cast(const void *sub, const __cxxabiv1::__class_type_info *src, const __cxxabiv1::__class_type_info *dst, ptrdiff_t src2dst_offset) {
    if(src2dst_offset < 0) printf("__dynamic_cast hint usage is a stub\n");
    return reinterpret_cast<void*>(((uintptr_t) sub) + src2dst_offset); // I'll figure this out. Later.
}

namespace std {

void __throw_bad_alloc() {
    fprintf(stderr, "Bad alloc\n");
    exit(1);
}

void __throw_bad_cast() {
    fprintf(stderr, "Bad cast\n");
    exit(1);
}

void __throw_logic_error(const char*) {
    fprintf(stderr, "Logic error\n");
    exit(1);
}

void __throw_system_error(int) {
    fprintf(stderr, "System error\n");
    exit(1);
}

void __throw_out_of_range_fmt(const char*, ...) {
    fprintf(stderr, "Out of range format\n");
    exit(1);
}

type_info::~type_info() {
}

bool type_info::__do_catch(const type_info *__thr_type, void **__thr_obj, unsigned __outer) const {
    printf("type_info::__do_catch(const type_info*, void**, unsigned) is a stub\n");
    return false; // Let's hope we never need this :)
}

bool type_info::__do_upcast(const __cxxabiv1::__class_type_info *__dst_type, void **__obj_ptr) const {
    printf("type_info::__do_upcast(const __class_type_info*, void**) is a stub\n");
    return false; // I'll figure out how this is supposed to work later
}

bool type_info::__is_function_p() const {
    return false;
}

bool type_info::__is_pointer_p() const {
    return false;
}

} // namespace std

namespace __cxxabiv1 {

__class_type_info::~__class_type_info() {}

bool __class_type_info::__do_catch(const type_info *__thr_type, void **__thr_obj, unsigned __outer) const {
    printf("__class_type_info::__do_catch(const type_info*, void**, unsigned) is a stub\n");
    return false; // Let's hope we never need this :)
}

bool __class_type_info::__do_dyncast(ptrdiff_t __src2dst, __sub_kind __access_path, const __class_type_info *__dst_type, const void *__obj_ptr, const __class_type_info *__src_type, const void *__src_ptr, __dyncast_result &__result) const {
    printf("__class_type_info::__do_dyncast(ptrdiff_t, __sub_kind, const __class_type_info*, const void*, const __class_type_info*, const void*, __dyncast_result&) is a stub\n");
    return false; // I'll figure out how this is supposed to work later
}

__class_type_info::__sub_kind __class_type_info::__do_find_public_src(ptrdiff_t __src2dst, const void *__obj_ptr, const __class_type_info *__src_type, const void *sub_ptr) const {
    printf("__class_type_info::__do_find_public_src(ptrdiff_t, const void*, const __class_type_info*, const void*) is a stub\n");
    return __unknown; // I'll figure out how this is supposed to work later
}

bool __class_type_info::__do_upcast(const __class_type_info *__dst_type, void **__obj_ptr) const {
    printf("__class_type_info::__do_upcast(const __class_type_info*, void**) is a stub\n");
    return false; // I'll figure out how this is supposed to work later
}

bool __class_type_info::__do_upcast(const __class_type_info *__dst, const void *__obj, __upcast_result &__restrict __result) const {
    printf("__class_type_info::__do_upcast(const __class_type_info*, const void*, __upcast_result &restrict) is a stub\n");
    return false; // I'll figure out how this is supposed to work later
}

__forced_unwind::~__forced_unwind() throw() {}

__function_type_info::~__function_type_info() {}

bool __function_type_info::__is_function_p() const {
    return true;
}

__pbase_type_info::~__pbase_type_info() {}

bool __pbase_type_info::__do_catch(const std::type_info *__thr_type, void **__thr_obj, unsigned int __outer) const {
    printf("__pbase_type_info::__do_catch(const type_info*, void**, unsigned) is a stub\n");
    return false; // Let's hope we never need this :)
}

__pointer_type_info::~__pointer_type_info() {}

bool __pointer_type_info::__is_pointer_p() const {
    return true;
}

bool __pointer_type_info::__pointer_catch(const __pbase_type_info *__thr_type, void **__thr_obj, unsigned __outer) const {
    printf("__pointer_type_info::__pointer_catch(const __pbase_type_info*, void**, unsigned) is a stub\n");
    return false; // Let's hope we never need this :)
}

__si_class_type_info::~__si_class_type_info() {}

bool __si_class_type_info::__do_dyncast(ptrdiff_t __src2dst, __sub_kind __access_path, const __class_type_info *__dst_type, const void *__obj_ptr, const __class_type_info *__src_type, const void *__src_ptr, __dyncast_result &__result) const {
    printf("__si_class_type_info::__do_dyncast(ptrdiff_t, __sub_kind, const __class_type_info*, const void*, const __class_type_info*, const void*, __dyncast_result&) is a stub\n");
    return false; // I'll figure out how this is supposed to work later
}

__si_class_type_info::__sub_kind __si_class_type_info::__do_find_public_src(ptrdiff_t __src2dst, const void *__obj_ptr, const __class_type_info *__src_type, const void *sub_ptr) const {
    printf("__si_class_type_info::__do_find_public_src(ptrdiff_t, const void*, const __class_type_info*, const void*) is a stub\n");
    return __unknown; // I'll figure out how this is supposed to work later
}

bool __si_class_type_info::__do_upcast(const __class_type_info *__dst, const void *__obj, __upcast_result &__restrict __result) const {
    printf("__si_class_type_info::__do_upcast(const __class_type_info*, const void*, __upcast_result &restrict) is a stub\n");
    return false; // I'll figure out how this is supposed to work later
}

__vmi_class_type_info::~__vmi_class_type_info() {}

bool __vmi_class_type_info::__do_dyncast(ptrdiff_t __src2dst, __sub_kind __access_path, const __class_type_info *__dst_type, const void *__obj_ptr, const __class_type_info *__src_type, const void *__src_ptr, __dyncast_result &__result) const {
    printf("__vmi_class_type_info::__do_dyncast(ptrdiff_t, __sub_kind, const __class_type_info*, const void*, const __class_type_info*, const void*, __dyncast_result&) is a stub\n");
    return false; // I'll figure out how this is supposed to work later
}

__vmi_class_type_info::__sub_kind __vmi_class_type_info::__do_find_public_src(ptrdiff_t __src2dst, const void *__obj_ptr, const __class_type_info *__src_type, const void *sub_ptr) const {
    printf("__vmi_class_type_info::__do_find_public_src(ptrdiff_t, const void*, const __class_type_info*, const void*) is a stub\n");
    return __unknown; // I'll figure out how this is supposed to work later
}

bool __vmi_class_type_info::__do_upcast(const __class_type_info *__dst, const void *__obj, __upcast_result &__restrict __result) const {
    printf("__vmi_class_type_info::__do_upcast(const __class_type_info*, const void*, __upcast_result &restrict) is a stub\n");
    return false; // I'll figure out how this is supposed to work later
}

} // namespace abi
