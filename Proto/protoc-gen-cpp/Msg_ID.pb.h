// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Msg_ID.proto

#ifndef PROTOBUF_Msg_5fID_2eproto__INCLUDED
#define PROTOBUF_Msg_5fID_2eproto__INCLUDED

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
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

namespace protobuf_Msg_5fID_2eproto {
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
}  // namespace protobuf_Msg_5fID_2eproto

enum MessageID {
  MSG_BEGIN = 0,
  MSG_HEART = 1,
  MSG_CONNECT_SUCCESS = 2,
  MSG_DISCONNECT_NTY = 3,
  MSG_LOGINSVR_MSGID_BEGIN = 1000000,
  MSG_CHECK_VERSION_REQ = 1000001,
  MSG_CHECK_VERSION_ACK = 1000002,
  MSG_ACCOUNT_REG_REQ = 1000003,
  MSG_ACCOUNT_REG_ACK = 1000004,
  MSG_ACCOUNT_LOGIN_REQ = 1000005,
  MSG_ACCOUNT_LOGIN_ACK = 1000006,
  MSG_ACCOUNT_LOGINREG_REQ = 1000007,
  MSG_ACCOUNT_LOGINREG_ACK = 1000008,
  MSG_SERVER_LIST_REQ = 1000009,
  MSG_SERVER_LIST_ACK = 1000010,
  MSG_SELECT_SERVER_REQ = 1000011,
  MSG_SELECT_SERVER_ACK = 1000012,
  MSG_LOGIC_REGTO_LOGIN_REQ = 1000013,
  MSG_LOGIC_REGTO_LOGIN_ACK = 1000014,
  MSG_LOGINSVR_MSGID_END = 1999999,
  MSG_LOGICSVR_MSGID_BEGIN = 2000000,
  MSG_ROLE_LIST_REQ = 2000001,
  MSG_ROLE_LIST_ACK = 2000002,
  MSG_ROLE_CREATE_REQ = 2000003,
  MSG_ROLE_CREATE_ACK = 2000004,
  MSG_ROLE_DELETE_REQ = 2000005,
  MSG_ROLE_DELETE_ACK = 2000006,
  MSG_ROLE_LOGIN_REQ = 2000007,
  MSG_ROLE_LOGIN_ACK = 2000008,
  MSG_ROLE_LOGOUT_REQ = 2000009,
  MSG_ROLE_LOGOUT_ACK = 2000010,
  MSG_DATA_UPDATE = 2000011,
  MSG_GAME_REG_LOGIC_REQ = 2000012,
  MSG_GAME_REG_LOGIC_ACK = 2000013,
  MSG_NOTIFY_INTO_SCENE = 2000014,
  MSG_GMSVR_REGTO_LOGIC_REQ = 2000015,
  MSG_LOGICSVR_MSGID_END = 2999999,
  MSG_SCENESVR_MSGID_BEGIN = 3000000,
  MSG_CREATE_SCENE_REQ = 3000001,
  MSG_CREATE_SCENE_ACK = 3000002,
  MSG_DELETE_SCENE_REQ = 3000003,
  MSG_DELETE_SCENE_ACK = 3000004,
  MSG_SCENE_DESTROY_REQ = 3000005,
  MSG_SCENE_DESTROY_ACK = 3000006,
  MSG_TRANS_ROLE_DATA_REQ = 3000007,
  MSG_TRANS_ROLE_DATA_ACK = 3000008,
  MSG_NOTIFY_ROLE_ENTER_REQ = 3000009,
  MSG_NOTIFY_ROLE_ENTER_ACK = 3000010,
  MSG_ENTER_SCENE_REQ = 3000011,
  MSG_ENTER_SCENE_ACK = 3000012,
  MSG_LEAVE_SCENE_REQ = 3000013,
  MSG_LEAVE_SCENE_ACK = 3000014,
  MSG_NEARBY_ADD_NTY = 3000015,
  MSG_NEARBY_DEL_NTY = 3000016,
  MSG_NEARBY_UPDATE_NTY = 3000017,
  MSG_ROLE_MOVE_REQ = 3000018,
  MSG_ROLE_SKILL_REQ = 3000019,
  MSG_SCENESVR_MSGID_END = 3999999,
  MSG_REQ_LOGIN = 1001,
  MSG_ACK_LOGIN = 1002,
  MSG_REQ_LOGINSERVER = 1003,
  MSG_ACK_LOGINSERVER = 1004,
  MSG_REQ_GETSERVERLIST = 1005,
  MSG_ACK_GETSERVERLIST = 1006,
  MSG_REQ_CREATEROLE = 1007,
  MSG_ACK_CREATEROLE = 1008,
  MSG_REQ_ENTERGAME = 1009,
  MSG_ACK_ENTERGAME = 1010,
  MSG_REQ_REGISTER = 1011,
  MSG_ACK_REGISTER = 1012,
  MSG_REQ_SORTBAG = 1101,
  MSG_ACK_SORTBAG = 1102,
  MSG_REQ_USEITEM = 1103,
  MSG_ACK_USEITEM = 1104,
  MSG_REQ_DRESS_EQUIP = 1105,
  MSG_ACK_DRESS_EQUIP = 1106,
  MSG_REQ_UNLOAD_EQUIP = 1107,
  MSG_ACK_UNLOAD_EQUIP = 1108,
  MSG_REQ_DRESS_GEM = 1109,
  MSG_ACK_DRESS_GEM = 1110,
  MSG_REQ_UNLOAD_GEM = 1111,
  MSG_ACK_UNLOAD_GEM = 1112,
  MSG_REQ_COMPOSE_CHIP = 1113,
  MSG_ACK_COMPOSE_CHIP = 1114,
  MSG_REQ_STRENGTHEN_EQUIP = 1115,
  MSG_ACK_STRENGTHEN_EQUIP = 1116,
  MSG_REQ_ADVANCE_EQUIP = 1117,
  MSG_ACK_ADVANCE_EQUIP = 1118,
  MSG_REQ_UPSTAR_EQUIP = 1119,
  MSG_ACK_UPSTAR_EQUIP = 1120,
  MSG_REQ_STRENGTHEN_GEM = 1121,
  MSG_ACK_STRENGTHEN_GEM = 1122,
  MSG_REQ_ONEKEYTODRESSGEM = 1151,
  MSG_ACK_ONEKEYTODRESSGEM = 1152,
  MSG_REQ_ONEKEYTOUNLOADGEM = 1153,
  MSG_ACK_ONEKEYTOUNLOADGEM = 1154,
  MSG_REQ_GET_CHAPTERAWARD = 1201,
  MSG_ACK_GET_CHAPTERAWARD = 1202,
  MSG_REQ_BATTLE_CHECK = 1203,
  MSG_ACK_BATTLE_CHECK = 1204,
  MSG_REQ_PASSCOPY = 1205,
  MSG_ACK_PASSCOPY = 1206,
  MSG_REQ_SETMOUNT = 1301,
  MSG_ACK_SETMOUNT = 1302,
  MSG_REQ_CHARGE_RELICS = 1401,
  MSG_ACK_CHARGE_RELICS = 1402,
  MSG_REQ_UPGRADE_RELICS = 1403,
  MSG_ACK_UPGRADE_RELICS = 1404,
  MSG_REQ_BATTLE_RELICS = 1405,
  MSG_ACK_BATTLE_RELICS = 1406,
  MSG_REQ_UNLOAD_RELICS = 1407,
  MSG_ACK_UNLOAD_RELICS = 1408,
  MSG_REQ_BUY_STORE = 1501,
  MSG_ACK_BUY_STORE = 1502,
  MSG_REQ_UPGRADE_PET = 1601,
  MSG_ACK_UPGRADE_PET = 1602,
  MSG_REQ_BATTLE_PET = 1603,
  MSG_ACK_BATTLE_PET = 1604,
  MSG_REQ_UNLOAD_PET = 1605,
  MSG_ACK_UNLOAD_PET = 1606,
  MSG_REQ_CHANGE_PARTNER = 1607,
  MSG_ACK_CHANGE_PARTNER = 1608,
  MSG_REQ_ADVANVE_PARTNER = 1609,
  MSG_ACK_ADVANVE_PARTNER = 1610,
  MSG_REQ_UPGRADE_PARTNER = 1611,
  MSG_ACK_UPGRADE_PARTNER = 1612,
  MSG_REQ_SUBMIT_TASK = 1613,
  MSG_ACK_SUBMIT_TASK = 1614,
  MSG_REQ_ADDHERO_EXP = 2001,
  MSG_ACK_ADDHERO_EXP = 2002,
  MessageID_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  MessageID_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool MessageID_IsValid(int value);
const MessageID MessageID_MIN = MSG_BEGIN;
const MessageID MessageID_MAX = MSG_SCENESVR_MSGID_END;
const int MessageID_ARRAYSIZE = MessageID_MAX + 1;

const ::google::protobuf::EnumDescriptor* MessageID_descriptor();
inline const ::std::string& MessageID_Name(MessageID value) {
  return ::google::protobuf::internal::NameOfEnum(
    MessageID_descriptor(), value);
}
inline bool MessageID_Parse(
    const ::std::string& name, MessageID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MessageID>(
    MessageID_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::MessageID> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::MessageID>() {
  return ::MessageID_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Msg_5fID_2eproto__INCLUDED
