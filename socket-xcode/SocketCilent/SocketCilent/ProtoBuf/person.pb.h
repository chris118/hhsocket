// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: person.proto

#ifndef PROTOBUF_person_2eproto__INCLUDED
#define PROTOBUF_person_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
class person;
class personDefaultTypeInternal;
extern personDefaultTypeInternal _person_default_instance_;

namespace protobuf_person_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_person_2eproto

// ===================================================================

class person : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:person) */ {
 public:
  person();
  virtual ~person();

  person(const person& from);

  inline person& operator=(const person& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const person& default_instance();

  static inline const person* internal_default_instance() {
    return reinterpret_cast<const person*>(
               &_person_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(person* other);

  // implements Message ----------------------------------------------

  inline person* New() const PROTOBUF_FINAL { return New(NULL); }

  person* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const person& from);
  void MergeFrom(const person& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(person* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string name = 3;
  bool has_name() const;
  void clear_name();
  static const int kNameFieldNumber = 3;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // required int32 age = 1;
  bool has_age() const;
  void clear_age();
  static const int kAgeFieldNumber = 1;
  ::google::protobuf::int32 age() const;
  void set_age(::google::protobuf::int32 value);

  // required int32 userid = 2;
  bool has_userid() const;
  void clear_userid();
  static const int kUseridFieldNumber = 2;
  ::google::protobuf::int32 userid() const;
  void set_userid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:person)
 private:
  void set_has_age();
  void clear_has_age();
  void set_has_userid();
  void clear_has_userid();
  void set_has_name();
  void clear_has_name();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::int32 age_;
  ::google::protobuf::int32 userid_;
  friend struct protobuf_person_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// person

// required int32 age = 1;
inline bool person::has_age() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void person::set_has_age() {
  _has_bits_[0] |= 0x00000002u;
}
inline void person::clear_has_age() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void person::clear_age() {
  age_ = 0;
  clear_has_age();
}
inline ::google::protobuf::int32 person::age() const {
  // @@protoc_insertion_point(field_get:person.age)
  return age_;
}
inline void person::set_age(::google::protobuf::int32 value) {
  set_has_age();
  age_ = value;
  // @@protoc_insertion_point(field_set:person.age)
}

// required int32 userid = 2;
inline bool person::has_userid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void person::set_has_userid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void person::clear_has_userid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void person::clear_userid() {
  userid_ = 0;
  clear_has_userid();
}
inline ::google::protobuf::int32 person::userid() const {
  // @@protoc_insertion_point(field_get:person.userid)
  return userid_;
}
inline void person::set_userid(::google::protobuf::int32 value) {
  set_has_userid();
  userid_ = value;
  // @@protoc_insertion_point(field_set:person.userid)
}

// optional string name = 3;
inline bool person::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void person::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void person::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void person::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
inline const ::std::string& person::name() const {
  // @@protoc_insertion_point(field_get:person.name)
  return name_.GetNoArena();
}
inline void person::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:person.name)
}
#if LANG_CXX11
inline void person::set_name(::std::string&& value) {
  set_has_name();
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:person.name)
}
#endif
inline void person::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:person.name)
}
inline void person::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:person.name)
}
inline ::std::string* person::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:person.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* person::release_name() {
  // @@protoc_insertion_point(field_release:person.name)
  clear_has_name();
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void person::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:person.name)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_person_2eproto__INCLUDED
