// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Protocol.proto

#include "Protocol.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace Protocol {
PROTOBUF_CONSTEXPR PacketHeader::PacketHeader(
    ::_pbi::ConstantInitialized)
  : id_(0u)
  , size_(0u){}
struct PacketHeaderDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PacketHeaderDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PacketHeaderDefaultTypeInternal() {}
  union {
    PacketHeader _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PacketHeaderDefaultTypeInternal _PacketHeader_default_instance_;
PROTOBUF_CONSTEXPR BuffData::BuffData(
    ::_pbi::ConstantInitialized)
  : victims_()
  , _victims_cached_byte_size_(0)
  , buffid_(0u)
  , remaintime_(0){}
struct BuffDataDefaultTypeInternal {
  PROTOBUF_CONSTEXPR BuffDataDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~BuffDataDefaultTypeInternal() {}
  union {
    BuffData _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 BuffDataDefaultTypeInternal _BuffData_default_instance_;
PROTOBUF_CONSTEXPR Playerinfo::Playerinfo(
    ::_pbi::ConstantInitialized)
  : buffs_()
  , header_(nullptr)
  , id_(uint64_t{0u})
  , hp_(0u)
  , atk_(0u){}
struct PlayerinfoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PlayerinfoDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PlayerinfoDefaultTypeInternal() {}
  union {
    Playerinfo _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PlayerinfoDefaultTypeInternal _Playerinfo_default_instance_;
}  // namespace Protocol
static ::_pb::Metadata file_level_metadata_Protocol_2eproto[3];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_Protocol_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_Protocol_2eproto = nullptr;

const uint32_t TableStruct_Protocol_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::PacketHeader, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::PacketHeader, id_),
  PROTOBUF_FIELD_OFFSET(::Protocol::PacketHeader, size_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::BuffData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::BuffData, buffid_),
  PROTOBUF_FIELD_OFFSET(::Protocol::BuffData, remaintime_),
  PROTOBUF_FIELD_OFFSET(::Protocol::BuffData, victims_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::Playerinfo, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::Playerinfo, header_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Playerinfo, id_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Playerinfo, hp_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Playerinfo, atk_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Playerinfo, buffs_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Protocol::PacketHeader)},
  { 8, -1, -1, sizeof(::Protocol::BuffData)},
  { 17, -1, -1, sizeof(::Protocol::Playerinfo)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::Protocol::_PacketHeader_default_instance_._instance,
  &::Protocol::_BuffData_default_instance_._instance,
  &::Protocol::_Playerinfo_default_instance_._instance,
};

const char descriptor_table_protodef_Protocol_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016Protocol.proto\022\010Protocol\"(\n\014PacketHead"
  "er\022\n\n\002id\030\001 \001(\r\022\014\n\004size\030\002 \001(\r\"\?\n\010BuffData"
  "\022\016\n\006buffId\030\001 \001(\r\022\022\n\nremainTime\030\002 \001(\002\022\017\n\007"
  "victims\030\003 \003(\r\"|\n\nPlayerinfo\022&\n\006header\030\001 "
  "\001(\0132\026.Protocol.PacketHeader\022\n\n\002id\030\002 \001(\004\022"
  "\n\n\002hp\030\003 \001(\r\022\013\n\003atk\030\004 \001(\r\022!\n\005buffs\030\005 \003(\0132"
  "\022.Protocol.BuffDatab\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_Protocol_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_Protocol_2eproto = {
    false, false, 267, descriptor_table_protodef_Protocol_2eproto,
    "Protocol.proto",
    &descriptor_table_Protocol_2eproto_once, nullptr, 0, 3,
    schemas, file_default_instances, TableStruct_Protocol_2eproto::offsets,
    file_level_metadata_Protocol_2eproto, file_level_enum_descriptors_Protocol_2eproto,
    file_level_service_descriptors_Protocol_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_Protocol_2eproto_getter() {
  return &descriptor_table_Protocol_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_Protocol_2eproto(&descriptor_table_Protocol_2eproto);
namespace Protocol {

// ===================================================================

class PacketHeader::_Internal {
 public:
};

PacketHeader::PacketHeader(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:Protocol.PacketHeader)
}
PacketHeader::PacketHeader(const PacketHeader& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&size_) -
    reinterpret_cast<char*>(&id_)) + sizeof(size_));
  // @@protoc_insertion_point(copy_constructor:Protocol.PacketHeader)
}

inline void PacketHeader::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&id_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&size_) -
    reinterpret_cast<char*>(&id_)) + sizeof(size_));
}

PacketHeader::~PacketHeader() {
  // @@protoc_insertion_point(destructor:Protocol.PacketHeader)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void PacketHeader::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void PacketHeader::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void PacketHeader::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.PacketHeader)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&size_) -
      reinterpret_cast<char*>(&id_)) + sizeof(size_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PacketHeader::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 size = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          size_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* PacketHeader::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.PacketHeader)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 id = 1;
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(1, this->_internal_id(), target);
  }

  // uint32 size = 2;
  if (this->_internal_size() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(2, this->_internal_size(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.PacketHeader)
  return target;
}

size_t PacketHeader::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.PacketHeader)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // uint32 id = 1;
  if (this->_internal_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_id());
  }

  // uint32 size = 2;
  if (this->_internal_size() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_size());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData PacketHeader::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    PacketHeader::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*PacketHeader::GetClassData() const { return &_class_data_; }

void PacketHeader::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<PacketHeader *>(to)->MergeFrom(
      static_cast<const PacketHeader &>(from));
}


void PacketHeader::MergeFrom(const PacketHeader& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.PacketHeader)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_id() != 0) {
    _internal_set_id(from._internal_id());
  }
  if (from._internal_size() != 0) {
    _internal_set_size(from._internal_size());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void PacketHeader::CopyFrom(const PacketHeader& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.PacketHeader)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PacketHeader::IsInitialized() const {
  return true;
}

void PacketHeader::InternalSwap(PacketHeader* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(PacketHeader, size_)
      + sizeof(PacketHeader::size_)
      - PROTOBUF_FIELD_OFFSET(PacketHeader, id_)>(
          reinterpret_cast<char*>(&id_),
          reinterpret_cast<char*>(&other->id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata PacketHeader::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_Protocol_2eproto_getter, &descriptor_table_Protocol_2eproto_once,
      file_level_metadata_Protocol_2eproto[0]);
}

// ===================================================================

class BuffData::_Internal {
 public:
};

BuffData::BuffData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  victims_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:Protocol.BuffData)
}
BuffData::BuffData(const BuffData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      victims_(from.victims_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&buffid_, &from.buffid_,
    static_cast<size_t>(reinterpret_cast<char*>(&remaintime_) -
    reinterpret_cast<char*>(&buffid_)) + sizeof(remaintime_));
  // @@protoc_insertion_point(copy_constructor:Protocol.BuffData)
}

inline void BuffData::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&buffid_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&remaintime_) -
    reinterpret_cast<char*>(&buffid_)) + sizeof(remaintime_));
}

BuffData::~BuffData() {
  // @@protoc_insertion_point(destructor:Protocol.BuffData)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void BuffData::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void BuffData::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void BuffData::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.BuffData)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  victims_.Clear();
  ::memset(&buffid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&remaintime_) -
      reinterpret_cast<char*>(&buffid_)) + sizeof(remaintime_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* BuffData::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint32 buffId = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          buffid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // float remainTime = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 21)) {
          remaintime_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else
          goto handle_unusual;
        continue;
      // repeated uint32 victims = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedUInt32Parser(_internal_mutable_victims(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 24) {
          _internal_add_victims(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* BuffData::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.BuffData)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 buffId = 1;
  if (this->_internal_buffid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(1, this->_internal_buffid(), target);
  }

  // float remainTime = 2;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_remaintime = this->_internal_remaintime();
  uint32_t raw_remaintime;
  memcpy(&raw_remaintime, &tmp_remaintime, sizeof(tmp_remaintime));
  if (raw_remaintime != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(2, this->_internal_remaintime(), target);
  }

  // repeated uint32 victims = 3;
  {
    int byte_size = _victims_cached_byte_size_.load(std::memory_order_relaxed);
    if (byte_size > 0) {
      target = stream->WriteUInt32Packed(
          3, _internal_victims(), byte_size, target);
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.BuffData)
  return target;
}

size_t BuffData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.BuffData)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated uint32 victims = 3;
  {
    size_t data_size = ::_pbi::WireFormatLite::
      UInt32Size(this->victims_);
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    int cached_size = ::_pbi::ToCachedSize(data_size);
    _victims_cached_byte_size_.store(cached_size,
                                    std::memory_order_relaxed);
    total_size += data_size;
  }

  // uint32 buffId = 1;
  if (this->_internal_buffid() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_buffid());
  }

  // float remainTime = 2;
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_remaintime = this->_internal_remaintime();
  uint32_t raw_remaintime;
  memcpy(&raw_remaintime, &tmp_remaintime, sizeof(tmp_remaintime));
  if (raw_remaintime != 0) {
    total_size += 1 + 4;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData BuffData::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    BuffData::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*BuffData::GetClassData() const { return &_class_data_; }

void BuffData::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<BuffData *>(to)->MergeFrom(
      static_cast<const BuffData &>(from));
}


void BuffData::MergeFrom(const BuffData& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.BuffData)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  victims_.MergeFrom(from.victims_);
  if (from._internal_buffid() != 0) {
    _internal_set_buffid(from._internal_buffid());
  }
  static_assert(sizeof(uint32_t) == sizeof(float), "Code assumes uint32_t and float are the same size.");
  float tmp_remaintime = from._internal_remaintime();
  uint32_t raw_remaintime;
  memcpy(&raw_remaintime, &tmp_remaintime, sizeof(tmp_remaintime));
  if (raw_remaintime != 0) {
    _internal_set_remaintime(from._internal_remaintime());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void BuffData::CopyFrom(const BuffData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.BuffData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BuffData::IsInitialized() const {
  return true;
}

void BuffData::InternalSwap(BuffData* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  victims_.InternalSwap(&other->victims_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(BuffData, remaintime_)
      + sizeof(BuffData::remaintime_)
      - PROTOBUF_FIELD_OFFSET(BuffData, buffid_)>(
          reinterpret_cast<char*>(&buffid_),
          reinterpret_cast<char*>(&other->buffid_));
}

::PROTOBUF_NAMESPACE_ID::Metadata BuffData::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_Protocol_2eproto_getter, &descriptor_table_Protocol_2eproto_once,
      file_level_metadata_Protocol_2eproto[1]);
}

// ===================================================================

class Playerinfo::_Internal {
 public:
  static const ::Protocol::PacketHeader& header(const Playerinfo* msg);
};

const ::Protocol::PacketHeader&
Playerinfo::_Internal::header(const Playerinfo* msg) {
  return *msg->header_;
}
Playerinfo::Playerinfo(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  buffs_(arena) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:Protocol.Playerinfo)
}
Playerinfo::Playerinfo(const Playerinfo& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      buffs_(from.buffs_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_header()) {
    header_ = new ::Protocol::PacketHeader(*from.header_);
  } else {
    header_ = nullptr;
  }
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&atk_) -
    reinterpret_cast<char*>(&id_)) + sizeof(atk_));
  // @@protoc_insertion_point(copy_constructor:Protocol.Playerinfo)
}

inline void Playerinfo::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&header_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&atk_) -
    reinterpret_cast<char*>(&header_)) + sizeof(atk_));
}

Playerinfo::~Playerinfo() {
  // @@protoc_insertion_point(destructor:Protocol.Playerinfo)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Playerinfo::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete header_;
}

void Playerinfo::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Playerinfo::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.Playerinfo)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  buffs_.Clear();
  if (GetArenaForAllocation() == nullptr && header_ != nullptr) {
    delete header_;
  }
  header_ = nullptr;
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&atk_) -
      reinterpret_cast<char*>(&id_)) + sizeof(atk_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Playerinfo::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .Protocol.PacketHeader header = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_header(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint64 id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 hp = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          hp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint32 atk = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          atk_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .Protocol.BuffData buffs = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_buffs(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<42>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Playerinfo::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.Playerinfo)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .Protocol.PacketHeader header = 1;
  if (this->_internal_has_header()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::header(this),
        _Internal::header(this).GetCachedSize(), target, stream);
  }

  // uint64 id = 2;
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(2, this->_internal_id(), target);
  }

  // uint32 hp = 3;
  if (this->_internal_hp() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(3, this->_internal_hp(), target);
  }

  // uint32 atk = 4;
  if (this->_internal_atk() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(4, this->_internal_atk(), target);
  }

  // repeated .Protocol.BuffData buffs = 5;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_buffs_size()); i < n; i++) {
    const auto& repfield = this->_internal_buffs(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(5, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.Playerinfo)
  return target;
}

size_t Playerinfo::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.Playerinfo)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .Protocol.BuffData buffs = 5;
  total_size += 1UL * this->_internal_buffs_size();
  for (const auto& msg : this->buffs_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // .Protocol.PacketHeader header = 1;
  if (this->_internal_has_header()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *header_);
  }

  // uint64 id = 2;
  if (this->_internal_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_id());
  }

  // uint32 hp = 3;
  if (this->_internal_hp() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_hp());
  }

  // uint32 atk = 4;
  if (this->_internal_atk() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_atk());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Playerinfo::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Playerinfo::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Playerinfo::GetClassData() const { return &_class_data_; }

void Playerinfo::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Playerinfo *>(to)->MergeFrom(
      static_cast<const Playerinfo &>(from));
}


void Playerinfo::MergeFrom(const Playerinfo& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.Playerinfo)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  buffs_.MergeFrom(from.buffs_);
  if (from._internal_has_header()) {
    _internal_mutable_header()->::Protocol::PacketHeader::MergeFrom(from._internal_header());
  }
  if (from._internal_id() != 0) {
    _internal_set_id(from._internal_id());
  }
  if (from._internal_hp() != 0) {
    _internal_set_hp(from._internal_hp());
  }
  if (from._internal_atk() != 0) {
    _internal_set_atk(from._internal_atk());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Playerinfo::CopyFrom(const Playerinfo& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.Playerinfo)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Playerinfo::IsInitialized() const {
  return true;
}

void Playerinfo::InternalSwap(Playerinfo* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  buffs_.InternalSwap(&other->buffs_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Playerinfo, atk_)
      + sizeof(Playerinfo::atk_)
      - PROTOBUF_FIELD_OFFSET(Playerinfo, header_)>(
          reinterpret_cast<char*>(&header_),
          reinterpret_cast<char*>(&other->header_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Playerinfo::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_Protocol_2eproto_getter, &descriptor_table_Protocol_2eproto_once,
      file_level_metadata_Protocol_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Protocol::PacketHeader*
Arena::CreateMaybeMessage< ::Protocol::PacketHeader >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::PacketHeader >(arena);
}
template<> PROTOBUF_NOINLINE ::Protocol::BuffData*
Arena::CreateMaybeMessage< ::Protocol::BuffData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::BuffData >(arena);
}
template<> PROTOBUF_NOINLINE ::Protocol::Playerinfo*
Arena::CreateMaybeMessage< ::Protocol::Playerinfo >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::Playerinfo >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
