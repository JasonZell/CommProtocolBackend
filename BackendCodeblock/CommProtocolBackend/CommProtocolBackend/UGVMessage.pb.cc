// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: UGVMessage.proto
//#include "stdafx.h"
#include "UGVMessage.pb.h"
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
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)
namespace UGV {
class ArmCommandDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ArmCommand>
      _instance;
} _ArmCommand_default_instance_;
}  // namespace UGV
namespace protobuf_UGVMessage_2eproto {
void InitDefaultsArmCommandImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  ::google::protobuf::internal::InitProtobufDefaultsForceUnique();
#else
  ::google::protobuf::internal::InitProtobufDefaults();
#endif  // GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
  {
    void* ptr = &::UGV::_ArmCommand_default_instance_;
    new (ptr) ::UGV::ArmCommand();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::UGV::ArmCommand::InitAsDefaultInstance();
}

void InitDefaultsArmCommand() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &InitDefaultsArmCommandImpl);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::UGV::ArmCommand, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::UGV::ArmCommand, id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::UGV::ArmCommand, position_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::UGV::ArmCommand)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::UGV::_ArmCommand_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "UGVMessage.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\020UGVMessage.proto\022\003UGV\"*\n\nArmCommand\022\n\n"
      "\002id\030\001 \001(\r\022\020\n\010position\030\002 \001(\rb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 75);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "UGVMessage.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_UGVMessage_2eproto
namespace UGV {

// ===================================================================

void ArmCommand::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ArmCommand::kIdFieldNumber;
const int ArmCommand::kPositionFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ArmCommand::ArmCommand()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    ::protobuf_UGVMessage_2eproto::InitDefaultsArmCommand();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:UGV.ArmCommand)
}
ArmCommand::ArmCommand(const ArmCommand& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&id_, &from.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&position_) -
    reinterpret_cast<char*>(&id_)) + sizeof(position_));
  // @@protoc_insertion_point(copy_constructor:UGV.ArmCommand)
}

void ArmCommand::SharedCtor() {
  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&position_) -
      reinterpret_cast<char*>(&id_)) + sizeof(position_));
  _cached_size_ = 0;
}

ArmCommand::~ArmCommand() {
  // @@protoc_insertion_point(destructor:UGV.ArmCommand)
  SharedDtor();
}

void ArmCommand::SharedDtor() {
}

void ArmCommand::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ArmCommand::descriptor() {
  ::protobuf_UGVMessage_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_UGVMessage_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ArmCommand& ArmCommand::default_instance() {
  ::protobuf_UGVMessage_2eproto::InitDefaultsArmCommand();
  return *internal_default_instance();
}

ArmCommand* ArmCommand::New(::google::protobuf::Arena* arena) const {
  ArmCommand* n = new ArmCommand;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ArmCommand::Clear() {
// @@protoc_insertion_point(message_clear_start:UGV.ArmCommand)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&position_) -
      reinterpret_cast<char*>(&id_)) + sizeof(position_));
  _internal_metadata_.Clear();
}

bool ArmCommand::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:UGV.ArmCommand)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // uint32 id = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 position = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &position_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:UGV.ArmCommand)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:UGV.ArmCommand)
  return false;
#undef DO_
}

void ArmCommand::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:UGV.ArmCommand)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 id = 1;
  if (this->id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->id(), output);
  }

  // uint32 position = 2;
  if (this->position() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->position(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:UGV.ArmCommand)
}

::google::protobuf::uint8* ArmCommand::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:UGV.ArmCommand)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 id = 1;
  if (this->id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->id(), target);
  }

  // uint32 position = 2;
  if (this->position() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->position(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:UGV.ArmCommand)
  return target;
}

size_t ArmCommand::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:UGV.ArmCommand)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // uint32 id = 1;
  if (this->id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->id());
  }

  // uint32 position = 2;
  if (this->position() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->position());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ArmCommand::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:UGV.ArmCommand)
  GOOGLE_DCHECK_NE(&from, this);
  const ArmCommand* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ArmCommand>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:UGV.ArmCommand)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:UGV.ArmCommand)
    MergeFrom(*source);
  }
}

void ArmCommand::MergeFrom(const ArmCommand& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:UGV.ArmCommand)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.id() != 0) {
    set_id(from.id());
  }
  if (from.position() != 0) {
    set_position(from.position());
  }
}

void ArmCommand::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:UGV.ArmCommand)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ArmCommand::CopyFrom(const ArmCommand& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:UGV.ArmCommand)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ArmCommand::IsInitialized() const {
  return true;
}

void ArmCommand::Swap(ArmCommand* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ArmCommand::InternalSwap(ArmCommand* other) {
  using std::swap;
  swap(id_, other->id_);
  swap(position_, other->position_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ArmCommand::GetMetadata() const {
  protobuf_UGVMessage_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_UGVMessage_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace UGV

// @@protoc_insertion_point(global_scope)
