#include <cxxabi.h>
#include <cstdint>
#include <cstdio> // DEBUGGING
#include <cstdlib>
#include <exception>
#include <unwind.h>
#include <vector>

namespace std {

void __throw_bad_alloc() {
    fprintf(stderr, "Bad alloc\n");
    std::terminate();
}

void __throw_bad_cast() {
    fprintf(stderr, "Bad cast\n");
    std::terminate();
}

void __throw_invalid_argument(const char*) {
    fprintf(stderr, "Invalid argument\n");
    std::terminate();
}

void __throw_logic_error(const char*) {
    fprintf(stderr, "Logic error\n");
    std::terminate();
}

void __throw_system_error(int) {
    fprintf(stderr, "System error\n");
    std::terminate();
}

void __throw_out_of_range_fmt(const char*, ...) {
    fprintf(stderr, "Out of range format\n");
    std::terminate();
}

size_t _Hash_bytes(const void *ptr, size_t len, size_t seed) {
    size_t result = seed + 0x959524864321F0DCL; // Numbers off the top of my head. Should be replaced by PRNG
    for(size_t i = 0; i < len; i++) {
        result += reinterpret_cast<const uint8_t*>(ptr)[i];
        result *= 0xCD0F123468425959; // Reverse of ^. Not mathematically sound
    }
    return result;
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

struct __cxa_exception {
    std::type_info *exceptionType;
    void(*exceptionDestructor)(void*);
//    std::unexpected_handler unexpectedHandler;
    void *unexpectedHandler; // std::unexpected was removed in C++17
    std::terminate_handler terminateHandler;
    int handlerCount;
    int handlerSwitchValue;
    const char *actionRecord;
    const char *languageSpecificData;
    void *catchTemp;
    void *adjustedPtr;
    _Unwind_Exception unwindHeader;
}; // From the Itanium C++ Exception Handling ABI specification

struct __cxa_eh_globals {
    __cxa_exception *caughtExceptions;
    unsigned int uncaughtExceptions;
};

static thread_local __cxa_eh_globals *__cxa_globals = new __cxa_eh_globals{nullptr, 0};

extern "C" void* __cxa_allocate_exception(size_t thrown_size) {
    void *result = malloc(thrown_size);
    if(!result) std::terminate();
    return result;
}

extern "C" void* __cxa_begin_catch(void *exception_object) {
    printf("__cxa_begin_catch is a stub\n");
    std::terminate();
}

extern "C" __cxa_eh_globals* __cxa_get_globals() {
    return __cxa_globals;
}

extern "C" void __cxa_guard_abort(int64_t*) {
    printf("__cxa_guart_abort is a stub\n");
    std::terminate();
}

extern "C" int __cxa_guard_acquire(int64_t *guard_object) {
    return reinterpret_cast<uint8_t*>(guard_object)[0] != 0;
}

extern "C" void __cxa_guard_release(int64_t*) {
    printf("__cxa_guard_release is a stub\n");
    std::terminate();
}

extern "C" __cxa_refcounted_exception* __cxa_init_primary_exception(void *object, std::type_info *tinfo, void (*dest)(void*)) {
    printf("__cxa_init_primary_exception is a stub\nAlso, this impl doesn't intentionally use it.\n");
    std::terminate();
}

extern "C" void __cxa_pure_virtual() {
    fprintf(stderr, "Pure virtual function called\n");
    std::terminate();
}

extern "C" void __cxa_throw(void *thrown_exception, std::type_info *tinfo, void(*dest)(void*)) {
    __cxa_exception *hdr = (((__cxa_exception*) thrown_exception) - 1);
    // Save the current unexpected_handler and terminate_handler in the __cxa_exception header.
    hdr->unexpectedHandler = nullptr;
    hdr->terminateHandler = std::get_terminate();
    // Save the tinfo and dest arguments in the __cxa_exception header.
    hdr->exceptionType = tinfo;
    hdr->exceptionDestructor = dest;
    // Set the exception_class field in the unwind header. This is a 64-bit value representing the ASCII string "XXXXC++\0", where "XXXX" is a vendor-dependent string. That is, for implementations conforming to this ABI, the low-order 4 bytes of this 64-bit value will be "C++\0".
    hdr->unwindHeader.exception_class = 0x4C472B2B432B2B00; // "LG++C++\0"; LG++ for LC implementation of GNU C++ libraries
    // Increment the uncaught_exception flag.
    __cxa_eh_globals *globals = __cxa_get_globals();
    globals->uncaughtExceptions++;
    // Call _Unwind_RaiseException in the system unwind library, Its argument is the pointer to the thrown exception, which __cxa_throw itself received as an argument.
    _Unwind_RaiseException((_Unwind_Exception*) thrown_exception);
    fprintf(stderr, "Exception not handled, terminating\n");
    abort(); // Something has gone dreadfully wrong.
}

extern "C" void __cxa_throw_bad_array_new_length() {
    fprintf(stderr, "Bad array new length\n");
    std::terminate();
}

extern "C" void *__dynamic_cast(const void *sub, const __class_type_info *src, const __class_type_info *dst, ptrdiff_t src2dst_offset) {
    if(src2dst_offset < 0) { printf("__dynamic_cast hint usage is a stub\n"); std::terminate(); }
    return reinterpret_cast<void*>(((uintptr_t) sub) + src2dst_offset); // I'll figure this out. Later.
}

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

static uint64_t __readuleb128(uint8_t* &data) {
    uint8_t cur_byte;
    uint64_t result = 0;
    uint8_t shift = 0;
    do {
        cur_byte = *(data++);
        result |= uint64_t(cur_byte) << shift;
        shift += 7;
    } while(cur_byte & 0x80);
    return result;
}

struct __lsda_call_site {
    void *start;
    void *end;
    void *landing_pad;
    uint8_t actions;
};

class __lsda {
  private:
    uint8_t field1;
    uint8_t field2;
    uint8_t field3;
    std::vector<__lsda_call_site> call_sites; // Are you saying you have something better?
  public:
    __lsda(uint8_t *data);
};

__lsda::__lsda(uint8_t *data) {
    field1 = *(data++);
    field2 = *(data++);
    size_t lsda_size = __readuleb128(data);
    field3 = *(data++);
    size_t call_site_table_size = __readuleb128(data);
    uint8_t *call_site_table_end = call_site_table_size + data;
    while(data < call_site_table_end) {
        call_sites.push_back(
            __lsda_call_site {
                reinterpret_cast<void*>(__readuleb128(data)),
                reinterpret_cast<void*>(__readuleb128(data)),
                reinterpret_cast<void*>(__readuleb128(data)),
                *(data++)
            }
        );
    }
}

extern "C" _Unwind_Reason_Code __gxx_personality_v0(int version, _Unwind_Action actions, _Unwind_Exception_Class exception_class, struct _Unwind_Exception *ue_header, struct _Unwind_Context *context) {
    __lsda lsda(static_cast<uint8_t*>(_Unwind_GetLanguageSpecificData(context)));
    if(actions & _UA_SEARCH_PHASE) {
        
    } else if(actions & _UA_CLEANUP_PHASE) {
        
    }
    return _URC_CONTINUE_UNWIND;
}

} // namespace abi
