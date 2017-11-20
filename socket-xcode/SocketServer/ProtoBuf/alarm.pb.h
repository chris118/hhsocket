// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: alarm.proto

#ifndef PROTOBUF_alarm_2eproto__INCLUDED
#define PROTOBUF_alarm_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_alarm_2eproto();
void protobuf_AssignDesc_alarm_2eproto();
void protobuf_ShutdownFile_alarm_2eproto();

class alarm;

// ===================================================================

class alarm : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:alarm) */ {
 public:
  alarm();
  virtual ~alarm();

  alarm(const alarm& from);

  inline alarm& operator=(const alarm& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const alarm& default_instance();

  void Swap(alarm* other);

  // implements Message ----------------------------------------------

  inline alarm* New() const { return New(NULL); }

  alarm* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const alarm& from);
  void MergeFrom(const alarm& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(alarm* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // optional int32 obj_type = 2;
  void clear_obj_type();
  static const int kObjTypeFieldNumber = 2;
  ::google::protobuf::int32 obj_type() const;
  void set_obj_type(::google::protobuf::int32 value);

  // optional int32 timestamp = 3;
  void clear_timestamp();
  static const int kTimestampFieldNumber = 3;
  ::google::protobuf::int32 timestamp() const;
  void set_timestamp(::google::protobuf::int32 value);

  // optional int32 x = 4;
  void clear_x();
  static const int kXFieldNumber = 4;
  ::google::protobuf::int32 x() const;
  void set_x(::google::protobuf::int32 value);

  // optional int32 y = 5;
  void clear_y();
  static const int kYFieldNumber = 5;
  ::google::protobuf::int32 y() const;
  void set_y(::google::protobuf::int32 value);

  // optional int32 w = 6;
  void clear_w();
  static const int kWFieldNumber = 6;
  ::google::protobuf::int32 w() const;
  void set_w(::google::protobuf::int32 value);

  // optional int32 h = 7;
  void clear_h();
  static const int kHFieldNumber = 7;
  ::google::protobuf::int32 h() const;
  void set_h(::google::protobuf::int32 value);

  // optional int32 start_timestamp = 8;
  void clear_start_timestamp();
  static const int kStartTimestampFieldNumber = 8;
  ::google::protobuf::int32 start_timestamp() const;
  void set_start_timestamp(::google::protobuf::int32 value);

  // optional int32 end_timestamp = 9;
  void clear_end_timestamp();
  static const int kEndTimestampFieldNumber = 9;
  ::google::protobuf::int32 end_timestamp() const;
  void set_end_timestamp(::google::protobuf::int32 value);

  // optional int32 credibility = 10;
  void clear_credibility();
  static const int kCredibilityFieldNumber = 10;
  ::google::protobuf::int32 credibility() const;
  void set_credibility(::google::protobuf::int32 value);

  // optional bytes alarm_pic = 11;
  void clear_alarm_pic();
  static const int kAlarmPicFieldNumber = 11;
  const ::std::string& alarm_pic() const;
  void set_alarm_pic(const ::std::string& value);
  void set_alarm_pic(const char* value);
  void set_alarm_pic(const void* value, size_t size);
  ::std::string* mutable_alarm_pic();
  ::std::string* release_alarm_pic();
  void set_allocated_alarm_pic(::std::string* alarm_pic);

  // optional bytes alarm_vid = 12;
  void clear_alarm_vid();
  static const int kAlarmVidFieldNumber = 12;
  const ::std::string& alarm_vid() const;
  void set_alarm_vid(const ::std::string& value);
  void set_alarm_vid(const char* value);
  void set_alarm_vid(const void* value, size_t size);
  ::std::string* mutable_alarm_vid();
  ::std::string* release_alarm_vid();
  void set_allocated_alarm_vid(::std::string* alarm_vid);

  // optional bytes src_image = 13;
  void clear_src_image();
  static const int kSrcImageFieldNumber = 13;
  const ::std::string& src_image() const;
  void set_src_image(const ::std::string& value);
  void set_src_image(const char* value);
  void set_src_image(const void* value, size_t size);
  ::std::string* mutable_src_image();
  ::std::string* release_src_image();
  void set_allocated_src_image(::std::string* src_image);

  // @@protoc_insertion_point(class_scope:alarm)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int32 id_;
  ::google::protobuf::int32 obj_type_;
  ::google::protobuf::int32 timestamp_;
  ::google::protobuf::int32 x_;
  ::google::protobuf::int32 y_;
  ::google::protobuf::int32 w_;
  ::google::protobuf::int32 h_;
  ::google::protobuf::int32 start_timestamp_;
  ::google::protobuf::int32 end_timestamp_;
  ::google::protobuf::int32 credibility_;
  ::google::protobuf::internal::ArenaStringPtr alarm_pic_;
  ::google::protobuf::internal::ArenaStringPtr alarm_vid_;
  ::google::protobuf::internal::ArenaStringPtr src_image_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_alarm_2eproto();
  friend void protobuf_AssignDesc_alarm_2eproto();
  friend void protobuf_ShutdownFile_alarm_2eproto();

  void InitAsDefaultInstance();
  static alarm* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// alarm

// optional int32 id = 1;
inline void alarm::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 alarm::id() const {
  // @@protoc_insertion_point(field_get:alarm.id)
  return id_;
}
inline void alarm::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:alarm.id)
}

// optional int32 obj_type = 2;
inline void alarm::clear_obj_type() {
  obj_type_ = 0;
}
inline ::google::protobuf::int32 alarm::obj_type() const {
  // @@protoc_insertion_point(field_get:alarm.obj_type)
  return obj_type_;
}
inline void alarm::set_obj_type(::google::protobuf::int32 value) {
  
  obj_type_ = value;
  // @@protoc_insertion_point(field_set:alarm.obj_type)
}

// optional int32 timestamp = 3;
inline void alarm::clear_timestamp() {
  timestamp_ = 0;
}
inline ::google::protobuf::int32 alarm::timestamp() const {
  // @@protoc_insertion_point(field_get:alarm.timestamp)
  return timestamp_;
}
inline void alarm::set_timestamp(::google::protobuf::int32 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:alarm.timestamp)
}

// optional int32 x = 4;
inline void alarm::clear_x() {
  x_ = 0;
}
inline ::google::protobuf::int32 alarm::x() const {
  // @@protoc_insertion_point(field_get:alarm.x)
  return x_;
}
inline void alarm::set_x(::google::protobuf::int32 value) {
  
  x_ = value;
  // @@protoc_insertion_point(field_set:alarm.x)
}

// optional int32 y = 5;
inline void alarm::clear_y() {
  y_ = 0;
}
inline ::google::protobuf::int32 alarm::y() const {
  // @@protoc_insertion_point(field_get:alarm.y)
  return y_;
}
inline void alarm::set_y(::google::protobuf::int32 value) {
  
  y_ = value;
  // @@protoc_insertion_point(field_set:alarm.y)
}

// optional int32 w = 6;
inline void alarm::clear_w() {
  w_ = 0;
}
inline ::google::protobuf::int32 alarm::w() const {
  // @@protoc_insertion_point(field_get:alarm.w)
  return w_;
}
inline void alarm::set_w(::google::protobuf::int32 value) {
  
  w_ = value;
  // @@protoc_insertion_point(field_set:alarm.w)
}

// optional int32 h = 7;
inline void alarm::clear_h() {
  h_ = 0;
}
inline ::google::protobuf::int32 alarm::h() const {
  // @@protoc_insertion_point(field_get:alarm.h)
  return h_;
}
inline void alarm::set_h(::google::protobuf::int32 value) {
  
  h_ = value;
  // @@protoc_insertion_point(field_set:alarm.h)
}

// optional int32 start_timestamp = 8;
inline void alarm::clear_start_timestamp() {
  start_timestamp_ = 0;
}
inline ::google::protobuf::int32 alarm::start_timestamp() const {
  // @@protoc_insertion_point(field_get:alarm.start_timestamp)
  return start_timestamp_;
}
inline void alarm::set_start_timestamp(::google::protobuf::int32 value) {
  
  start_timestamp_ = value;
  // @@protoc_insertion_point(field_set:alarm.start_timestamp)
}

// optional int32 end_timestamp = 9;
inline void alarm::clear_end_timestamp() {
  end_timestamp_ = 0;
}
inline ::google::protobuf::int32 alarm::end_timestamp() const {
  // @@protoc_insertion_point(field_get:alarm.end_timestamp)
  return end_timestamp_;
}
inline void alarm::set_end_timestamp(::google::protobuf::int32 value) {
  
  end_timestamp_ = value;
  // @@protoc_insertion_point(field_set:alarm.end_timestamp)
}

// optional int32 credibility = 10;
inline void alarm::clear_credibility() {
  credibility_ = 0;
}
inline ::google::protobuf::int32 alarm::credibility() const {
  // @@protoc_insertion_point(field_get:alarm.credibility)
  return credibility_;
}
inline void alarm::set_credibility(::google::protobuf::int32 value) {
  
  credibility_ = value;
  // @@protoc_insertion_point(field_set:alarm.credibility)
}

// optional bytes alarm_pic = 11;
inline void alarm::clear_alarm_pic() {
  alarm_pic_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& alarm::alarm_pic() const {
  // @@protoc_insertion_point(field_get:alarm.alarm_pic)
  return alarm_pic_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void alarm::set_alarm_pic(const ::std::string& value) {
  
  alarm_pic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:alarm.alarm_pic)
}
inline void alarm::set_alarm_pic(const char* value) {
  
  alarm_pic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:alarm.alarm_pic)
}
inline void alarm::set_alarm_pic(const void* value, size_t size) {
  
  alarm_pic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:alarm.alarm_pic)
}
inline ::std::string* alarm::mutable_alarm_pic() {
  
  // @@protoc_insertion_point(field_mutable:alarm.alarm_pic)
  return alarm_pic_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* alarm::release_alarm_pic() {
  // @@protoc_insertion_point(field_release:alarm.alarm_pic)
  
  return alarm_pic_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void alarm::set_allocated_alarm_pic(::std::string* alarm_pic) {
  if (alarm_pic != NULL) {
    
  } else {
    
  }
  alarm_pic_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), alarm_pic);
  // @@protoc_insertion_point(field_set_allocated:alarm.alarm_pic)
}

// optional bytes alarm_vid = 12;
inline void alarm::clear_alarm_vid() {
  alarm_vid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& alarm::alarm_vid() const {
  // @@protoc_insertion_point(field_get:alarm.alarm_vid)
  return alarm_vid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void alarm::set_alarm_vid(const ::std::string& value) {
  
  alarm_vid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:alarm.alarm_vid)
}
inline void alarm::set_alarm_vid(const char* value) {
  
  alarm_vid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:alarm.alarm_vid)
}
inline void alarm::set_alarm_vid(const void* value, size_t size) {
  
  alarm_vid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:alarm.alarm_vid)
}
inline ::std::string* alarm::mutable_alarm_vid() {
  
  // @@protoc_insertion_point(field_mutable:alarm.alarm_vid)
  return alarm_vid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* alarm::release_alarm_vid() {
  // @@protoc_insertion_point(field_release:alarm.alarm_vid)
  
  return alarm_vid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void alarm::set_allocated_alarm_vid(::std::string* alarm_vid) {
  if (alarm_vid != NULL) {
    
  } else {
    
  }
  alarm_vid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), alarm_vid);
  // @@protoc_insertion_point(field_set_allocated:alarm.alarm_vid)
}

// optional bytes src_image = 13;
inline void alarm::clear_src_image() {
  src_image_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& alarm::src_image() const {
  // @@protoc_insertion_point(field_get:alarm.src_image)
  return src_image_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void alarm::set_src_image(const ::std::string& value) {
  
  src_image_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:alarm.src_image)
}
inline void alarm::set_src_image(const char* value) {
  
  src_image_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:alarm.src_image)
}
inline void alarm::set_src_image(const void* value, size_t size) {
  
  src_image_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:alarm.src_image)
}
inline ::std::string* alarm::mutable_src_image() {
  
  // @@protoc_insertion_point(field_mutable:alarm.src_image)
  return src_image_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* alarm::release_src_image() {
  // @@protoc_insertion_point(field_release:alarm.src_image)
  
  return src_image_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void alarm::set_allocated_src_image(::std::string* src_image) {
  if (src_image != NULL) {
    
  } else {
    
  }
  src_image_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), src_image);
  // @@protoc_insertion_point(field_set_allocated:alarm.src_image)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_alarm_2eproto__INCLUDED
