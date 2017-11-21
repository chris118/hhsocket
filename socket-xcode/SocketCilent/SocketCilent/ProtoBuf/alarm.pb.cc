// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: alarm.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "alarm.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* AlarmInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AlarmInfo_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_alarm_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_alarm_2eproto() {
  protobuf_AddDesc_alarm_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "alarm.proto");
  GOOGLE_CHECK(file != NULL);
  AlarmInfo_descriptor_ = file->message_type(0);
  static const int AlarmInfo_offsets_[13] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, obj_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, timestamp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, x_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, y_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, w_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, h_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, start_timestamp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, end_timestamp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, credibility_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, alarm_pic_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, alarm_vid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, src_image_),
  };
  AlarmInfo_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      AlarmInfo_descriptor_,
      AlarmInfo::default_instance_,
      AlarmInfo_offsets_,
      -1,
      -1,
      -1,
      sizeof(AlarmInfo),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AlarmInfo, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_alarm_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      AlarmInfo_descriptor_, &AlarmInfo::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_alarm_2eproto() {
  delete AlarmInfo::default_instance_;
  delete AlarmInfo_reflection_;
}

void protobuf_AddDesc_alarm_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_alarm_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\013alarm.proto\"\346\001\n\tAlarmInfo\022\n\n\002id\030\001 \001(\005\022"
    "\020\n\010obj_type\030\002 \001(\005\022\021\n\ttimestamp\030\003 \001(\005\022\t\n\001"
    "x\030\004 \001(\005\022\t\n\001y\030\005 \001(\005\022\t\n\001w\030\006 \001(\005\022\t\n\001h\030\007 \001(\005"
    "\022\027\n\017start_timestamp\030\010 \001(\005\022\025\n\rend_timesta"
    "mp\030\t \001(\005\022\023\n\013credibility\030\n \001(\005\022\021\n\talarm_p"
    "ic\030\013 \001(\014\022\021\n\talarm_vid\030\014 \001(\014\022\021\n\tsrc_image"
    "\030\r \001(\014b\006proto3", 254);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "alarm.proto", &protobuf_RegisterTypes);
  AlarmInfo::default_instance_ = new AlarmInfo();
  AlarmInfo::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_alarm_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_alarm_2eproto {
  StaticDescriptorInitializer_alarm_2eproto() {
    protobuf_AddDesc_alarm_2eproto();
  }
} static_descriptor_initializer_alarm_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int AlarmInfo::kIdFieldNumber;
const int AlarmInfo::kObjTypeFieldNumber;
const int AlarmInfo::kTimestampFieldNumber;
const int AlarmInfo::kXFieldNumber;
const int AlarmInfo::kYFieldNumber;
const int AlarmInfo::kWFieldNumber;
const int AlarmInfo::kHFieldNumber;
const int AlarmInfo::kStartTimestampFieldNumber;
const int AlarmInfo::kEndTimestampFieldNumber;
const int AlarmInfo::kCredibilityFieldNumber;
const int AlarmInfo::kAlarmPicFieldNumber;
const int AlarmInfo::kAlarmVidFieldNumber;
const int AlarmInfo::kSrcImageFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

AlarmInfo::AlarmInfo()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:AlarmInfo)
}

void AlarmInfo::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

AlarmInfo::AlarmInfo(const AlarmInfo& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:AlarmInfo)
}

void AlarmInfo::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = 0;
  obj_type_ = 0;
  timestamp_ = 0;
  x_ = 0;
  y_ = 0;
  w_ = 0;
  h_ = 0;
  start_timestamp_ = 0;
  end_timestamp_ = 0;
  credibility_ = 0;
  alarm_pic_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  alarm_vid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  src_image_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

AlarmInfo::~AlarmInfo() {
  // @@protoc_insertion_point(destructor:AlarmInfo)
  SharedDtor();
}

void AlarmInfo::SharedDtor() {
  alarm_pic_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  alarm_vid_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  src_image_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void AlarmInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AlarmInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AlarmInfo_descriptor_;
}

const AlarmInfo& AlarmInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_alarm_2eproto();
  return *default_instance_;
}

AlarmInfo* AlarmInfo::default_instance_ = NULL;

AlarmInfo* AlarmInfo::New(::google::protobuf::Arena* arena) const {
  AlarmInfo* n = new AlarmInfo;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void AlarmInfo::Clear() {
// @@protoc_insertion_point(message_clear_start:AlarmInfo)
#if defined(__clang__)
#define ZR_HELPER_(f) \
  _Pragma("clang diagnostic push") \
  _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") \
  __builtin_offsetof(AlarmInfo, f) \
  _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<AlarmInfo*>(16)->f)
#endif

#define ZR_(first, last) do {\
  ::memset(&first, 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(id_, start_timestamp_);
  ZR_(end_timestamp_, credibility_);
  alarm_pic_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  alarm_vid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  src_image_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());

#undef ZR_HELPER_
#undef ZR_

}

bool AlarmInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:AlarmInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 id = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_obj_type;
        break;
      }

      // optional int32 obj_type = 2;
      case 2: {
        if (tag == 16) {
         parse_obj_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &obj_type_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_timestamp;
        break;
      }

      // optional int32 timestamp = 3;
      case 3: {
        if (tag == 24) {
         parse_timestamp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &timestamp_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_x;
        break;
      }

      // optional int32 x = 4;
      case 4: {
        if (tag == 32) {
         parse_x:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &x_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_y;
        break;
      }

      // optional int32 y = 5;
      case 5: {
        if (tag == 40) {
         parse_y:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &y_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_w;
        break;
      }

      // optional int32 w = 6;
      case 6: {
        if (tag == 48) {
         parse_w:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &w_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_h;
        break;
      }

      // optional int32 h = 7;
      case 7: {
        if (tag == 56) {
         parse_h:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &h_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_start_timestamp;
        break;
      }

      // optional int32 start_timestamp = 8;
      case 8: {
        if (tag == 64) {
         parse_start_timestamp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &start_timestamp_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(72)) goto parse_end_timestamp;
        break;
      }

      // optional int32 end_timestamp = 9;
      case 9: {
        if (tag == 72) {
         parse_end_timestamp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &end_timestamp_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(80)) goto parse_credibility;
        break;
      }

      // optional int32 credibility = 10;
      case 10: {
        if (tag == 80) {
         parse_credibility:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &credibility_)));

        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(90)) goto parse_alarm_pic;
        break;
      }

      // optional bytes alarm_pic = 11;
      case 11: {
        if (tag == 90) {
         parse_alarm_pic:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_alarm_pic()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(98)) goto parse_alarm_vid;
        break;
      }

      // optional bytes alarm_vid = 12;
      case 12: {
        if (tag == 98) {
         parse_alarm_vid:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_alarm_vid()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(106)) goto parse_src_image;
        break;
      }

      // optional bytes src_image = 13;
      case 13: {
        if (tag == 106) {
         parse_src_image:
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_src_image()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:AlarmInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:AlarmInfo)
  return false;
#undef DO_
}

void AlarmInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:AlarmInfo)
  // optional int32 id = 1;
  if (this->id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // optional int32 obj_type = 2;
  if (this->obj_type() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->obj_type(), output);
  }

  // optional int32 timestamp = 3;
  if (this->timestamp() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->timestamp(), output);
  }

  // optional int32 x = 4;
  if (this->x() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->x(), output);
  }

  // optional int32 y = 5;
  if (this->y() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->y(), output);
  }

  // optional int32 w = 6;
  if (this->w() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->w(), output);
  }

  // optional int32 h = 7;
  if (this->h() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(7, this->h(), output);
  }

  // optional int32 start_timestamp = 8;
  if (this->start_timestamp() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(8, this->start_timestamp(), output);
  }

  // optional int32 end_timestamp = 9;
  if (this->end_timestamp() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(9, this->end_timestamp(), output);
  }

  // optional int32 credibility = 10;
  if (this->credibility() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(10, this->credibility(), output);
  }

  // optional bytes alarm_pic = 11;
  if (this->alarm_pic().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      11, this->alarm_pic(), output);
  }

  // optional bytes alarm_vid = 12;
  if (this->alarm_vid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      12, this->alarm_vid(), output);
  }

  // optional bytes src_image = 13;
  if (this->src_image().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      13, this->src_image(), output);
  }

  // @@protoc_insertion_point(serialize_end:AlarmInfo)
}

::google::protobuf::uint8* AlarmInfo::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:AlarmInfo)
  // optional int32 id = 1;
  if (this->id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // optional int32 obj_type = 2;
  if (this->obj_type() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->obj_type(), target);
  }

  // optional int32 timestamp = 3;
  if (this->timestamp() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->timestamp(), target);
  }

  // optional int32 x = 4;
  if (this->x() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->x(), target);
  }

  // optional int32 y = 5;
  if (this->y() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->y(), target);
  }

  // optional int32 w = 6;
  if (this->w() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, this->w(), target);
  }

  // optional int32 h = 7;
  if (this->h() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, this->h(), target);
  }

  // optional int32 start_timestamp = 8;
  if (this->start_timestamp() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(8, this->start_timestamp(), target);
  }

  // optional int32 end_timestamp = 9;
  if (this->end_timestamp() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, this->end_timestamp(), target);
  }

  // optional int32 credibility = 10;
  if (this->credibility() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(10, this->credibility(), target);
  }

  // optional bytes alarm_pic = 11;
  if (this->alarm_pic().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        11, this->alarm_pic(), target);
  }

  // optional bytes alarm_vid = 12;
  if (this->alarm_vid().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        12, this->alarm_vid(), target);
  }

  // optional bytes src_image = 13;
  if (this->src_image().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        13, this->src_image(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:AlarmInfo)
  return target;
}

int AlarmInfo::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:AlarmInfo)
  int total_size = 0;

  // optional int32 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->id());
  }

  // optional int32 obj_type = 2;
  if (this->obj_type() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->obj_type());
  }

  // optional int32 timestamp = 3;
  if (this->timestamp() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->timestamp());
  }

  // optional int32 x = 4;
  if (this->x() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->x());
  }

  // optional int32 y = 5;
  if (this->y() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->y());
  }

  // optional int32 w = 6;
  if (this->w() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->w());
  }

  // optional int32 h = 7;
  if (this->h() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->h());
  }

  // optional int32 start_timestamp = 8;
  if (this->start_timestamp() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->start_timestamp());
  }

  // optional int32 end_timestamp = 9;
  if (this->end_timestamp() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->end_timestamp());
  }

  // optional int32 credibility = 10;
  if (this->credibility() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->credibility());
  }

  // optional bytes alarm_pic = 11;
  if (this->alarm_pic().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->alarm_pic());
  }

  // optional bytes alarm_vid = 12;
  if (this->alarm_vid().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->alarm_vid());
  }

  // optional bytes src_image = 13;
  if (this->src_image().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->src_image());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void AlarmInfo::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:AlarmInfo)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const AlarmInfo* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const AlarmInfo>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:AlarmInfo)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:AlarmInfo)
    MergeFrom(*source);
  }
}

void AlarmInfo::MergeFrom(const AlarmInfo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:AlarmInfo)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.id() != 0) {
    set_id(from.id());
  }
  if (from.obj_type() != 0) {
    set_obj_type(from.obj_type());
  }
  if (from.timestamp() != 0) {
    set_timestamp(from.timestamp());
  }
  if (from.x() != 0) {
    set_x(from.x());
  }
  if (from.y() != 0) {
    set_y(from.y());
  }
  if (from.w() != 0) {
    set_w(from.w());
  }
  if (from.h() != 0) {
    set_h(from.h());
  }
  if (from.start_timestamp() != 0) {
    set_start_timestamp(from.start_timestamp());
  }
  if (from.end_timestamp() != 0) {
    set_end_timestamp(from.end_timestamp());
  }
  if (from.credibility() != 0) {
    set_credibility(from.credibility());
  }
  if (from.alarm_pic().size() > 0) {

    alarm_pic_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.alarm_pic_);
  }
  if (from.alarm_vid().size() > 0) {

    alarm_vid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.alarm_vid_);
  }
  if (from.src_image().size() > 0) {

    src_image_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.src_image_);
  }
}

void AlarmInfo::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:AlarmInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AlarmInfo::CopyFrom(const AlarmInfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:AlarmInfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AlarmInfo::IsInitialized() const {

  return true;
}

void AlarmInfo::Swap(AlarmInfo* other) {
  if (other == this) return;
  InternalSwap(other);
}
void AlarmInfo::InternalSwap(AlarmInfo* other) {
  std::swap(id_, other->id_);
  std::swap(obj_type_, other->obj_type_);
  std::swap(timestamp_, other->timestamp_);
  std::swap(x_, other->x_);
  std::swap(y_, other->y_);
  std::swap(w_, other->w_);
  std::swap(h_, other->h_);
  std::swap(start_timestamp_, other->start_timestamp_);
  std::swap(end_timestamp_, other->end_timestamp_);
  std::swap(credibility_, other->credibility_);
  alarm_pic_.Swap(&other->alarm_pic_);
  alarm_vid_.Swap(&other->alarm_vid_);
  src_image_.Swap(&other->src_image_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata AlarmInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AlarmInfo_descriptor_;
  metadata.reflection = AlarmInfo_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// AlarmInfo

// optional int32 id = 1;
void AlarmInfo::clear_id() {
  id_ = 0;
}
 ::google::protobuf::int32 AlarmInfo::id() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.id)
  return id_;
}
 void AlarmInfo::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.id)
}

// optional int32 obj_type = 2;
void AlarmInfo::clear_obj_type() {
  obj_type_ = 0;
}
 ::google::protobuf::int32 AlarmInfo::obj_type() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.obj_type)
  return obj_type_;
}
 void AlarmInfo::set_obj_type(::google::protobuf::int32 value) {
  
  obj_type_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.obj_type)
}

// optional int32 timestamp = 3;
void AlarmInfo::clear_timestamp() {
  timestamp_ = 0;
}
 ::google::protobuf::int32 AlarmInfo::timestamp() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.timestamp)
  return timestamp_;
}
 void AlarmInfo::set_timestamp(::google::protobuf::int32 value) {
  
  timestamp_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.timestamp)
}

// optional int32 x = 4;
void AlarmInfo::clear_x() {
  x_ = 0;
}
 ::google::protobuf::int32 AlarmInfo::x() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.x)
  return x_;
}
 void AlarmInfo::set_x(::google::protobuf::int32 value) {
  
  x_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.x)
}

// optional int32 y = 5;
void AlarmInfo::clear_y() {
  y_ = 0;
}
 ::google::protobuf::int32 AlarmInfo::y() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.y)
  return y_;
}
 void AlarmInfo::set_y(::google::protobuf::int32 value) {
  
  y_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.y)
}

// optional int32 w = 6;
void AlarmInfo::clear_w() {
  w_ = 0;
}
 ::google::protobuf::int32 AlarmInfo::w() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.w)
  return w_;
}
 void AlarmInfo::set_w(::google::protobuf::int32 value) {
  
  w_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.w)
}

// optional int32 h = 7;
void AlarmInfo::clear_h() {
  h_ = 0;
}
 ::google::protobuf::int32 AlarmInfo::h() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.h)
  return h_;
}
 void AlarmInfo::set_h(::google::protobuf::int32 value) {
  
  h_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.h)
}

// optional int32 start_timestamp = 8;
void AlarmInfo::clear_start_timestamp() {
  start_timestamp_ = 0;
}
 ::google::protobuf::int32 AlarmInfo::start_timestamp() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.start_timestamp)
  return start_timestamp_;
}
 void AlarmInfo::set_start_timestamp(::google::protobuf::int32 value) {
  
  start_timestamp_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.start_timestamp)
}

// optional int32 end_timestamp = 9;
void AlarmInfo::clear_end_timestamp() {
  end_timestamp_ = 0;
}
 ::google::protobuf::int32 AlarmInfo::end_timestamp() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.end_timestamp)
  return end_timestamp_;
}
 void AlarmInfo::set_end_timestamp(::google::protobuf::int32 value) {
  
  end_timestamp_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.end_timestamp)
}

// optional int32 credibility = 10;
void AlarmInfo::clear_credibility() {
  credibility_ = 0;
}
 ::google::protobuf::int32 AlarmInfo::credibility() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.credibility)
  return credibility_;
}
 void AlarmInfo::set_credibility(::google::protobuf::int32 value) {
  
  credibility_ = value;
  // @@protoc_insertion_point(field_set:AlarmInfo.credibility)
}

// optional bytes alarm_pic = 11;
void AlarmInfo::clear_alarm_pic() {
  alarm_pic_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& AlarmInfo::alarm_pic() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.alarm_pic)
  return alarm_pic_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void AlarmInfo::set_alarm_pic(const ::std::string& value) {
  
  alarm_pic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:AlarmInfo.alarm_pic)
}
 void AlarmInfo::set_alarm_pic(const char* value) {
  
  alarm_pic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:AlarmInfo.alarm_pic)
}
 void AlarmInfo::set_alarm_pic(const void* value, size_t size) {
  
  alarm_pic_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:AlarmInfo.alarm_pic)
}
 ::std::string* AlarmInfo::mutable_alarm_pic() {
  
  // @@protoc_insertion_point(field_mutable:AlarmInfo.alarm_pic)
  return alarm_pic_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* AlarmInfo::release_alarm_pic() {
  // @@protoc_insertion_point(field_release:AlarmInfo.alarm_pic)
  
  return alarm_pic_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void AlarmInfo::set_allocated_alarm_pic(::std::string* alarm_pic) {
  if (alarm_pic != NULL) {
    
  } else {
    
  }
  alarm_pic_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), alarm_pic);
  // @@protoc_insertion_point(field_set_allocated:AlarmInfo.alarm_pic)
}

// optional bytes alarm_vid = 12;
void AlarmInfo::clear_alarm_vid() {
  alarm_vid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& AlarmInfo::alarm_vid() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.alarm_vid)
  return alarm_vid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void AlarmInfo::set_alarm_vid(const ::std::string& value) {
  
  alarm_vid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:AlarmInfo.alarm_vid)
}
 void AlarmInfo::set_alarm_vid(const char* value) {
  
  alarm_vid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:AlarmInfo.alarm_vid)
}
 void AlarmInfo::set_alarm_vid(const void* value, size_t size) {
  
  alarm_vid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:AlarmInfo.alarm_vid)
}
 ::std::string* AlarmInfo::mutable_alarm_vid() {
  
  // @@protoc_insertion_point(field_mutable:AlarmInfo.alarm_vid)
  return alarm_vid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* AlarmInfo::release_alarm_vid() {
  // @@protoc_insertion_point(field_release:AlarmInfo.alarm_vid)
  
  return alarm_vid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void AlarmInfo::set_allocated_alarm_vid(::std::string* alarm_vid) {
  if (alarm_vid != NULL) {
    
  } else {
    
  }
  alarm_vid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), alarm_vid);
  // @@protoc_insertion_point(field_set_allocated:AlarmInfo.alarm_vid)
}

// optional bytes src_image = 13;
void AlarmInfo::clear_src_image() {
  src_image_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& AlarmInfo::src_image() const {
  // @@protoc_insertion_point(field_get:AlarmInfo.src_image)
  return src_image_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void AlarmInfo::set_src_image(const ::std::string& value) {
  
  src_image_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:AlarmInfo.src_image)
}
 void AlarmInfo::set_src_image(const char* value) {
  
  src_image_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:AlarmInfo.src_image)
}
 void AlarmInfo::set_src_image(const void* value, size_t size) {
  
  src_image_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:AlarmInfo.src_image)
}
 ::std::string* AlarmInfo::mutable_src_image() {
  
  // @@protoc_insertion_point(field_mutable:AlarmInfo.src_image)
  return src_image_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* AlarmInfo::release_src_image() {
  // @@protoc_insertion_point(field_release:AlarmInfo.src_image)
  
  return src_image_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void AlarmInfo::set_allocated_src_image(::std::string* src_image) {
  if (src_image != NULL) {
    
  } else {
    
  }
  src_image_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), src_image);
  // @@protoc_insertion_point(field_set_allocated:AlarmInfo.src_image)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)