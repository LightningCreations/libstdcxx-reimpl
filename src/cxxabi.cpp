#include <cxxabi.h>
#include <cstdint>
#include <cstdio> // DEBUGGING
#include <cstdlib>

extern "C" void __cxa_pure_virtual() { while(1); }
void *__gxx_personality_v0 = NULL;
extern "C" void *__dynamic_cast(const void *sub, const __cxxabiv1::__class_type_info *src, const __cxxabiv1::__class_type_info *dst, ptrdiff_t src2dst_offset) {
    printf("__dynamic_cast is a stub\n");
    return reinterpret_cast<void*>(((uintptr_t) sub) + src2dst_offset); // I'll figure this out. Later.
}

namespace std {

[[noreturn]] void __throw_bad_cast() {
    fprintf(stderr, "Bad cast\n");
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
