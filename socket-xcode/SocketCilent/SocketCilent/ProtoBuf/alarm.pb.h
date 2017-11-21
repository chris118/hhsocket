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

class AlarmInfo;

// ===================================================================

class AlarmInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:AlarmInfo) */ {
 public:
  AlarmInfo();
  virtual ~AlarmInfo();

  AlarmInfo(const AlarmInfo& from);

  inline AlarmInfo& operator=(const AlarmInfo& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const AlarmInfo& default_instance();

  void Swap(AlarmInfo* other);

  // implements Message ----------------------------------------------

  inline AlarmInfo* New() const { return New(NULL); }

  AlarmInfo* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const AlarmInfo& from);
  void MergeFrom(const AlarmInfo& from);
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
  void InternalSwap(AlarmInfo* other);
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

  // @@protoc_insertion_point(class_scope:AlarmInfo)
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
  static AlarmInfo* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// AlarmInfo

// optional int32 id = 1;
inline void AlarmInfo::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 AlarmInfo::id() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.id)
  return id_;
}
inline void AlarmInfo::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.id)
}

// optional int32 obj_type = 2;
inline void AlarmInfo::clear_obj_type() {
  obj_type_ = 0;
}
inline ::google::protobuf::int32 AlarmInfo::obj_type() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.obj_type)
  return obj_type_;
}
inline void AlarmInfo::set_obj_type(::google::protobuf::int32 value) {
  
  obj_type_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.obj_type)
}

// optional int32 timestamp = 3;
inline void AlarmInfo::clear_timestamp() {
  timestamp_ = 0;
}
inline ::google::protobuf::int32 AlarmInfo::timestamp() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.timestamp)
  return timestamp_;
}
inline void AlarmInfo::set_timestamp(::google::protobuf::int32 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.timestamp)
}

// optional int32 x = 4;
inline void AlarmInfo::clear_x() {
  x_ = 0;
}
inline ::google::protobuf::int32 AlarmInfo::x() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.x)
  return x_;
}
inline void AlarmInfo::set_x(::google::protobuf::int32 value) {
  
  x_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.x)
}

// optional int32 y = 5;
inline void AlarmInfo::clear_y() {
  y_ = 0;
}
inline ::google::protobuf::int32 AlarmInfo::y() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.y)
  return y_;
}
inline void AlarmInfo::set_y(::google::protobuf::int32 value) {
  
  y_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.y)
}

// optional int32 w = 6;
inline void AlarmInfo::clear_w() {
  w_ = 0;
}
inline ::google::protobuf::int32 AlarmInfo::w() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.w)
  return w_;
}
inline void AlarmInfo::set_w(::google::protobuf::int32 value) {
  
  w_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.w)
}

// optional int32 h = 7;
inline void AlarmInfo::clear_h() {
  h_ = 0;
}
inline ::google::protobuf::int32 AlarmInfo::h() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.h)
  return h_;
}
inline void AlarmInfo::set_h(::google::protobuf::int32 value) {
  
  h_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.h)
}

// optional int32 start_timestamp = 8;
inline void AlarmInfo::clear_start_timestamp() {
  start_timestamp_ = 0;
}
inline ::google::protobuf::int32 AlarmInfo::start_timestamp() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.start_timestamp)
  return start_timestamp_;
}
inline void AlarmInfo::set_start_timestamp(::google::protobuf::int32 value) {
  
  start_timestamp_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.start_timestamp)
}

// optional int32 end_timestamp = 9;
inline void AlarmInfo::clear_end_timestamp() {
  end_timestamp_ = 0;
}
inline ::google::protobuf::int32 AlarmInfo::end_timestamp() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.end_timestamp)
  return end_timestamp_;
}
inline void AlarmInfo::set_end_timestamp(::google::protobuf::int32 value) {
  
  end_timestamp_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.end_timestamp)
}

// optional int32 credibility = 10;
inline void AlarmInfo::clear_credibility() {
  credibility_ = 0;
}
inline ::google::protobuf::int32 AlarmInfo::credibility() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.credibility)
  return credibility_;
}
inline void AlarmInfo::set_credibility(::google::protobuf::int32 value) {
  
  credibility_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.credibility)
}

// optional bytes alarm_pic = 11;
inline void AlarmInfo::clear_alarm_pic() {
  alarm_pic_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& AlarmInfo::alarm_pic() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.alarm_pic)
  return alarm_pic_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AlarmInfo::set_alarm_pic(const ::std::string& value) {
  
  alarm_pic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:AlarmInfo.alarm_pic)
}
inline void AlarmInfo::set_alarm_pic(const char* value) {
  
  alarm_pic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:AlarmInfo.alarm_pic)
}
inline void AlarmInfo::set_alarm_pic(const void* value, size_t size) {
  
  alarm_pic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:AlarmInfo.alarm_pic)
}
inline ::std::string* AlarmInfo::mutable_alarm_pic() {
  
  // @@protoc_insertion_point(field_mutable:AlarmInfo.alarm_pic)
  return alarm_pic_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* AlarmInfo::release_alarm_pic() {
  // @@protoc_insertion_point(field_release:AlarmInfo.alarm_pic)
  
  return alarm_pic_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AlarmInfo::set_allocated_alarm_pic(::std::string* alarm_pic) {
  if (alarm_pic != NULL) {
    
  } else {
    
  }
  alarm_pic_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), alarm_pic);
  // @@protoc_insertion_point(field_set_allocated:AlarmInfo.alarm_pic)
}

// optional bytes alarm_vid = 12;
inline void AlarmInfo::clear_alarm_vid() {
  alarm_vid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& AlarmInfo::alarm_vid() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.alarm_vid)
  return alarm_vid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AlarmInfo::set_alarm_vid(const ::std::string& value) {
  
  alarm_vid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:AlarmInfo.alarm_vid)
}
inline void AlarmInfo::set_alarm_vid(const char* value) {
  
  alarm_vid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:AlarmInfo.alarm_vid)
}
inline void AlarmInfo::set_alarm_vid(const void* value, size_t size) {
  
  alarm_vid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:AlarmInfo.alarm_vid)
}
inline ::std::string* AlarmInfo::mutable_alarm_vid() {
  
  // @@protoc_insertion_point(field_mutable:AlarmInfo.alarm_vid)
  return alarm_vid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* AlarmInfo::release_alarm_vid() {
  // @@protoc_insertion_point(field_release:AlarmInfo.alarm_vid)
  
  return alarm_vid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AlarmInfo::set_allocated_alarm_vid(::std::string* alarm_vid) {
  if (alarm_vid != NULL) {
    
  } else {
    
  }
  alarm_vid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), alarm_vid);
  // @@protoc_insertion_point(field_set_allocated:AlarmInfo.alarm_vid)
}

// optional bytes src_image = 13;
inline void AlarmInfo::clear_src_image() {
  src_image_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& AlarmInfo::src_image() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.src_image)
  return src_image_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AlarmInfo::set_src_image(const ::std::string& value) {
  
  src_image_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:AlarmInfo.src_image)
}
inline void AlarmInfo::set_src_image(const char* value) {
  
  src_image_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:AlarmInfo.src_image)
}
inline void AlarmInfo::set_src_image(const void* value, size_t size) {
  
  src_image_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:AlarmInfo.src_image)
}
inline ::std::string* AlarmInfo::mutable_src_image() {
  
  // @@protoc_insertion_point(field_mutable:AlarmInfo.src_image)
  return src_image_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* AlarmInfo::release_src_image() {
  // @@protoc_insertion_point(field_release:AlarmInfo.src_image)
  
  return src_image_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void AlarmInfo::set_allocated_src_image(::std::string* src_image) {
  if (src_image != NULL) {
    
  } else {
    
  }
  src_image_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), src_image);
  // @@protoc_insertion_point(field_set_allocated:AlarmInfo.src_image)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_alarm_2eproto__INCLUDED